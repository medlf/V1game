CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lm -L -lgame
CPPFLAGS =-I ../include
EXEC=net_text
OBJETS=net_text.o game.o game_io.o

all : $(EXEC)
	./$(EXEC)

net_text : $(OBJETS)  
	$(CC) -o net_text $(OBJETS) $(LDFLAGS)

net_text.o : net_text.c game.h game_io.h
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

libgame.a : game.o game_io.o 
	ar rcs libgame.a game.o game_io.o 

.PHONY : clean
clean : 
	rm -f $(EXEC) $(EXEC).o
