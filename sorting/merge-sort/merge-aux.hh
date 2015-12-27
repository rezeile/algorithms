/*
 * Implementation of a top-down (recursive) merge sort algorithm that uses an 
 * explicit auxillary array to store the result of merging two sorted 
 * sub-arrays. Contrast this implementation with the merge-abstract-inplace.hh
 * which is in the same directory or can be found on the web at the following
 * address:
 * https://github.com/rezeile/algorithms/blob/master/sorting/merge-sort/merge-abstract-inplace.hh

 * Author: Eliezer Abate
 * Last Edited: Dec 27 2015 15:16 PST
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
  namespace detail {
  	/*
  	 * The merge routine is the most important part of the algorithm and in this case
     * we return an auxillary array of type vector after every call to merge. Note that
     * we don't lost the value of the returned local variable because C++ has a notion
     * of a copy assignment whereby results get copied over during a function return call
     * on an object prior to the object being destoryed. 
  	 */
    template<typename T, typename Comparator>
  	std::vector<T> merge(std::vector<T> left, std::vector<T> right, Comparator comp) {
  	  /* indices for left and right vectors */
      int m = 0;
      int n = 0;
      int size = left.size() + right.size();
      std::vector<T> result(left.size() + right.size());
  	  for(int i = 0; i < size; i++) {
  	  	/* check whether we have exhaused the left sub-array, [0, mid -1] */
  	  	if(m > left.size() - 1) result[i] = right[n++];
  	  	/* check whether we have exhaused the right sub-array, [mid, high] */
  	  	else if(n > right.size() - 1) result[i] = left[m++]; 
  	  	/* perform our comparison function */
  	  	else if(comp(left[m],right[n])) result[i] = left[m++]; 
  	  	/* opposite return value from comp() */
  	  	else result[i] = right[n++];
  	  }	
      return result;
  	}

  	/*
  	 * sort routine which handles the overall algorithm. This algorithm will be internally 
  	 * utilized by the MergeSort routine which we export to our clients. Idea to place the
     * merge routine in the same elems parameter that we passed by reference was obtained
     * from Keith Schwarz's implementation whose link is given above.
  	 */
  	 template<typename T, typename Comparator>
  	 void sort(std::vector<T> &elems, Comparator comp) {
  	   if(elems.size() <= 1) return;
  	   /* sort sub-arrays */
  	   int mid = (elems.size() - 1) / 2;
       /* configure left sub array */
       std::vector<T> left, right;
       for(int i = 0; i <= mid; i++)
          left.push_back(elems[i]);
       for(int i = mid + 1; i < elems.size(); i++)
          right.push_back(elems[i]);
  	   sort(left,comp);
  	   sort(right,comp);
  	   elems = merge(left,right,comp);
  	 }
  }


 /* 
  * Wrapper around the implementation of merge sort that uses the sort 
  * and merge routines defined within the detail namespace. 
  */
  template<typename T, typename Comparator>
  void MergeSortAUX(std::vector<T> &elems, Comparator comp) {
    detail::sort(elems,comp);
  }

 /*
  * MergeSort without user-specified comparator function. Calls on the 
  * MergeSort routine above to implement Comparator-less wrapper 
  * function.
  */
  template<typename T>
  void MergeSortAUX(std::vector<T> &elems) {
    MergeSortAUX(elems, std::less<T>());
  }

