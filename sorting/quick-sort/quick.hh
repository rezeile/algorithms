/*
 * The program implements the quicksort algorithm. Quicksort is a divide and 
 * conquer algorithm that solves the sorting problem by first partitioning
 * elements into two halves, around a particular pivot. Then the algorithm
 * recursively calls quicksort to sort the two halves. No items or a single
 * item is considered trivially sorted and all others are solves using 
 * recursive calls to quicksort.
 *
 * Consider the following illustration of performing the quicksort partion algorithm
 * on a list of integers in order to arrange them from least to greatest:
 *
 * START 
 * Indices:    1   2   3   4   5   6
 *           |_4_|_9_|_2_|_8_|_3_|_5_|
 *             ^                   ^
 *			   |	               |
 *
 *			   j				 pivot 
 *
 * We choose as the pivot the last element, the element at index 6 which happens
 * to be 5. And we are going to make two partions in-place: one of elements that 
 * are smaller than five and one of elements that are greater than 5. This means
 * that we will need to examine all the integers between indices 1 and 5, inclusive
 * and place them in the appropriate partion. 
 * 
 * We will maintain two pointers: that will keep track of the last element in 
 * the smaller partiton and another pointer that keeps track of the element that
 * is one past the last element of the larger partition. We will refer the former
 * as i and the latter as j. Note that initially we have i at the first index meaning
 * that there is neither a small or a large partition.
 *
 * On our first run of the algorithm, we obtain the following picture of the array. 
 * Note that now i refers to the first element (that is element 4 which is smaller
 * than our pivot 5 is inserted into the smaller partion) and j one past the larger
 * partion (still none).
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_9_|_2_|_8_|_3_|_5_|
 *             ^   ^               ^
 *			   |   |	           |
 *
 *			   i   j		     pivot 
 *
 * On the next run note that our index j shifts to the right (one past the last element
 * of the largest partition) meaning that element 9 is inserted into the larger partition.
 *
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_9_|_2_|_8_|_3_|_5_|
 *             ^       ^           ^
 *			   |       |	       |
 *
 *			   i       j		 pivot 
 *
 * 
 * On the next run notice that we swap the elements at indices 2 and 3, increasing the 
 * smaller partion array by 1. Thus we have [4,2] in the smaller partition and [9] in the
 * larger partition.
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_2_|_9_|_8_|_3_|_5_|
 *                 ^       ^       ^
 *			       |       |	   |
 *
 *			       i       j     pivot 
 * 
 *
 * On this run we note that the element at index 4, namely 8 is larger than our pivot 5
 * and thus we simply shift our pointing index j one position to the right. Thus we have
 * [4,2] in the smaller array and we have a new addition in the larger partion and that array
 * looks like the following: [9,8].
 *
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_2_|_9_|_8_|_3_|_5_|
 *                 ^           ^   ^
 *			       |           |   |
 *
 *			       i           j  pivot 
 *
 * On the last run (last because we needed to evaluate all the elements to the left of the 
 * pivot [indices 1 through 5, inclusive]), we see that the element at index 5, 3, is less
 * than the pivot, which is 5, and thus in this case we swap indices j and i + 1, effectively
 * similating an addition to the end of the smaller partion. We also shift i by 1 to make 
 * it point to the last element which we just added in the smaller partition. Note also that
 * we no longer have our pointing index j.
 *
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_2_|_3_|_8_|_9_|_5_|
 *                     ^           ^
 *			           |           |
 *
 *			           i          pivot 
 *
 * On the final partion we simply swap the element at index + 1 with the element at i + 1. We
 * know this is the appropriate place to place the pivot because all elements 0 through i are
 * smaller than the pivot and all elements i + i through pivot - 1 are larger. Thus the swap 
 * achieves the property whereby the pivot will be smaller than the elements to its right and 
 * larger than the elements to its left.
 *
 * Indices:    1   2   3   4   5   6
 *           |_4_|_2_|_3_|_5_|_9_|_8_|
 *                         ^
 *			               |
 *
 *			              pivot 
 *
 *
 * Thus that completes a full run a single partion step during the quick sort algorithm. 
 *  
 * Author: Eliezer Abate
 * Credit: The visual illustration above was inspired from Chapter 7 of Introduction to 
 *         Algorithms by Cormer, Leiserson, Rivest, and Stein (Third Edition).
 * Last Edit: Dec 27 16:47 PST
 *
 */