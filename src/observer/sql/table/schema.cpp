#include "schema.h"
#include "storage/common/table.h"

Schema::Schema(const std::vector<Column> &columns)
{
  set_columns(columns);
}

Schema::Schema(const Table *table, const std::vector<FieldMeta> *table_schema)
{
  std::vector<Column> columns;
  for (const auto &field : *table_schema) {
    ColumnName col_name(table->name(), field.name());
    columns.emplace_back(col_name, field.type(), field.len(), field.visible(), field.nullable());
  }

  set_columns(columns);
}

Schema::Schema(SchemaRef left, SchemaRef right)
{
  std::vector<Column> cols;
  for (Column col : left->columns_) {
    cols.push_back(col);
  }
  for (Column col : right->columns_) {
    cols.push_back(col);
  }
  set_columns(cols);
}

Schema::Schema(std::vector<SchemaRef> schemas)
{
  std::vector<Column> cols;
  for (auto &schema : schemas) {
    for (Column &col : schema->columns_) {
      cols.push_back(col);
    }
  }
  set_columns(cols);
}

void Schema::set_columns(const std::vector<Column> &columns)
{
  // start at offset 4, for null field bitmap
  size_t curr_offset = 4;
  for (auto column : columns) {
    // set column offset
    column.column_offset_ = curr_offset;
    curr_offset += column.fixed_length_;

    // add column
    this->columns_.push_back(column);
  }

  length_ = curr_offset;
}



std::vector<Column> Schema::find_columns(std::string table_name, std::string column_name)
{
  std::vector<Column> found_columns;
  
  if (column_name.empty()) {
    if (table_name.empty()) {
      // Wildcard with no table name: *
      found_columns.insert(found_columns.end(), columns_.begin(), columns_.end());
    } else {
      // Wildcard with a table name: t.*
      for (Column col : columns_) {
        if (col.get_name().table_name_ == table_name) {
          found_columns.push_back(col);
        }
      }
    }
  } else {
    if (table_name.empty()) {
      // Column name with no table name:  col
      for (Column col : columns_) {
        if (col.get_name().column_name_ == column_name) {
          found_columns.push_back(col);
        }
      }
    } else {
      // Column name with table name:  t.col
      for (Column col : columns_) {
        if (col.get_name().column_name_ == column_name && col.get_name().table_name_ == table_name) {
          found_columns.push_back(col);
        }
      }
    }
  }

  return found_columns;
}

std::unordered_set<std::string> Schema::get_involved_tables() const
{
  std::unordered_set<std::string> names;
  for (const auto &col: columns_) {
    if (names.find(col.get_name().table_name_) == names.end()) {
      names.insert(col.get_name().table_name_);
    }
  }
  return names;
}

RC Schema::set_table_name(std::string table_name)
{
  std::unordered_set<std::string> col_names;
  for (const auto &col : columns_) {
    std::string name = col.get_name().column_name();
    if (col_names.find(name) != col_names.end()) {
      // duplicated column name, which indicates that table_name can't be overrided.
      return RC::DUPLICATE;
    }
    col_names.insert(name);
  }

  for (auto &col : columns_) {
    col.name_.table_name_ = table_name;
  }

  return RC::SUCCESS;
}

