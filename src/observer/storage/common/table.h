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
// Created by Meiyi & Wangyunlai on 2021/5/12.
//

#ifndef __OBSERVER_STORAGE_COMMON_TABLE_H__
#define __OBSERVER_STORAGE_COMMON_TABLE_H__

#include "storage/common/table_meta.h"

struct RID;
class Record;
class DiskBufferPool;
class RecordFileHandler;
class RecordFileScanner;
class Index;
class IndexScanner;
class Trx;

class Table {
public:
  Table() = default;
  ~Table();

  /**
   * 创建一个表
   * @param path 元数据保存的文件 (完整路径)
   * @param name 表名
   * @param base_dir 表数据存放的路径
   * @param attribute_count 字段个数
   * @param attributes 字段
   */
  RC create(const char *path, const char *name, const char *base_dir, int attribute_count, const AttrInfo attributes[]);

  /**
   * 打开一个表
   * @param meta_file 保存表元数据的文件完整路径
   * @param base_dir 表所在的文件夹，表记录数据文件、索引数据文件存放位置
   */
  RC open(const char *meta_file, const char *base_dir);

  RC drop(const char *table_name);

  RC insert_record(Trx *trx, int value_num, const Value *values);
  RC update_record(Trx *trx, Record *old_record, Record *new_record);
  RC delete_record(Trx *trx, Record *record);

  RC scan_record(Trx *trx, int limit, void *context, void (*record_reader)(const char *, void *));

  RC create_index(Trx *trx, const char *index_name, const std::vector<std::string> &attribute_names, int is_unique);

  RC get_record_scanner(RecordFileScanner &scanner);

  RecordFileHandler *record_handler() const
  {
    return record_handler_;
  }

public:
  const char *name() const;

  const TableMeta &table_meta() const;

  RC sync();

public:
  RC commit_insert(Trx *trx, const RID &rid);
  RC commit_delete(Trx *trx, const RID &rid);
  RC rollback_insert(Trx *trx, const RID &rid);
  RC rollback_delete(Trx *trx, const RID &rid);

private:
  RC scan_record(Trx *trx, int limit, void *context, RC (*record_reader)(Record *, void *));

  RC insert_record(Trx *trx, Record *record);

  RC check_unique_constraint(const char *record_data);

private:
  RC insert_entry_of_indexes(const char *record, const RID &rid);
  RC delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists);

private:
  RC init_record_handler(const char *base_dir);
  RC make_record(int value_num, const Value *values, char *&record_out);

public:
  Index *find_index(const std::string &index_name) const;
  Index *find_index_by_field(const std::string &field_name) const;

private:
  std::string base_dir_;
  TableMeta table_meta_;
  DiskBufferPool *data_buffer_pool_ = nullptr;   // 数据文件关联的 buffer pool
  RecordFileHandler *record_handler_ = nullptr;  // 记录操作
  std::vector<Index *> indexes_;
};

#endif  // __OBSERVER_STORAGE_COMMON_TABLE_H__
