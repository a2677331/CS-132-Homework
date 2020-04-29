// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 00/00/2019
// Project1.cpp

#include <iostream>

using namespace std;

#include "rationalNum.h"

int main()
{
    rationalNum rNum1, rNum2; // two rational numbers
    int rNumerator,           // rational numerator
        rDenominator;         // rational denominator
    char FOerator,            // first Operator
         SOerator = '\0',     // second Operator
         option;              // user's option

    do // Display Menu
    {
        // Read the First rational number
        cout << "Please enter an expression: ";
        cin >> rNumerator;
        rNum1.setNum(rNumerator);
        cin.ignore();  // Skip the rational symbol between Rational Numerator and Rational Denominator.
        cin >> rDenominator;
        rNum1.setDen(rDenominator);
        
        // Read operator between between two rational numbers
        cin >> FOerator;   // read the first operator
        if(cin.peek() == '=') // peek if the second operator symbol exists
        {
            SOerator = '='; // if exists, assign second operator
            cin.ignore();
        }

        
        // Read the Second rational number
        if(FOerator != 'I' && FOerator != 'M' && FOerator != 'R'
           && FOerator != 'i' && FOerator != 'm' && FOerator != 'r')
        {
            cin >> rNumerator;
            rNum2.setNum(rNumerator);
            cin.ignore();  // Skip the rational symbol between Rational Numerator and Rational Denominator.
            cin >> rDenominator;
            rNum2.setDen(rDenominator);
        }
        
        // Print Result
        switch (FOerator)
        {
            // when the operator is +
            case '+':
                cout << rNum1 + rNum2;
                break;
            
            // when the operator is -
            case '-':
                cout << rNum1 - rNum2;
                break;
            
            // when the operator is *
            case '*':
                cout << rNum1 * rNum2;
                break;
            
            // when the operator is /
            case '/':
                cout << rNum1 / rNum2;
                break;
            
            // when the operator is R or r
            case 'R':
            case 'r':
                rNum1.reduce();
                cout << rNum1;
                break;
            
            // when the operator is I or i
            case 'I':
            case 'i':
                rNum1.invert(rNum1);
                cout << rNum1;
                break;
                
            // when the operator is M or m
            case 'M':
            case 'm':
                rNum1.mixed();
                cout << rNum1;
                break;
                
            // when the operator is <
            case '<':
                if(SOerator == '=') // when the operator is <=
                {
                    if(rNum1 <= rNum2)
                        cout << "Ture\n";
                    else
                        cout << "False\n";
                    break;
                }
                else if(rNum1 < rNum2)
                    cout << "Ture\n";
                else
                    cout << "False\n";
                break;
                
            // when the operator is >
            case '>':
                if(SOerator == '=') // when the operator is >=
                {
                    if(rNum1 >= rNum2)
                        cout << "Ture\n";
                    else
                        cout << "False\n";
                    break;
                }
                else if(rNum1 > rNum2)
                    cout << "Ture\n";
                else
                    cout << "False\n";
                break;
            
            // when the operator is ==
            case '=':
                if(SOerator == '=')
                {
                    if(rNum1 == rNum2)
                        cout << "Ture\n";
                    else
                        cout << "False\n";
                    break;
                }
                else if(rNum1 == rNum2)
                    cout << "Ture\n";
                else
                    cout << "False\n";
                break;
                
            default:
                break;
        } // end of Switch statement
        
        // Prompt user to try again or not
        cout << "\nAgain(Y or N)? ";
        cin >> option;
    }while(option == 'y' || option == 'Y'); // end of do-while loop
    
    return 0;
}
