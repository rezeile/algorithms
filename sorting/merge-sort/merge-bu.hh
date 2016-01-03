/*
 * Implementation of a top-down (recursive) merge sort algorithm for sortin an 
 * array of templetized items. The idea for an abstract in-place merge, one in 
 * which we appear to sort and merge the arrays in place (rather than using an 
 * auxilary array) was taken from Robert Sedgewick and Kevin Wayne's Introduction 
 * to Algorithms, Third Edition (Chapter 2.3 Merge Sort). 
 *
 * 
 *
 * Author: Eliezer Abate
 * Last Edited: Jan 3 2015 14:55 PST
 */
 
 #ifndef __MERGE_BU_HH
 #define __MERGE_BU_HH

 #include <vector> /* for std::vector */
 #include <functional> /* for std::less<T>() */
 #include <algorithm> /* for std::min */
 #include <iostream>
 #include "../sort-util.hh"
 
 /*
  * We will place the details of the merge and sort algorithms in the detail
  * name space to avoid cluttering the global namespace. Idea for placing in 
  * a seperate namespace was obtained from Stanford CS instructor Keith Schwarz's 
  * merge sort implementation which can be found on his website at:
  * http://www.keithschwarz.com/interesting/code/?dir=mergesort
  */
  namespace mergeBUDetail {
  	/* 
  	 * Utility function that copies current elements into auxillary array 
  	 */
  	 template<typename T>
  	 void copy(std::vector<T> elems, std::vector<T> &aux, int lo, int high) {
  	 	for(int i = lo; i <= high; i++) {
  	 		aux[i] = elems[i];
  	 	}
  	 }

  	/* Abstract in-place merge. Not an actual in-place merge, but receives a 
     * data vector whose left and right sub-arrays are in sorted order and using
     * a client-passed auxillary vector, this function returns the original vector
     * in sorted order. 
     */
    template<typename T, typename Comparator>
  	void merge(std::vector<T> &elems,std::vector<T> &aux,int lo, int mid, int high, Comparator comp) {
      if(lo >= high) return; /* already merged */
      copy(elems,aux,lo,high);
      int i = lo;
      int j = mid + 1;
      for(int k = lo; k <= high; k++) {
        if(i > mid) elems[k] = aux[j++];
        else if(j > high) elems[k] = aux[i++];
        /* need to make sure we use aux in the comparison stage, since elems
         * gets modified in the intervening steps between index lo and high 
         */
        else if(comp(aux[j],aux[i])) elems[k] = aux[j++];
        else elems[k] = aux[i++];
      }
  	}

  	/*
  	 * Bottom-Up Merge Sort
  	 */
  	 template<typename T, typename Comparator>
  	 void sort(std::vector<T> &elems,std::vector<T> &aux,Comparator comp) {
       for(int i = 1; i < elems.size(); i = i + i)
        for(int j = 0; j < elems.size() - i; j += i + i) {
          int inc = j + 2*i - 1;
          int max = elems.size() - 1;
          int hi = std::min(inc,max);
          merge(elems,aux,j,j + i - 1,hi,comp);
        }
  	 }
  }


 /* 
  * Wrapper around the implementation of merge sort that uses the sort 
  * and merge routines defined within the detail namespace. 
  */
  template<typename T, typename Comparator>
  void MergeSortBU(std::vector<T> &elems, Comparator comp) {
    std::vector<T> aux(elems.size());
    mergeBUDetail::sort(elems,aux,comp);
  }

 /*
  * MergeSort without user-specified comparator function. Calls on the 
  * MergeSort routine above to implement Comparator-less wrapper 
  * function.
  */
  template<typename T>
  void MergeSortBU(std::vector<T> &elems) {
    MergeSortBU(elems, std::less<T>());
  }

#endif

