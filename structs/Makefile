CXX = g++
CC = gcc
CFLAGS = -Wall -O2 -std=gnu11
CXXFLAGS = -Wall -O2
LDFLAGS = -lrt
CXXSRCS = structs.cpp 
CXXSRCS_NOOP = structs-noop.cpp
SRCS = hrt.c
BIN = computeavg 
BIN_NOOP = computeavg-noop

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $(CXXSRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRCS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN) *.o

noop:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $(CXXSRCS_NOOP)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRCS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN_NOOP) *.o

clean:
	rm -f $(BIN) *.o
