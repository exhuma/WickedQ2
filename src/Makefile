# Makefile for Quake 2, gamei386.so
#
# 7 January 1998,  jet@poboxes.com

# The name of your C compiler:
CC=gcc

# You may need to adjust these C options:
#CFLAGS= -O3 -march=i486

#####################################################################

SOURCES=$(shell find . -name '*.c')
OBJS=$(SOURCES:.c=.o)
TARGET=release/gamei386.so

all: ${TARGET}

${TARGET}: $(OBJS)
	mkdir release
	$(CC) -shared -o ${TARGET} $(OBJS) -lm

clean:
	rm -f *.o *~ core

.c.o:
	$(CC) $(CFLAGS) -c $*.c -o $*.o

# end of file
