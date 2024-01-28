SRC = add.o sub.o test.o

test:${SRC}
	gcc add.o sub.o test.o -o test
add.o:add.c
	gcc -c add.c -o add.o
sub.o:sub.c
	gcc -c sub.c -o sub.o
test.o:test.c
	gcc -c test.c -o test.o

.PHONY:clean
clean:
	rm *.o
