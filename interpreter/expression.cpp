#include "expression.h"

#include "value.h"
#include "variable.h"

using namespace std;

shared_ptr<Expression> Expression::parse(const string &token) {
  if (token == "+" || token == "=")
    return nullptr;
  if (std::isdigit(token.front())) {
    return make_shared<Value>(stoul(token));
  } else {
    return make_shared<Variable>(token);
  }
}