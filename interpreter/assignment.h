#pragma once

#include "environment.h"
#include "expression.h"

#include <memory>
#include <string>

/// Represents statements like "LHS = RHS"
class Assignment {
private:
  std::string destination;
  std::shared_ptr<Expression> expression;

public:
  Assignment(const std::string &destination,
             std::shared_ptr<Expression> expression);
  std::string to_string() const;
  static std::shared_ptr<Assignment> parse(const std::string &line);
  std::string get_destination() const;
  std::shared_ptr<Expression> get_expression() const;
};