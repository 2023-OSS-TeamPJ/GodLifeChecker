Checker : main.c crud.o evaluate.o
	gcc -o Checker main.c crud.o evaluate.o
clean:
	rm *.o Checker
