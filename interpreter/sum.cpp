#include "sum.h"

using namespace std;

Sum::Sum(const vector<shared_ptr<Expression>> expressions)
    : expressions(expressions) {}
string Sum::to_string() const {
  string str = "Sum{";
  for (const auto expr : expressions) {
    str += expr->to_string() + ",";
  }
  str += "}";
  return str;
}
unsigned long Sum::evaluate(const Environment &env) {
  unsigned long sum = 0;
  for (const auto expr : expressions) {
    sum += expr->evaluate(env);
  }
  return sum;
}