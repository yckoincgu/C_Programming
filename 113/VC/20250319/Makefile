# Makefile
BIN = decimal_to_binary
SOURCES = decimal_to_binary_main.c decimal_to_binary_transfer.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -g3 -Wall

ALL: $(BIN)

$(BIN): $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(BIN)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@


clean:
	rm -f $(BIN) $(OBJECTS)
