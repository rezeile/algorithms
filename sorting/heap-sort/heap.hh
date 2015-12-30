/*
 * Implementation of the heapsort algorithm that uses a max heap structure 
 * in order to sort elements in ascending order. The algorithm progresses
 * by first taking an array of items and rearranging them so that they
 * satisfy the max heap property, and once these elements have the heap 
 * property we continually swap the node with the highest value (located
 * at index 1) with the last (and second last, ...) element of our array.
 *
 * Consider the following illustration where we start out with the following
 * array:
 * 
 * Indices:     1  2  3  4  5
 *              -  -  -  -  -
 * Array Form: [3, 8, 2, 7, 4]                    
 *
 * Tree Representation:
 * 
 *                  3
 *                 / \
 *               /     \
 *              8       2
 *             / \       
 *            7   4    
 *
 * We proceed by starting at the right most leaf (the last element) and working
 * backwards to ensure that each node satisfies the max property. The max heap
 * property is a property whereby each node has a higher value than each of its
 * left and right children (if any). For example node 8 in the above diagram 
 * satisfies the max heap property (since its children, 7 and 4, both have lower
 * values that it does), however node 3 does not satisfy the max heap property 
 * (since one of its children, namely node 8 has a higher value than it does).
 *
 * Thus in our code we will have a routine that accepts a node whose its left
 * and right children satisfy the max heap property but the node itself may or 
 * may not. This routine will swap the nodes until the starting node satisfies
 * the heap property. Note that our root node is indexed at 1. Furthermore, for
 * any node i, its left child (if any) is located at the index 2 * i and its 
 * right child is located at index 2 * i + 1. Now to rephrase the first sentence
 * of this paragraph, we would pass our routine, which we will call max-heapify
 * a reference to our array of elements, and an index representing a node, and
 * at the routine's completion, the node at index i will satisfy the max heap 
 * property. 
 *
 * So we will run this max-heapify property starting at the first parent, index 3
 * (value 8), and work backwards on each node index 3 through 1, and at the compl-
 * etion of this phase, the array will satisfy the heap property and look like 
 * the following:
 *
 *
 * Indices:     1  2  3  4  5
 *              -  -  -  -  -
 * Array Form: [8, 7, 2, 3, 4]                    
 *
 * Tree Representation:
 * 
 *                  8
 *                 / \
 *               /     \
 *              7       2
 *             / \       
 *            3   4    
 *
 *
 * Now after our array satsifies the heap property we are sure that the largest node
 * occurs at index 1 in our array (value 8), and we can simply swap it with the last 
 * element. But since our new sub array (index 1 through 3) may not satisfy the heap 
 * property we will need to run our max-heapify routine on the first node. Thus our
 * algorithm for heapsort looks like the following:
 *
 * func heapsort(A,index):
 *    array_length = A.length
 *    build-heap(A,1,array_length) // by successively calling max-heapify 
 *    for int i = 0 to i <= A.length - 1
 *       exchange(A,1,array_length--)
 *       map-heapify(A,1,array_length)
 *
 * Below we will provide an implementation of the following routines:
 *
 * - max-heapify
 * - build-heap
 * - heapsort 
 *
 * Author: Eliezer Abate
 * Last Edit: Dec 28 2015 21:48 PST
 *
 */
 
 #include <vector>
 #include <functional> /* for std::less() */
 #include <iostream>

 /* 
  * We will implement the partion routine in a separate namespace. 
  */
 namespace detail {




 }

 /* 
  * This is the actual heapsort routine that we export to our clients 
  */
 template<typename T, typename Comparator>
 void HeapSort(std::vector<T> &elems, Comparator comp) {
 	
 }

 /*
  * Overloaded function that uses the above definition to allow users
  * to use heapsort without providing a comparator function. By default
  * we use the less than operator.
  */
  template<typename T>
  void HeapSort(std::vector<T> &elems) {
  	QuickSort(elems,std::less<T>());
  }
