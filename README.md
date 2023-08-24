# Python C++

Shows how to call C++ code from python.

# Source Files

| file                         | language | description           |
|:----------------------------:|:--------:|:---------------------:|
| math\_functions.hpp          | C++      | header file           |
| math\_functions.cpp          | C++      | implementation file   |
| math\_functions\_wrapper.cpp | C++      | pybind11 wrapper code |
| test\_math\_functions.py     | Python   | Calls C++ code.       |

The C++ class is defined
[here.](https://github.com/rboman77/python_cplusplus/blob/a828de499cdb140ed9edddfd10aca7157e0312a4/math_functions.hpp#L5)

The pybind11 interface code is
[here.](https://github.com/rboman77/python_cplusplus/blob/a828de499cdb140ed9edddfd10aca7157e0312a4/math_functions_wrapper.cpp#L7C8-L7C8)


# Pybind11

Here we use pybind11 to interface python and C++. Other
possibilities are:

* SWIG
* gRPC
* cython

For more information on pybind1, see
[this link.](https://pybind11.readthedocs.io/en/stable/)

# STL Vector

Note the method std::vector<int>MathFunctions::integer_range(int limit).
In this case, pybind11 is able to convert the std::vector into a python
list.
