# Makefile
TARGET = EX1018
SOURCES = EX1018_1.c lib_test.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -g3 -lglfw -lGL -lm

all:
    @echo $(SOURCES) 

$(TARGET): $(OBJECTS)
        gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c
        gcc $(CFLAGS) -c $< -o $@


#clean:
#        rm -f $(TARGET) $(OBJECTS)