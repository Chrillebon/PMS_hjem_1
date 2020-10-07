CC=gcc
CPPFLAGS=
CCFLAGS=-Wall -std=c99
LDFLAGS=
LDLIBS=


SOURCES=
OBJECTS=
TARGET=
.PHONY: all

all: running clean

running: testing.o

clean:
	rm -f testing *.o
