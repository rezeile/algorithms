all: car.o main.o prog adjlist
car.o: car.cc 
	g++ -std=c++11 -c car.cc
main.o: main.cc
	g++ -std=c++11 -c main.cc
prog:
	g++ -std=c++11 -o prog car.o main.o 
adjlist: adjlist.cc
	g++ -std=c++11 -o adjlist adjlist.cc
clean:
	rm adjlist main prog main.o car.o
