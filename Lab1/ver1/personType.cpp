// Jian Zhong
// CS132 Lab 1
// Todays Date

//  personTypeimp.cpp

#include "personType.h"
#include <iostream>
#include <string>

//Output
void personType::print() const
{
    cout << getLast() << ' ' << getFirst();
}

//Mutator
void personType::setName(string firstName, string lastName)
{
    fName = firstName;
    lName = lastName;
}

//Accessors
string personType::getFirst() const
{
    return fName;
}

string personType::getLast() const
{
    return lName;
}

//Default Constructor
personType::personType(string firstName, string lastName)
{
    setName(firstName, lastName);
}