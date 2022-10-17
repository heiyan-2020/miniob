#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/DropStatement.h"

class Session;
class Table;

class DropCommand : public Command {
public:
  explicit DropCommand(const hsql::DropStatement *stmt);
  ~DropCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_drop_table(const SQLStageEvent *sql_event);

private:
  const hsql::DropStatement *stmt_;
};