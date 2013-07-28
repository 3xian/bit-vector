AR = ar
AR_FLAGS = crv
CXX = c++
CXX_FLAGS = -O2 -g -Wall -std=c++0x

.PHONY: all clean

all: bit_vector.a
	rm bit_vector.o
	mkdir -p include
	cp src/bit_vector.h include

clean:
	rm -rf include bit_vector.a

bit_vector.a: bit_vector.o
	$(AR) $(AR_FLAGS) bit_vector.a bit_vector.o

bit_vector.o: src/bit_vector.cc src/bit_vector.cc
	$(CXX) $(CXX_FLAGS) -c src/bit_vector.cc
