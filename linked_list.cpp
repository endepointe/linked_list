/********************************************************************
 * Filename: linked_list.cpp
 * Author: Alvin Johns
 * Date: 11/28/19
 * Desc: Class function to manipulate an object oriented linked
 * 	list.
 * Input: a node class
 * Output: a linked list of nodes
 * Sources: Geeks for Geeks for getting mergeSort working
 * *****************************************************************/

#include "node.h"
#include "linked_list.h"
#include <string>
#include <iostream>
using namespace std;	


/*************************************************************************
 * Function: linked list constructor 
 * desc: creates the dynamix container to hold the list
 * params: none
 * pre: a list does not exist
 * post: a list of size >= 0 exists
 * ***********************************************************************/
Linked_List::Linked_List() {
	length = 0;
	head = nullptr;
}

Linked_List::~Linked_List() {
	clear();
}

/*************************************************************************
 * Function: get_length
 * desc: returns the number of nodes in the linked list
 * params: none
 * pre: a list >= 0 exists
 * post: the node count does not change
 * ***********************************************************************/
int Linked_List::get_length() {
	return length;
}


	
/*************************************************************************
 * Function: print 
 * desc: prints the nodes in the linked list
 * params: none
 * pre: a list >= 0 exists
 * post: the node count does not change
 * ***********************************************************************/
void Linked_List::print() {

	Node *curr = head;

	while (curr != nullptr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}	
	
  

/*************************************************************************
 * Function: clear 
 * desc: deletes the entire list and resets length to 0 
 * params: none
 * pre: a list >= 0 exists
 * post: the node count does not change
 * ***********************************************************************/
void Linked_List::clear() {
	
	Node *next = head;
	Node *curr = nullptr;

	while (next) {
		curr = next;
		next->val = 0;
		next = next->next;
		delete curr;
		length--;
	}

	head = nullptr;
}
	

	
/*************************************************************************
 * Function: push_front 
 * desc: insert a new value at the front of the list 
 * params: integer to be inserted 
 * pre: a list >= 0 exists
 * post: the node count increased by one 
 * ***********************************************************************/
unsigned int Linked_List::push_front(int v) {

	Node *node = new Node();

	node->val = v;

	length++;

	node->next = head;
	
	head = node;

	return length;
}

	
/*************************************************************************
 * Function: push_back 
 * desc: inserts a new value at the back of the list 
 * params: value to be inserted 
 * pre: a list >= 0 exists
 * post: the node count increased by one 
 * ***********************************************************************/
unsigned int Linked_List::push_back(int v) {

	Node *node = new Node();

	node->val = v;
	node->next = nullptr;

	length++;

	if (head == nullptr) {
		head = node;
		return length;
	}

	Node *curr = head;

	while (curr->next) {
		curr = curr->next;
	}

	curr->next = node;
	
	return length;
}
	

/*************************************************************************
 * Function: insert 
 * desc: insert a new  value in the list at the specified index 
 * params: integer to be inserted at the given index 
 * pre: a list >= 0 exists
 * post: the node count increased by one 
 * ***********************************************************************/
unsigned int Linked_List::insert(int v, unsigned int p) {

	Node *node = new Node();
	Node *curr = head;
	node->val = v;
	unsigned int i = 0;	
	
	if (p < 0) {
		p = 0;
	}

	if (p == 0) {
	
		delete node;	
		
		return push_front(v);

	} else if (p >= get_length()) {

		delete node;

		return push_back(v);

	} else {

		for (i; i < length; i++) {
			if (i == p - 1) {
				length++;
				node->next = curr->next;
				curr->next = node;
				break;
			}	
			curr = curr->next;
		}
	}
/* b 
 * a c d 
 * 
 * insert at beginning { b a c d }
 * 	b->n = a 
 *
 * insert at end { a c d b }
 * 	d->next = b
 * 	b->next = nullptr
 *
 * insert in middle { a b c d }
 * 	b->next = a->next
 * 	a->next = b
 *
 */
	return length;
}


/*************************************************************************
 * Function: sort_ascending 
 * desc: top function that begins the sorting of the list from least
 * 	to greatest 
 * params: none
 * pre: a list >= 0 exists
 * post: value i is less than i + 1 until end is reached
 *
 * example: for a list of {2, 6, 4, 9, 1, 5, 8, 7, 3} 
 * 	split the list into two halves:
 *
 * 		the addy of begin and the addy of end of each list
 * 		will be used to continue the separation.
 *
 * 	{ 2, 6, 4, 9, 1 } and { 5, 8, 7, 3 }
 * 	
 * 	{ 2, 6, 4 } and { 9, 1 } and { 5, 8 } and { 7, 3 }	
 * 		
 * 	{ 2, 6 }, { 4 }, { 9 }, { 1 }, { 5 }, { 8 }, { 7 }, { 3 }
 *
 *	{ 2 }, { 6 }, { 4 }, { 9 }, { 1 }, { 5 }, { 8 }, { 7 }, { 3 }
 *
 *	{ 2, 4, 6 } and { 1, 9 } and { 5, 8 } and { 3, 7 }
 *
 *	{ 1, 2, 4, 6, 9 } and { 3, 5, 7, 8 }
 *
 *	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
 * ***********************************************************************/
void Linked_List::sort_ascending() {			

	Node **begin = &head;

	cout << begin << endl;
	
	mergeSortAsc(begin);
}


/*************************************************************************
 * Function: sort_descending 
 * desc: top function that begins the sorting of the list from 
 * 	greatest to least 
 * params: none
 * pre: a list >= 0 exists
 * post: value at i is > i + 1 until the end is reached 
 * ***********************************************************************/
void Linked_List::sort_descending() {

	Node **begin = &head;

	cout << begin << endl;
	
	mergeSortDesc(begin);
}


/*************************************************************************
 * Function: mergeSortAsc 
 * desc: recursive call to the function that sorts and merges the list in
 * 	ascending order 
 * params: reference to the head of list being operated on
 * pre: a list >= 0 exists
 * post: value at i is > i + 1 until the end is reached 
 * ***********************************************************************/
void Linked_List::mergeSortAsc(Node **hRef) {

	Node *h = *hRef;
	Node *a;
	Node *b;

	//cout << "head ptr: " << hRef << endl;

	if ( (h == nullptr) || (h->next == nullptr) ) {
		/*
		cout << "**** IN IF ****" << endl;
		cout << "head: " << h << " ---";
		cout << "head val: " << h->val << endl;
		cout << "a: " << a << " ---";
		cout << "a val: " << a->val << endl;
		cout << "b: " << b << " ---";
		cout << "b val: " << b->val << endl;
		cout << "***** END IN IF ******" << endl;
		*/
		return;
	}

	splitList(h, &a, &b);

	mergeSortAsc(&a);
	mergeSortAsc(&b);

	*hRef = sortedMergeAsc(a, b);

}


/*************************************************************************
 * Function: mergeSortDesc 
 * desc: recursive call to the function that sorts the list in descending
 * 	order. 
 * params: reference to the head of list being operated on
 * pre: a list >= 0 exists
 * post: value at i is > i + 1 until the end is reached 
 * ***********************************************************************/
void Linked_List::mergeSortDesc(Node **hRef) {

	Node *h = *hRef;
	Node *a;
	Node *b;

	if ( (h == nullptr) || (h->next == nullptr) ) {
		return;
	}

	splitList(h, &a, &b);

	mergeSortDesc(&a);
	mergeSortDesc(&b);

	*hRef = sortedMergeDesc(a, b);

}


/*************************************************************************
 * Function: splitList 
 * desc: split the list into smaller parts, until each part is equal to
 * 	one. 
 * params: a ref to beginning and two references to side a and side b 
 * pre: a list >= 0 exists
 * post: value at i is > i + 1 until the end is reached 
 * ***********************************************************************/
void Linked_List::splitList(Node *src, Node **fRef, Node **bRef) {

	Node *A;
	Node *B;
	B = src;
	A = src->next;

	while (A != nullptr) {
		A = A->next; 
		if (A != nullptr) {
			B = B->next;
			A = A->next;
		}
	}

	*fRef = src;
	*bRef = B->next;
	B->next = nullptr;

}


/*************************************************************************
 * Function: sortedMergeAsc
 * desc: sorts and merges the given list in ascending order, returning
 * 	the reference to the head.
 * params: refs to the two lists that are being merged
 * pre: a list >= 0 exists
 * post: the node count does not change
 * ***********************************************************************/
Node * Linked_List::sortedMergeAsc(Node *a, Node *b) {

	Node *result = nullptr;
	
	if (a == nullptr) {
		return b;
	} else if (b == nullptr) {
		return a;
	}

	if (a->val <= b->val) {
		result = a;
		result->next = sortedMergeAsc(a->next, b);
	} else {
		result = b;
		result->next = sortedMergeAsc(a, b->next);
	}
	
	return result;
}


/*************************************************************************
 * Function: sortedMergeDesc
 * desc: sorts and merges the given list in ascending order, returning
 * 	the reference to the head 
 * params: refs to the two lists that are being merged
 * pre: a list >= 0 exists
 * post: the node count does not change
 * ***********************************************************************/
Node * Linked_List::sortedMergeDesc(Node *a, Node *b) {

	Node *result = nullptr;
	
	if (a == nullptr) {
		return b;
	} else if (b == nullptr) {
		return a;
	}

	if (a->val >= b->val) {
		result = a;
		result->next = sortedMergeDesc(a->next, b);
	} else {
		result = b;
		result->next = sortedMergeDesc(a, b->next);
	}
	
	return result;
}

/*************************************************************************
 * Function: we4r 
 * desc: returns the number of primes in the linked list
 * params: none
 * pre: a list >= 0 exists
 * post: the node count does not change, primes are counted and returned
 * 	sieve of erathanos would not be ideal in this situation. dirty sol
 *
 * ***********************************************************************/
int Linked_List::we4r() {

	Node *h = head;
	bool prime;
	int primes = 0;

	while (h) {

		if (h->val > 1){
			if ((h->val % 2 != 0) || (h->val % 3 != 0) || (h->val % 5 != 0) || (h->val % 7 != 0) || (h->val == 11)) {
				prime = true;	
			} else {
				prime = false;
			}
		}

		if (prime == true) {
			primes++;
		}

		h = h->next;

		prime = false;
	}

	return primes;
}

/////////////////////////////////////////////////////////////////////
//
//  Functions for the driver file, asking the user for input
//  
/********************************************************************
 * Function: readInt 
 * Desc: gets a number as input to put into the linked list 
 * Params: none
 * Output: a number 
 * *****************************************************************/
int Linked_List::readInt() {

	int num;

	cout << "Please enter a number: ";

	cin >> num;

	cin.ignore(100, '\n');

	while (cin.fail()) {
		cin.clear();
		cout << "Not a number, try again." << endl;
		cout << "Enter a number: ";
		cin.ignore(2, '\n');
		cin >> num;
	};

	return num;
}


/********************************************************************
 * Function: cont 
 * Desc: gets a character as input and determines whether the user 
 * 	would like to continue entering numbers
 * Params: none
 * Output: a bool whether the user wants to continue entering 
 * 	numbers for the linked list 
 * *****************************************************************/
bool Linked_List::cont() {

	bool flag = false;
	char choice[2];

	cin.get(choice, 2, '\n') ;

	cin.ignore(100, '\n');
	
	while (flag == false) {
		if (choice[0] == 110 || choice[0] == 121) {
			flag = true;	
			break;
		}
		cout << "Not a choice, try again (y or n): ";
		cin.get(choice, 2, '\n');
		cin.ignore(2, '\n');
	};

	if (choice[0] == 'y') {
		return true;	
	}

	if (choice[0] == 'n') {
		return false;
	}

}


/********************************************************************
 * Function: again 
 * Desc: gets a character as input and determines whether the user 
 * 	would like to exit the program
 * Params: none
 * Output: a bool whether the user wants to continue entering 
 * 	numbers for the linked list 
 * *****************************************************************/
bool Linked_List::again() {

	bool flag = false;
	char choice[2];

	cin.get(choice, 2, '\n') ;

	cin.ignore(100, '\n');
	
	while (flag == false) {
		if (choice[0] == 110 || choice[0] == 121) {
			flag = true;	
			break;
		}
		cout << "Not a choice, try again (y or n): ";
		cin.get(choice, 2, '\n');
		cin.ignore(2, '\n');
	};

	if (choice[0] == 'y') {
		clear();
		return true;	
	}

	if (choice[0] == 'n') {
		return false;
	}
}


/********************************************************************
 * Function: chooseSort 
 * Desc: gets a character as input and sorts and prints the list
 * 	in either ascending or descending order 
 * Params: linked_list pointer 
 * Output: sorted list 
 * *****************************************************************/
void Linked_List::chooseSort() {

	bool flag = false;
	char choice[2];

	cout << "Sort ascending or descending (a or d)? ";

	cin.get(choice, 2, '\n') ;

	cin.ignore(100, '\n');
	
	while (flag == false) {
		if (choice[0] == 100 || choice[0] == 97) {
			flag = true;	
			break;
		}
		cout << "Not a choice, try again (a or d): ";
		cin.get(choice, 2, '\n');
		cin.ignore(2, '\n');
	};

	if (choice[0] == 'a') {
		sort_ascending();
	}
	
	if (choice[0] == 'd') {
		sort_descending();
	}
}
