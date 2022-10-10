#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/UpdateStatement.h"

class Session;
class Table;

class UpdateCommand : public Command {
public:
  explicit UpdateCommand(const hsql::UpdateStatement *stmt);
  ~UpdateCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

  RC do_update(const SQLStageEvent *sql_event);

private:
  const hsql::UpdateStatement *stmt_;
};