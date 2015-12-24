/*
 * An implementation of the selection sort algorithm in C++. The algorithm works for all 
 * inputs for which the comparison operator (<, >) is defined. This algorithm proceeds
 * by finding the smallest item from a set of integers and then placing it at the smallest
 * index position, and then finding the next smallest integer and placing it at index
 * position (smallest + 1), and so forth. Consider the following illustration, where where
 * we want to sort the following array of integers:
 *
 *
 * Index Position
 *   1   2   3   4
 *   -   -   -   -
 * | 8 | 6 | 4 | 2 |
 *
 * On the first run the algorith identifies the smallest element, namely 2, and then proceeds
 * to swap the element at 2's index (4) with index 1. Thus we have:
 *
 * Index Position
 *   1   2   3   4
 *   -   -   -   -
 * | 2 | 6 | 4 | 8 |
 *
 * Note that index 1 and 4 have been swapped and we know, for sure, that the smallest index 
 * contains the smallest element. We now move on to index 2 and we procced by placing the next
 * smallest integer at that index. This entails that we swap the elements at positions 2 and 3.
 * Thus, we have:
 *
 *
 * Index Position
 *   1   2   3   4
 *   -   -   -   -
 * | 2 | 4 | 6 | 8 |
 *
 *
 * Note that even though our array appears to be sorted in this position, we still need to search
 * the remaining indices, namely indices 3 through 4 to make sure that the smallest element is 
 * indeed placed at the right position. This means the search is indeed required, but we can do 
 * without the swap.
 */

#ifndef _SELECTION_H
#define _SELECTION_H

#include <vector> 
#include <functional> /* for what? */

template<typename T>
void SelectionSort(std::vector<T> &elems, )


#endif
 
