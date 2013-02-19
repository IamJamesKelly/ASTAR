CC=gcc
CFLAGS=-I. -fopenmp
APP=ASTAR

build: main.o
	$(CC) -o $(APP) main.o $(CFLAGS)

clean:
	rm *.o
	rm $(APP)