all: sort-compare
dep1: bubble-sort/bubble.hh insertion-sort/insertion.hh
dep2: quick-sort/quick.hh shell-sort/shell.hh
dep3: heap-sort/heap.hh merge-sort/merge-aip.hh
dep4: selection-sort/selection.hh merge-sort/merge-aux.hh
dep5: merge-sort/merge-ip.hh
sort-compare: $(dep1) $(dep2) $(dep3) $(dep4) $(dep5) sort-compare.cc
	g++ -std=c++11 -o sort-compare sort-compare.cc
clean:
	rm sort-compare
rm:
	rm *~ .*~
