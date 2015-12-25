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
 #include "insertion.hh"
 
 static void printVector(std::vector<int> elems) {
  std::cout << "[";
  for(int i = 0; i < elems.size(); i++) {
    if(i != elems.size() - 1) std::cout << elems[i] << ",";
    else std::cout << elems[i];
  }
  std::cout << "]" << std::endl;
 }

 int main(int argc, char *argv[]) {
   int arr[3] = {1000,10000,100000};
   for(int j = 0; j < 3; j++) {
      std::vector<int> v;
      for(int i = 0; i < arr[j]; i++) {
        v.push_back(rand() % arr[j] + 1);
      }
      std::cout << "Element count: " << arr[j] << std::endl;
      std::clock_t start;
      start = std::clock();
      InsertionSort(v);
      double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
      std::cout << "Duration: " << duration << " seconds." << std::endl;
   }
   return 0;
 }

