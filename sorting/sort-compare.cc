/*
 * A program that compares various sorting algorithms 
 */

 #include <ctime>                                        /* for std::clock_t and std::clock() */
 #include <cstdlib>						                           /* for rand() */
 #include <vector>
 #include <string>                                       /* for std::string and std::stoi(...) */
 #include "merge-sort/merge-aip.hh"                      /* for MergeSortAIP */
 #include "merge-sort/merge-ip.hh"                       /* for MergeSortIP */
 #include "merge-sort/merge-aux.hh"                      /* for MergeSortAUX */
 #include "insertion-sort/insertion.hh"                  /* for InsertionSort */
 #include "selection-sort/selection.hh"                  /* for SelectionSort */
 #include "shell-sort/shell.hh"                          /* for ShellSort */
 #include "quick-sort/quick.hh"                          /* for QuickSort */
 #include "heap-sort/heap.hh"                            /* for HeapSort */
 #include "bubble-sort/bubble.hh"
 #include <iostream> 					                           /* for std::cout */

 /* 
  * global string array of functions 
  */
 std::string funcs[9] = {"Selection","Insertion","Shell","MergeAIP", "MergeAUX","Quick","Heap","MergeIP","Bubble"};
 
 /* 
  * utitlity function that executes the passed function
  * and then gets its time.
  */
 double getDuration(std::string s, int n) {
  std::cout << "Algorithm: " << s << std::endl;
 	/* generate random int array of size n */
 	std::vector<int> v;
 	for(int i = 0; i < n; i++) {
 		v.push_back((rand() % n) + 1); /* random value 1 through n, inclusive */
 	}
 	std::clock_t start; 
 	double duration;
 	if(s.compare(funcs[0]) == 0) {
 		start = std::clock();
 		SelectionSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
 	} else if (s.compare(funcs[1]) == 0) {
 		start = std::clock();
 		InsertionSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
 	} else if (s.compare(funcs[2]) == 0) {
 		start = std::clock();
 		ShellSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
 	} else if (s.compare(funcs[3]) == 0) {
 		start = std::clock();
 		MergeSortAIP(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
 	} else if (s.compare(funcs[4]) == 0) {
    start = std::clock();
    MergeSortAUX(v);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
  } else if (s.compare(funcs[5]) == 0) {
    start = std::clock();
    QuickSort(v);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
  } else if (s.compare(funcs[6]) == 0) {
    start = std::clock();
    HeapSort(v);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
  } else if (s.compare(funcs[7]) == 0) {
    start = std::clock();
    MergeSortIP(v);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
  } else if (s.compare(funcs[8]) == 0) {
    start = std::clock();
    BubbleSort(v);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "Time for " << s << " is: " << duration << " seconds." << std::endl;
  }
 	return duration;
 }
 
 int main(int argc, char *argv[]) {
 	if(argc != 4) {
 		std::cout << "Too few arguments!" << std::endl;
 		exit(0);
 	}
    std::string s1(argv[1]);
    std::string s2(argv[2]);
    std::string num(argv[3]);
    int n = std::stoi(num);
    double time1 = getDuration(s1, n);
    double time2 = getDuration(s2, n);
    std::cout << "For " << n << " integers " << s1 << " is: " << std::endl;
    std::cout << time2/time1 << " faster than " << s2 << std::endl;
 	return 0;
 }
