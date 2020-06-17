
#include "node.h"
#include "derived_node.h"
#include <string>
#include <iostream>
using namespace std;


D_Node::D_Node() {
	cout << "d_node created" << endl;
	name = "node name";
	id = 6;
}

D_Node::D_Node(int dv) : Node(dv) {
	cout << "new val added to d_node" << endl;
}

void D_Node::setName(string str) {
	name = str;
}

string D_Node::getName() {
	return name;
}

int D_Node::getId() {
	return id;
}


