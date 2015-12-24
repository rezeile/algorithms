#include <vector>
#include <iostream>
#include "selection-int.hh"

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
  std::cout << "Before SelectionSort" << std::endl;
  printVector(v);
  std::cout << "After SelectionSort" << std::endl;
  SelectionSort(v);
  printVector(v);
  return 0;
}
