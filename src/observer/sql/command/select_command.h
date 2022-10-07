#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "sql/table/tuple.h"

class Session;
class Table;

class SelectCommand : public Command {
public:
  explicit SelectCommand(const hsql::SelectStatement *stmt);
  ~SelectCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  static void tuple_to_string(std::ostream &os, const Tuple &tuple);

private:
  const hsql::SelectStatement *stmt_;
};