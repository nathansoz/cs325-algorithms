CC=g++
CFLAGS=-Wall -pedantic -std=c++0x

all:
	$(CC) $(CFLAGS) src/Helper/timingRoutines.cpp src/Helper/fileUtils.cpp src/changegreedy.cpp src/changeslow.cpp src/dynProgCoin.cpp src/main.cpp -o main -lboost_system -lboost_filesystem
clean:
	rm -f main
