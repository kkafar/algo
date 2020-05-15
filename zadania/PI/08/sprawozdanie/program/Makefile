# -*- MakeFile -*-

main: main.o uti.o
	gcc -o main main.o uti.o

main.o: main.c uti.h
	gcc -Wall -c -o main.o main.c

uti.o: uti.c uti.h
	gcc -Wall -c -o uti.o uti.c

run:
	./main

clean:
	rm -f *.o

valgrind_run:
	gcc -Wall -O0 -o main main.c uti.c
	valgrind --leak-check=yes ./main