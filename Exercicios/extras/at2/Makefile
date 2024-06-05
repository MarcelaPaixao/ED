run:
	make compile
	./prog

compile:
	clear
	gcc -o prog *.c

valgrind:
	clear
	make compile
	valgrind --leak-check=full -s --track-origins=yes  ./prog
