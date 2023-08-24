CC = g++
CFLAGS = -I/usr/include/python3.9 -fPIC

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

math_functions: math_functions.o math_functions_wrapper.o
	g++ --shared -o math_functions.so math_functions.o math_functions_wrapper.o -lpython3.9 -lm

clean:
	rm *.o *.so

