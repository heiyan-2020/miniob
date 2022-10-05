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

#ifndef __OBSERVER_SESSION_SESSIONSTAGE_H__
#define __OBSERVER_SESSION_SESSIONSTAGE_H__

#include "common/seda/stage.h"
#include "net/connection_context.h"
#include "common/metrics/metrics.h"

class SessionStage : public common::Stage {
public:
  ~SessionStage();
  static Stage *make_stage(const std::string &tag);

protected:
  // common function
  SessionStage(const char *tag);
  bool set_properties() override;

  bool initialize() override;
  void cleanup() override;
  void handle_event(common::StageEvent *event) override;
  void callback_event(common::StageEvent *event, common::CallbackContext *context) override;

protected:
  void handle_input(common::StageEvent *event);

  void handle_request(common::StageEvent *event);

private:
  Stage *plan_cache_stage_ = nullptr;
  common::SimpleTimer *sql_metric_ = nullptr;
  static const std::string SQL_METRIC_TAG;
};

#endif  //__OBSERVER_SESSION_SESSIONSTAGE_H__
