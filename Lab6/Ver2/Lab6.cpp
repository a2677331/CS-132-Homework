// Jian Zhong
// Prof. Mackay
// CS132 Lab 5
// 00/00/2019

#include <iostream>
#include "Stack.h"

using namespace std;

// Function to find the prime factors
// of a positive number that is greater than 1.
void findPrimeFactors(int, int, stack&);

/*-------------------------Driver Function--------------------------*/
int main()
{
    char answer;
    int n, d = 0;
    
    do
    {
        stack pFactor; // declare a stack type
        cout << "Please enter a positive integer, GREATER THAN 1: ";
        cin >> n; // input number for prime factorization

        // Find the prime factors of n
        findPrimeFactors(n, d, pFactor);

        // Print the prime factors of n
        cout << "The prime factors are: ";
        cout << pFactor;

        // prompt user to try again or not
        cout << "Again? (Y or N)\n";
        cin >> answer;
    }while(answer == 'Y' || answer == 'y');
    
    return 0; // end of main
}


// Definition of findPrimeFactors();
void findPrimeFactors(int n, int d, stack& pFactor)
{
    // if integer n is greater than 1, find prime factors.
    if(n > 1)
    {
        d = 2;
        while(n != 1)
            if (n % d == 0) // if d divides n, d is a prime factor.
            {
                pFactor.push(d); // insert the prime factor d into stack
                n = n / d; // replace n by the quotient of n divided by d.
            }
            else
                d++;
    }
    // if integer n is equal or less than 1.
    else
        cout << "INVALID input." << endl;
}
