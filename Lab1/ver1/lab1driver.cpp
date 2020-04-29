// Jian Zhong
// CS132 Lab 1
// Todays Date

#include <iostream>
#include <string>
#include "personType.h"
#include "partTimeEmployee.h" //Part Time Employee

using namespace std; 
   
int main()
{
	// creating an object with values
    partTimeEmployee newEmp("John", "Smith", 15.34, 67);
    //⚠️invoke specific class object only by constructor parameter

	// printing the values for that object
    newEmp.print();

    return 0;
}
