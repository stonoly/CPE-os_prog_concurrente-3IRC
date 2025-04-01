CFLAGS=-Wall -Wextra -g

all:init clean rdv_n

rdv_n:rdv_n.o dijkstra.o
rdv_n.o:rdv_n.c rdv_n.h dijkstra.h share_memory.h

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h share_memory.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h share_memory.h

dijkstra.o:dijkstra.c dijkstra.h

clean_all:
	rm -rf *.o init clean first second dijkstra