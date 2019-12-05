#include "tools.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int readInt(string str) {

	int number = 0;
	int size = str.length();

	char cArr[size + 1];

	strcpy(cArr, str.c_str());

	for (int i = 0; i < size; i++) {
		cout << i << " pos: " << str[i] << endl;
		if (cArr[i] >= 48 || cArr[i] <= 57) {
			number *= 10;
			number += cArr[i] - 48;	
		}
	}	
	
	return number;	
}

string revStr(string str) {
	cout << "soome str" << endl;

}
