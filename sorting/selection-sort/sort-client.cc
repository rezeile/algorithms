/*
 * A comprehensive sort-client which executes sorting algorithms on various
 * inputs of integer arrays and prints out statistics pertaining to the runtime
 * of the algorithms.
 *
 * Author: Eliezer Abate
 * Last Updated: Dec 23 11:26 (PST)
 */
 #include <iostream>

 enum Algorithm {
   SelectionSort,
   InsertionSort,
   ShellSort,
   MergeSort
 };

 enum Ordering {
   Random,
   Sequential
 };

 int main(int argc, char *argv[]) {
 	int kDefaultAlgorithm = -1; /* all */
  int kDefaultArrayLength = 1024;
  int kDefaultFrequency = 3; /* three doublings 1024 2048 2096 */
  int kDefualtOrdering = 0; /* random */
  if (argc != 9) {
    std::cerr << "[usage]: ";
    std::cerr << "./sort-client -a algorithm -n array-length ";
    std::cerr << "-f doubling-frequency -o ordering" << std::endl;
    exit(0);
  }
 }

