/****************************************************************************
 * Filename: node.h
 * Author: Alvin Johns
 * Date: Nov 28, 2019
 * Desc: class to hold a node object
 * Input: none
 * Output: none
 * *************************************************************************/
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node {

	private:
		// empty

	protected:
		int pro_count;
		
	public:

		Node();
		Node *next;
		int val;

		// functions not implemented
		/*
		Node();
		Node(int);
		Node(Node*);

		void addNode(Node*,int);
		Node * getNextNode();
		int getVal();
		void pro_incrCount();
		int pro_getCount();
		*/
		
};
#endif
