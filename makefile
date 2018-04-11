CXXFLAGS= -Wall -pedantic -std=c++17  -g -Iinc
__start__:sortowanie
	./sortowanie 



sortowanie: obj obj/main.o  obj/szybki.o obj/scalanie.o 
           
	g++ -Wall -pedantic -std=c++11 -o sortowanie  obj/main.o  obj/szybki.o obj/scalanie.o 
                      

obj/szybki.o: src/szybki.cpp  inc/szybki.hpp
	g++ -c ${CXXFLAGS} -o obj/szybki.o src/szybki.cpp 

obj/main.o: src/main.cpp  inc/szybki.hpp inc/scalanie.hpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/scalanie.o: src/scalanie.cpp inc/scalanie.hpp 
	g++ -c ${CXXFLAGS} -o obj/scalanie.o src/scalanie.cpp

