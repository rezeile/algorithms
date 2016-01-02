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
 * Last Edited: Dec 26 2015 13:44 PST
 */
 
 #include <vector> /* for std::vector */
 #include <functional> /* for std::less<T>() */
 
 /*
  * We will place the details of the merge and sort algorithms in the detail
  * name space to avoid cluttering the global namespace. Idea for placing in 
  * a seperate namespace was obtained from Stanford CS instructor Keith Schwarz's 
  * merge sort implementation which can be found on his website at:
  * http://www.keithschwarz.com/interesting/code/?dir=mergesort
  */
  namespace mergeDetail {
  	/* 
  	 * Utility function that copies current elements into auxillary array 
  	 */
  	 template<typename T>
  	 void copy(std::vector<T> elems, std::vector<T> &aux, int lo, int high) {
  	 	for(int i = lo; i <= high; i++) {
  	 		aux[i] = elems[i];
  	 	}
  	 }

  	/*
  	 * Abstraction of an in-place merge that expects a left half of vector elems and
  	 * a right half of vector elems to be in sorted order, and this merge routine 
  	 * proceeds to sort the two disjoint sub-arrays into a larger sorted array of 
  	 * size (high - lo). 
  	 */
    template<typename T, typename Comparator>
  	void merge(std::vector<T> &elems,std::vector<T> &aux,int lo, int mid, int high, Comparator comp) {
  	  /* assume an auxillary array exists and is populated with elements lo through high */
  	  
      /* according to sedgewick making aux local to merge would dominate the run time of 
       * merge since elems.size() new elements are allocated on every call to merge. */
  	  int m = lo; /* begining index of left sub-array */
  	  int n = mid + 1; /* begining index of right sub-array */
  	  for(int i = lo; i <= high; i++) {
  	  	/* check whether we have exhaused the left sub-array, [0, mid -1] */
  	  	if(m > mid) {
  	  		aux[i] = elems[n++];
  	  	}
  	  	/* check whether we have exhaused the right sub-array, [mid, high] */
  	  	else if(n > high) {
  	  		aux[i] = elems[m++];
  	  	}
  	  	/* perform our comparison function */
  	  	else if(comp(aux[m],aux[n])) {
  	  		aux[i] = elems[m++];
  	  	}
  	  	/* opposite return value from comp() */
  	  	else {
  	  		aux[i] = elems[n++];
  	  	}
  	  }	
  	}

  	/*
  	 * sort routine which handles the overall algorithm. This algorithm will be internally 
  	 * utilized by the MergeSort routine which we export to our clients.
  	 */
  	 template<typename T, typename Comparator>
  	 void sort(std::vector<T> &elems,std::vector<T> &aux, int lo,int high, Comparator comp) {
  	   /* return if we reach a single element */
  	   if(lo >= high) return;
  	   int mid = (lo + high) / 2;
  	   /* sort sub-arrays */
  	   sort(aux,elems,lo,mid,comp);
  	   sort(aux,elems,mid + 1,high,comp);
  	   merge(elems,aux,lo,mid,high,comp);
  	 }
  }


 /* 
  * Wrapper around the implementation of merge sort that uses the sort 
  * and merge routines defined within the detail namespace. 
  */
  template<typename T, typename Comparator>
  void MergeSortAIP(std::vector<T> &elems, Comparator comp) {
    std::vector<T> aux(elems.size());
    mergeDetail::copy(elems,aux,0,elems.size() - 1);
    mergeDetail::sort(elems,aux,0,elems.size() - 1,comp);
  }

 /*
  * MergeSort without user-specified comparator function. Calls on the 
  * MergeSort routine above to implement Comparator-less wrapper 
  * function.
  */
  template<typename T>
  void MergeSortAIP(std::vector<T> &elems) {
    MergeSortAIP(elems, std::less<T>());
  }

