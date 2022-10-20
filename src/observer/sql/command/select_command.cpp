#include "select_command.h"
#include "sql/binder/planner.h"
#include "storage/common/db.h"
#include "session/session.h"
#include "storage/common/table.h"
#include "sql/table/column.h"
#include "sql/binder/binder.h"
#include "util/string_utils.h"

SelectCommand::SelectCommand(const hsql::SelectStatement *stmt) : Command{hsql::kStmtSelect}, stmt_{stmt}
{}

RC SelectCommand::execute(const SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  RC rc;
  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  rc = planner.make_plan_sel(stmt_, sp);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  rc = sp->prepare();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  rc = sp->initialize();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  std::stringstream ss;
  print_header(ss, sp->get_schema(), sql_event->headers(), planner.binder_.has_multi_table_);
  TupleRef tuple;
  while ((rc = sp->next()) == RC::SUCCESS) {
    rc = sp->current_tuple(tuple);
    if (rc != RC::SUCCESS) {
      break;
    }
    tuple_to_string(ss, *tuple, sp->get_schema());

    ss << std::endl;
  }
  if (rc != RC::RECORD_EOF) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
//  if (stmt_->order != nullptr) {
//    int len = ss.str().length();
//    std::string out = ss.str().substr(0, len - 1);
//    ss.str("");
//    ss << out;
//  }
  session_event->set_response(ss.str());
  return RC::SUCCESS;
}

void SelectCommand::print_header(
    std::ostream &os, SchemaRef schema, const std::vector<HeaderAlias> &headers, bool has_multi_table)
{
  bool first = true;
  const std::vector<Column> &columns = schema->get_columns();
  bool table_name_ignorable = schema->ignore_table_name() && !has_multi_table;
  if (table_name_ignorable) {
    for (const auto &column : columns) {
      if (column.is_visible()) {
        if (!first) {
          os << " | ";
        }
        os << column.get_name().to_string(table_name_ignorable);
        first = false;
      }
    }
  } else {
    for (const auto &header : headers) {
      if (ends_with(header.name, "*")) {
        std::vector<Column> involved_columns = schema->find_columns(get_table_name_from_header(header), {});
        for (const auto &column : involved_columns) {
          if (column.is_visible()) {
            if (!first) {
              os << " | ";
            }
            os << column.get_name().to_string(table_name_ignorable);
            first = false;
          }
        }
      } else {
        if (!first) {
          os << " | ";
        }
        if (!header.alias.empty()) {
          os << header.alias;
        } else {
          os << header.name;
        }
        first = false;
      }
    }
  }
  if (schema->get_column_count() > 0) {
    os << std::endl;
  }
}

void SelectCommand::tuple_to_string(std::ostream &os, const Tuple &tuple, SchemaRef schema)
{
  // Transforming result set into strings.
  std::string row;
  bool first = true;
  common::Bitmap null_field_bitmap{tuple.get_record().data(), 32};
  for (auto i = 0; i < schema->get_column_count(); i++) {
    const auto &column = schema->get_column(i);
    if (column.is_visible()) {
      if (!first) {
        row += " | ";
      }
      if (null_field_bitmap.get_bit(i)) {
        row += "null";
      } else {
        row += tuple.get_value(schema, i).to_string();
      }
      first = false;
    }
  }
  os << row;
}

/**
 * 将 sub query 的结果 (Value) 保存到 new_values 中
 * @param sql_event
 * @param new_values
 * @return
 */
RC SelectCommand::get_res_values(const SQLStageEvent *sql_event, std::vector<Value> &new_values) {
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();

  RC rc;
  Planner planner(db);
  std::shared_ptr<PlanNode> sp;
  rc = planner.make_plan_sel(stmt_, sp);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  rc = sp->prepare();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }
  rc = sp->initialize();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  TupleRef tuple;
  while ((rc = sp->next()) == RC::SUCCESS) {
    rc = sp->current_tuple(tuple);
    if (rc != RC::SUCCESS) {
      break;
    }
    tuple_to_value(*tuple, sp->get_schema(), new_values);
  }
  if (rc != RC::RECORD_EOF) {
    return rc;
  }
  return RC::SUCCESS;
}

void SelectCommand::tuple_to_value(const Tuple &tuple, SchemaRef schema, std::vector<Value> &new_values)
{
  common::Bitmap null_field_bitmap{tuple.get_record().data(), 32};
  for (auto i = 0; i < schema->get_column_count(); i++) {
    const auto &column = schema->get_column(i);
    if (column.is_visible()) {
      if (null_field_bitmap.get_bit(i)) {
        // null value
        new_values.emplace_back(Value());
      }
      else {
        new_values.emplace_back(tuple.get_value(schema, i));
      }
    }
  }
}

std::string SelectCommand::get_table_name_from_header(HeaderAlias header)
{
  size_t dot_pos = header.name.find('.');
  if (dot_pos == std::string::npos) {
    return {}; //doesn't specify table name, just return empty.
  }
  return header.name.substr(0, dot_pos);
}
