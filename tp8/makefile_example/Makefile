CFLAGS=-Wall -Wextra -g

TARGETS=toto

all: $(TARGETS)

toto: main.o fonction.o
	gcc $^ -o $@ $(LIBS)

main.o: fonction.h main.c

fonction.o: fonction.h fonction.c

clean:
	rm *.o $(TARGETS)
