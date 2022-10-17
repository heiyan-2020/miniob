#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/UpdateStatement.h"
#include "storage/common/field_meta.h"
#include "type/value.h"

class Session;
class Table;

class UpdateCommand : public Command {
public:
  explicit UpdateCommand(const hsql::UpdateStatement *stmt);
  ~UpdateCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

  RC do_update(const SQLStageEvent *sql_event);

  RC data_2_value(const hsql::Expr *expr, Value &value, const FieldMeta &fieldMeta);

  RC check_schema(const FieldMeta& field_meta, const hsql::UpdateClause * updateClause);
private:
  const hsql::UpdateStatement *stmt_;
};