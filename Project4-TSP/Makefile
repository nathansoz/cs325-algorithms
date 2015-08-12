CC=g++
CFLAGS=-Wall -pedantic -std=c++0x -O3

all:
	$(CC) $(CFLAGS) src/TSP_Solver.cpp src/main.cpp -lboost_system -lboost_thread-mt -o main
clean:
	rm -f main
