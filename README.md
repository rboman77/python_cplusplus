# Python C++

Shows how to call C++ code from python.

# Source Files

| file                         | language | description           |
|:----------------------------:|:--------:|:---------------------:|
| math\_functions.hpp          | C++      | header file           |
| math\_functions.cpp          | C++      | implementation file   |
| math\_functions\_wrapper.cpp | C++      | pybind11 wrapper code |
| test\_math\_functions.py     | Python   | Calls C++ code.       |

# Code Sections

## C++ Class Defintion

This is the C++ class to call from python. The integer\_range()
method is particularly interesting because it returns and STL vector.
Pybind11 converts the STL vector into a python list.


```C++
class MathFunctions {
  std::string label_;
public:
  MathFunctions(const std::string label);
  std::string get_label();
  int add_integers(int a, int b);
  double divide_doubles(double a, double b);
  // C++ code that emulates python range(limit).
  std::vector<int> integer_range(int limit);
};
```

## Pybind11 Binding Code


```C++
namespace py = pybind11;

PYBIND11_MODULE(math_functions, m) {
  py::class_<MathFunctions>(m, "MathFunctions")
      .def(py::init<const std::string &>())
      .def("add_integers", &MathFunctions::add_integers)
      .def("divide_doubles", &MathFunctions::divide_doubles)
      .def("get_label", &MathFunctions::get_label)
      .def("integer_range", &MathFunctions::integer_range);
}

```

For more information on pybind11, see
[this link.](https://pybind11.readthedocs.io/en/stable/)

## Python Code Calling C++

```python
import math_functions

# mypy: disable-error-code=import

LABEL = "TEST_LABEL"

handle = math_functions.MathFunctions(LABEL)

assert handle.get_label() == LABEL

# Integer case matches exactly.
a_int = 101
b = 333
assert handle.add_integers(a_int, b) == a_int + b

# In general, floating point computations may not match. But they
# should be very close.
a_float = 10.2
b_float = 3.5
py_result = a_float / b_float
cpp_result = handle.divide_doubles(a_float, b_float)
fraction_error = abs(py_result - cpp_result) / py_result
assert fraction_error < 1e-8

# Example of returning a tuple from C++. Note that pybind11 converts
# the std::vector into a python list.
num_elements = 10
py_list = list(range(num_elements))
cpp_list = handle.integer_range(num_elements)
assert isinstance(cpp_list, list)
assert py_list == cpp_list
```

# Alternatives to Pybind11

## SWIG
SWIG is a very versatile tool. It supports a number
of languages including Python, Java, and Golang.

## gRPC
Grpc is a remote procedure call framework. It can be used
to call C++ from Python, but if that is all you need, it is
most likely more complicated that you need. But if you need
a framework that can integrate multiple languages all at the
same time, or if you are doing client-server computing, it is
a great framework.

## Cython
Cython is a bridge between Python and C/C++.
