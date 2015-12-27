all: sort-compare
dependencies1: merge-sort/merge.hh insertion-sort/insertion.hh
dependencies2: shell-sort/shell.hh selection-sort/selection.hh
sort-compare:  $(dependencies1) $(dependencies2) sort-compare.cc
	g++ -o sort-compare sort-compare.cc
clean:
	rm sort-compare
rm:
	rm *~ .*~
