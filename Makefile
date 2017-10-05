CC = gcc
CFLAGS = -c -fPIC
CDEPENDENCIES = -lm
CLIBFLAGS = -shared -W -o
LIBS = ./libpower.so ./libcomponent.so ./libcalc.so
LIBSGLOBAL = /usr/lib/libpower.so /usr/lib/libcomponent.so /usr/lib/libcalc.so

all: electrotest

electrotest: lib
		$(CC) -Llib $(LIBS) electrotest.c $(LIBS) $(CDEPENDENCIES) -o electrotest

lib: $(LIBS)

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

install: lib
	cp *.so /usr/lib/
	$(CC) -Llib $(LIBSGLOBAL) electrotest.c $(LIBSGLOBAL) $(CDEPENDENCIES) -o electrotest
	cp electrotest /usr/bin/electrotest

clean:
	rm -f *.gch *.o *.so *.exe *.out electrotest
