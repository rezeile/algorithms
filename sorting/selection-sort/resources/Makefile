all: enum-c enum-cc compare compare2
compare2: compare2.cc
	g++ -o compare2 compare2.cc
compare: compare.cc
	g++ -o compare compare.cc
enum-c: enum.c
	gcc -o enum-c enum.c
enum-cc: enum.cc
	g++ -o enum-cc enum.cc
clean:
	rm enum-c enum-cc
rm:
	rm *~ .*~
