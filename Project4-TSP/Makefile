CC=g++
CFLAGS=-Wall -pedantic -std=c++0x -O3

all:
	$(CC) $(CFLAGS) src/TSP_Solver.cpp src/main.cpp -lboost_system -lboost_thread-mt -lboost_filesystem -o main
clean:
	rm -f main
