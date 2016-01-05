/*
 * A program that reads in a text file and then maps 
 * each word in the text file with its total frequency count.
 * 
 * Author: Eliezer Abate
 * Last Edited Jan 4 2016 17:13
 */

 #include <string>
 #include "symbol-table.hh"
 #include <iostream>

 int main(int argc, char *argv[]) {
 	int minlen = std::stoi(argv[2]);
 	ST<std::string,int> st = new ST<std::string,int>;
 	std::string w;
 	while(std::cin >> w) {
 		if(w.size() < minlen) continue; /* Ignore short keys */
 		if(!st.contains(w)) st.put(w,1);
 		else 				st.put(w,st.get(w) + 1);
 	}

 	/* find key with the highest frequency count, using iterators */
 	std::string max = "";
 	st.put(max,0);
 	for(std::string w : st.keys())
 		if(st.get(w) > st.get(max))
 			max = word;
 	std::cout << max << " " << st.get(max) << std::endl;
 	return 0;
 }