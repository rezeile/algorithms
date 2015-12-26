 #include <vector>
 
 /*
  * A utility function to print out a vector of elements.
  */
 template<typename T>
 void printVector(std::vector<T> elems) {
  std::cout << "[";
  for(int i = 0; i < elems.size(); i++) {
    if(i != elems.size() - 1) std::cout << elems[i] << ",";
    else std::cout << elems[i];
  }
  std::cout << "]" << std::endl;
 }

 /* 
  * A simple utitlity function that takes a vector of elements by 
  * reference and swaps the elements at the provided indices i and
  * j.
  */
 template<typename T>
 void swap(std::vector<T> &elems, const int i, const int j) {
 	T temp = elems[i];
 	elems[i] = elems[j];
 	elems[j] = temp;
 }