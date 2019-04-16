TARGET = Yahtzee

CC = gcc
LINKER = gcc
rm = rm -f
FLAGS = -Wall -g3
FLAGS2 = -W -Wall -ansi -pedantic


# SDL 2
SDL_DIR=${HOME}/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include

LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDL_INC_DIR}


# Repertoires
SRCDIR = src
OBJDIR = obj
BINDIR = bin

DIRS = $(OBJDIR) $(BINDIR)

.PHONY: DIRS
all: $(DIRS) $(BINDIR)/$(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


# Liaison

$(BINDIR)/$(TARGET) : $(OBJECTS)
	@$(LINKER) $(OBJECTS) ${LIBS} ${INCS} ${FLAGS} -o $@
	@echo "Liaison OK"


# Compilation des objets

$(OBJDIR)/affichage.o : $(SRCDIR)/affichage.c
	${CC} -o $(OBJDIR)/affichage.o -c $(SRCDIR)/affichage.c ${LIBS} ${INCS} ${FLAGS}

$(OBJDIR)/fonctions_jeu.o : $(SRCDIR)/fonctions_jeu.c
	${CC} -o $(OBJDIR)/fonctions_jeu.o -c $(SRCDIR)/fonctions_jeu.c $(FLAGS2)

$(OBJDIR)/fonctions_joueur.o : $(SRCDIR)/fonctions_joueur.c
	${CC} -o $(OBJDIR)/fonctions_joueur.o -c $(SRCDIR)/fonctions_joueur.c $(FLAGS2)

$(OBJDIR)/mains.o : $(SRCDIR)/mains.c
	${CC} -o $(OBJDIR)/mains.o -c $(SRCDIR)/mains.c $(FLAGS2)

$(OBJDIR)/ordinateur.o : $(SRCDIR)/ordinateur.c
	${CC} -o $(OBJDIR)/ordinateur.o -c $(SRCDIR)/ordinateur.c $(FLAGS2) -std=c99

$(OBJDIR)/main.o : $(SRCDIR)/main.c
	${CC} -o $(OBJDIR)/main.o -c $(SRCDIR)/main.c $(FLAGS2) -std=c99


.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Nettoyage OK"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Suppression des executables"
