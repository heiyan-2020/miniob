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
// Created by Meiyi & Longda on 2021/5/11.
//
#ifndef __OBSERVER_STORAGE_DEFAULT_ENGINE_H__
#define __OBSERVER_STORAGE_DEFAULT_ENGINE_H__

#include <string>
#include <map>

#include "storage/common/db.h"

class Trx;

class DefaultHandler {
public:
  DefaultHandler() = default;

  virtual ~DefaultHandler() noexcept;

  RC init(const char *base_dir);
  void destroy();

  RC create_db(const char *dbname);
  RC drop_db(const char *dbname);
  RC open_db(const char *dbname);
  RC close_db(const char *dbname);

public:
  Db *find_db(const char *dbname) const;
  Table *find_table(const char *dbname, const char *table_name) const;

  RC sync();

public:
  static void set_default(DefaultHandler *handler);
  static DefaultHandler &get_default();

private:
  std::string base_dir_;
  std::string db_dir_;
  std::map<std::string, Db *> opened_dbs_;
};  // class Handler

#endif  // __OBSERVER_STORAGE_DEFAULT_ENGINE_H__
