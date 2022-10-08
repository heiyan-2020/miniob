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
// Created by Longda on 2021/4/13.
//

#include <cstring>
#include <string>

#include "resolve_stage.h"

#include "common/conf/ini.h"
#include "common/io/io.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "session/session.h"
#include "sql/command/command.h"
#include "sql/command/create_command.h"
#include "sql/command/show_command.h"
#include "sql/command/drop_command.h"
#include "sql/command/select_command.h"
#include "sql/command/insert_command.h"
#include "sql/command/update_command.h"
#include "sql/command/delete_command.h"
#include "planner.h"
#include "sql/command/other_command.h"

using namespace common;

//! Constructor
ResolveStage::ResolveStage(const char *tag) : Stage(tag)
{}

//! Parse properties, instantiate a stage object
Stage *ResolveStage::make_stage(const std::string &tag)
{
  auto *stage = new (std::nothrow) ResolveStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ResolveStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ResolveStage::set_properties()
{
  return true;
}

//! Initialize stage params and validate outputs
bool ResolveStage::initialize()
{
  LOG_TRACE("Enter");
  auto stgp = next_stage_list_.begin();
  query_cache_stage_ = *(stgp++);
  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ResolveStage::cleanup()
{
  LOG_TRACE("Enter");
  LOG_TRACE("Exit");
}

void ResolveStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter");
  auto *sql_event = dynamic_cast<SQLStageEvent *>(event);
  if (nullptr == sql_event) {
    LOG_WARN("failed to get sql stage event");
    return;
  }

  SessionEvent *session_event = sql_event->session_event();

  Db *db = session_event->session()->get_current_db();
  if (nullptr == db) {
    LOG_ERROR("cannot current db");
    return;
  }

  // command
  const auto &result = sql_event->result();
  auto stmt = result->getStatement(0);
  switch (stmt->type()) {  // TODO(vgalaxy): only consider the first stmt
    case hsql::kStmtCreate:
      sql_event->set_command(std::make_unique<CreateCommand>(dynamic_cast<const hsql::CreateStatement *>(stmt)));
      break;
    case hsql::kStmtShow:
      sql_event->set_command(std::make_unique<ShowCommand>(dynamic_cast<const hsql::ShowStatement *>(stmt)));
      break;
    case hsql::kStmtDrop:
      sql_event->set_command(std::make_unique<DropCommand>(dynamic_cast<const hsql::DropStatement *>(stmt)));
      break;
    case hsql::kStmtSelect:
      sql_event->set_command(std::make_unique<SelectCommand>(dynamic_cast<const hsql::SelectStatement *>(stmt)));
      break;
    case hsql::kStmtInsert:
      sql_event->set_command(std::make_unique<InsertCommand>(dynamic_cast<const hsql::InsertStatement *>(stmt)));
      break;
    case hsql::kStmtUpdate:
      sql_event->set_command(std::make_unique<UpdateCommand>(dynamic_cast<const hsql::UpdateStatement *>(stmt)));
      break;
    case hsql::kStmtDelete:
      sql_event->set_command(std::make_unique<DeleteCommand>(dynamic_cast<const hsql::DeleteStatement *>(stmt)));
      break;
    case hsql::kStmtOther:
      sql_event->set_command(std::make_unique<OtherCommand>(dynamic_cast<const hsql::OtherStatement *>(stmt)));
      break;
    default:
      session_event->set_response("Unsupported");
  }

  query_cache_stage_->handle_event(sql_event);
  LOG_TRACE("Exit");
}

void ResolveStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter");
  LOG_TRACE("Exit");
}
