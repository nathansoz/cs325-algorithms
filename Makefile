CC=g++
CFLAGS=-c -Wall

all:
	$(CC) src/Helper/fileUtils.cpp src/enum.cpp src/betterEnum.cpp src/linear.cpp src/main.cpp -o main
