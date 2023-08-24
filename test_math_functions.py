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

