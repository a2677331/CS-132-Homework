// Jian Zhong
// Prof. Mackay
// CS132 Lab 6
// 10/17/2019

#include <iostream>
#include "Stack.h"

using namespace std;

/* Function to find the prime factors
 of a positive number that is greater than 1. */
void findPrimeFactors(int, stack&);
void testDataInput(istream&, int&); // ⚠️validation这里的int后面要加&，要不就容易出错。


/*-------------------------Driver Function--------------------------*/
int main()
{
    char answer;
    int n;  // number for the prime factorization
    
    do
    {
        stack pFactor; // declare a stack type
        cout << "Please enter a positive integer GREATER THAN 1: ";
        cin >> n;
        testDataInput(cin, n); // Input validation
        findPrimeFactors(n, pFactor);  // Find the prime factors of n

        // Print the prime factors of n
        cout << "The prime factorization is: ";
        cout << pFactor;

        // prompt user to try again or not
        cout << "Again? (Y or N)\n";
        cin >> answer;
        
    }while(answer == 'Y' || answer == 'y');
    
    return 0; // end of main
}


// Definition of findPrimeFactors();
void findPrimeFactors(int n, stack& pFactor)
{
        int d = 2; // the smallest integer greater than 1
        while(n != 1)
            if (n % d == 0) // if d divides n, d is a prime factor.
            {
                pFactor.push(d); // push the prime factor d into stack
                n = n / d; // replace n by the quotient of n divided by d.
            }
            else
                d++;
}

// Input Validation
void testDataInput(istream& in, int& input)
{
    while (!in || (in.peek() != '\n'))
    {
        in.clear();           // clear bad input
        in.ignore(200, '\n'); // discard input
        cout << "Invalid input, please enter again: ";
        in >> input;          // update the input
    }
    
    if (input <= 1)
    {
        in.ignore(200, '\n'); // discard input
        cout << "Use a positive non-zero integer, enter again: ";
        in >> input;          // update the input
        testDataInput(in, input);
    }
        
}
