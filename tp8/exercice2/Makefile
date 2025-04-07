CFLAGS=-Wall -Wextra -g

all:init clean rdv_two_f rdv_two_s init_bis clean_bis rdv_two_f_bis rdv_two_s_bis rdv_two_t_bis

rdv_two_f:rdv_two_f.o dijkstra.o
rdv_two_f.o:rdv_two_f.c rdv_two.h dijkstra.h

rdv_two_f_bis:rdv_two_f_bis.o dijkstra.o
rdv_two_f_bis.o:rdv_two_f_bis.c rdv_two.h dijkstra.h

rdv_two_s:rdv_two_s.o dijkstra.o
rdv_two_s.o:rdv_two_s.c rdv_two.h dijkstra.h

rdv_two_s_bis:rdv_two_s_bis.o dijkstra.o
rdv_two_s_bis.o:rdv_two_s_bis.c rdv_two.h dijkstra.h

rdv_two_t_bis:rdv_two_t_bis.o dijkstra.o
rdv_two_t_bis.o:rdv_two_t_bis.c rdv_two.h dijkstra.h

init:init.o dijkstra.o
init.o:init.c init.h dijkstra.h

init_bis:init_bis.o dijkstra.o
init_bis.o:init_bis.c init.h dijkstra.h

clean:clean.o dijkstra.o
clean.o:clean.c clean.h dijkstra.h

clean_bis:clean_bis.o dijkstra.o
clean_bis.o:clean_bis.c clean.h dijkstra.h

dijkstra.o:dijkstra.c dijkstra.h

clean_all:
	rm -rf *.o init clean first second dijkstra