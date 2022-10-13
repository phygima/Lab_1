#pragma once
#include "MyString.h"


class Encoder                                                                                   
{                                                                                                
public:                                                                                         

    Encoder(); //default constructor
    

    Encoder(const char* str); //constructor with parameter
    

    Encoder(const MyString& other); //copy constructor

    //destructor
    ~Encoder();

    //encoded string output method
    char* getEncStr();
    
    //decoded string output method
    char* getDecStr();

	//metod cStr()
	char* cStr();

    char* getSubStr(int start, int len);

    char getElement(int indexE);

    //string encoding method
    void encode();
    
    //string decoding method
    void decode();

    char* erase(int start, int len);

    char* getStrchr(char ch);
    
    //encoding method documentation output method
    char* getDoc();
    
    //overloading = operator
    Encoder& operator=(const Encoder& other);

protected:


private:
    MyString str; //input string field

    //upper case alphabet (uncoded)
    const char upperDecoded[26] = {'A','B','C','D','E','F','G','H','I','J','K',  
                                   'L','M','N','O','P','Q','R','S','T','U','V',
                                   'W','X','Y','Z'};

    //upper case alphabet (encoded)
    const char upperEncoded[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P',
                                   'O','N','M','L','K','J','I','H','G','F','E',
                                   'D','C','B','A'};

    //алфавит нижнего регистра (незакодированный)
    const char lowerDecoded[26] = {'a','b','c','d','e','f','g','h','i','j','k',
                                   'l','m','n','o','p','q','r','s','t','u','v',
                                   'w','x','y','z'};

    //lower case alphabet (uncoded)
    const char lowerEncoded[26] = {'z','y','x','w','v','u','t','s','r','q','p',
                                   'o','n','m','l','k','j','i','h','g','f','e',
                                   'd','c','b','a'};
    //digit set (uncoded)
    const int decArrNumb[10] = { '0','1','2','3','4','5','6','7','8','9' };

    //digit set (encoded)
    const int encArrNumb[10] = { '9','8','7','6','5','4','3','2','1','0' };
    MyString encStr; //encoded string field
    MyString decStr; //decoded string field
    int length; //string length field

    //documentation {
    MyString doc1 = { "The cipher used in the program is the simple substit" }; 
    MyString doc2 = { "ition cipher used for the Hebrew alphabetand from th" };
    MyString doc3 = { "ere it got its name(Atbash). Encryption occurs by re" };
    MyString doc4 = { "placing the first letter of the alphabet with the la" };
    MyString doc5 = { "st, the second with the penultimate one." };

};