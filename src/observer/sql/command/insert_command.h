#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/InsertStatement.h"

class Session;
class Table;

class InsertCommand : public Command {
public:
  explicit InsertCommand(const hsql::InsertStatement *stmt);
  ~InsertCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  const hsql::InsertStatement *stmt_;
};