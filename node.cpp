#include "node.h"
#include <string>
#include <iostream>
using namespace std;

///*
Node::Node() {
	cout << "node created" << endl;
	next = nullptr;
	val = 0;
	//pro_count = 0;
}
/*
Node::Node(int nv) {
	val = nv;
}

Node::Node(Node *nPtr) {
	val = nPtr->val;	
	next = nPtr->next;
}

void Node::addNode(Node *nAddy, int v) {
	next = nAddy;
	val = v;
}

Node * Node::getNextNode() {
	return next;
}
 
int Node::getVal() {
	return val;
}

void Node::pro_incrCount() {
	++pro_count;
}

int Node::pro_getCount() {
	return pro_count;
}
*/
