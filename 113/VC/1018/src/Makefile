# Makefile
BIN = hellomake
SOURCES = hellomake.c hellofunc.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -g3 -Wall 	# debugging information; telling the compiler to enable a standard set of warnings about potential issues 
	


$(BIN):$(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(BIN)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

ALL: $(BIN)

clean:
	rm -f $(BIN) $(OBJECTS)
