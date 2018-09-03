dict1: main.o entry.o bst.o
	gcc bin/dict1.o bin/entry.o bin/bst.o -o bin/dict1 -Wall -g

main.o: main.c entry.h bst.h
	gcc main.c -o bin/dict1.o -c -Wall -g

entry.o: entry.c entry.h
	gcc entry.c -o bin/entry.o -c -Wall -g

bst.o: bst.c bst.h entry.h
	gcc bst.c -o bin/bst.o -c -Wall -g
