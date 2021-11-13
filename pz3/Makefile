# Makefile for gtest examples

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

G++ = gcc
G++_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE) -std=c++17 
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

OBJECTS = main.o 
TARGET = container_test

all: $(TARGET) gcov

$(TARGET): $(OBJECTS)
			g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS) $(GCOV_FLAGS)

%.o : %.cpp
			$(G++) $(G++_FLAGS) $(GCOV_FLAGS) $<

gcov: container_test
	./container_test

clean:
			rm -rf *.gcov *.gcda *.gcno $(TARGET) $(OBJECTS) 
					
.PHONY: all clean