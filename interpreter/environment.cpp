#include "environment.h"

#include <memory>
#include <string>

using namespace std;

shared_ptr<Expression> Environment::lookup(const string &name) const {
  const auto found = bindings.find(name);
  if (found == bindings.cend()) {
    // should never happen according to problem statement
    throw invalid_argument("Unexpected variable '" + name + "'");
  }
  return found->second;
}
shared_ptr<Expression> Environment::bind(const string &name,
                                         shared_ptr<Expression> expression) {
  return bindings[name] = expression;
}
Environment::iterator Environment::begin() { return bindings.begin(); }
Environment::iterator Environment::end() { return bindings.end(); }