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

#include <algorithm>
#include <common/lang/string.h>

#include "storage/common/table_meta.h"
#include "json/json.h"
#include "common/log/log.h"
#include "storage/trx/trx.h"
#include "sql/table/schema.h"

static const Json::StaticString FIELD_TABLE_NAME("table_name");
static const Json::StaticString FIELD_FIELDS("fields");
static const Json::StaticString FIELD_INDEXES("indexes");

std::vector<FieldMeta> TableMeta::sys_fields_;

TableMeta::TableMeta(const TableMeta &other)
    : name_(other.name_), fields_(other.fields_), indexes_(other.indexes_), record_size_(other.record_size_)
{}

void TableMeta::swap(TableMeta &other) noexcept
{
  name_.swap(other.name_);
  fields_.swap(other.fields_);
  indexes_.swap(other.indexes_);
  std::swap(record_size_, other.record_size_);
}

RC TableMeta::init_sys_fields()
{
  sys_fields_.reserve(1);
  FieldMeta field_meta;
  RC rc = field_meta.init(Trx::trx_field_name(), Trx::trx_field_type(), 0, Trx::trx_field_len(), false);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to init trx field. rc = %d:%s", rc, strrc(rc));
    return rc;
  }

  sys_fields_.push_back(field_meta);
  return rc;
}

RC TableMeta::init(const char *name, const Schema& schema)
{
  if (common::is_blank(name)) {
    return RC::INVALID_ARGUMENT;
  }

  RC rc;
  if (sys_fields_.empty()) {
    rc = init_sys_fields();
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to init_sys_fields, name:%s ", name);
      return rc;
    }
  }

  const std::vector<Column> &cols = schema.get_columns();

  fields_.resize(cols.size() + sys_fields_.size());
  for (size_t i = 0; i < sys_fields_.size(); i++) {
    fields_[i] = sys_fields_[i];
  }

  // 当前实现下，所有类型都是 4 字节对齐的，所以不再考虑字节对齐问题
  int field_offset = sys_fields_.back().offset() + sys_fields_.back().len();

  for (int i = 0; i < cols.size(); i++) {
    const Column &col = cols[i];
    rc = fields_[i + sys_fields_.size()].init(
        col.name_.column_name_.c_str(),
        col.column_type_,
        field_offset,
        col.fixed_length_,
        true);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to init field meta. table name=%s, field name: %s", name, col.name_.column_name_.c_str());
      return rc;
    }

    field_offset += col.fixed_length_;
  }

  record_size_ = field_offset;

  name_ = name;
  LOG_INFO("Successfully initialized table meta. table name=%s", name);
  return RC::SUCCESS;
}

RC TableMeta::add_index(const IndexMeta &index)
{
  indexes_.push_back(index);
  return RC::SUCCESS;
}

std::string TableMeta::name() const
{
  return name_;
}

const FieldMeta *TableMeta::trx_field() const
{
  return &fields_[0];
}

const FieldMeta *TableMeta::field(int index) const
{
  return &fields_[index];
}
const FieldMeta *TableMeta::field(const std::string &field_name) const
{
  for (const FieldMeta &field : fields_) {
    if (field.name() == name_) {
      return &field;
    }
  }
  return nullptr;
}

const FieldMeta *TableMeta::find_field_by_offset(int offset) const
{
  for (const FieldMeta &field : fields_) {
    if (field.offset() == offset) {
      return &field;
    }
  }
  return nullptr;
}
int TableMeta::field_num() const
{
  return fields_.size();
}

int TableMeta::sys_field_num() const
{
  return sys_fields_.size();
}

const IndexMeta *TableMeta::index(const std::string &index_name) const
{
  for (const IndexMeta &index : indexes_) {
    if (index.name() == index_name) {
      return &index;
    }
  }
  return nullptr;
}

const IndexMeta *TableMeta::find_index_by_field(const std::string &field_name) const
{
  for (const IndexMeta &index : indexes_) {
    // 只有多列索引的第一个字段出现在查询条件中，该索引才可能被使用
    // 目前只考虑单列索引
    if (index.fields().size() == 1 && index.fields().at(0) == field_name) {
      return &index;
    }
  }
  return nullptr;
}

const IndexMeta *TableMeta::find_index_by_fields(const std::vector<std::string> &field_names) const
{
  for (const IndexMeta &index : indexes_) {
    if (index.fields() == field_names) {
      return &index;
    }
  }
  return nullptr;
}

const IndexMeta *TableMeta::index(int i) const
{
  return &indexes_[i];
}

int TableMeta::index_num() const
{
  return indexes_.size();
}

int TableMeta::record_size() const
{
  return record_size_;
}

int TableMeta::serialize(std::ostream &ss) const
{

  Json::Value table_value;
  table_value[FIELD_TABLE_NAME] = name_;

  Json::Value fields_value;
  for (const FieldMeta &field : fields_) {
    Json::Value field_value;
    field.to_json(field_value);
    fields_value.append(std::move(field_value));
  }

  table_value[FIELD_FIELDS] = std::move(fields_value);

  Json::Value indexes_value;
  for (const auto &index : indexes_) {
    Json::Value index_value;
    index.to_json(index_value);
    indexes_value.append(std::move(index_value));
  }
  table_value[FIELD_INDEXES] = std::move(indexes_value);

  Json::StreamWriterBuilder builder;
  Json::StreamWriter *writer = builder.newStreamWriter();

  std::streampos old_pos = ss.tellp();
  writer->write(table_value, &ss);
  int ret = (int)(ss.tellp() - old_pos);

  delete writer;
  return ret;
}

int TableMeta::deserialize(std::istream &is)
{
  if (sys_fields_.empty()) {
    init_sys_fields();
  }

  Json::Value table_value;
  Json::CharReaderBuilder builder;
  std::string errors;

  std::streampos old_pos = is.tellg();
  if (!Json::parseFromStream(builder, is, &table_value, &errors)) {
    LOG_ERROR("Failed to deserialize table meta. error=%s", errors.c_str());
    return -1;
  }

  const Json::Value &table_name_value = table_value[FIELD_TABLE_NAME];
  if (!table_name_value.isString()) {
    LOG_ERROR("Invalid table name. json value=%s", table_name_value.toStyledString().c_str());
    return -1;
  }

  std::string table_name = table_name_value.asString();

  const Json::Value &fields_value = table_value[FIELD_FIELDS];
  if (!fields_value.isArray() || fields_value.empty()) {
    LOG_ERROR("Invalid table meta. fields is not array, json value=%s", fields_value.toStyledString().c_str());
    return -1;
  }

  RC rc = RC::SUCCESS;
  int field_num = fields_value.size();
  std::vector<FieldMeta> fields(field_num);
  for (int i = 0; i < field_num; i++) {
    FieldMeta &field = fields[i];

    const Json::Value &field_value = fields_value[i];
    rc = FieldMeta::from_json(field_value, field);
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to deserialize table meta. table name=%s", table_name.c_str());
      return -1;
    }
  }

  std::sort(
      fields.begin(), fields.end(), [](const FieldMeta &f1, const FieldMeta &f2) { return f1.offset() < f2.offset(); });

  name_.swap(table_name);
  fields_.swap(fields);
  record_size_ = fields_.back().offset() + fields_.back().len() - fields_.begin()->offset();

  const Json::Value &indexes_value = table_value[FIELD_INDEXES];
  if (!indexes_value.empty()) {
    if (!indexes_value.isArray()) {
      LOG_ERROR("Invalid table meta. indexes is not array, json value=%s", fields_value.toStyledString().c_str());
      return -1;
    }
    const int index_num = indexes_value.size();
    std::vector<IndexMeta> indexes(index_num);
    for (int i = 0; i < index_num; i++) {
      IndexMeta &index = indexes[i];

      const Json::Value &index_value = indexes_value[i];
      rc = IndexMeta::from_json(*this, index_value, index);
      if (rc != RC::SUCCESS) {
        LOG_ERROR("Failed to deserialize table meta. table name=%s", table_name.c_str());
        return -1;
      }
    }
    indexes_.swap(indexes);
  }

  return (int)(is.tellg() - old_pos);
}

int TableMeta::get_serial_size() const
{
  return -1;
}

void TableMeta::to_string(std::string &output) const
{}

void TableMeta::desc(std::ostream &os) const
{
  os << name_ << '(' << std::endl;
  for (const auto &field : fields_) {
    os << '\t';
    field.desc(os);
    os << std::endl;
  }

  for (const auto &index : indexes_) {
    os << '\t';
    index.desc(os);
    os << std::endl;
  }
  os << ')' << std::endl;
}
