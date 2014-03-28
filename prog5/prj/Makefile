__start__: obj program5
	./program5

obj:
	mkdir obj

program5: obj/main.o obj/funkcje.o obj/sortowanie.o
	g++ -Wall -o program5 obj/main.o obj/funkcje.o obj/sortowanie.o

obj/main.o: src/main.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/funkcje.o: inc/funkcje.hh src/funkcje.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/funkcje.o src/funkcje.cpp

obj/sortowanie.o:  inc/sortowanie.hh src/sortowanie.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/sortowanie.o src/sortowanie.cpp

clean:
	rm -f program5 core obj/*
