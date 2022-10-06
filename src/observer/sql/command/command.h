#pragma once

#include "util/macros.h"
#include "sql/parser/hsql/SQLParserResult.h"
#include "rc.h"
#include "event/session_event.h"
#include "event/sql_event.h"

class SQLStageEvent;

class Command {
public:
  virtual ~Command() = default;
  explicit Command(hsql::StatementType type);

  virtual RC execute(const SQLStageEvent *sql_event) = 0;

private:
  hsql::StatementType type_;
};