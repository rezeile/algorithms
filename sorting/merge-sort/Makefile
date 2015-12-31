all: sort-client-ip sort-client-aux sort-client-aip
sort-client-ip: merge-ip.hh sort-client-ip.cc
	g++ -o sort-client-ip sort-client-ip.cc
sort-client-aux: merge-aux.hh sort-client-aux.cc
	g++ -o sort-client-aux sort-client-aux.cc
sort-client-aip: merge-aip.hh sort-client-aip.cc
	g++ -o sort-client-aip sort-client-aip.cc
clean:
	rm sort-client-aip sort-client-aux sort-client-ip
rm:
	rm *~ .*~
