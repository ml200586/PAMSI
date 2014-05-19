__start__: obj program8
	./program8

obj:
	mkdir obj

program8: obj/main.o obj/adt.o 
	g++ -Wall -o program8 obj/main.o obj/adt.o

obj/main.o: src/main.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/adt.o: inc/adt.hh src/adt.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/adt.o src/adt.cpp



clean:
	rm -f program8 core obj/*
