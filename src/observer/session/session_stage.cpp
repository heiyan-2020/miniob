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

#include "session_stage.h"

#include <cstring>
#include <string>

#include "common/conf/ini.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"

#include "common/lang/mutex.h"
#include "common/metrics/metrics_registry.h"
#include "common/seda/callback.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "net/server.h"
#include "session/session.h"

using namespace common;

const std::string SessionStage::SQL_METRIC_TAG = "SessionStage.sql";

// Constructor
SessionStage::SessionStage(const char *tag) : Stage(tag), plan_cache_stage_(nullptr), sql_metric_(nullptr)
{}

// Parse properties, instantiate a stage object
Stage *SessionStage::make_stage(const std::string &tag)
{
  auto *stage = new (std::nothrow) SessionStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecutorStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

// Set properties for this object set in stage specific properties
bool SessionStage::set_properties()
{
  return true;
}

// Initialize stage params and validate outputs
bool SessionStage::initialize()
{
  LOG_TRACE("Enter");

  auto stgp = next_stage_list_.begin();
  plan_cache_stage_ = *(stgp++);

  MetricsRegistry &metricsRegistry = get_metrics_registry();
  sql_metric_ = new SimpleTimer();
  metricsRegistry.register_metric(SQL_METRIC_TAG, sql_metric_);

  LOG_TRACE("Exit");
  return true;
}

// Cleanup after disconnection
void SessionStage::cleanup()
{
  LOG_TRACE("Enter");

  MetricsRegistry &metricsRegistry = get_metrics_registry();
  if (sql_metric_ != nullptr) {
    metricsRegistry.unregister(SQL_METRIC_TAG);
    delete sql_metric_;
    sql_metric_ = nullptr;
  }

  LOG_TRACE("Exit");
}

void SessionStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter");

  // right now, we just support only one event.
  handle_request(event);

  LOG_TRACE("Exit");
}

void SessionStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter");

  auto *sev = dynamic_cast<SessionEvent *>(event);
  if (nullptr == sev) {
    LOG_ERROR("Cannot cast event to sessionEvent");
    return;
  }

  std::string response = std::string{sev->get_response()};
  // TODO(vgalaxy): assume
  if ((response.at(response.length() - 1)) != '\n') {
      response += "\n";
  }

  Server::send(sev->get_client(), response.c_str(),
      static_cast<int>(response.length() + 1));  // include '\0'

  LOG_TRACE("Exit");
}

void SessionStage::handle_request(StageEvent *event)
{
  auto *sev = dynamic_cast<SessionEvent *>(event);
  if (nullptr == sev) {
    LOG_ERROR("Cannot cat event to sessionEvent");
    return;
  }

  TimerStat sql_stat(*sql_metric_);
  if (nullptr == sev->get_request_buf()) {
    LOG_ERROR("Invalid request buffer.");
    sev->done_immediate();
    return;
  }

  std::string sql = sev->get_request_buf();
  if (common::is_blank(sql.c_str())) {
    sev->done_immediate();
    return;
  }

  auto *cb = new (std::nothrow) CompletionCallback(this, nullptr);
  if (cb == nullptr) {
    LOG_ERROR("Failed to new callback for SessionEvent");
    sev->done_immediate();
    return;
  }

  sev->push_callback(cb);

  auto *sql_event = new SQLStageEvent(sev, sql);
  plan_cache_stage_->handle_event(sql_event);
}
