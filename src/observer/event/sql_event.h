/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Longda on 2021/4/14.
//

#ifndef __OBSERVER_SQL_EVENT_SQLEVENT_H__
#define __OBSERVER_SQL_EVENT_SQLEVENT_H__

#include <string>
#include "common/seda/stage_event.h"
#include "sql/parser/hsql/SQLParserResult.h"
#include "sql/command/command.h"

class SessionEvent;
class Stmt;
class Command;
struct Query;

class SQLStageEvent : public common::StageEvent {
public:
  SQLStageEvent(SessionEvent *event, std::string sql);
  ~SQLStageEvent() noexcept override;

  SessionEvent *session_event() const
  {
    return session_event_;
  }

  const std::string &sql() const
  {
    return sql_;
  }
  const std::unique_ptr<hsql::SQLParserResult>& result() const
  {
    return result_;
  }
  const std::unique_ptr<Command>& command() const
  {
    return command_;
  }

  void set_sql(const char *sql)
  {
    sql_ = sql;
  }
  void set_result(std::unique_ptr<hsql::SQLParserResult> result)
  {
    result_ = std::move(result);
  }
  void set_command(std::unique_ptr<Command> command)
  {
    command_ = std::move(command);
  }

private:
  SessionEvent *session_event_ = nullptr;
  std::string sql_{};
  std::unique_ptr<hsql::SQLParserResult> result_{};
  std::unique_ptr<Command> command_{};
};

#endif  //__OBSERVER_SQL_EVENT_SQLEVENT_H__
