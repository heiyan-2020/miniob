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
#include <regex>

#include "parse_stage.h"

#include "common/conf/ini.h"
#include "common/io/io.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"
#include "event/session_event.h"
#include "event/sql_event.h"

#include "hsql/SQLParser.h"
#include "sql/binder/planner.h"

#include "util/string_utils.h"

using namespace common;

//! Constructor
ParseStage::ParseStage(const char *tag) : Stage(tag)
{}

//! Parse properties, instantiate a stage object
Stage *ParseStage::make_stage(const std::string &tag)
{
  auto *stage = new (std::nothrow) ParseStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ParseStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ParseStage::set_properties()
{
  return true;
}

//! Initialize stage params and validate outputs
bool ParseStage::initialize()
{
  LOG_TRACE("Enter");
  auto stgp = next_stage_list_.begin();
  resolve_stage_ = *(stgp++);
  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ParseStage::cleanup()
{
  LOG_TRACE("Enter");
  LOG_TRACE("Exit");
}

void ParseStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter");
  RC rc = handle_request(event);
  if (RC::SUCCESS != rc) {
    callback_event(event, nullptr);
    return;
  }

  auto *cb = new (std::nothrow) CompletionCallback(this, nullptr);
  if (cb == nullptr) {
    LOG_ERROR("Failed to new callback for SQLStageEvent");
    callback_event(event, nullptr);
    return;
  }

  event->push_callback(cb);
  resolve_stage_->handle_event(event);
  event->done_immediate();

  LOG_TRACE("Exit");
}

void ParseStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter");
  auto *sql_event = dynamic_cast<SQLStageEvent *>(event);
  sql_event->session_event()->done_immediate();
  //  sql_event->done_immediate();
  LOG_TRACE("Exit");
}

RC ParseStage::handle_request(StageEvent *event)
{
  auto *sql_event = dynamic_cast<SQLStageEvent *>(event);
  const std::string &sql = sql_event->sql();

  // hyrise parser
  hsql::SQLParserResult result;
  std::string str{sql};
  hsql::SQLParser::parse(str, &result);
  if (result.isValid()) {
    sql_event->set_result(std::make_unique<hsql::SQLParserResult>(std::move(result)));
    parse_headers(sql_event, str);
  } else {
    // transform char -> char(4)
    // TODO(vgalaxy): consider coexistence of char and char (xxx)
    std::string str_trans = std::regex_replace(str, std::regex{"char"}, "char(4)");
    // parse again
    result.reset();
    hsql::SQLParser::parse(str_trans, &result);
    if (result.isValid()) {
      sql_event->set_result(std::make_unique<hsql::SQLParserResult>(std::move(result)));
      parse_headers(sql_event, str_trans);
    } else {
      sql_event->session_event()->set_response("Failed to parse sql\n");
      result.reset();
      return RC::INTERNAL;
    }
  }

  return RC::SUCCESS;
}

RC ParseStage::parse_headers(SQLStageEvent *event, const std::string &sql)
{
  std::string str{sql};
  std::string str_copy{sql};
  transform(str_copy.begin(), str_copy.end(), str_copy.begin(), ::tolower);
  auto select_size = std::string{"select"}.size();
  auto find_select = str_copy.find("select");
  if (find_select == std::string::npos) {
    return RC::GENERIC_ERROR;
  }
  auto find_from = str_copy.find("from");
  if (find_from != std::string::npos) {
    str = str.substr(find_select + select_size, find_from - (find_select + select_size));
    event->set_headers(split(trim(str)));
    return RC::SUCCESS;
  } else {
    // select without from clause
    auto find_end = str_copy.find(';');
    if (find_end == std::string::npos) {
      return RC::GENERIC_ERROR;
    }
    str = str.substr(find_select + select_size, find_end - (find_select + select_size));
    event->set_headers(split(trim(str)));
    return RC::SUCCESS;
  }
}
