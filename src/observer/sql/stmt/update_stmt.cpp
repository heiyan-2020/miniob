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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "filter_stmt.h"

UpdateStmt::UpdateStmt(Table *table, const Value *value, int value_offset)
    : table_(table), value_(value), value_offset_(value_offset)
{}

RC UpdateStmt::create(Db *db, const Updates &update_sql, Stmt *&stmt)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // table
  const char *table_name = update_sql.relation_name;
  if (nullptr == table_name) {
    LOG_WARN("invalid argument. relation name is null.");
    return RC::INVALID_ARGUMENT;
  }

  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(table_name, table));

  // field
  const char *field_name = update_sql.attribute_name;
  const FieldMeta *field_meta = table->table_meta().field(field_name);
  if (nullptr == field_meta) {
    LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
    return RC::SCHEMA_FIELD_MISSING;
  }

  const AttrType field_type = field_meta->type();
  const AttrType value_type = update_sql.value.type;
  if (field_type != value_type) {
    LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
        table_name,
        field_meta->name(),
        field_type,
        value_type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, &table_map, update_sql.conditions, update_sql.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  auto *update_stmt = new UpdateStmt(table, &update_sql.value, field_meta->offset());
  update_stmt->filter_stmt_ = filter_stmt;
  stmt = update_stmt;
  return RC::SUCCESS;
}
