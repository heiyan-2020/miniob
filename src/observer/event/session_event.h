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

#ifndef __OBSERVER_SESSION_SESSIONEVENT_H__
#define __OBSERVER_SESSION_SESSIONEVENT_H__

#include <cstring>
#include <string>

#include "common/seda/stage_event.h"
#include "net/connection_context.h"

class Session;

class SessionEvent : public common::StageEvent {
public:
  explicit SessionEvent(ConnectionContext *client);
  ~SessionEvent() override = default;

  ConnectionContext *get_client() const;
  Session *session() const;

  const std::string &get_response() const;
  void set_response(const char *response);
  void set_response(const char *response, int len);
  void set_response(std::string &&response);
  char *get_request_buf();

private:
  ConnectionContext *client_;

  std::string response_;
};

#endif  //__OBSERVER_SESSION_SESSIONEVENT_H__
