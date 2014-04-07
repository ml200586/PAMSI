__start__: obj program6
	./program6

obj:
	mkdir obj

program6: obj/main.o
	g++ -Wall -o program6 obj/main.o

obj/main.o: src/main.cpp inc/tab_asocjacyjna.hh 
	g++ -c -Wall -pedantic -iquote inc -o obj/main.o src/main.cpp
		
clean:
	rm -f program6 core obj/*
