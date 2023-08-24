#include <string>

#include <pybind11/pybind11.h>

namespace py = pybind11;



class MathFunction {
  MathFunction(const std::string label);
  int add_integers(int a, int b);
  int divide_floats(float a, float b);
};


PYBIND11_MODULE(math_functions, m) {
  py::class_<MathFunction>(m, "MathFunction")
    .def(py::init<const std::string&>());
}

