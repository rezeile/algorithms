/* 
 * An implementation of the insertion sort algorithm, which sorts a list
 * of elements in ascending order according to an ordering specified by
 * user via a comparator function, or the default less than operator. 
 * Consider the following illustration of sorting an array of integers 
 * using insertion sort:
 *
 *       Index Position
 *   1   2   3   4   5   6
 * | 9 | 7 | 5 | 3 | 1 | 2 |
 *
 * Insertion sort works by comparing adjacent integers and swapping the 
 * elements, if necessary, in order to place them in the order specified 
 * by a comparison function. So the next stage of the above array would
 * look like the following:
 *
 * First stage (Current Index = 2):
 *
 *       Index Position 
 *   1   2   3   4   5   6
 * | 7 | 9 | 5 | 3 | 1 | 2 |
 *  <----> 
 * Note that 7 and 9 have swapped positions.
 *
 * Next stage (Current Index = 3):
 *
 *       Index Position
 *   1   2   3   4   5   6
 * | 7 | 5 | 9 | 3 | 1 | 2 |
 *       <----> 
 *
 * Next stage (Current Index = 3):
 *
 *       Index Position
 *   1   2   3   4   5   6
 * | 5 | 7 | 9 | 3 | 1 | 2 |
 *   <----> 
 *
 * The important thing to note is the the swapping continues to occur until 
 * all the elements to the left of the current index, including the element
 * at the current index are in sorted order, although they may not be in 
 * their final positions yet. Thus in our case elements at index 1 through 3, 
 * namely, 5, 7, and 9 and in sorted order.
 *     
 *
 * Final Stage:
 *
 *       Index Position
 *   1   2   3   4   5   6
 * | 1 | 2 | 3 | 5 | 7 | 9 |
 *
 *
 *
 * Author: Eliezer Abate
 * Last Edited: Dec 24 2015 16:18
 */
 
 #include <functional> /* for std::less<T>() */
 #include <vector>
 #include "../sort-util.hh" /* for swap */

 /* 
  * function: InsertionSort
  * -----------------------
  * Implementation of insertion sort algorithm.
  */
 template<typename T, typename Comparator>
 void InsertionSort(std::vector<T> &elems, Comparator comp) {
 	for(int i = 0; i < elems.size() - 1; i++) {
    /* since we need at least two elements to 
     * swap we must start at j = i + 1 */ 
 		for(int j = i + 1; j > 0 && comp(elems[j], elems[j - 1]); j--) 
 				swap(elems,j - 1,j);
 	}
 }

 /* 
  * Insertion sort without a comparator function. Uses the 
  * above implementation to default using std::less
  */
  template<typename T>
  void InsertionSort(std::vector<T> &elems) {
  	InsertionSort(elems,std::less<T>());
  }




