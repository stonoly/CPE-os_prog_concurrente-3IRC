CFLAGS=-Wall -Wextra -g

all:init clean first second

first:first.o dijkstra.o
first.o:first.c first.h dijkstra.h

second:second.o dijkstra.o
second.o:second.c second.h dijkstra.h

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

dijkstra.o:dijkstra.c dijkstra.h

clean_all:
	rm -rf *.o init clean first second dijkstra