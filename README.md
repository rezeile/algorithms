## Implementation of classic algorithms in C++

Author: Eliezer Abate
Last Edit: Februaryr 11 2019

### Brief Description

The following is an implementation of classic algorithms in C++.

Each class of algorithms is located within its own directory. For example within
the sorting directory, one can find the directories, 'quick-sort', 'merge-sort',
and 'insertion-sort', among others. And withing these sub-directories, the 
algorithm is implemented in a C++ header file (.hh), and there is usually one
or more client files that provide a basic test case for the algorithm.

A ~~strikethrough~~ on a description indicates that it has already been implemented. 
Similarly a description missing a strikethrough is on my TODO list and will be 
implemented at a later date. 

_---_

### Sorting

- ~~selection sort~~
- ~~insertion sort~~
- ~~shell sort~~
- ~~top down merge sort (abstract in place, auxillary)~~
- ~~quick sort~~
- ~~heap sort~~
- ~~in-place merge (w/ merge for right sub-array)~~
- ~~bottom up merge sort~~
- 3-way partioning quick sort
- in-place merge

### Graphs

- depth first search
- breadth first search
- connected components
- reachability
- topological sort
- strong components (Kosaraju)
- minimum spanning tree (Prim)
- minimum spanning tree (Kruskal)
- shortest paths (Dijkstra)
- shortest paths in DAGs
- shortest paths (Bellman Ford)
- articulation points/bridges

### Strings

- LSD string sort
- MSD string sort
- three way string quicksort
- trie symbol table
- TST symbol table
- substring search (Knuth-Morris-Pratt)
- substring search (Boyer-Moore)
- substring search (Rabin-Karp)
- regular expression pattern matching 
- huffman expansion/compression
- lzw compression/expansion

### Dynamic Programming

- rod cutting
- matrix chain multiplication
- longest common subsequence
- optimal binary search tree
- longest simple path in a DAG
- longest palindrome subsequence
- bitonic euclidean TSP
- printing neatly
- edit distance
