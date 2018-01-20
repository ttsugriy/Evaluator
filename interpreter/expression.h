#pragma once

#include <memory>
#include <string>

class Environment;

/// Represents an expression supported by the interpreter.
class Expression {
public:
  /// Evaluates provided expressions and returns a resulting value.
  /// Note that circular references are not detected and clients must
  /// ensure that input is valid. This is according to the problem
  /// statement.
  virtual unsigned long evaluate(const Environment &env) = 0;
  /// Conerts an expression to a string representation for debugging.
  virtual std::string to_string() const = 0;
  /// Parses provided token into corresponding expression.
  /// Token that do not map into any expressions are parsed into nullptr.
  static std::shared_ptr<Expression> parse(const std::string &token);
};