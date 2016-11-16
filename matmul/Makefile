CXX = g++
CC = gcc
CFLAGS = -Wall -O2 -std=gnu11
CXXFLAGS = -Wall -O2
LDFLAGS = -lrt
CXXSRCS = matmul.cpp matmul-driver.cpp 
CXXSRCS_NOOP = matmul-noop.cpp matmul-driver.cpp
SRCS = hrt.c
BIN = mm
BIN_NOOP = mm-noop

all:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $(CXXSRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRCS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $(BIN) *.o

noop:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $(CXXSRCS_NOOP)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRCS)
	$(CXX) $(CFLGAS) $(LDFLAGS) -o $(BIN_NOOP) *.o

clean:
	rm -f $(BIN) *.o
