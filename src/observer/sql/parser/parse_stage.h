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

#ifndef __OBSERVER_SQL_PARSE_STAGE_H__
#define __OBSERVER_SQL_PARSE_STAGE_H__

#include "common/seda/stage.h"
#include "rc.h"
#include "event/sql_event.h"

struct HeaderAlias;

class ParseStage : public common::Stage {
public:
  ~ParseStage() override = default;
  static Stage *make_stage(const std::string &tag);

protected:
  // common function
  explicit ParseStage(const char *tag);
  bool set_properties() override;

  bool initialize() override;
  void cleanup() override;
  void handle_event(common::StageEvent *event) override;
  void callback_event(common::StageEvent *event, common::CallbackContext *context) override;

protected:
  RC handle_request(common::StageEvent *event);

private:
  std::vector<HeaderAlias> parse_headers(const std::string &sql);
  HeaderAlias parse_alias(const std::string &str);
  Stage *resolve_stage_ = nullptr;
};

#endif  //__OBSERVER_SQL_PARSE_STAGE_H__
