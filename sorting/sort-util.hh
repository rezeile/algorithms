 #include <vector>

 /* swaps the elements at index i and j */
 template<typename T>
 static void swap(std::vector<T> &elems, const int i, const int j) {
 	T temp = elems[i];
 	elems[i] = elems[j];
 	elems[j] = temp;
 }