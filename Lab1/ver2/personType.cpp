// Jian Zhong
// CS132 Lab 1
// 09/03/2019

// personTypeimp.cpp

#include "personType.h"
#include <iostream>

//Definition of print()
void personType::print() const
{
    cout << getLast() << ' ' << getFirst();
}

//Definition of setName()
void personType::setName(string firstName, string lastName)
{
    fName = firstName;
    lName = lastName;
}

//Definition of getFirst()
string personType::getFirst() const
{
    return fName;
}

//Definition of getLast()
string personType::getLast() const
{
    return lName;
}

//Definition of Default Constructor
personType::personType(string firstName, string lastName)
{
    setName(firstName, lastName);
}
