# Evaluator
Simple expression evaluator.

[![Build Status](https://travis-ci.org/ttsugriy/Evaluator.svg?branch=master)](https://travis-ci.org/ttsugriy/Evaluator)

## Getting Started

Follow instructions below to get you a copy of the project up and running.

### Prerequisites

In order to target as many platforms and development environments as possible,
while making instructions as simple as possible, a [cmake](https://cmake.org/)
build system is used. You can grab the latest version from their
[official site](https://cmake.org/download/) or run

```
brew install cmake
```
if you're using MacOS.

### Building

In order to build the `Evaluator` binary, it's recommended to create and use
a separate build directory. For example you can run following commands in the repository root:
```
mkdir build && cd build
```
Inside of this directory, you can now generate a build recipe (Makefile by default)
by running
```
cmake ..
```
assuming `build` directory created in a previous step was created in the repository root.
The last step is to actually produce the binary by running
```
make
```
You will now find the `Evaluator` binary inside of `build` directory.

## Using

`Evaluator` binary takes a single argument with a path to a file containing expressions
in the form of `LHS = RHS` where `LHS` is a variable identifier and `RHS` is either
an unsigned integer, variable name or their sum. For example, when it's invoked by running
```
Evaluator input
```
where `input` file contains
```
x = 1 + y + 2
y = z + 3
z = 2
```

The output will be
```
x = 8
y = 5
z = 2
```

Note that variables can be defined in any order, but are assumed to not contain
any circular references, since it's impossible to evaluate such expressions. Current
implementation does not have a built-in cycle detection, even though it's easy to
add by using one of many cycle detection algoriths for graphs by modelling expressions
as nodes and variable references as edges.

## Running the tests

After building the binary you can run `ctest` inside of `build` directory and
hopefully see all tests passing:
```
Test project /src/evaluator/build
    Start 1: Evaluator_trivial
1/5 Test #1: Evaluator_trivial ................   Passed    0.02 sec
    Start 2: Evaluator_simple_sum
2/5 Test #2: Evaluator_simple_sum .............   Passed    0.00 sec
    Start 3: Evaluator_reversed_order
3/5 Test #3: Evaluator_reversed_order .........   Passed    0.00 sec
    Start 4: Evaluator_multi_level
4/5 Test #4: Evaluator_multi_level ............   Passed    0.00 sec
    Start 5: Evaluator_example
5/5 Test #5: Evaluator_example ................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   0.04 sec
```
If any of the tests above fails you can enable verbose output to see what exactly
went wrong by adding an appropriate flag:
```
ctest -V
```
This way you can also see actual output produced by every test case:

## License

This project is licensed under the GNU GPLv3 license. You can find its copy in [LICENSE](LICENSE) file.