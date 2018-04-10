CXXFLAGS= -g -Iinc -Wall -pedantic -std=c++11

__start__:sortowanie
	./sortowanie 



sortowanie: obj obj/main.o  obj/szybki.o obj/scalanie.o obj/kontener.o
           
	g++ -Wall -pedantic -std=c++11 -o sortowanie  obj/main.o  obj/szybki.o obj/scalanie.o obj/kontener.o
                      
obj/kontener.o: src/kontener.cpp inc/kontener.hh 
	g++ -c ${CXXFLAGS} -o obj/kontener.o src/kontener.cpp

obj/szybki.o: src/szybki.cpp inc/kontener.hh inc/szybki.hh
	g++ -c ${CXXFLAGS} -o obj/szybki.o src/szybki.cpp

obj/main.o: src/main.cpp  inc/szybki.hh inc/scalanie.hh inc/kontener.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/scalanie.o: src/scalanie.cpp inc/scalanie.hh inc/kontener.hh
	g++ -c ${CXXFLAGS} -o obj/scalanie.o src/scalanie.cpp

