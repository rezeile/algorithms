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
#include <cassert>

/*
 * A Node in an adjacency list. 
 */
struct Node {
	int value;
	Node *next;
};

void addEdge(Node *new_node, Node *base) {
	assert(new_node != NULL && base != NULL);
	assert(base->next == NULL);
    
	Node *cur = new_node;
	while(cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = base;
}

int main(int argc, char *argv[]) {
	/* create base nodes */
	std::vector<Node*> v;
	for(int i = 1; i <= 5; i++) {
		Node *n = new Node;
		n->value = i;
		n->next = NULL;
		v.push_back(n); 
	}
	
	/* attach adjacent nodes (edges) */
	
	/* to node 1 */
	Node *e1 = new Node;
	e1->value = 2;
	Node *e2 = new Node;
	e2->value = 5;
	Node *e3 = new Node;
	e3->value = 4;
	
	addEdge(e1,v[0]);
	addEdge(e2,v[0]);
	addEdge(e3,v[0]);
	

	/* to node 2 */
	e1 = new Node;
	e1->value = 1;
	e2 = new Node;
	e2->value = 3;
	addEdge(e1,v[1]);
	addEdge(e2,v[1]);

	/* to node 3 */
	e1 = new Node;
	e1->value = 2;
	addEdge(e1,v[2]);

	/* to node 4 */
	e1 = new Node;
	e1->value = 1;
	addEdge(e1,v[3]);

	/* to node 5 */
	e1 = new Node;
	e1->value = 1;
	addEdge(e1,v[4]);
	
	return 0;
}
