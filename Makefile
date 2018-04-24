all: main.o ED.o
	g++ main.o ED.o -o ED  -lsfml-system -g

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic -lsfml-system -g

ED.o: ED.cpp ED.hpp
	g++ -c ED.cpp -Wall -Werror -ansi -pedantic -g

clean: 
	rm *.o ED
