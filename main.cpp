#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "MyString.h"
#include "Encoder.h"


using namespace std;



int main()
{

	Encoder r = "Hello";

	MyString str;

	str = r.cStr();

	r.encode();

	cout << "Encoded string: " << r.getEncStr() << endl;

	cout << "str[0] = " << r.getElement(0) << "\n" << endl;
	
	cout << "Substr:  " << r.getSubStr(0, 4) << "\n" << endl;

	cout << "Erase method:  " << r.erase(1, 2) << "\n" << endl;
	
	cout << "First entry of substr:  " << r.getStrchr('l') << "\n" << endl;



	cout <<"Documentation:\n\n" << r.getDoc() << endl << endl;

	


	system("pause");
	return 0;
}
