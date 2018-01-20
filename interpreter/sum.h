#pragma once

#include "expression.h"

#include <memory>
#include <vector>

/// Represents expressions like "x + 1 + y".
class Sum : public Expression {
private:
  std::vector<std::shared_ptr<Expression>> expressions;

public:
  Sum(const std::vector<std::shared_ptr<Expression>> expressions);
  std::string to_string() const;
  virtual unsigned long evaluate(const Environment &env);
};