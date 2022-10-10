#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/DeleteStatement.h"

class Session;
class Table;

class DeleteCommand : public Command {
public:
  explicit DeleteCommand(const hsql::DeleteStatement *stmt);
  ~DeleteCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

  RC do_delete(const SQLStageEvent *sql_event);

private:
  const hsql::DeleteStatement *stmt_;
};