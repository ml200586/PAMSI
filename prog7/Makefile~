__start__: obj mnozenie
	./mnozenie

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall



obj:
	mkdir obj

mnozenie: obj/main.o obj/funkcje.o obj/stos_tablica.o obj/stos_lista.o obj/kolejka_tablica.o obj/kolejka_lista.o obj/sortowanie.o
	g++ ${LDFLAGS} -o mnozenie obj/main.o obj/funkcje.o obj/stos_tablica.o obj/stos_lista.o obj/kolejka_tablica.o obj/kolejka_lista.o obj/sortowanie.o

obj/main.o: src/main.cpp 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/funkcje.o src/funkcje.cpp

obj/stos_tablica.o: src/stos_tablica.cpp inc/stos_tablica.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/stos_tablica.o src/stos_tablica.cpp

obj/stos_lista.o: src/stos_lista.cpp inc/stos_lista.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/stos_lista.o src/stos_lista.cpp

obj/kolejka_tablica.o: src/kolejka_tablica.cpp inc/kolejka_tablica.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/kolejka_tablica.o src/kolejka_tablica.cpp

obj/kolejka_lista.o: src/kolejka_lista.cpp inc/kolejka_lista.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/kolejka_lista.o src/kolejka_lista.cpp
	
obj/sortowanie.o: src/sortowanie.cpp inc/sortowanie.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/sortowanie.o src/sortowanie.cpp

clean:
	rm -f mnozenie obj/* core*
