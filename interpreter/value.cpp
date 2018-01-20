#include "value.h"

#include <string>

using namespace std;

Value::Value(unsigned long value) : value(value) {}

string Value::to_string() const {
  return "Value{" + std::to_string(value) + "}";
}
unsigned long Value::evaluate(const Environment &env) { return value; }