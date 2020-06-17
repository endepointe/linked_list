
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
  
  // checks for the first primes, up to 31
  // 	for the given testv = 1.
  int testp = 1; // enter a test position here
  int testv = 2; // enter a test value here

  do {
    value = list.readInt();
    list.push_front(value);
    //list.push_back(value);
    //list.insert(value, list.get_length());


///*
    list.push_front(testv); // 2
    list.push_back(testv + 1); // 3
    list.insert(testv + 3, testp); // 5
    list.push_front(testv + 5); // 7
    list.push_back(testv + 9); // 11
    list.insert(testv + 11, testp + 1); // 13
    list.push_front(testv + 15); // 17
    list.push_back(testv + 21); // 23
    list.insert(testv + 29, testp); // 31
//*/
    cout << "Do you want another num (y or n): ";

    if (list.cont()) {	

      do {
	value = list.readInt();
	list.push_front(value);
	//list.push_back(value);
	//list.insert(value, list.get_length());
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
