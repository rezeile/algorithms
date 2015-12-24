/* 
 * Attept at generic selection sort.
 */

 #include <vector>
 #include <iostream>
 
 static bool compare(int a, int b) {
 	return a < b;
 }
 
 static void printVector(std::vector<int> elems) {
  std::cout << "[";
  for(int i = 0; i < elems.size(); i++) {
    if(i != elems.size() - 1) std::cout << elems[i] << ",";
    else std::cout << elems[i];
  }
  std::cout << "]" << std::endl;
 }

 template<typename T, typename Comparator>
 void SelectionSort(std::vector<T> &elems, Comparator comp) {
 	/* find 'best fit' element according to the comp function */
 	for(int i = 0; i < elems.size(); i++) {
 		T best = i;
 		for(int j = i + 1; j < elems.size(); j++) {
 			if(comp(elems[j],elems[best])) {
 				best = j;
 			}
 		}
 		/* swap if necessary */
 		if(best != i) {
 			std::cout << "best: " <<best << std::endl;
 			T temp = elems[i];
 			elems[i] = elems[best];
 			elems[best] = temp;
 		}
 	}
 }

 int main(int argc, char *argv[]) {
 	std::vector<int> v;
    for(int i = 10; i >= 1; i--) {
      v.push_back(i);
    }
 	printVector(v);
 	SelectionSort(v,compare);
 	printVector(v);
 	return 0;
 }