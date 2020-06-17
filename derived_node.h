
#ifndef DERIVED_NODE_H
#define DERIVED_NODE_H
#include "node.h"
#include <string>
using namespace std;


class D_Node : public Node {

	private:
		string name;
		int id;

	public:
		D_Node();
		D_Node(int);
		void setName(string);
		string getName();
		int getId();
};
#endif
