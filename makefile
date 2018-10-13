compile: player.o list.o test.o
	gcc test.o

run:
	./a.out

player.o:
	gcc -c player.c

list.o:
	gcc -c list.c

test.o:
	gcc -c test.c

clean:
	-rm -f *.o a.out
