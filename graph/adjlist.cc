/*
 * A simple program that represents the static 
 * undirected graph below using an adjacency list.
 *  
 *     |1| ----- |4|
 *     / \
 *    /   \
 *   /    |5|
 *  /
 * |2| ----- |3|
 *
 * Author: Eliezer Abate
 * Date: March 22 2016 1:10 PM PST
 *
 */

#include <iostream> /* for cout */
#include <vector> 
/*
 * A Node in an adjacency list. 
 */
struct Node {
	int value;
	Node *next;
};

int main(int argc, char *argv[]) {
	/* create base nodes */
	std::vector<Node> v;
	std::cout << "adjlist.cc" << std::endl;
	return 0;
}
