
CC=gcc
FLAGS=-Wall -g

all: client serveur


%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)


client: client.o
	$(CC) -o $@ $^ $(LDFLAGS)

serveur: serveur.c
	$(CC) -o serveur serveur.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


