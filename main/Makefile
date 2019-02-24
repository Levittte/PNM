COMPILER = g++

FLAGS = -std=c++0x -Wall -Wextra -Wpedantic -fopenmp 


OS := $(shell uname)
ifeq ($(OS),Darwin)
	COMPILER = g++-8
endif

ifdef SYSTEMROOT
    RM = del /Q
else
    RM = rm -f
endif


default: all

all: clean main.o matrix.o function.o methods.o
	$(COMPILER) $(FLAGS) main.o matrix.o function.o methods.o -o main

main.o: 
	$(COMPILER) -c $(FLAGS) main.cpp -o main.o

matrix.o:
	$(COMPILER) -c $(FLAGS) ./matrix.cpp -o matrix.o

function.o:
	$(COMPILER) -c $(FLAGS) ./function.cpp -o function.o

methods.o:
	$(COMPILER) -c $(FLAGS) ./methods.cpp -o methods.o


clean:
	$(RM) *.o main all