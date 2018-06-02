CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -g -Iinclude -c -o

main:
   
	$(CC) $(CFLAGS) bin/queueADT.o src/queueADT.c  
	$(CC) $(CFLAGS) bin/LinkedListAPI.o src/LinkedListAPI.c 
	$(CC) $(CFLAGS) bin/main.o src/main.c
	$(CC) bin/main.o bin/queueADT.o bin/LinkedListAPI.o -o bin/runMe

cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude src/*.c -i ./include


doxy: Doxyfile
	doxygen

clean:
	rm bin/*.o bin/runMe

