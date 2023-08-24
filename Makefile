CC = g++
CFLAGS = -I/usr/include/python3.9

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

math_functions: math_functions.o math_functions_wrapper.o
	echo "compiled"
