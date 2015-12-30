## Implementation of classic algorithms in C++

Author: Eliezer Abate
Last Edit: Dec 30 14:23 PST

#### Brief Description

The following is an implementation of common sorting, searching, string, and 
graph algorithms in C++. The list of algorithms below are found in the 
appendix section in Robert Segewick and Kevin Wayne's Introduction to 
Algorithms (Third Edition) on page 954.

Each class of algorithms is located within its own directory. For example within
the sorting directory, one can find the directories, 'quick-sort', 'merge-sort',
and 'insertion-sort', among others. And withing these sub-directories, the 
algorithm is implemented in a C++ header file (.hh), and there is usually one
or more client files that provide a basic test case for the algorithm.

#### Finished Implementations

##### Sorting

- selection sort 
- insertion sort [tutorial on eliezerabate.com as well]
- shell sort
- top down merge sort (abstract in place, auxillary)
- quick sort
- heap sort

#### TODO

##### Sorting 

- bottom up merge sort
- 3-way partioning quick sort

##### Symbol Tables

- sequential search 
- binary search
- binary tree search
- red-black bst search
- hasing with separate chaining
- hasing with linear probing

##### Graphs

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

##### Strings

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


