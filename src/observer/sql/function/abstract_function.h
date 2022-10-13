#pragma once

#include <memory>

class AbstractFunction;
using AbstractFunctionRef = std::shared_ptr<AbstractFunction>;

class AbstractFunction : public std::enable_shared_from_this<AbstractFunction> {

};