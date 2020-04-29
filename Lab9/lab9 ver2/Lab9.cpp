// Jian Zhong
// Prof. Mackay
// CS132 Lab 9
// 11/17/2019

#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes:
bool palCheck(string, int = 0);  // The string version palCheck
bool palCheck(int, int);         // The integer version palCheck
int countDigit(int, int = 0);    // Function to count the digit # of an integer


// *--- Driver Code ---*
int main()
{
    string str; // a string input
    int num;    // a positive number input
    
    // Using the String version palCheck:
    cout << "*** String version Palindrome Check ***"
         << "\nEnter Input: ";
    cin >> str;
    if ( palCheck(str) )
        cout << "It is a palindrome.\n";
    else
        cout << "NOT a palindrome.\n";
    
    // Using the Integer version palCheck:
    cout << "\n*** Integer version Palindrome Check ***"
         << "\nEnter Input: ";
    cin >> num;
    if ( palCheck(num, countDigit(num)) )
        cout << "It is a palindrome.\n\n";
    else
        cout << "NOT a palindrome.\n\n";
    
    return 0;
} // *--- End of Driver Code ---*


// Definition of string version palCheck ():
bool palCheck(string arr, int firstPos)
{
    unsigned lastPos = arr.length() - 1 - firstPos;   // last index of the string
    
    if (firstPos < lastPos)								   // Base Case 1 -- no engouth index to compare
    {
        if ( arr[firstPos] != arr[lastPos] ) return false; // Base Case 2 -- does not match value
        
        return ( palCheck(arr, firstPos + 1) );            // Recursive Case -- if match, keep checking
    }
    return true;
}

// Definition of integer version palCheck ():
bool palCheck(int num, int numDigit) // The integer version palCheck
{
    if (numDigit <= 1) return true;			      // Base Case 1 -- if equal to or less than one value is left
    
    int firstDigit = num / pow(10, numDigit - 1), // the first digit of num
        lastDigit = num % 10;                     // the last digit of num
    
    if (firstDigit != lastDigit) return false;    // Base Case 2 -- does not match value
    
    return ( palCheck((num % static_cast<int>(pow(10, numDigit - 1))) / 10, 
                      numDigit - 2) );			  // Recursive Case -- get rid of the first and last digit, keep checking
}

// Definition of countDigit ():
int countDigit(int num, int counter)
{
    counter++;
    
    if (num / 10 == 0) return counter;			  // Base Case -- integers counting is complete

    return ( countDigit(num / 10, counter) );	  // Recursive Case -- if not, keep counting
}
