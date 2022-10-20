#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/SelectStatement.h"
#include "sql/table/tuple.h"
#include "sql/table/schema.h"
#include "sql/parser/parse_stage.h"

class Session;
class Table;

class SelectCommand : public Command {
public:
  explicit SelectCommand(const hsql::SelectStatement *stmt);
  ~SelectCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

  RC get_res_values(const SQLStageEvent *sql_event, std::vector<Value> &new_values);

private:
  void tuple_to_value(const Tuple &tuple, SchemaRef schema, std::vector<Value>& new_values);
  void tuple_to_string(std::ostream &os, const Tuple &tuple, SchemaRef schema);
  void print_header(std::ostream &os, SchemaRef schema, const std::vector<HeaderAlias> &headers, bool has_multi_table);

  // extracting involved table name of header. if header doesn't specify table name like *, just return empty.
  std::string get_table_name_from_header(HeaderAlias);

private:
  const hsql::SelectStatement *stmt_;
};