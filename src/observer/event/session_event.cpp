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

#include "session_event.h"

SessionEvent::SessionEvent(ConnectionContext *client) : client_(client)
{}

ConnectionContext *SessionEvent::get_client() const
{
  return client_;
}

Session *SessionEvent::session() const
{
  return client_->session;
}

const std::string &SessionEvent::get_response() const
{
  return response_;
}

void SessionEvent::set_response(const char *response)
{
  set_response(response, static_cast<int>(strlen(response)));
}

void SessionEvent::set_response(const char *response, int len)
{
  response_.assign(response, len);
}

void SessionEvent::set_response(std::string &&response)
{
  response_ = std::move(response);
}

char *SessionEvent::get_request_buf()
{
  return client_->buf;
}