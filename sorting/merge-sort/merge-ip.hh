/*
 * Implementation of a top-down (recursive) merge sort algorithm for sorting an 
 * array of templetized items. This implementation uses an in-place merge routine
 * that I devised, but takes O(n^2) time.
 * 
 *
 * Author: Eliezer Abate
 * Last Edited: Dec 26 2015 13:44 PST
 */
 
 #ifndef _MERGE_IP_HH
 #define _MERGE_IP_HH

 #include <vector> /* for std::vector */
 #include <functional> /* for std::less<T>() */
 
 /*
  * We will place the details of the merge and sort algorithms in the detail
  * name space to avoid cluttering the global namespace. Idea for placing in 
  * a seperate namespace was obtained from Stanford CS instructor Keith Schwarz's 
  * merge sort implementation which can be found on his website at:
  * http://www.keithschwarz.com/interesting/code/?dir=mergesort
  */
  namespace mergeIPDetail {
  	/* forward declare sort */
  	template<typename T, typename Comparator>
  	void sort(std::vector<T> &elems, int lo, int mid, int high, Comparator comp);

  	/* 
     * Utility function that exhanges two elements.
     */
     template<typename T>
     void exchange(std::vector<T> &elems, int i, int j) {
        T temp = elems[i];
        elems[i] = elems[j];
        elems[j] = temp;
     }

  	/*
  	 * Abstraction of an in-place merge that expects a left half of vector elems and
  	 * a right half of vector elems to be in sorted order, and this merge routine 
  	 * proceeds to sort the two disjoint sub-arrays into a larger sorted array of 
  	 * size (high - lo). 
  	 */
    template<typename T, typename Comparator>
  	void merge(std::vector<T> &elems, int lo, int mid, int high, Comparator comp) {
  	    /* start of left sub-array */
  		int i = lo;
  		while(i <= mid) {
  			if(elems[i] > elems[mid + 1]) {
  				exchange(elems,i,mid + 1);
  				/* merge sort right half just in case placed out of position */
  				int l = mid + 1;
  				int h = high;
  				int m = (l + h) / 2;
  				sort(elems,l,m,h,comp);
  			}
  			i++;
  		}
  	}

  	/*
  	 * sort routine which handles the overall algorithm. This algorithm will be internally 
  	 * utilized by the MergeSort routine which we export to our clients.
  	 */
  	 template<typename T, typename Comparator>
  	 void sort(std::vector<T> &elems, int lo, int mid, int high, Comparator comp) {
  	   /* return if we reach a single element */
  	   if((lo == mid) && (mid == high)) return;
  	   /* configure left sub-array indices */
  	   int l_lo = lo;
  	   int l_high = mid;
  	   int l_mid = (l_lo + l_high) / 2;
  	   /* configure right sub-array indices */
  	   int r_lo = mid + 1;
  	   int r_high = high;
  	   int r_mid = (r_lo + r_high) / 2;
  	   /* sort sub-arrays */
  	   sort(elems,l_lo,l_mid,l_high,comp);
  	   sort(elems,r_lo,r_mid,r_high,comp);
  	   merge(elems,lo,mid,high,comp);
  	 }
  }


 /* 
  * Wrapper around the implementation of merge sort that uses the sort 
  * and merge routines defined within the detail namespace. 
  */
  template<typename T, typename Comparator>
  void MergeSortIP(std::vector<T> &elems, Comparator comp) {
    mergeIPDetail::sort(elems,0, (elems.size() - 1) / 2, elems.size() - 1, comp);
  }

 /*
  * MergeSort without user-specified comparator function. Calls on the 
  * MergeSort routine above to implement Comparator-less wrapper 
  * function.
  */
  template<typename T>
  void MergeSortIP(std::vector<T> &elems) {
    MergeSortIP(elems, std::less<T>());
  }

#endif

