all: fork.o
	gcc -o test fork.o

fork.o: fork.c
	gcc -c fork.c

run: test
	./test

clean:
	rm *.o
	rm ./test