__start__: obj program3
	./program3

obj:
	mkdir obj

program3: obj/main.o obj/funkcje.o obj/stos.o obj/stos_list.o obj/kolejka_list.o obj/kolejka.o
	g++ -Wall -o program3 obj/main.o obj/funkcje.o obj/stos.o obj/stos_list.o obj/kolejka_list.o obj/kolejka.o

obj/main.o: src/main.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/funkcje.o: inc/funkcje.hh src/funkcje.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/funkcje.o src/funkcje.cpp

obj/stos.o: inc/stos.hh src/stos.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/stos.o src/stos.cpp
	
obj/stos_list.o:  inc/stos_list.hh src/stos_list.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/stos_list.o src/stos_list.cpp
	
obj/kolejka_list.o:  inc/kolejka_list.hh src/kolejka_list.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/kolejka_list.o src/kolejka_list.cpp
	
obj/kolejka.o:  inc/kolejka.hh src/kolejka.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/kolejka.o src/kolejka.cpp
	
clean:
	rm -f program3 core obj/*
