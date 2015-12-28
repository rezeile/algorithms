all: sort-compare
dependencies1: merge-sort/merge-abstact-inplace.hh insertion-sort/insertion.hh
dependencies2: shell-sort/shell.hh selection-sort/selection.hh
dependencies3: merge-sort/merge-aux.hh quick-sort/quick.hh
sort-compare:  $(dependencies1) $(dependencies2) $(dependencies3)  sort-compare.cc
	g++ -o sort-compare sort-compare.cc
clean:
	rm sort-compare
rm:
	rm *~ .*~
