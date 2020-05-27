all: main

main: main.o uti.o skiplist.o skiplist_mod.o
	gcc -o main main.o uti.o skiplist.o skiplist_mod.o

main.o: main.c uti.h skiplist.h skiplist_mod.h
	gcc -Wall -c -o main.o main.c

uti.o: uti.c uti.h
	gcc -Wall -c -o uti.o uti.c

skiplist.o: skiplist.c skiplist.h
	gcc -Wall -c -o skiplist.o skiplist.c

skiplist_mod.o: skiplist_mod.c skiplist_mod.h
	gcc -Wall -c -o skiplist_mod.o skiplist_mod.c

run:
	./main

clean:
	rm -f *.o

valgrind_run: 
	gcc -Wall -O0 -o main main.c uti.c skiplist.c skiplist_mod.c
	valgrind --leak-check=yes ./main	