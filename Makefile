CC = g++
INC_DIR = ./thirdparry/rapidjson
CFLAGS = -std=c++0x -I$(INC_DIR)
PROGS = main
MAKEFLAGS = -k

all: $(PROGS)

main:
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	rm -f *.o main