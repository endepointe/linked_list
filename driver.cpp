/***************************************************************************
 * Program: Linked List 
 * Author: Alvin Johns
 * Date: Nov 29, 2019
 * Desc: driver file to build a linked list from scratch
 * ************************************************************************/


#include <iostream>
#include "tools.h"
#include "node.h"
#include "linked_list.h"
#include <string>

using namespace std;

int main() {

	srand(time(NULL));

	Linked_List list;
		
	int r;
	int pos4 = 4;
	int pos15 = 15;
	unsigned int ui;
	
	for (int i = 0; i < 100; i++) {
		//r = rand() % 250;
		r = i;
		//cout << "pos " << i << ": " << r << endl;
		list.push_front(r);
	}

	list.print();

	cout << "\nlength: " << list.get_length() << endl;

	list.insert(999, 100);
	
	cout << "split" << endl;

	list.sort_descending();

	cout << "head: " << &list << endl;

	list.print();

	cout << "primes: " << list.we4r() << endl;

	return 0;
}
