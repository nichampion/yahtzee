NOMPROJET = Yahtzee

CC = gcc

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

DIRS	 = $(OBJDIR) $(BINDIR) 

.PHONY: DIRS
all: $(DIRS) $(BINDIR)/$(NOMPROJET)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(NOMPROJET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Edition des liens effectuee"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation "$<" reussie"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Nettoyage effectue"

.PHONY: remove
	
remove: clean
	@$(rm) $(BINDIR)/$(NOMPROJET)
	@echo "Suppression de l'executable"

