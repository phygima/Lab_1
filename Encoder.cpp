#include <iostream>
#include "Encoder.h"
#include "MyString.h"

using namespace std;

//default constructor
Encoder::Encoder()
{
	str = nullptr;
	length = 0;
}

//constructor with parameter  
Encoder::Encoder(const char* accStr)	
{	
	str = MyString(accStr);
	length = str.lengthStr();
	encStr = str;
	decStr = str;
}

Encoder::Encoder(const MyString& other)
{
    this->str = MyString(other);
    char* strLoc = str.cStr();
    length = strlen(strLoc);
    encStr = this->str;
    decStr = this->str;
}	


//destructor
Encoder::~Encoder()
{

}

//encoded string output method
char* Encoder::getEncStr()
{
  return encStr.getString();
}


//decoded string output method
char* Encoder::getDecStr()
{
  return decStr.getString();
}

//metod cStr()
char* Encoder::cStr()					
{
	char* ch = new char[length + 1];
	int i;
	for (i = 0; i < length; i++) {
		ch[i] = str[i];
	}
	ch[i] = '\0';
	return ch;
}

char Encoder::getElement(int indexE)
{
	return str.getElement(indexE);;
}

//string encoding method
void Encoder::encode()
{
	for (int i = 0; i < length; i++)
	{
		if (isupper(this->str[i]) && isalpha(this->str[i]))
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (upperDecoded[j] == this->str[i])
				{
					step = j;
				}
			}
			/*encStr[i] = upperEncoded[step];*/
			encStr.setElement(upperEncoded[step], i);
		}
		else if (isalpha(this->str[i]))
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (lowerDecoded[j] == this->str[i])
				{
					step = j;
				}
			}
			/*encStr[i] = lowerEncoded[step];*/
			encStr.setElement(lowerEncoded[step], i);
		}
		else if (this->str[i] >= '0' && this->str[i] <= '9')
		{
			int step;
			for (int j = 0; j < 10; j++)
				if (decArrNumb[j] == this->str[i])
				{
					step = j;
				}
			/*encStr[i] = encArrNumb[step];*/
			encStr.setElement(encArrNumb[step], i);
		}
		else if (this->str[i] == ' ')
		{
			/*encStr[i] = ' ';*/
			encStr.setElement(' ', i);
		}
	}
}

//string decoding method
void Encoder::decode()
{
	for (int i = 0; i < length; i++)
	{
		if (isupper(this->str[i]) && isalpha(this->str[i])) //Capital + letter
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (upperEncoded[j] == this->str[i])
				{
					step = j;
				}
			}
			/*decStr[i] = upperDecoded[step];*/
			decStr.setElement(upperDecoded[step], i);
		}
		else if (isalpha(this->str[i])) //just a letter
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (lowerEncoded[j] == this->str[i])
				{
					step = j;
				}
			}
			/*decStr[i] = lowerDecoded[step];*/
			encStr.setElement(lowerDecoded[step], i);
		}
		else if (this->str[i] >= '0' && this->str[i] <= '9')
		{
			int step;
			for (int j = 0; j < 10; j++)
				if (encArrNumb[j] == this->str[i])
				{
					step = j;
				}
			/*encStr[i] = decArrNumb[step];*/
			decStr.setElement(decArrNumb[step], i);
		}
		else if (this->str[i] == ' ')
		{
			/*decStr[i] = ' ';*/
			decStr.setElement(' ', i);
		}
	}
}

char* Encoder::getSubStr(int start, int len)
{
	return str.getSubStr(start, len);
}

char* Encoder::erase(int start, int len)
{
	int size = strlen(getSubStr(start, len));
	return  str.erase(size, start, len);
}

char* Encoder::getStrchr(char ch)
{
	return str.getStrchr(str.cStr(), ch);
}

//encoding method documentation output method
char* Encoder::getDoc()
{
	MyString resultDoc = doc1 + doc2 + doc3 + doc4 + doc5;
	return resultDoc.cStr();
}

//overloading = operator
Encoder& Encoder::operator=(const Encoder& other)
{
	MyString tmpStr;

	this->str = tmpStr.cStr();

	length = strlen(tmpStr.cStr());
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = tmpStr[i];
	}

	this->str[length] = '\0';

	return *this;
}
