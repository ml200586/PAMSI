__start__: obj program7
	./program7

CPPFLAGS=-Wall -pedantic -Iinc -c
LDFLAGS=-Wall


obj:
	mkdir obj

program7: obj/main.o obj/bst.o obj/funkcje.o obj/tabhash.o
	g++ ${LDFLAGS} -o program7 obj/main.o obj/bst.o obj/funkcje.o obj/tabhash.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/bst.o: src/bst.cpp inc/bst.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/bst.o src/bst.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/funkcje.o src/funkcje.cpp

obj/tabhash.o: src/tabhash.cpp inc/tabhash.hh
	g++ -c -Wall -pedantic -g -Iinc -o obj/tabhash.o src/tabhash.cpp	

clean:
	rm -f program7 obj/* core*
