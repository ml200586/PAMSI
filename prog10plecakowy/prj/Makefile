__start__: obj program10
	./program10

obj:
	mkdir obj

program10: obj/main.o obj/plecak.o 
	g++ -Wall -o program10 obj/main.o obj/plecak.o

obj/main.o: src/main.cpp 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp

obj/plecak.o: inc/plecak.hh src/plecak.cpp
	g++ -c -Wall -pedantic -iquote inc -o obj/plecak.o src/plecak.cpp



clean:
	rm -f program10 core obj/*
