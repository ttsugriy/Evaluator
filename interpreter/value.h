#pragma once

#include "expression.h"

#include <string>

/// Represents literal expressions like "4".
class Value : public Expression {
private:
  unsigned long value;

public:
  Value(unsigned long value);
  std::string to_string() const;
  virtual unsigned long evaluate(const Environment &env);
};