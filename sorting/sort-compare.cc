/*
 * A program that compares various sorting algorithms 
 */

 #include <ctime>                       /* for std::clock_t and std::clock() */
 #include <cstdlib>						/* for rand() */
 #include <vector>
 #include <string>                      /* for std::string and std::stoi(...) */
 #include "merge-sort/merge.hh"         /* for MergeSort */
 #include "insertion-sort/insertion.hh" /* for InsertionSort */
 #include "selection-sort/selection.hh" /* for SelectionSort */
 #include "shell-sort/shell.hh"         /* for ShellSort */
 #include <iostream> 					/* for std::cout */

 /* 
  * global string array of functions 
  */
 std::string funcs[4] = {"Selection","Insertion","Shell","Merge"};
 
 /* 
  * utitlity function that executes the passed function
  * and then gets its time.
  */
 double getDuration(std::string s, int n) {
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
 	} else if (s.compare(funcs[1]) == 0) {
 		start = std::clock();
 		InsertionSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
 	} else if (s.compare(funcs[2]) == 0) {
 		start = std::clock();
 		ShellSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
 	} else if (s.compare(funcs[3]) == 0) {
 		start = std::clock();
 		MergeSort(v);
 		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
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
    std::cout << "Time for " << s1 << " is: " << time1 << " seconds." << std::endl;
    std::cout << "Time for " << s2 << " is: " << time2 << " seconds." << std::endl;
    std::cout << "For " << n << " integers " << s1 << " is: " << std::endl;
    std::cout << time2/time1 << " faster than " << s2 << std::endl;
 	return 0;
 }