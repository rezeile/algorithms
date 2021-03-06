/*
 * A comprehensive sort-client which executes sorting algorithms on various
 * inputs of integer arrays and prints out statistics pertaining to the runtime
 * of the algorithms.
 *
 * Author: Eliezer Abate
 * Last Updated: Dec 23 11:26 (PST)
 */
 #include <iostream>
 #include <vector>
 #include <ctime>
 #include <cstdlib>
 #include "shell.hh"
 #include "../sort-util.hh"
 
 int main(int argc, char *argv[]) {
   int arr[3] = {10,10,10};
   for(int j = 0; j < 3; j++) {
      std::vector<int> v;
      for(int i = 0; i < arr[j]; i++) {
        v.push_back(rand() % arr[j] + 1);
      }
      std::cout << "Element count: " << arr[j] << std::endl;
      std::clock_t start;
      start = std::clock();
      printVector(v);
      ShellSort(v);
      double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
      std::cout << "Duration: " << duration << " seconds." << std::endl;
      printVector(v);
   }
   return 0;
 }

