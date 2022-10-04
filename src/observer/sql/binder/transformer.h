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
};