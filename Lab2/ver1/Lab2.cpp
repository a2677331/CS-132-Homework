// Jian Zhong
// Prof. Mackay
// 09/10/2019
// Lab 2


#include<iostream>
using namespace std;

// function prototypes go here
void Swap(int *num1ptr, int *num2ptr);
int *larger(int *um1ptr, int *num2ptr);

int main()
{
    int *num1ptr, *num2ptr;
    
    num1ptr = new int;
    num2ptr = new int;
    
    cout << "Please enter 2 integers: ";
    cin >> *num1ptr >> *num2ptr;
    
    cout << "You entered " << *num1ptr << " and " << *num2ptr << endl;
    
    // the call to the Swap function
    Swap(num1ptr, num2ptr);
    
    cout << "After Swapping, the values are " << *num1ptr << " and " << *num2ptr << endl;
    
    //the call the the 'larger' function
    cout << "The larger of the 2 values is: " << *larger(num1ptr, num2ptr) << endl;
    return 0;
}

// function definitions go here
void Swap(int *num1ptr, int *num2ptr) //the Swap function
{
    int tmp; //temporary int variable for swapping integers
    
    tmp = *num1ptr;
    *num1ptr = *num2ptr;
    *num2ptr = tmp;
}

int *larger(int *num1ptr, int *num2ptr) //the 'larger' function
{
    if (*num1ptr > *num2ptr)
        return num1ptr;
    else
        return num2ptr;
}
