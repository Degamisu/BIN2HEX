OBJS	= bin2hex.o
SOURCE	= bin2hex.c
HEADER	= stdlib.h stdio.h
OUT	= 
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bin2hex.o: bin2hex.c
	$(CC) $(FLAGS) bin2hex.c 


clean:
	rm -f $(OBJS) $(OUT)
