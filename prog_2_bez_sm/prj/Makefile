__start__: obj program1
	./program1

obj:
	mkdir obj

program1: obj/main.o obj/funkcje.o 
	g++ -Wall -o program1 obj/main.o obj/funkcje.o

obj/main.o: src/main.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/funkcje.o: inc/funkcje.hh src/funkcje.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/funkcje.o src/funkcje.cpp



clean:
	rm -f uzytkownicy core obj/*
