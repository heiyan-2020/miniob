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
    sql_event->set_headers(parse_headers(str));
  } else {
    // transform char -> char(4)
    // TODO(vgalaxy): consider coexistence of char and char (xxx)
    std::string str_trans = std::regex_replace(str, std::regex{"char"}, "char(4)");
    // parse again
    result.reset();
    hsql::SQLParser::parse(str_trans, &result);
    if (result.isValid()) {
      sql_event->set_result(std::make_unique<hsql::SQLParserResult>(std::move(result)));
      sql_event->set_headers(parse_headers(str));
    } else {
      sql_event->session_event()->set_response("Failed to parse sql\n");
      result.reset();
      return RC::INTERNAL;
    }
  }

  return RC::SUCCESS;
}

std::vector<HeaderAlias> ParseStage::parse_headers(const std::string &sql)
{
  std::string str{sql};

  // for find
  std::string str_copy{sql};
  transform(str_copy.begin(), str_copy.end(), str_copy.begin(), ::tolower);

  auto select_size = std::string{"select"}.size();
  auto find_start = str_copy.find("select");
  if (find_start == std::string::npos) {
    return {};
  }
  auto find_end = str_copy.find("from");
  if (find_end == std::string::npos) {
    // select without from clause
    find_end = str_copy.find(';');
    if (find_end == std::string::npos) {
      return {};
    }
  }

  str = str.substr(find_start + select_size, find_end - (find_start + select_size));
  auto select_values = split(trim(str));
  std::vector<HeaderAlias> headers{};
  for (const auto &select_value : select_values) {
    headers.push_back(parse_alias(trim(select_value)));
  }
  return headers;
}

HeaderAlias ParseStage::parse_alias(const std::string &str) {
  // remove as
  std::string tmp;
  // TODO(vgalaxy): consider "As" or "aS"
  tmp = std::regex_replace(str, std::regex{"as"}, "");
  tmp = std::regex_replace(tmp, std::regex{"AS"}, "");

  size_t len = tmp.size();
  size_t curr_index{};
  std::string name{};
  std::string alias{};
  bool in_fn{};
  bool in_str{};
  bool has_alias{};

  while (curr_index < len) {
    if (tmp[curr_index] == '(') {
      in_fn = true;
    }
    if (tmp[curr_index] == ')') {
      in_fn = false;
    }
    if (tmp[curr_index] == '\'') {
      in_str = !in_str;
    }
    if (tmp[curr_index] == ' ') {
      if (in_fn || in_str) {
        name += tmp[curr_index];
      } else {
        has_alias = true;
      }
    } else {
      if (!has_alias) {
        name += tmp[curr_index];
      } else {
        alias += tmp[curr_index];
      }
    }
    curr_index++;
  }

  return {name, alias};
}
