CC=g++
CFLAGS=-c -Wall

all:
	$(CC) src/enum.cpp src/betterEnum.cpp src/linear.cpp src/main.cpp -o main
