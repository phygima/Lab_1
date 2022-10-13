#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "MyString.h"
#include "Encoder.h"
#include <assert.h>

using namespace std;


	//constructor without parameters
		//constructor without parameters
	MyString::MyString()
	{
		str = nullptr;
		length = 0;
		sz = 0;

	}


	/**
	* copy constructor, necessary to create an exact copy of
	* a class object but in a different memory area
	*/
	MyString::MyString(const char* str)
	{
		/**
		* the strlen function gets the number of characters in the string
		* we pass to the object
		*/
		length = strlen(str);


		this->str = new char[length + 1];

		// copy the characters of the string to the array of our class
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		//close the line with a terminating zero
		this->str[length] = '\0';

	}

	/**
	* copy constructor, necessary to create an exact copy of
	* a class object but in a different memory area
	*/
	MyString::MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	/**
	* destructor, responsible for freeing the resources occupied by the object,
	* called when the class object is destroyed
	*/
	MyString::~MyString()
	{
		delete[] this->str;
	
	}

	char* MyString::getString() 
	{
		return this->cStr();
	}

	void MyString::setString(char* str)  
	{
		this->str = new char[strlen(str)+1];
		strcpy(this->str, str);
	}
	
	//reversive length
	int MyString:: lengthStr() 
	{
		return length;
	}

	//method cStr
	 char* MyString::cStr() 
	{
		char* ch = new char[length + 1];
		int i;

		for (i = 0; i < length; i++) {
			ch[i] = str[i];
		}
		ch[i] = '\0';
		return ch;
	}

	 //substring method
	 char* MyString::getSubStr(int start, int len)
	 {
		 int size = len - start;
		 char* result = new char[size + 1];

		 strncpy(result, &str[start], size);

		 result[size] = 0;

		 return result;

	 }

	 //metod get element of string
	 char MyString::getElement(int index) 
	 {
		 int size = 1;
		 char* result = new char[size + 1];

		 strncpy(result, &str[index], size);
		 char s = result[0];

		 return s;

	 }

	 //metod set element of string
	 void MyString::setElement(char sym, int index)
	 {
		 this->str[index] = sym;
	 }

	 //substring removal method
	 char* MyString::erase(int size, int start, int len)
	 {

		 /*int size = strlen(getSubStr(start, len));*/
		 int i, j;
		 char* newString = new char[strlen(str) - size + 1];

		 for (i = 0; i < start; i++)
			 newString[i] = str[i];

		 for (i = start, j = start + len; j < strlen(str); i++, j++)
			 newString[i] = str[j];

		 newString[i] = '\0';

		 return newString;

	 }


	 //method to get the first occurrence of a  substring
	 char* MyString::getStrchr(char* str, char ch)
	 {

		 assert(str != NULL);
		 while (*str)
		 {
			 if (*str == ch)
				 return str;
			 else
				 str++;
		 }
		 return NULL;
	 }


	/**
	* overloaded assignment operator, called when it is necessary
	* to assign the value of one object to another
	*/
	MyString &MyString:: operator =(const MyString& other)
	{
		
		//standard operator overload syntax =

		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	MyString& MyString::  operator =(const char* other)
	{
		
		//standard operator overload syntax =

		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	MyString& MyString ::operator= (const char& ch)
	{
		//standard operator overload syntax =
		length = 1;
		str = new char[length];
		str[0] = ch;
		return *this;

	}


	




	//overloaded addition operator
	MyString MyString:: operator+(const MyString& other)
	{
		//create a new empty object
		MyString newStr;

		//get the number of characters
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		//allocate space in dynamic memory for a new line
		newStr.str = new char[thisLength + otherLength + 1];

		//copy data
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';


		//return the result of the concatenation
		return newStr;
	}



	//overloading == operator
	bool MyString:: operator ==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}


	//overloading [] operator
	char& MyString:: operator [](int index)
	{
		return this->str[index];
	}







