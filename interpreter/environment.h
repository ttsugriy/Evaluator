#pragma once

#include "expression.h"

#include <memory>
#include <string>
#include <unordered_map>

/// Represents execution environment that can be used to bind and lookup
/// variable names to corresponding expressions.
class Environment {
private:
  std::unordered_map<std::string, std::shared_ptr<Expression>> bindings;

public:
  using iterator =
      std::unordered_map<std::string, std::shared_ptr<Expression>>::iterator;
  std::shared_ptr<Expression> lookup(const std::string &name) const;
  std::shared_ptr<Expression> bind(const std::string &name,
                                   std::shared_ptr<Expression> expression);
  iterator begin();
  iterator end();
};