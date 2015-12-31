/*
 * An implementation of the bubble sort algorithm.
 */

#ifndef _BUBBLE_HH
#define _BUBBLE_HH

#include <vector> 
#include <functional> /* std::less<T> */
#include "../sort-util.hh" /* for swap */

/* 
 * function: BubbleSort(elems,comp);
 * ---------------------------------
 * templetized implementation of the bubble sort algorithm, 
 * which sorts an array of elements according to an ordering
 * directed by the user-specified comp function.
 */
template<typename T, typename Comparator>
void BubbleSort(std::vector<T> &elems, Comparator comp) {
 	/* note we start at the second to last index element */
 	for(int i = elems.size() - 2; i >= 0; i--) {
 		for(int j = 0; j <= i; j++) {
 			if(comp(elems[j + 1], elems[j]))
 				swap(elems,j+1,j);
 		}
 	}
}


/*
 * Uses the above implementation to invoke the default version of a 
 * call to BubbleSort (i.e. without the user specifying a comparator
 * function.)
 */
template<typename T>
void BubbleSort(std::vector<T> &elems) {
	BubbleSort(elems,std::less<T>());
}


#endif
 
