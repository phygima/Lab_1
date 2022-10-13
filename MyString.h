#ifndef LAB1_MYSTRING_H
#define LAB1_MYSTRING_H
#define _CRT_SECURE_NO_DEPRECATE




class MyString {


public:
	//defult constructor
	MyString();

	//constructor with parameters
	MyString(const char* str);

	//copy constructor
	MyString(const MyString& other);

	//destructor
	~MyString();

	//method Get
	char* getString();
	
	//method Set
	void setString(char* str);

	//reversive length
	int lengthStr();

	//method cstr
	char* cStr();

	//metod get substring
	char* getSubStr(int start, int len);

	//metod get element of string
	char getElement(int index);

	void setElement(char sym, int index);
	
	 //substring removal method
	char* erase(int size, int start, int len);

	//method to get the first occurrence of a  substring
	char* getStrchr(char* s, char c);

	// overloading = operator
	MyString& operator =(const MyString& other);

	MyString& operator =(const char* other);

	MyString& operator= (const char& ch);


	//overloading + operator
	MyString operator+(const MyString& other);


	//overloading == operator
	bool operator ==(const MyString& other);

	//overloading [] operator
	char& operator [](int index);

	


protected:



private:
	char* str;
	int length;
	int sz;

};

#endif //LAB1_MYSTRING_H