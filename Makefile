dict1: dict1.o entry.o
	gcc bin/dict1.o bin/entry.o -o bin/dict1 -Wall -g

dict1.o: dict1.c entry.h
	gcc dict1.c -o bin/dict1.o -c -Wall -g

entry.o: entry.c entry.h
	gcc entry.c -o bin/entry.o -c -Wall -g
