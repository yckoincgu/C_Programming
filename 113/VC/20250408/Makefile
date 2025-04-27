# Makefile
# https://www.youtube.com/watch?v=CRlqU9XzVr4&ab_channel=JacobSorber
BINDIR=bin
SRCDIR=src
OBJDIR=obj
INCDIR =include
DEPDIR =.deps

BIN = $(BINDIR)/a
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
CFLAGS = -g3 -Wall -I$(INCDIR) 
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d


ALL: $(BIN)

$(BIN):$(OBJECTS)
	@mkdir -p $(BINDIR)  # Ensure the bin directory exists
	gcc $(CFLAGS) $(OBJECTS) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) $(DEPDIR)  # Ensure directories exist
	gcc $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/* $(DEPDIR)/*
