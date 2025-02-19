# Directories
ODIR = output  # Output directory for object files and executable

# Object files
OBJECTS = hellomake.o hellofunc.o
OBJ = $(addprefix $(ODIR)/,$(OBJECTS))  # Add $(ODIR)/ prefix to object files

# Ensure the output directory exists
#$(ODIR):
#	mkdir -p $(ODIR)

%.o: %.c
	gcc -c $< -o $@

# Rule to link object files into the final executable
hellomake: %.o
	gcc -o $@ $^

#Default target
all: hellomake

# Clean up
#clean:
#	rm -f $(ODIR)/*.o hellomake

# Phony targets
.PHONY: all clean