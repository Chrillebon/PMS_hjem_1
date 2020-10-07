CC=gcc
CPPFLAGS=
CCFLAGS=-Wall -std=c99
LDFLAGS=
LDLIBS=


SOURCES=
OBJECTS=
TARGET=
.PHONY: all

all: clean testing

clean:
	rm -f testing *.o
testing:
