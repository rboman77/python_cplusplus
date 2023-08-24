#include <string>


class MathFunctions {
  std::string label_;
public:
  MathFunctions(const std::string label);
  std::string get_label();
  int add_integers(int a, int b);
  double divide_doubles(double a, double b);
};

