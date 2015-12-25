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
   std::vector<int> v;
   for(int i = 10; i >= 1; i--) {
     v.push_back(i);
   }
   std::cout << "Before InsertionSort" << std::endl;
   printVector(v);
   std::cout << "After InsertionSort" << std::endl;
   InsertionSort(v);
   printVector(v);
   return 0;
 }

