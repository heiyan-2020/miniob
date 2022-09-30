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
// Created by Meiyi & wangyunlai.wyl on 2021/5/19.
//

#include "storage/index/bplus_tree_index.h"
#include "common/log/log.h"

BplusTreeIndex::~BplusTreeIndex() noexcept
{
  close();
}

RC BplusTreeIndex::create(const char *file_name, IndexMeta index_meta, std::vector<FieldMeta> field_metas)
{
  if (inited_) {
    LOG_WARN("Failed to create index due to the index has been created before. file_name:%s, index:%s, fields:%s",
        file_name,
        index_meta.name().c_str(),
        index_meta.fields_str().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_metas);

  std::vector<AttrType> attr_types{};
  std::vector<int> attr_lengths{};
  for (const auto &field_meta : field_metas) {
    attr_types.emplace_back(field_meta.type());
    attr_lengths.emplace_back(field_meta.len());
  }

  RC rc = index_handler_.create(file_name, attr_types, attr_lengths);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to create index_handler, file_name:%s, index:%s, fields:%s, rc:%s",
        file_name,
        index_meta.name().c_str(),
        index_meta.fields_str().c_str(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully create index, file_name:%s, index:%s, fields:%s",
      file_name,
      index_meta.name().c_str(),
      index_meta.fields_str().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::open(const char *file_name, IndexMeta index_meta, std::vector<FieldMeta> field_metas)
{
  if (inited_) {
    LOG_WARN("Failed to open index due to the index has been inited before. file_name:%s, index:%s, fields:%s",
        file_name,
        index_meta.name().c_str(),
        index_meta.fields_str().c_str());
    return RC::RECORD_OPENNED;
  }

  Index::init(index_meta, field_metas);

  RC rc = index_handler_.open(file_name);
  if (RC::SUCCESS != rc) {
    LOG_WARN("Failed to open index_handler, file_name:%s, index:%s, fields:%s, rc:%s",
        file_name,
        index_meta.name().c_str(),
        index_meta.fields_str().c_str(),
        strrc(rc));
    return rc;
  }

  inited_ = true;
  LOG_INFO("Successfully open index, file_name:%s, index:%s, fields:%s",
      file_name,
      index_meta.name().c_str(),
      index_meta.fields_str().c_str());
  return RC::SUCCESS;
}

RC BplusTreeIndex::close()
{
  if (inited_) {
    LOG_INFO("Begin to close index, index:%s, fields:%s",
        index_meta_.name().c_str(),
        index_meta_.fields_str().c_str());
    index_handler_.close();
    inited_ = false;
  }
  LOG_INFO("Successfully close index.");
  return RC::SUCCESS;
}

char *BplusTreeIndex::make_user_key(const char *record)
{
  char *key = (char *)this->index_handler_.alloc();
  if (key == nullptr) {
    LOG_WARN("Failed to alloc memory for key.");
    return nullptr;
  }
  int attr_length{};
  for (const auto &field_meta : field_metas_) {
    memcpy(key + attr_length, record + field_meta.offset(), field_meta.len());
    attr_length += field_meta.len();
  }
  return key;
}

void BplusTreeIndex::free_user_key(char *user_key)
{
  this->index_handler_.free(user_key);
}

int BplusTreeIndex::user_key_len()
{
  int attr_length{};
  for (const auto &field_meta : field_metas_) {
    attr_length += field_meta.len();
  }
  return attr_length;
}

RC BplusTreeIndex::check_unique_constraint(const char *record)
{
  RC rc = RC::SUCCESS;
  std::list<RID> rids{};
  char *user_key = make_user_key(record);
  index_handler_.get_entry(user_key, user_key_len() + static_cast<int>(sizeof(RID)), rids);
  if (!rids.empty() && index_meta_.is_unique()) {
    rc = RC::CONSTRAINT_UNIQUE;
  }
  free_user_key(user_key);
  return rc;
}

RC BplusTreeIndex::insert_entry(const char *record, const RID *rid)
{
  char *user_key = make_user_key(record);
  RC rc = index_handler_.insert_entry(user_key, rid);
  free_user_key(user_key);
  return rc;
}

RC BplusTreeIndex::delete_entry(const char *record, const RID *rid)
{
  char *user_key = make_user_key(record);
  RC rc = index_handler_.delete_entry(user_key, rid);
  free_user_key(user_key);
  return rc;
}

IndexScanner *BplusTreeIndex::create_scanner(
    const char *left_key, int left_len, bool left_inclusive, const char *right_key, int right_len, bool right_inclusive)
{
  auto *index_scanner = new BplusTreeIndexScanner(index_handler_);
  RC rc = index_scanner->open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open index scanner. rc=%d:%s", rc, strrc(rc));
    delete index_scanner;
    return nullptr;
  }
  return index_scanner;
}

RC BplusTreeIndex::sync()
{
  return index_handler_.sync();
}

////////////////////////////////////////////////////////////////////////////////
BplusTreeIndexScanner::BplusTreeIndexScanner(BplusTreeHandler &tree_handler) : tree_scanner_(tree_handler)
{}

BplusTreeIndexScanner::~BplusTreeIndexScanner() noexcept
{
  tree_scanner_.close();
}

RC BplusTreeIndexScanner::open(
    const char *left_key, int left_len, bool left_inclusive, const char *right_key, int right_len, bool right_inclusive)
{
  return tree_scanner_.open(left_key, left_len, left_inclusive, right_key, right_len, right_inclusive);
}

RC BplusTreeIndexScanner::next_entry(RID *rid)
{
  return tree_scanner_.next_entry(rid);
}

RC BplusTreeIndexScanner::destroy()
{
  delete this;
  return RC::SUCCESS;
}
