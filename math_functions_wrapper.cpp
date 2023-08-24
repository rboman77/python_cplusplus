#include <pybind11/pybind11.h>
#include "math_functions.hpp"

namespace py = pybind11;

PYBIND11_MODULE(math_functions, m) {
  py::class_<MathFunctions>(m, "MathFunction")
    .def(py::init<const std::string&>())
    .def("add_integers", &MathFunctions::add_integers)
    .def("divide_floats", &MathFunctions::divide_floats);
         
}

