// Jian Zhong
// CS132 Lab 1
// 09/03/2019

// partTimeEmployee.cpp

#include "partTimeEmployee.h"

#include <iostream>
#include <iomanip>


using namespace std;

// Definition of print()
void partTimeEmployee::print() const
{
    personType::print();
    cout << setprecision(1); // keep one decimal.
    cout << fixed;
    cout << "'s wages: " << setw(3) << calculatePay() << endl;
}

// Definition of calculatePay()
double partTimeEmployee::calculatePay() const
{
    return pRate * hWorked;
}

// Definition of setInfo()
void partTimeEmployee::setInfo(double payRate, double hoursworked)
{
    if(payRate >= 0)
        pRate = payRate;
    else
        pRate = 0;

    if(hoursworked >= 0)
        hWorked = hoursworked;
    else
        hWorked = 0;
}

// Definition of Constructor
partTimeEmployee::partTimeEmployee(string firstName, string lastName, double payRate, double hoursworked)
                    :personType(firstName, lastName) // base initializer
{
    setInfo(payRate, hoursworked);
}
