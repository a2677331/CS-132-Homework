// Jian Zhong
// CS132 Lab 1
// Todays Date

#include "personType.h" //⚠️ 好像不一定要加的
#include "partTimeEmployee.h"

#include <iostream>
#include <string>

using namespace std;

//Output
void partTimeEmployee::print() const
{
    personType::print();
    cout << "'s wages: " << calculatePay() << endl;
}

//Accessor
double partTimeEmployee::calculatePay() const
{
    return pRate * hWorked;
}

//Mutator
void partTimeEmployee::setInfo(double payRate, double hoursworked)
{
    if(payRate >= 0) //⚠️之前忘了设置这个条件
        pRate = payRate;
    else
        pRate = 0;

    if(hoursworked >= 0) //⚠️之前忘了设置这个条件
        hWorked = hoursworked;
    else
        hWorked = 0;
}

//Constructor
partTimeEmployee::partTimeEmployee(string firstName, string lastName, double payRate, double hoursworked)
                    :personType(firstName, lastName) //⚠️注意只有constructors可以用（base initializer）
{
    setInfo(payRate, hoursworked);
}
