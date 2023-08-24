#include "math_functions.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(math_functions, m) {
  py::class_<MathFunctions>(m, "MathFunctions")
      .def(py::init<const std::string &>())
      .def("add_integers", &MathFunctions::add_integers)
      .def("divide_doubles", &MathFunctions::divide_doubles)
      .def("get_label", &MathFunctions::get_label);
}
