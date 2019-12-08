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

  Linked_List list;
  int value;
  bool q;
  bool enterVal;
  char choice;

  do {
    value = list.readInt();

    list.push_front(value);
    //list.push_back(value);
    //list.insert(value, list.get_length());

    cout << "Do you want another num (y or n): ";

    if (list.cont()) {	

      do {

	value = list.readInt();
	//list.push_front(value);
	//list.push_back(value);
	list.insert(value, list.get_length());
	list.print();
	cout << "Do you want another num (y or n): ";
        enterVal = list.cont();
      } while (enterVal != false);
    }

    list.chooseSort();
    cout << "Your linked list is "; 
    list.print();
    cout << "You have " << list.we4r();
    cout << " prime number(s) in your list." << endl;
    cout << "Do you want to do this again (y or n)? ";

    q = list.again();
    
  } while (q != false);

  return 0;
}
