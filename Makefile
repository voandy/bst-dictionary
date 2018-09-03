dict1: main.o record.o bst.o
	gcc bin/dict1.o bin/record.o bin/bst.o -o dict1 -Wall -g

main.o: main.c record.h bst.h
	gcc main.c -o bin/dict1.o -c -Wall -g

record.o: record.c record.h
	gcc record.c -o bin/record.o -c -Wall -g

bst.o: bst.c bst.h record.h
	gcc bst.c -o bin/bst.o -c -Wall -g
