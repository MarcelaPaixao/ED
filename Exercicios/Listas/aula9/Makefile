run:
	make compile
	./prog < entrada.txt

compile:
	gcc -o prog *.c 

valgrind:
	make compile
	valgrind --leak-check=full -s --track-origins=yes  ./prog < entrada.txt

all:
	make valgrind