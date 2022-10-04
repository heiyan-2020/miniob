#pragma once

#include <vector>
#include <memory>

class BoundStatement
{

};

class Transformer
{
public:
  std::vector<std::unique_ptr<BoundStatement>> statements_;
  void transform_parse_tree(duckdb_libpgquery::PGList * parse_tree);
};