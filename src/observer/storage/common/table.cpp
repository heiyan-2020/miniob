/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Meiyi & Wangyunlai on 2021/5/13.
//

#include <climits>
#include <cstring>
#include <algorithm>
#include <utility>

#include "common/defs.h"
#include "storage/common/table.h"
#include "storage/common/table_meta.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/default/disk_buffer_pool.h"
#include "storage/record/record_manager.h"
#include "storage/common/meta_util.h"
#include "storage/index/index.h"
#include "storage/index/bplus_tree_index.h"
#include "storage/trx/trx.h"
#include "util/date_utils.h"
#include "common/lang/defer.h"
#include "sql/table/schema.h"
#include "type/value.h"
#include "storage/clog/clog.h"

Table::~Table()
{
  if (record_handler_ != nullptr) {
    delete record_handler_;
    record_handler_ = nullptr;
  }

  if (data_buffer_pool_ != nullptr) {
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
  }

  for (auto index : indexes_) {
    delete index;
  }
  indexes_.clear();

  LOG_INFO("Table has been closed: %s", name().c_str());
}

RC Table::create(const char *path, const char *name, const char *base_dir, const Schema &schema, CLogManager *clog_manager)
{
  if (common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }

  LOG_INFO("Begin to create table: %s", name);

  RC rc = RC::SUCCESS;

  // 使用 table_name.table 记录一个表的元数据
  // 判断表文件是否已经存在
  int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  if (fd < 0) {
    if (EEXIST == errno) {
      LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s", path, strerror(errno));
      return RC::SCHEMA_TABLE_EXIST;
    }
    LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s", path, errno, strerror(errno));
    return RC::IOERR;
  }

  close(fd);

  // 创建文件
  if ((rc = table_meta_.init(name, schema)) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta");
    return rc;  // delete table file
  }

  std::fstream fs;
  fs.open(path, std::ios_base::out | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write, file name = %s, errmsg = %s", path, strerror(errno));
    return RC::IOERR;
  }

  // 记录元数据到文件中
  table_meta_.serialize(fs);
  fs.close();

  std::string data_file = table_data_file(base_dir, name);
  BufferPoolManager &bpm = BufferPoolManager::instance();
  rc = bpm.create_file(data_file.c_str());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create disk buffer pool of data file. file name=%s", data_file.c_str());
    return rc;
  }

  rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create table %s due to init record handler failed.", data_file.c_str());
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;
  clog_manager_ = clog_manager;
  LOG_INFO("Successfully create table %s:%s", base_dir, name);
  return rc;
}

RC Table::open(const char *meta_file, const char *base_dir, CLogManager *clog_manager)
{
  // 加载元数据文件
  std::fstream fs;
  std::string meta_file_path = std::string(base_dir) + common::FILE_PATH_SPLIT_STR + meta_file;
  fs.open(meta_file_path, std::ios_base::in | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open meta file for read. file name=%s, errmsg=%s", meta_file_path.c_str(), strerror(errno));
    return RC::IOERR;
  }
  if (table_meta_.deserialize(fs) < 0) {
    LOG_ERROR("Failed to deserialize table meta. file name=%s", meta_file_path.c_str());
    fs.close();
    return RC::GENERIC_ERROR;
  }
  fs.close();

  // 加载数据文件
  RC rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open table %s due to init record handler failed.", base_dir);
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;

  const int index_num = table_meta_.index_num();
  for (int i = 0; i < index_num; i++) {
    std::vector<FieldMeta> field_metas{};
    const IndexMeta *index_meta = table_meta_.index(i);
    for (const auto &field_name : index_meta->fields()) {
      const FieldMeta *field_meta = table_meta_.field(field_name);
      if (field_meta == nullptr) {
        LOG_ERROR("Found invalid index meta info which has a non-exists field. table=%s, index=%s, fields=%s",
            name().c_str(),
            index_meta->name().c_str(),
            field_name.c_str());
        // skip cleanup
        // do all cleanup action in destructive Table function
        return RC::GENERIC_ERROR;
      }
      field_metas.push_back(*field_meta);
    }

    auto *index = new BplusTreeIndex();
    std::string index_file = table_index_file(base_dir, name().c_str(), index_meta->name().c_str());
    rc = index->open(index_file.c_str(), *index_meta, field_metas);
    if (rc != RC::SUCCESS) {
      delete index;
      LOG_ERROR("Failed to open index. table=%s, index=%s, file=%s, rc=%d:%s",
          name().c_str(),
          index_meta->name().c_str(),
          index_file.c_str(),
          rc,
          strrc(rc));
      // skip cleanup
      // do all cleanup action in destructive Table function
      return rc;
    }
    indexes_.push_back(index);
  }
  if (clog_manager_ == nullptr) {
    clog_manager_ = clog_manager;
  }
  return rc;
}

RC Table::commit_insert(Trx *trx, const RID &rid)
{
  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to get record %s: %s", this->name().c_str(), rid.to_string().c_str());
    return rc;
  }

  return trx->commit_insert(this, record);
}

RC Table::rollback_insert(Trx *trx, const RID &rid)
{

  Record record;
  RC rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to get record %s: %s", this->name().c_str(), rid.to_string().c_str());
    return rc;
  }

  // remove all indexes
  rc = delete_entry_of_indexes(record.data(), rid, false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record(rid=%d.%d) while rollback insert, rc=%d:%s",
        rid.page_num,
        rid.slot_num,
        rc,
        strrc(rc));
    return rc;
  }

  rc = record_handler_->delete_record(&rid);
  return rc;
}

RC Table::insert_record(Trx *trx, Record *record)
{
  RC rc = RC::SUCCESS;

  // init trx info
  if (trx != nullptr) {
    trx->init_trx_info(this, *record);
  }

  // do insert
  rc = record_handler_->insert_record(record->data(), table_meta_.record_size(), &record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%d:%s", table_meta_.name().c_str(), rc, strrc(rc));
    return rc;
  }

  // handle trx
  if (trx != nullptr) {
    rc = trx->insert_record(this, record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to log operation(insertion) to trx");

      RC rc2 = record_handler_->delete_record(&record->rid());
      if (rc2 != RC::SUCCESS) {
        LOG_ERROR("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
            name().c_str(),
            rc2,
            strrc(rc2));
      }
      return rc;
    }
  }

  // handle indexes
  rc = insert_entry_of_indexes(record->data(), record->rid());
  if (rc != RC::SUCCESS) {
    RC rc2 = delete_entry_of_indexes(record->data(), record->rid(), true);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
          name().c_str(),
          rc2,
          strrc(rc2));
    }

    rc2 = record_handler_->delete_record(&record->rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
          name().c_str(),
          rc2,
          strrc(rc2));
    }
    return rc;
  }

  // append clog record
  if (trx != nullptr) {
    CLogRecord *clog_record = nullptr;
    rc = clog_manager_->clog_gen_record(
        CLogType::REDO_INSERT, trx->get_current_id(), clog_record,
        name().c_str(), table_meta_.record_size(), record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a clog record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    rc = clog_manager_->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  return rc;
}

RC Table::recover_insert_record(Record *record)
{
  RC rc = RC::SUCCESS;

  rc = record_handler_->recover_insert_record(record->data(), table_meta_.record_size(), &record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%d:%s", table_meta_.name().c_str(), rc, strrc(rc));
    return rc;
  }

  return rc;
}

RC Table::insert_record(Trx *trx, const std::vector<Value> &values)
{
  char *record_data = (char *)calloc(table_meta_.record_size(), sizeof(char));
  DEFER([&]() { free(record_data); });

  common::Bitmap null_field_bitmap{record_data, 32};

  size_t curr_offset{static_cast<size_t>(table_meta_.trx_field()->offset() + table_meta_.trx_field()->len())};
  size_t curr_index{TableMeta::sys_field_num()};
  for (size_t i = 0; i < values.size(); ++i) {
    const auto &value = values[i];
    if (!value.is_null()) {
      value.serialize_to(record_data + curr_offset);
    } else {
      null_field_bitmap.set_bit(i + TableMeta::sys_field_num());
    }
    curr_offset += table_meta_.field(curr_index)->len();
    curr_index += 1;
  }

  // TODO(vgalaxy): listener
  RC rc = check_unique_constraint(record_data);
  if (rc != RC::SUCCESS) {
    LOG_WARN("Failed to insert a record due to violate unique constraint");
    return rc;
  }

  Record record;
  record.set_data(record_data);
  rc = insert_record(trx, &record);
  return rc;
}

std::string Table::name() const
{
  return table_meta_.name();
}

const TableMeta &Table::table_meta() const
{
  return table_meta_;
}

RC Table::init_record_handler(const char *base_dir)
{
  std::string data_file = table_data_file(base_dir, table_meta_.name().c_str());

  RC rc = BufferPoolManager::instance().open_file(data_file.c_str(), data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s", data_file.c_str(), rc, strrc(rc));
    return rc;
  }

  record_handler_ = new RecordFileHandler();
  rc = record_handler_->init(data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to init record handler. rc=%d:%s", rc, strrc(rc));
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
    delete record_handler_;
    record_handler_ = nullptr;
    return rc;
  }

  return rc;
}

RC Table::get_record_scanner(RecordFileScanner &scanner)
{
  RC rc = scanner.open_scan(*data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%d:%s", rc, strrc(rc));
  }
  return rc;
}

/**
 * 为了不把 Record 暴露出去，封装一下
 */
class RecordReaderScanAdapter {
public:
  explicit RecordReaderScanAdapter(void (*record_reader)(const char *data, void *context), void *context)
      : record_reader_(record_reader), context_(context)
  {}

  void consume(const Record *record)
  {
    record_reader_(record->data(), context_);
  }

private:
  void (*record_reader_)(const char *, void *);
  void *context_;
};

static RC scan_record_reader_adapter(Record *record, void *context)
{
  RecordReaderScanAdapter &adapter = *(RecordReaderScanAdapter *)context;
  adapter.consume(record);
  return RC::SUCCESS;
}

RC Table::scan_record(Trx *trx, int limit, void *context, void (*record_reader)(const char *, void *))
{
  RecordReaderScanAdapter adapter(record_reader, context);
  return scan_record(trx, limit, (void *)&adapter, scan_record_reader_adapter);
}

RC Table::scan_record(Trx *trx, int limit, void *context, RC (*record_reader)(Record *, void *))
{
  if (nullptr == record_reader) {
    return RC::INVALID_ARGUMENT;
  }

  if (0 == limit) {
    return RC::SUCCESS;
  }

  if (limit < 0) {
    limit = INT_MAX;
  }

  RC rc = RC::SUCCESS;
  RecordFileScanner scanner;
  rc = scanner.open_scan(*data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  int record_count = 0;
  Record record;
  while (scanner.has_next()) {
    rc = scanner.next(record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch next record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    if (trx == nullptr || trx->is_visible(this, &record)) {
      rc = record_reader(&record, context);
      if (rc != RC::SUCCESS) {
        break;
      }
      record_count++;
    }
  }

  scanner.close_scan();
  return rc;
}

class IndexInserter {
public:
  explicit IndexInserter(Index *index) : index_(index)
  {}

  RC insert_index(const Record *record)
  {
    return index_->insert_entry(record->data(), &record->rid());
  }

private:
  Index *index_;
};

static RC insert_index_record_reader_adapter(Record *record, void *context)
{
  IndexInserter &inserter = *(IndexInserter *)context;
  return inserter.insert_index(record);
}

RC Table::create_index(Trx *trx, const char *index_name, const std::vector<std::string> &attribute_names, int is_unique)
{
  if (common::is_blank(index_name)) {
    LOG_INFO("Invalid input arguments, table name is %s, index_name is blank", name().c_str());
    return RC::INVALID_ARGUMENT;
  }

  for (const auto &attribute_name : attribute_names) {
    if (common::is_blank(attribute_name.c_str())) {
      LOG_INFO("Invalid input arguments, table name is %s, attribute_name is blank", name().c_str());
      return RC::INVALID_ARGUMENT;
    }
  }

  if (table_meta_.index(index_name) != nullptr || table_meta_.find_index_by_fields(attribute_names)) {
    LOG_INFO("Invalid input arguments, table name is %s, index exist or attributes exist on index", name().c_str());
    return RC::SCHEMA_INDEX_EXIST;
  }

  std::vector<FieldMeta> field_metas{};
  for (const auto &attribute_name : attribute_names) {
    const FieldMeta *field_meta = table_meta_.field(attribute_name);
    if (!field_meta) {
      LOG_INFO("Invalid input arguments, there is no field of %s in table %s", attribute_name.c_str(), name().c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }
    field_metas.emplace_back(*field_meta);
  }

  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, attribute_names, is_unique);
  if (rc != RC::SUCCESS) {
    LOG_INFO("Failed to init IndexMeta in table %s", name().c_str());
    return rc;
  }

  // 创建索引相关数据
  auto *index = new BplusTreeIndex();
  std::string index_file = table_index_file(base_dir_.c_str(), name().c_str(), index_name);
  rc = index->create(index_file.c_str(), new_index_meta, field_metas);
  if (rc != RC::SUCCESS) {
    delete index;
    LOG_ERROR("Failed to create bplus tree index. file name=%s, rc=%d:%s", index_file.c_str(), rc, strrc(rc));
    return rc;
  }

  // 遍历当前的所有数据，插入这个索引
  IndexInserter index_inserter(index);
  rc = scan_record(trx, -1, &index_inserter, insert_index_record_reader_adapter);
  if (rc != RC::SUCCESS) {
    // rollback
    delete index;
    LOG_ERROR("Failed to insert index to all records. table=%s, rc=%d:%s", name().c_str(), rc, strrc(rc));
    return rc;
  }
  indexes_.push_back(index);

  TableMeta new_table_meta(table_meta_);
  rc = new_table_meta.add_index(new_index_meta);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to add index (%s) on table (%s). error=%d:%s", index_name, name().c_str(), rc, strrc(rc));
    return rc;
  }

  // 创建元数据临时文件
  std::string tmp_file = table_meta_file(base_dir_.c_str(), name().c_str()) + ".tmp";
  std::fstream fs;
  fs.open(tmp_file, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", tmp_file.c_str(), strerror(errno));
    return RC::IOERR;  // 创建索引中途出错，要做还原操作
  }
  if (new_table_meta.serialize(fs) < 0) {
    LOG_ERROR("Failed to dump new table meta to file: %s. sys err=%d:%s", tmp_file.c_str(), errno, strerror(errno));
    return RC::IOERR;
  }
  fs.close();

  // 覆盖原始元数据文件
  std::string meta_file = table_meta_file(base_dir_.c_str(), name().c_str());
  int ret = rename(tmp_file.c_str(), meta_file.c_str());
  if (ret != 0) {
    LOG_ERROR("Failed to rename tmp meta file (%s) to normal meta file (%s) while creating index (%s) on table (%s). "
              "system error=%d:%s",
        tmp_file.c_str(),
        meta_file.c_str(),
        index_name,
        name().c_str(),
        errno,
        strerror(errno));
    return RC::IOERR;
  }

  table_meta_.swap(new_table_meta);

  LOG_INFO("Successfully added a new index (%s) on the table (%s)", index_name, name().c_str());

  return rc;
}

RC Table::update_record(Trx *trx, Record *old_record, Record *new_record)
{
  assert(old_record->rid() == new_record->rid());

  RC rc;
  rc = delete_entry_of_indexes(old_record->data(), old_record->rid(), false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record (rid=%d.%d). rc=%d:%s",
        old_record->rid().page_num,
        old_record->rid().slot_num,
        rc,
        strrc(rc));
  }

  rc = check_unique_constraint(new_record->data());
  if (rc != RC::SUCCESS) {
    LOG_WARN("Failed to update a record due to violate unique constraint");
    // rollback deleted index
    rc = insert_entry_of_indexes(old_record->data(), old_record->rid());
    if (rc != RC::SUCCESS) {
      LOG_PANIC("Failed to insert indexes of record (rid=%d.%d). rc=%d:%s",
          old_record->rid().page_num,
          old_record->rid().slot_num,
          rc,
          strrc(rc));
    }
    return RC::CONSTRAINT_UNIQUE;
  }

  rc = insert_entry_of_indexes(new_record->data(), new_record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to insert indexes of record (rid=%d.%d). rc=%d:%s",
        new_record->rid().page_num,
        new_record->rid().slot_num,
        rc,
        strrc(rc));
  }

  rc = record_handler_->update_record(new_record);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to update record (rid=%d.%d). rc=%d:%s",
        new_record->rid().page_num, new_record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  if (trx != nullptr) {
    // TODO(vgalaxy): trx->update_record

    CLogRecord *clog_record = nullptr;
    rc = clog_manager_->clog_gen_record(CLogType::REDO_UPDATE, trx->get_current_id(), clog_record,
        name().c_str(), table_meta_.record_size(), new_record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a clog record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    rc = clog_manager_->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  return rc;
}

RC Table::delete_record(Trx *trx, Record *record)
{
  RC rc = RC::SUCCESS;

  rc = delete_entry_of_indexes(record->data(), record->rid(), false);  // 重复代码 refer to commit_delete
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record (rid=%d.%d). rc=%d:%s",
        record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  rc = record_handler_->delete_record(&record->rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete record (rid=%d.%d). rc=%d:%s",
        record->rid().page_num, record->rid().slot_num, rc, strrc(rc));
    return rc;
  }

  if (trx != nullptr) {
    rc = trx->delete_record(this, record);

    CLogRecord *clog_record = nullptr;
    rc = clog_manager_->clog_gen_record(CLogType::REDO_DELETE, trx->get_current_id(), clog_record,
        name().c_str(), 0, record);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to create a clog record. rc=%d:%s", rc, strrc(rc));
      return rc;
    }
    rc = clog_manager_->clog_append_record(clog_record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  return rc;
}

RC Table::recover_delete_record(Record *record)
{
  RC rc = RC::SUCCESS;
  rc = record_handler_->delete_record(&record->rid());
  return rc;
}

RC Table::recover_update_record(Record *record)
{
  return record_handler_->update_record(record);
}

RC Table::commit_delete(Trx *trx, const RID &rid)
{
  RC rc = RC::SUCCESS;
  Record record;
  rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = delete_entry_of_indexes(record.data(), record.rid(), false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to delete indexes of record(rid=%d.%d). rc=%d:%s",
        rid.page_num,
        rid.slot_num,
        rc,
        strrc(rc));  // TODO: panic?
  }

  rc = record_handler_->delete_record(&rid);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return rc;
}

RC Table::rollback_delete(Trx *trx, const RID &rid)
{
  RC rc = RC::SUCCESS;
  Record record;
  rc = record_handler_->get_record(&rid, &record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return trx->rollback_delete(this, record);  // update record in place
}

RC Table::check_unique_constraint(const char *record_data)
{
  RC rc = RC::SUCCESS;
  char *tmp = (char *)calloc(4, sizeof(char));
  memcpy(tmp, record_data, 4);
  common::Bitmap null_field_bitmap{tmp, 32};
  for (Index *index : indexes_) {
    rc = index->check_unique_constraint(record_data);
    if (rc != RC::SUCCESS) {
      int null_field_idx = null_field_bitmap.next_setted_bit(0);
      bool pass{};
      while (null_field_idx != -1) {
        const FieldMeta *field_meta = this->table_meta_.field(null_field_idx);
        if (index->find_field_meta_by_name(field_meta->name()) && field_meta->nullable()) {
          pass = true;
          break;
        }
        null_field_idx = null_field_bitmap.next_setted_bit(null_field_idx);
      }
      if (pass) {
        continue;
      }
      free(tmp);
      return rc;
    }
  }
  free(tmp);
  return RC::SUCCESS;
}

RC Table::insert_entry_of_indexes(const char *record, const RID &rid)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->insert_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      break;
    }
  }
  return rc;
}

RC Table::delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      if (rc != RC::RECORD_INVALID_KEY || !error_on_not_exists) {
        break;
      }
    }
  }
  return rc;
}

Index *Table::find_index(const std::string &index_name) const
{
  for (Index *index : indexes_) {
    if (index->index_meta().name() == index_name) {
      return index;
    }
  }
  return nullptr;
}

Index *Table::find_index_by_field(const std::string &field_name) const
{
  for (Index *index : indexes_) {
    // 只有多列索引的第一个字段出现在查询条件中，该索引才可能被使用
    // 目前只考虑单列索引
    if (index->index_meta().fields().size() == 1 && index->index_meta().fields().at(0) == field_name) {
      return index;
    }
  }
  return nullptr;
}

RC Table::sync()
{
//  RC rc = data_buffer_pool_->flush_all_pages();
//  if (rc != RC::SUCCESS) {
//    LOG_ERROR("Failed to flush table's data pages. table=%s, rc=%d:%s", name().c_str(), rc, strrc(rc));
//    return rc;
//  }
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->sync();
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to flush index's pages. table=%s, index=%s, rc=%d:%s",
          name().c_str(),
          index->index_meta().name().c_str(),
          rc,
          strrc(rc));
      return rc;
    }
  }
  LOG_INFO("Sync table over. table=%s", name().c_str());
  return rc;
}

RC Table::drop(const char *table_name)
{
  LOG_INFO("Begin to drop table %s", table_name);

  // TODO(vgalaxy): check
  this->data_buffer_pool_->flush_all_pages();  // ignore rc

  int res;
  BufferPoolManager &bpm = BufferPoolManager::instance();
  // before removing file, trying to close file by bpm

  // drop meta file
  std::string meta_file = table_meta_file(base_dir_.c_str(), table_name);
  LOG_INFO("Begin to drop meta file %s", meta_file.c_str());
  bpm.close_file(meta_file.c_str());  // ignore rc
  res = remove(meta_file.c_str());
  if (res != 0) {
    LOG_ERROR("Failed to drop meta file %s, err %s", meta_file.c_str(), strerror(errno));
  }

  // drop data file
  std::string data_file = table_data_file(base_dir_.c_str(), table_name);
  LOG_INFO("Begin to drop data file %s", data_file.c_str());
  // should not close data file, handled in `Table::~Table()`
  // bpm.close_file(data_file.c_str());  // ignore rc
  res = remove(data_file.c_str());
  if (res != 0) {
    LOG_ERROR("Failed to drop data file %s, err %s", data_file.c_str(), strerror(errno));
  }

  // drop index file
  for (Index *index : indexes_) {
    std::string index_file = table_index_file(base_dir_.c_str(), table_name, index->index_meta().name().c_str());
    LOG_INFO("Begin to drop index file %s", index_file.c_str());
    // should not close index file, handled in `BplusTreeIndex::~BplusTreeIndex()`
    // bpm.close_file(index_file.c_str());  // ignore rc
    res = remove(index_file.c_str());
    if (res != 0) {
      LOG_ERROR("Failed to drop index file %s, err %s", index_file.c_str(), strerror(errno));
    }
  }

  return RC::SUCCESS;
}

std::vector<Index *> Table::get_indexes() const
{
  return indexes_;
}
