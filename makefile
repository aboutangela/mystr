all: mystr.o
	gcc -o test mystr.o

mystr.o: mystr.c mystr.h
	gcc -c mystr.c

run:
	./test

clean:
	rm *.o
