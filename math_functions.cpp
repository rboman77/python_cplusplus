#include "math_functions.hpp"

MathFunctions::MathFunctions(const std::string label) : label_(label) {}

std::string MathFunctions::get_label() {
  // Example of how to return a class variable.
  return label_;
}

int MathFunctions::add_integers(int a, int b) { return a + b; }

double MathFunctions::divide_doubles(double a, double b) { return a / b; }

std::vector<int> MathFunctions::integer_range(int limit) {
  // Equivalent of Python range(limit).
  std::vector<int> result;
  for (auto i = 0; i < limit; i++) {
    result.push_back(i);
  }
  return result;
}
