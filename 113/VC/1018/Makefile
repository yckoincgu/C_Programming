ODIR=output
$(ODIR):
	mkdir -p $(ODIR)

OBJECTS=hellomake.o hellofunc.o

hellomake.o:hellomake.c	
	gcc -c -o output/hellomake.o hellomake.c 
hellofunc.o:hellofunc.c	
	gcc -c -o output/hellofunc.o hellofunc.c 

hellomake:$(OBJECTS)
	gcc -o output/hellomake output/$(OBJECTS) 
	