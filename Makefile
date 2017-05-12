CC = gcc
CFLAGS = -Wall -g -O2 -fPIC

all: libmylib.so tlstest

libmylib.so: libmylib.o
	$(CC) -o $@ $^ -shared

tlstest: tlstest.o
	$(CC) -L. -Wl,-rpath=. -o $@ $^ -lpthread -lmylib

clean:
	rm -f *.o
	rm -f tlstest
	rm -f libmylib.so
