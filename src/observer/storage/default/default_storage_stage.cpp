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

#include <cstring>
#include <string>

#include "storage/default/default_storage_stage.h"

#include "common/conf/ini.h"
#include "common/io/io.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/seda/timer_stage.h"
#include "common/metrics/metrics_registry.h"
#include "rc.h"
#include "storage/default/default_handler.h"
#include "storage/common/table.h"
#include "storage/common/table_meta.h"
#include "storage/trx/trx.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"

using namespace common;

const std::string DefaultStorageStage::QUERY_METRIC_TAG = "DefaultStorageStage.query";
const char *CONF_BASE_DIR = "BaseDir";
const char *CONF_SYSTEM_DB = "SystemDb";

const char *DEFAULT_SYSTEM_DB = "sys";

//! Constructor
DefaultStorageStage::DefaultStorageStage(const char *tag) : Stage(tag), handler_(nullptr)
{}

//! Destructor
DefaultStorageStage::~DefaultStorageStage()
{
  delete handler_;
  handler_ = nullptr;
}

//! Parse properties, instantiate a stage object
Stage *DefaultStorageStage::make_stage(const std::string &tag)
{
  auto *stage = new (std::nothrow) DefaultStorageStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new DefaultStorageStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool DefaultStorageStage::set_properties()
{
  std::string stageNameStr(stage_name_);
  std::map<std::string, std::string> section = get_properties()->get(stageNameStr);

  // 初始化时打开默认的 database，没有的话会自动创建
  auto iter = section.find(CONF_BASE_DIR);
  if (iter == section.end()) {
    LOG_ERROR("Config cannot be empty: %s", CONF_BASE_DIR);
    return false;
  }

  const char *base_dir = iter->second.c_str();

  const char *sys_db = DEFAULT_SYSTEM_DB;
  iter = section.find(CONF_SYSTEM_DB);
  if (iter != section.end()) {
    sys_db = iter->second.c_str();
    LOG_INFO("Use %s as system db", sys_db);
  }

  handler_ = &DefaultHandler::get_default();
  if (RC::SUCCESS != handler_->init(base_dir)) {
    LOG_ERROR("Failed to init default handler");
    return false;
  }

  RC ret = handler_->create_db(sys_db);
  if (ret != RC::SUCCESS && ret != RC::SCHEMA_DB_EXIST) {
    LOG_ERROR("Failed to create system db");
    return false;
  }

  ret = handler_->open_db(sys_db);
  if (ret != RC::SUCCESS) {
    LOG_ERROR("Failed to open system db");
    return false;
  }

  Session &default_session = Session::default_session();
  default_session.set_current_db(sys_db);

  LOG_INFO("Open system db success: %s", sys_db);
  return true;
}

//! Initialize stage params and validate outputs
bool DefaultStorageStage::initialize()
{
  LOG_TRACE("Enter");

  MetricsRegistry &metricsRegistry = get_metrics_registry();
  query_metric_ = new SimpleTimer();
  metricsRegistry.register_metric(QUERY_METRIC_TAG, query_metric_);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void DefaultStorageStage::cleanup()
{
  LOG_TRACE("Enter");

  if (handler_) {
    handler_->destroy();
    handler_ = nullptr;
  }

  LOG_TRACE("Exit");
}

void DefaultStorageStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter");

  // do nothing

  LOG_TRACE("Exit");
}

void DefaultStorageStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter");

  // do nothing

  LOG_TRACE("Exit");
}
