#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/CreateStatement.h"

class Session;
class Table;

class CreateCommand : public Command {
public:
  explicit CreateCommand(const hsql::CreateStatement* stmt);
  ~CreateCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_create_table(const SQLStageEvent *sql_event);
  RC do_create_index(const SQLStageEvent *sql_event);

private:
  const hsql::CreateStatement* stmt_;
};