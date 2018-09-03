dict1: main.o record.o bst.o
	gcc bin/dict1.o bin/record.o bin/bst.o -o dict1 -Wall -g

dict2: main.o record.o llist.o bst2.o
	gcc bin/dict1.o bin/record.o bin/llist.o bin/bst2.o -o dict2 -Wall -g

main.o: main.c record.h bst.h
	gcc main.c -o bin/dict1.o -c -Wall -g

record.o: record.c record.h
	gcc record.c -o bin/record.o -c -Wall -g

bst.o: bst.c bst.h record.h
	gcc bst.c -o bin/bst.o -c -Wall -g

llist.o: llist.c llist.h record.h
	gcc llist.c -o bin/llist.o -c -Wall -g

bst2.o: bst2.c bst2.h record.h llist.h
	gcc bst2.c -o bin/bst2.o -c -Wall -g
