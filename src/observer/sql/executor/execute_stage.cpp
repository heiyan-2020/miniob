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
// Created by Meiyi & Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/lang/defer.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/common/table.h"
#include "storage/common/field.h"
#include "storage/index/index.h"
#include "storage/default/default_handler.h"
#include "storage/trx/trx.h"
#include "storage/index/bplus_tree.h"

using namespace common;

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag)
{}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag)
{
  auto *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties()
{
  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize()
{
  LOG_TRACE("Enter");

  auto stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");

  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup()
{
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter");

  handle_request(event);

  LOG_TRACE("Exit");
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter");

  // here finish read all data from disk or network, but do nothing here.

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_request(common::StageEvent *event)
{
  auto *sql_event = dynamic_cast<SQLStageEvent *>(event);
  sql_event->command()->execute(sql_event);
}

//RC ExecuteStage::do_delete(SQLStageEvent *sql_event)
//{
//  Stmt *stmt = sql_event->stmt();
//  SessionEvent *session_event = sql_event->session_event();
//
//  if (stmt == nullptr) {
//    LOG_WARN("cannot find statement");
//    return RC::GENERIC_ERROR;
//  }
//
//  auto *delete_stmt = (DeleteStmt *)stmt;
//  TableScanOperator scan_oper(delete_stmt->table());
//  DeleteOperator delete_oper(delete_stmt);
//  delete_oper.add_child(&scan_oper);
//
//  RC rc = delete_oper.open();
//  if (rc != RC::SUCCESS) {
//    session_event->set_response("FAILURE");
//  } else {
//    session_event->set_response("SUCCESS");
//  }
//  return rc;
//}
//
//RC ExecuteStage::do_update(SQLStageEvent *sql_event)
//{
//  Stmt *stmt = sql_event->stmt();
//  SessionEvent *session_event = sql_event->session_event();
//
//  if (stmt == nullptr) {
//    LOG_WARN("cannot find statement");
//    return RC::GENERIC_ERROR;
//  }
//
//  auto *update_stmt = (UpdateStmt *)stmt;
//  TableScanOperator scan_oper(update_stmt->table());
//  UpdateOperator update_oper(update_stmt);
//  update_oper.add_child(&scan_oper);
//
//  RC rc = update_oper.open();
//  if (rc != RC::SUCCESS) {
//    session_event->set_response("FAILURE");
//  } else {
//    session_event->set_response("SUCCESS");
//  }
//  return rc;
//}
