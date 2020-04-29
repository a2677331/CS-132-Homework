// Jian Zhong
// Prof. Mackay
// CS132 Lab 9
// 11/17/2019

#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes:
bool palCheck(string, int = 0); // The string version palCheck
bool palCheck(int, int);        // The integer version palCheck
int countDigit(int, int = 0);   // Function to count the # of an integer



// *--- Driver Code ---*
int main()
{
    string str; // a string input
    int num;    // a positive number input
    
    // Using the String version palCheck func:
    cout << "*** String version palCheck ***"
         << "\nEnter Input: ";
    cin >> str;
    if ( palCheck(str) )
        cout << "It is a palindrome.\n";
    else
        cout << "NOT a palindrome.\n";
    
    // Using the Integer version palCheck func:
    cout << "\n*** Integer version palCheck ***"
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
    unsigned long lastPos = arr.length() - 1 - firstPos; // last index of the string to be compared
    
    if (firstPos < lastPos)
    {
        // Base Case: if the first value does not match the last value, return false.
        if ( arr[firstPos] != arr[lastPos] ) return false;
        
        // Recursive Case: if match, call the algorithm recursively.
        return ( palCheck(arr, firstPos + 1) );
        // ⚠️ 这个搞了很久，别漏了return，return确保了有不正确就结束程序，而不是返回最初执行时还会给true的输出。
    }
    return true;
    

// Definition of integer version palCheck ():
bool palCheck(int num, int numDigit) // The integer version palCheck
{
    // Base Case 1: if less than one value is left, return true.
    if (numDigit <= 1) return true;
    
    int firstDigit = num / pow(10, numDigit - 1), // get the first digit of num variable
        lastDigit = num % 10;                     // get the last digit of num variable
    
    // Base Case 2: if first digit is not equal to last digit, return false.
    if (firstDigit != lastDigit) return false;
    
    // Recursive Case: cross num variable out, and apply for the algorithm recursively.
    return ( palCheck((num % static_cast<int>(pow(10, numDigit - 1))) / 10, numDigit - 2) ); // ⚠️ 别漏了return
    /* ----------------------------------------------------------------
     ⚠️ Due to the value of pow () is always double,
     and % is a binary operator,which works for only integer operands,
     so need to change value of pow () into integer before use %.
    ---------------------------------------------------------------- */
}

// Definition of countDigit ():
int countDigit(int num, int counter)
{
    counter++;
    
    if (num / 10 == 0)
        return counter;
    
    // ⚠️ 这里记得要加counter， 要不然会永远从0开始，输出错误值：1.
    // ⚠️ 注意和下面的区别，这个不会有多重输出，输出正确！
    return ( countDigit(num / 10, counter) );
    
    // ⚠️ 注意和上面的区别，这个是错的，有多重输出，输出错误！
    // countDigit(num / 10, counter);
    // return counter;
}
