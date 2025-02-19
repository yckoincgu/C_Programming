ODIR=output
$(ODIR):
	mkdir -p $(ODIR)

OBJECTS=hellomake.o hellofunc.o

hellomake.o:hellomake.c	
	gcc -c hellomake.c -o output/hellomake.o  
hellofunc.o:hellofunc.c	
	gcc -c hellofunc.c -o output/hellofunc.o  

hellomake:$(OBJECTS)
	gcc -o output/hellomake output/$(OBJECTS) 
	