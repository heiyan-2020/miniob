#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/ShowStatement.h"
#include "storage/index/index.h"

class Session;
class Table;

class ShowCommand : public Command {
public:
  explicit ShowCommand(const hsql::ShowStatement *stmt);
  ~ShowCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  void index_info_prefix(const char* table_name, std::ostream &os, const IndexMeta& index_meta);
  void index_2_string(const char* table_name, std::ostream &os, const Index *index);
  RC do_show_tables(const SQLStageEvent *sql_event);
  RC do_desc_table(const SQLStageEvent *sql_event);
  RC do_show_index(const SQLStageEvent *sql_event);

private:
  const hsql::ShowStatement *stmt_;
};