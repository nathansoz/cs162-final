CC = g++
CFLAGS = -std=c++0x
PROGS = main
MAKEFLAGS = -k

all: $(PROGS)

main:
	$(CC) $(CFLAGS) include/SozLibs/*.cpp include/creatures/*.cpp main.cpp -o main

clean:
	rm -f *.o main