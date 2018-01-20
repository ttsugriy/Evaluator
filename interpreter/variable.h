#pragma once

#include "environment.h"

#include <string>

/// Represents variable usages like "foo".
class Variable : public Expression {
private:
  const std::string name;

public:
  Variable(const std::string &name);
  std::string to_string() const;
  virtual unsigned long evaluate(const Environment &env);
};