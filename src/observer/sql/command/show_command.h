#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/ShowStatement.h"

class Session;
class Table;

class ShowCommand : public Command {
public:
  explicit ShowCommand(const hsql::ShowStatement *stmt);
  ~ShowCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_show_tables(const SQLStageEvent *sql_event);
  RC do_desc_table(const SQLStageEvent *sql_event);

private:
  const hsql::ShowStatement *stmt_;
};