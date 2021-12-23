run: main
	./main

main: main.o lista.o
	gcc lista.o main.o -o main

main.o: main.c
	gcc -c main.c

lista.o: lista.h lista.c
	gcc -c lista.c

clean: lista.o lista.c
	rm lista.o
	rm main.o