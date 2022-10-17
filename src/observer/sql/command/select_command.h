#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "sql/table/tuple.h"
#include "sql/table/schema.h"

class Session;
class Table;

class SelectCommand : public Command {
public:
  explicit SelectCommand(const hsql::SelectStatement *stmt);
  ~SelectCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  void tuple_to_string(std::ostream &os, const Tuple &tuple, SchemaRef schema);
  void print_header(std::ostream &os, SchemaRef schema, const std::vector<std::string> &headers, bool has_multi_table);

private:
  const hsql::SelectStatement *stmt_;
};