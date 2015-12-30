/*
 * Implementation of the heapsort algorithm that uses a max heap structure 
 * in order to sort elements in ascending order (or an order given by a 
 * client specified comparator function). The algorithm progresses
 * by first taking an array of items and rearranging them so that they
 * satisfy the max heap property, and once these elements have the heap 
 * property it continually swaps the node with the highest value (located
 * at index 1) with the last element of our the array. Afterwards it ensures
 * that the sub array beginning at index 1 and ending at (last index - 1)
 * satisfies the max heap property. After the max-heap property is satisfied
 * in the sub array, the second largest element is located at index 1 and the
 * algorithm swaps the element at this index with the element at the second
 * largest index (last index - 1). The algorithm performs this operation 
 * until all elements are sorted.
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
 * Thus in our code we will have a routine that accepts a node whose left
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
 * We will run this max-heapify function starting at the first parent, index 3
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
 * All passed parameters are assumed to be for 1-indexed arrays (unlike 0-index arrays).
 *
 * Author: Eliezer Abate
 * Last Edit: Dec 28 2015 21:48 PST
 *
 */
 
 #ifndef _HEAP_HH
 #define _HEAP_HH

 #include <vector>
 #include <functional> /* for std::less() */
 #include <iostream>

 /* 
  * We will implement the partion routine in a separate namespace. 
  */
 namespace heapDetail {
    /* 
     * Utility function that takes as a paramter a vector
     * of what it assumes to be 1-indexed elements, and 
     * two 1-indexed indices i and j and performs a real
     * swap using their 0-based representation.
     */
     template<typename T>
     void exchange(std::vector<T> &elems, int i, int j) {
        T temp = elems[i - 1];
        elems[i - 1] = elems[j - 1];
        elems[j - 1] = temp;
     }
    /* 
     * function: max-heapify
     * ---------------------
     * This function assumes that it is passed a 1-indexed array
     * of elements (unlike traditional arrays where the first 
     * element's index is 0) and an index into one of these 
     * elements representing a node on a heap whose left and right
     * children satisfy the heap property (max or min) and this function
     * will ensure that the node specified by the index satisfies
     * the heap property as well. 
     * 
     * Note that when performing comparisons and exchanges we 
     * decrement our indices by 1 to reflect that we are 'really'
     * operating on a 0-indexed array. Furthermore observe that 
     * the heapify routine will either construct a max or min
     * heap depending on the comparator function provided.
     */
     template<typename T, typename Comparator>
     void heapify(std::vector<T> &elems, int i, Comparator comp, int last_index) {
        /* if the node is a leaf return. Note elems.size() / 2 is the largest
         * non-leaf (parent) node in the tree */
         if(i > last_index / 2) return;
         /* right child index */
         int lc = 2*i; 
         /* left child index */
         int rc = 2*i + 1; 
         /* at this point we know the node has at least a left child since its a parent */
         int largest_key = comp(elems[lc - 1],elems[i - 1]) ? i : lc;
         /* check if right child exists as well */
         if(rc <= last_index && comp(elems[largest_key - 1],elems[rc - 1])) largest_key = rc;
         if(largest_key != i) {
            exchange(elems,i,largest_key);
            heapify(elems,largest_key,comp,last_index);
         }
     }

     /*
      * function: build heap
      * --------------------
      * This function converts an input array into one that
      * satisfies the heap property using the heapify routine
      * declared above. Again it 'assumes' the array parameter
      * (std::vector<T> &elems) is a one-index array.
      */
      template<typename T, typename Comparator>
      void buildHeap(std::vector<T> &elems, Comparator comp) {
         /* index of largest parent index */
         int last_parent = elems.size() / 2;
         for(int i = last_parent; i >= 1 /* root */; i--) 
            heapify(elems,i,comp,elems.size());
      }

      /* 
       * function: sort 
       * -------------------
       * An implementation of heap sort using the buildHeap and 
       * heapify routines above 
       */
       template<typename T, typename Comparator>
       void sort(std::vector<T> &elems, Comparator comp) {
          int root_index = 1;
          int last_index = elems.size();
          buildHeap(elems,comp);
          /* note that we will have n - 1 swaps between index 1 and last index */
          for(int i = 1; i <= elems.size() - 1; i++) {
            exchange(elems,root_index,last_index);
            last_index--;
            heapify(elems,root_index,comp,last_index);
          }
       }
}

 /* 
  * This is the actual heapsort routine that we export to our clients 
  */
 template<typename T, typename Comparator>
 void HeapSort(std::vector<T> &elems, Comparator comp) {
    heapDetail::sort(elems,comp);
 }

 /*
  * Overloaded function that uses the above definition to allow users
  * to use heapsort without providing a comparator function. By default
  * we use the less than operator.
  */
  template<typename T>
  void HeapSort(std::vector<T> &elems) {
  	HeapSort(elems,std::less<T>());
  }

  #endif
