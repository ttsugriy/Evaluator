#include "interpreter/assignment.h"
#include "interpreter/environment.h"
#include "interpreter/expression.h"

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/// This simple evaluator takes a file name as an argument and produces a
/// line in the form of "variable_name = variable_value" for all variables
/// defined in provided file.
/// The content of the file is in the form of "LHS = RHS" where LHS is the
/// variable name and RHS is an unsigned integer, variable or their sum listed
/// in no particular order.
/// See tests directory for examples.
int main(int argc, const char *args[]) {
  if (argc != 2) {
    cerr << "Required input file path is not provided.\nUsage: " << args[0]
         << " <file_name>" << endl;
    exit(1);
  }
  string input_path(args[1]);
  ifstream input_file;
  input_file.open(input_path);
  if (!input_file) {
    cerr << "Unable to open file " << input_path << endl;
    exit(1);
  }
  string line;
  Environment env;
  while (getline(input_file, line)) {
    auto assignment = Assignment::parse(line);
    auto old_sum =
        env.bind(assignment->get_destination(), assignment->get_expression());
    if (assignment->get_expression() != old_sum) {
      throw invalid_argument("Attempted to reassign " +
                             assignment->get_destination());
    }
  }

  set<string> names;
  for (const auto &binding : env) {
    names.insert(binding.first);
  }
  for (const auto &name : names) {
    cout << name << " = " << env.lookup(name)->evaluate(env) << endl;
  }
  input_file.close();
  return 0;
}