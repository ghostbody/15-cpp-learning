all: main.cpp list
	g++ main.cpp list.cpp -o main -g
list:list.hpp list.cpp
	g++ list.hpp list.cpp -g -c
clean:
	rm -f *.o main *.hpp.gch
