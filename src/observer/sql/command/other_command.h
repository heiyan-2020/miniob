#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/OtherStatement.h"

class Session;
class Table;

class OtherCommand : public Command {
public:
  explicit OtherCommand(const hsql::OtherStatement *stmt);
  ~OtherCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_sync(const SQLStageEvent *sql_event);
  RC do_help(const SQLStageEvent *sql_event);

private:
  const hsql::OtherStatement *stmt_;
};