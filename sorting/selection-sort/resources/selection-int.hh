/*
 * Selection sort algorith that sorts n integers. The algorithm expects to 
 * receive an std::vector<int> of integers. 
 *
 * Author: Eliezer Abate
 * Last Edit: Wed Dec 23 11:03
 */

 #ifndef _SELECTION_INT_HH
 #define _SELECTION_INT_HH

 /*
  * function: SelectionSort
  * -----------------------
  * Exports the SelectionSort routine, which sorts a list of integers in 
  * ascending order within the given array. This routine does not use 
  * extra space and has a run time of Theta(n^2).
  */
 void SelectionSort(std::vector<int> &elems) {
 	for(int i = 0; i < elems.size(); i++) {
 		/* find smallest element in range i through i - 1 */
 		int smallestIndex = i;
 		for(int j = i + 1; j < elems.size(); j++) {
 			if(elems[j] < elems[smallestIndex])
 				smallestIndex = j;
 		}
 		/* swap elements */
 		if (smallestIndex != i) {
 			int temp = elems[i];
 			elems[i] = elems[smallestIndex];
 			elems[smallestIndex] = temp;
 		}
 	}
 }


 #endif