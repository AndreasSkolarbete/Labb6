CC = gcc
CFLAGS = -c -fPIC
CDEPENDENCIES = -lm
CLIBFLAGS = -shared -W -o
LIBOBJECTS = ./libpower.so ./libcomponent.so ./libcalc.so

all: electrotest

electrotest: lib
		$(CC) -Llib $(LIBOBJECTS) electrotest.c $(LIBOBJECTS) $(CDEPENDENCIES) -o electrotest

lib: $(LIBOBJECTS)

libpower.so: power.o
	$(CC) $(CLIBFLAGS) libpower.so power.o

power: power.c power.h
	$(CC) $(CFLAGS) power.c power.h $(CDEPENDENCIES)

libcomponent.so: libcomponent.o
	$(CC) $(CLIBFLAGS) libcomponent.so libcomponent.o

libcomponent: libcomponent.c libcomponent.h
	$(CC) $(CFLAGS) libcomponent.c libcomponent.h $(CDEPENDENCIES)

libcalc.so: calc.o
	$(CC) $(CLIBFLAGS) libcalc.so calc.o

calc: calc.c calc.h
	$(CC) $(CFLAGS) calc.c calc.h

#install:
#sudo cp ./program1 /usr/local/bin/program1

clean:
	rm -f *.gch *.o *.so *.exe *.out electrotest
