// Jian Zhong
// CS132 Lab 1
// Todays Date

#include <iostream>
#include <string>
#include "partTimeEmployee.h"

using namespace std;

int main()
{
    // creating an object with values
    partTimeEmployee newEmp("John", "Smith", 15.34);
    
    // printing the values for that object
    newEmp.print();
    
    return 0;
}
