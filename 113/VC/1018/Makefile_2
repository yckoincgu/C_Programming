# Makefile
# https://www.youtube.com/watch?v=CRlqU9XzVr4&ab_channel=JacobSorber

BINDIR=bin
BIN = $(BINDIR)/hellomake
SRCDIR=src
OBJDIR=obj
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
CFLAGS = -g3 -Wall  

ALL: $(BIN)

$(BIN):$(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@



clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
