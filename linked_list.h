/********************************************************************
 * Filename: linked_list
 * Author: Alvin Johns
 * Date: 11/28/19
 * Desc: Class function to manipulate a object oriented linked
 * 	list.
 * Input: a node class
 * Output: a linked list of nodes
 * *****************************************************************/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class Linked_List {
	
	private:
		unsigned int length;
		Node *head;

	public: 
		Linked_List();
		~Linked_List();
		int get_length();
		void print();
		void clear();
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int, unsigned int);
		void sort_ascending();
		void sort_descending();
		void mergeSortAsc(Node **);
		void mergeSortDesc(Node **);
		void splitList(Node *, Node **, Node **);
		Node * sortedMergeAsc(Node *, Node *);
		Node * sortedMergeDesc(Node *, Node *);
		int we4r();
};
#endif
