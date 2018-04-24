all:
	gcc *.c -o main -Wall -std=c99 -lm -I.
	
run:
	./main

debug:
	gcc *.c -o main -Wall -I. -v -g -lm
	valgrind --leak-check=full --show-leak-kinds=all -v ./main