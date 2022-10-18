#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/UpdateStatement.h"
#include "storage/common/field_meta.h"
#include "type/value.h"
#include "select_command.h"

class Session;
class Table;

class UpdateCommand : public Command {
public:
  explicit UpdateCommand(const hsql::UpdateStatement *stmt);
  ~UpdateCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_update(const SQLStageEvent *sql_event);
  RC data_2_value(const hsql::Expr *expr, Value &value, const FieldMeta &fieldMeta);
  RC check_schema(const FieldMeta& field_meta, const Value& value);
  RC get_sub_query(SelectCommand sel_command, const SQLStageEvent *sql_event, std::vector<Value>& new_values);
  Value type_cast(Value to_be_converted, const FieldMeta& field_meta);

  const hsql::UpdateStatement *stmt_;
};