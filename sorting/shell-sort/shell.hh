/* 
 * An implementation of the shell sort algorithm, which is a 
 * generalization of insertion sort. The main advantage of 
 * shell sort over insertion sort is that swaps do not need
 * to occur on elements that are next to each other. Choosing
 * some h, we can first sort a subsequnce of elements that
 * are a distance h apart and then eventually perform insertion
 * sort on a sequence that is mostly sorted (Recall that 
 * insertion sort takes O(n) time on an array that is sorted).
 *
 *
 * Author: Eliezer Abate
 * Last Edited: Dec 25 2015 14:08
 */
 
 #include <functional> /* for std::less<T>() */
 #include <vector>
 #include "../sort-util.hh" /* for swap */

 /* 
  * function: ShellSort
  * -----------------------
  * Implementation of insertion sort algorithm.
  */
 template<typename T, typename Comparator>
 void ShellSort(std::vector<T> &elems, Comparator comp) {
 	int N = elems.size();
 	int h = 1;
 	/** chose an appropriate h **/
 	while(h < N/3) h = 3*h + 1; /* note that we want h to reach 1 eventually 
 								 * so we choose 3*h % 3 = 1 */
 	while(h >= 1) {
 		for(int i = h; i < N; i++) {
 			for(int j = i + 1; j > 0 && comp(elems[j], elems[j - h]); j -= h) 
 				swap(elems,j - h,j);
 		}
 		h = h / 3;
 	}
 }

 /* 
  * Insertion sort without a comparator function. Uses the 
  * above implementation to default using std::less
  */
  template<typename T>
  void ShellSort(std::vector<T> &elems) {
  	ShellSort(elems,std::less<T>());
  }




