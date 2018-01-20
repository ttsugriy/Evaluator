#include "variable.h"

using namespace std;

Variable::Variable(const string &name) : name(name) {}
string Variable::to_string() const { return "Variable{" + name + "}"; }
unsigned long Variable::evaluate(const Environment &env) {
  return env.lookup(name)->evaluate(env);
}