#include "assignment.h"
#include "environment.h"
#include "sum.h"

#include <sstream>
#include <vector>

using namespace std;

Assignment::Assignment(const string &destination,
                       shared_ptr<Expression> expression)
    : destination(destination), expression(expression) {}

string Assignment::to_string() const {
  return "Assignment{" + destination + "=" + expression->to_string() + "}";
}

shared_ptr<Assignment> Assignment::parse(const string &line) {
  istringstream stream(line);
  string name;
  stream >> name;
  vector<shared_ptr<Expression>> expressions;
  while (!stream.eof()) {
    string token;
    stream >> token;
    auto expression = Expression::parse(token);
    if (expression == nullptr)
      continue;
    expressions.emplace_back(expression);
  }
  auto sum = make_shared<Sum>(expressions);
  return make_shared<Assignment>(name, sum);
}

string Assignment::get_destination() const { return destination; }

shared_ptr<Expression> Assignment::get_expression() const { return expression; }