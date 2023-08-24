# Python C++

Shows how to call C++ code from python.

# Source Files

| file                         | language | description           |
|:----------------------------:|:--------:|:---------------------:|
| math\_functions.hpp          | C++      | header file           |
| math\_functions.cpp          | C++      | implementation file   |
| math\_functions\_wrapper.cpp | C++      | pybind11 wrapper code |
| test\_math\_functions.py     | Python   | Calls C++ code.       |

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

This code creates the binding between Python and C++.

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

# Alternatives to Pybind11

## SWIG
SWIG is a very versatile tool. It supports a number
of languages including Python, Java, and Golang.

## gRPC
Grpc is a remote procedure call framework. It can be used
to call C++ from Python, but if that is all you need, it is
most likely more complicated that you need. But if you needed
a framework that can integrate multiple languages all at the
same time, or if you are doing client-server computing, it is
a great framework.

## Cython
Cython is a bridge between Python and C/C++.
