# Makefile for gtest examples

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = $GTEST_HOME/include

G++ = g++
G++_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE) -std=c++17
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

OBJECTS = main.o 
TARGET = container_test

all: $(TARGET)

$(TARGET): $(OBJECTS)
			g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
			$(G++) $(G++_FLAGS) $<

clean:
			rm -f $(TARGET) $(OBJECTS)
					
.PHONY: all clean