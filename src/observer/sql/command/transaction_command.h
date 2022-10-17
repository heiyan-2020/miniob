#pragma once

#include "command.h"
#include "sql/parser/hsql/sql/TransactionStatement.h"

class Session;
class Table;

class TransactionCommand : public Command {
public:
  explicit TransactionCommand(const hsql::TransactionStatement *stmt);
  ~TransactionCommand() override = default;

  RC execute(const SQLStageEvent *sql_event) override;

private:
  RC do_begin(const SQLStageEvent *sql_event);
  RC do_commit(const SQLStageEvent *sql_event);
  RC do_rollback(const SQLStageEvent *sql_event);

private:
  const hsql::TransactionStatement *stmt_;
};