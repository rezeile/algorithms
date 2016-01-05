/*
 * A program that reads in a text file and then maps 
 * each word in the text file with its total frequency count.
 * 
 * This program should be invoked from the command line 
 * in the following manner:
 * 
 * ./frequency 10 < war-and-peace.txt 
 *
 * The "10" above is the number of the largest string that 
 * we will consider in the frequency table and the "war-and-peace.txt" 
 * is the text file from which we will be reading the words.
 *  
 *
 * Author: Eliezer Abate
 * Last Edited Jan 4 2016 17:13
 */

 #include <string>
 #include "sequential-search-st.hh"
 #include <iostream>

 int main(int argc, char *argv[]) {
 	// int minlen = std::stoi(argv[2]);
 	// ST<std::string,int> st = new ST<std::string,int>;
 	// std::string w;
 	// while(std::cin >> w) {
 	// 	if(w.size() < minlen) continue; /* Ignore short keys */
 	// 	if(!st.contains(w)) st.put(w,1);
 	// 	else 				st.put(w,st.get(w) + 1);
 	// }

 	// /* find key with the highest frequency count, using iterators */
 	// std::string max = "";
 	// st.put(max,0);
 	// for(std::string w : st.keys())
 	// 	if(st.get(w) > st.get(max))
 	// 		max = word;
 	// std::cout << max << " " << st.get(max) << std::endl;
 	SequentialSearchST<std::string,int> st;
 	return 0;
 }