import math_functions

# mypy: disable-error-code=import

LABEL = "TEST_LABEL"

handle = math_functions.MathFunctions(LABEL)

assert handle.get_label() == LABEL

a_int = 101
b = 333
assert handle.add_integers(a_int, b) == a_int + b

a_float = 10.2
b_float = 3.5
assert handle.divide_floats(a_float, b) == a_float / b

