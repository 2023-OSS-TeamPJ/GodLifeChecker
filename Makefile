Checker : main.c crud.o evaluate.o
	gcc -o Checker main.c crud.o evaluate.o
crud.o : crud.c crud.h
	gcc -c crud.c -o crud.o
evaluate.o : evaluate.c evaluate.h
	gcc -c evaluate.c -o evaluate.o
clean:
	rm *.o Checker
