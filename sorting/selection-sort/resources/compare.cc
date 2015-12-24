#include <iostream>
#include <vector>
#include <algorithm> /* for sort */

/* function defined in global space */
bool greaterThan(int i, int j) {
	return i > j;
}

static void printVector(const std::vector<int> elems) {
  std::cout << "[";
  for(int i = 0; i < elems.size(); i++) {
    if(i != elems.size() - 1) std::cout << elems[i] << ",";
    else std::cout << elems[i];
  }
  std::cout << "]" << std::endl;
}

/** sort a vector of integers using the standard library */
int main(int argc, char *argv[]) {
	std::vector<int> v;
    for(int i = 10; i >= 1; i--) {
      v.push_back(i);
    }
    std::sort(v.begin(), v.end());
    std::sort(v.begin(), v.end(), greaterThan);
    printVector(v);
	return 0;
}