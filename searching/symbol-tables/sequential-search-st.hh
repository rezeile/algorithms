/* 
 * An implementation of a singly-linked list based symbol table. For
 * each key value pair, we will store its information in a linked node,
 * that will have the key, value, and a pointer to the next node (which
 * may be null). 
 *
 * Insertion in such a structure will take Theta(1) in all cases, and
 * the search or retrieval process may take O(n) in the worst case.
 *
 * This implementation supports the following operations:
 *
 * put      : place key value pair in the symbol table
 * get      : get a value that corresponds to a key
 * delete   : delete a value from the symbol table
 * size     : returns the number of elements in the symbol table
 * empty    : returs true if the symbol table is empty, false otherwise
 * contains : returns true if the given key is in the symbol table
 *
 * Author: Eliezer Abate
 * Last Edit: Jan 4 2016 17:40 PST
 */

 #ifndef _SEQUENTIAL_SEARCH_ST_HH
 #define _SEQUENTIAL_SEARCH_ST_HH

 #include <exception>
 
 template<typename Key, typename Value>
 struct Node {
 	Key k;
 	Value v;
 	Node *next;
 };

 template<typename Key, typename Value>
 class SequentialSearchST {
   public:
   	 SequentialSearchST();
   	 ~SequentialSearchST();
   	 void put(Key k, Value v);
   	 Value get(Key k);
   	 void remove(Key k); /* note that 'delete' is a C++ keyword and cannot be used in this case */
   	 bool contains(Key k);
   	 int size();
   	 bool empty();
   private:
   	 Node<Key,Value> *head;
   	 int count;
 };

 /* 
  * constructor
  * -----------
  */
 template<typename Key, typename Value>
 SequentialSearchST<Key, Value>::SequentialSearchST() {
 	head = NULL;
 	count = 0;
 }

 /* 
  * destructor
  * -----------
  */
 template<typename Key, typename Value>
 SequentialSearchST<Key, Value>::~SequentialSearchST() {
 	Node<Key,Value> *cur = head;
 	while(cur != NULL) {
 		Node<Key,Value> *next = cur->next;
 		delete cur;
 		cur = next;
 	}
 }

 /* 
  * function: put(Key k, Value v)
  *    usage: put("hi",34);
  * -----------------------------
  * Associates the a value with the
  * corresponding key and places 
  * both in the symbol table. This
  * operation takes constant time.
  */
 template<typename Key, typename Value>
 void SequentialSearchST<Key, Value>::put(Key k, Value v) {
 	/* create new storage node */
 	if(contains(k)) {
 		/* replace with new value */
 	} else {
 		Node<Key,Value> *n = new Node<Key,Value>;
 		n->k = k;
 		n->v = v;
 		/* add to head */
 		n->next = head;
 		head = n;
 	}
 }

 /* 
  * function: get(Key k)
  *    usage: Value v = get("hi");
  * -----------------------------
  * Retrieves the value associated with the
  * the given key. Returns NULL if the key
  * is not found in the symbol table.
  */
 template<typename Key, typename Value>
 Value SequentialSearchST<Key, Value>::get(Key k) {
 	Node<Key,Value> *cur = head;
 	while(cur != NULL) {
 		if(cur->k == k) {
 			return cur->v;
 		}
 		cur = cur->next;
 	}
 	return NULL;
 }

 /* 
  * function: remove(Key k)
  *    usage: remove("hi")
  * -----------------------------
  * Removes the given key from the 
  * symbol table.
  */
 template<typename Key, typename Value>
 void SequentialSearchST<Key, Value>::remove(Key k) {
 	if(empty()) 
 		throw "Attempted to remove from empty symbol table";

    Node<Key,Value> *cur = head;
 	/* remove from front */
 	if(head->k == k) {
 		Node<Key,Value> *temp = head;
 		head = head->next;
 		delete temp;
 	} 
 	/* remove from middle */
 	else if (cur != NULL && cur->next != NULL) {
 		if(cur->next->k == k) {
 			/* remove cur->next */
 			Node<Key,Value> *temp = cur->next;
 			cur->next = cur->next->next;
 			delete temp;
 		}
 		cur = cur->next;
 	}
 }

 /* 
  * function: contains()
  *    usage: if(contains(Key k))
  * -----------------------------
  * Returns true if the symbol table 
  * contains the key, false otherwise.
  */
 template<typename Key, typename Value>
 bool SequentialSearchST<Key, Value>::contains(Key k) {
 	Node<Key,Value> *cur = head;
 	while(cur != NULL) {
 		if(cur->k == k) {
 			return true;
 		}
 	}
 	return false;
 }

 /* 
  * function: size()
  *    usage: int N = size()
  * -----------------------------
  * Returns the size of the symbol
  * table.
  */
 template<typename Key, typename Value>
 int SequentialSearchST<Key, Value>::size() {
 	return count;
 }

  /* 
  * function: empty()
  *    usage: if(empty())
  * -----------------------------
  * Returns true if the symbol 
  * table is empty, false otherwise.
  */
 template<typename Key, typename Value>
 bool SequentialSearchST<Key, Value>::empty() {
 	return count == 0;
 }

 #endif  