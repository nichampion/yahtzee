CC = gcc
OBJ = main.o affichage.o fonctions_joueur.o ordinateur.o

Yahtzee : $(OBJ)
	$(CC) $(OBJ) -o Yahtzee

%.o : %.c %.h
	$(CC) -c $< -o $@

clean :
	rm -rf *.o
	rm Yahtzee

mrproper: clean
