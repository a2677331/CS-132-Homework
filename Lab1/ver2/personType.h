// Jian Zhong
// CS132 Lab 1
// 09/03/2019

// personType.h

#ifndef personType_h
#define personType_h

#include <string>

using namespace std;

class personType
{
public:
    //Output
    void print() const;
    //Function to output the first name and last name.
    //Postcondition: last name and first name are printed.

    //Mutator
    void setName(string, string);
    //Function to set first name and last name according to the parameters
    //Postcondition: fName = firstName, lName = lastName.

    //Accessors
    string getFirst() const;
    //Function to get the first name.
    //Postcondition: fName is returned.

    //Accessors
    string getLast() const;
    //Function to get the last name.
    //Postcondition: lName is returned.

    //Default Constructor
    personType(string = "", string = "");
    //Constructor with default parameters.
    //Postcondition: fName and lName are set to empty string.

private:
        string fName; //person's first name
        string lName; //person's last name
};

#endif /* personType_h */
