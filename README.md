# Python C++

Shows how to call C++ code from python.

# Pybind11

Here we use pybind11 to interface python and C++. Other
possibilities are:

* SWIG
* gRPC
* cython

| file                         | language | description           |
|:----------------------------:|:--------:|:---------------------:|
| math\_functions.hpp          | C++      | header file           |
| math\_functions.cpp          | C++      | implementation file   |
| math\_functions\_wrapper.cpp | C++      | pybind11 wrapper code |
| test\_math\_functions.py     | Python   | Calls C++ code.       |


# STL Vector

Note the method std::vector<int>MathFunctions::integer_range(int limit).
In this case, pybind11 is able to convert the std::vector into a python
list.
