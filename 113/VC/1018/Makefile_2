# Makefile
BINDIR=bin
BIN = $(BINDIR)/hellomake
SRCDIR=src
OBJDIR=obj
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
CFLAGS = -g3 -Wall  


$(BIN):$(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@

ALL: $(BIN)

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
