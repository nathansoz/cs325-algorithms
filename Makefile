CC=g++
CFLAGS=-Wall -pedantic -std=c++0x

all:
	$(CC) $(CFLAGS) src/Helper/fileUtils.cpp src/Helper/timingRoutines.cpp src/enum.cpp src/betterEnum.cpp src/linear.cpp src/main.cpp -o main
