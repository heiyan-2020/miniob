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
// Created by Meiyi & Wangyunlai.wyl on 2021/5/18.
//

#include "storage/common/index_meta.h"

#include <utility>
#include "storage/common/field_meta.h"
#include "storage/common/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "rc.h"
#include "json/json.h"

const static Json::StaticString FIELD_INDEX_NAME("index_name");
const static Json::StaticString FIELD_FIELDS_NAME("fields_name");
const static Json::StaticString FIELD_IS_UNIQUE("is_unique");

RC IndexMeta::init(const char *name, std::vector<std::string> fields, bool is_unique)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  fields_name_ = fields;
  is_unique_ = is_unique;
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_INDEX_NAME] = name_;
  Json::Value fields_value;
  for (const auto& field : fields_name_) {
    fields_value.append(field);
  }
  json_value[FIELD_FIELDS_NAME] = fields_value;
  json_value[FIELD_IS_UNIQUE] = is_unique_;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[FIELD_INDEX_NAME];
  const Json::Value &fields_value = json_value[FIELD_FIELDS_NAME];
  const Json::Value &is_unique_value = json_value[FIELD_IS_UNIQUE];

  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  if (!fields_value.isArray() || fields_value.empty()) {
    LOG_ERROR("Fields name of index [%s] is not an array. json value=%s",
        name_value.asCString(),
        fields_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  std::vector<std::string> fields{};
  int field_num = static_cast<int>(fields_value.size());
  for (int i = 0; i < field_num; i++) {
    const Json::Value &field_value = fields_value[i];
    if (!field_value.isString()) {
      LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
          name_value.asCString(),
          field_value.toStyledString().c_str());
      return RC::GENERIC_ERROR;
    }
    fields.emplace_back(field_value.asCString());
  }

  if (!is_unique_value.isBool()) {
    LOG_ERROR("Field name of index [%s] is not a boolean. json value=%s",
        name_value.asCString(),
        is_unique_value.toStyledString().c_str());
    return RC::GENERIC_ERROR;
  }

  return index.init(name_value.asCString(), fields, is_unique_value.asBool());
}

const std::string &IndexMeta::name() const
{
  return name_;
}

const std::vector<std::string> &IndexMeta::fields() const
{
  return fields_name_;
}

std::string IndexMeta::fields_str() const
{
  std::stringstream ss;
  ss << "{";
  for (std::vector<std::__cxx11::basic_string<char>>::size_type i = 0; i < fields_name_.size(); ++i) {
    ss << fields_name_[i];
    if (i != fields_name_.size() - 1) {
      ss << ",";
    }
  }
  ss << "}";
  return ss.str();
}

int IndexMeta::is_unique() const
{
  return is_unique_;
}

void IndexMeta::desc(std::ostream &os) const
{
  os << "index name=" << name() << ", fields=" << fields_str();
}