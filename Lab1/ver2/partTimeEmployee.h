// Jian Zhong
// CS132 Lab 1
// 09/03/2019

// partTimeEmployee.h

#ifndef partTimeEmployee_h
#define partTimeEmployee_h


#include "personType.h"

class partTimeEmployee: public personType
{
public:
    //Output
    void print() const;
    //Function to output the first name, last name, and wages.
    //Postcondition: last name first name's wages: $$$$.$$ are printed.

    //Accessor
    double calculatePay() const;
    //Function to calculate and return the wages.
    //Postcondition:  Pay is calculated and returned.

    //Mutator
    void setInfo(double, double);
    //Function to set payrate and hoursworked according to the parameters
    //Postcondition:     pRate = payRate; hWorked = hoursworked;
    //                   fName = firstName;  lName = lastName;

    //Constructor
    partTimeEmployee(string = "", string = "", double = 0.0, double = 0.0);
    //If no values are set, the default values are set to zero and empty string.
    //Postcondition: fName = "", lName = "", payRate = 0.0, hoursworked = 0.0
    
private:
        double pRate; // employee's payrate
        double hWorked; //employee's work hours
};

#endif /* partTimeEmployee_h */
