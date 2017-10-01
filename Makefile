CC = gcc
CFLAGS = -c -fPIC
CDEPENDENCIES = -lm
CLIBFLAGS = -shared -W -o
#OBJECTS = libpower.so #libcomponent.so libcalc.so

#all: program1

#program1: $(OBJECTS)
	#$(CC) $(OBJECTS) -o program1

#TODO lib: $(OBJECTS)
#	$(CC) $(OBJECTS) $(CLIBS)

#TODO: main.o: main.c main.h
#TODO: $(CC) $(CFLAGS) main.c main.h

libpower: power.o
	$(CC) $(CLIBFLAGS) libpower.so power.o

power: power.c power.h
	$(CC) $(CFLAGS) power.c power.h $(CDEPENDENCIES)

#TODO: libcomponent: libcomponent.o
#TODO: $(CC) $(CLIBFLAGS) libcomponent.so libcomponent.o

component: libcomponent.c libcomponent.h
	$(CC) $(CFLAGS) libcomponent.c libcomponent.h $(CDEPENDENCIES)

#TODO: libcalc: libcalc.o
#TODO	$(CC) $(CLIBFLAGS) libcalc.so libcalc.o

calc: calc.c calc.h
	$(CC) $(CFLAGS) calc.c calc.h

#install:
#sudo cp ./program1 /usr/local/bin/program1

clean:
	rm -f *.gch *.o *.so *.exe
