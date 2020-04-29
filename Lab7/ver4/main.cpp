// Jian Zhong
// Prof. Mackay
// CS132 Lab 7
// 10/25/2019

#include "DStack.h"         // a stack class

#include <iostream>         // <<, >>, cout, cin
#include <cmath>            // pow()
#include <string>           // string, ==, find,
#include <cctype>           // isalnum()
using namespace std;

// Function Prototypes
bool isOperator(const char&);       // prototype of isOperator() function
double evaluatePostfix(const string&); // prototype of evaluatePostfix() function

// Driver
int main()
{
    string postfixExp;
    cout << "NOTE: Enter # for Postfix expression to stop. \n"
    << "*** For decimal number evaluation, please change the StackElement typedef into \"double\" in DStack.h. ***\n";
    for (;;)
    {
        cout << "Postfix expression for evaluation: ";
        getline(cin, postfixExp);

        if (postfixExp == "#") break;

        cout << "The result is: "
             << evaluatePostfix(postfixExp) << endl << endl;
    }
    return 0;
} // End of Driver


// Definition of isOperator ()
/*-------------------------------------------------------------------------
   Function to find specific operators.

   Precondition:  None.
   Postcondition: return true if postfix operators are found,
                  return false if operators cannot be found.
-------------------------------------------------------------------------*/
bool isOperator(const char& c)
{
    return ( c == '+' || c == '-' ||
             c == '*' || c == '/' ||
             c == '^' || c == ' ' ||
             c == '.');
}


// Definition of evaluatePostfix ()
/*-------------------------------------------------------------------------
   Function to evaluate an postfix expression exp.

   Precondition:  None.
   Postcondition: an evaluation of the Postfix expression is returned
       or an error message displayed if exp is not well-formed.
-------------------------------------------------------------------------*/
double evaluatePostfix(const string& postfixExp)
{
    Stack aStack;   // declare a stack
    double op1, op2;   // the first and the second retrieved operand.
    int operatorCounter = 0, operandCounter = 0;

    // Scan the character one by one.
    for (size_t i = 0; i < postfixExp.length(); i++)
    {
        // Validation 1: check if the scanned character contains invalid operator or invalid operand.
        if ( !isOperator(postfixExp[i]) && !isdigit(postfixExp[i]) )
        {
            cout << "*** Invalid RPN Expression ***, returning garbage value:";
            StackElement garbage = -1;
            return garbage;
        } // End of Validation 1

        char token = postfixExp[i]; // the scanned character

        // CASE A: if the token is valid digit:
        if ( isdigit(token) || (token == '-' && isdigit(postfixExp[i + 1])) )
        {
            operandCounter++; // increase operand counter by 1.

            // Identify the negative operand:
            if (token == '-')
                i++; // increase i by 1 if scanned '-'

            double newOperand = static_cast<double>(postfixExp[i]) - '0'; // the token's double value

            // Identify single-digit integer, Non single-digit integer or decimal number:
            for (;;)
            {
                // Case 1: if the extra digit is not digit or not decimal point:
                if ( !isdigit(postfixExp[i + 1]) && (postfixExp[i + 1] != '.') ) break; // finish identification, quit the loop.

                // Case 2: if the extra digit is not a decimal point, get the Non single-digit integer:
                if (postfixExp[i + 1] != '.')
                {
                    newOperand = newOperand * 10 + (static_cast<double>(postfixExp[i + 1]) - '0');
                    i++;
                }

                // Case 3: if the extra digit is a decimal point, get the decimal number:
                if (postfixExp[i + 1] == '.')
                {
                    i++;
                    int j = 1;
                    double temp = newOperand; // variable to store decimal number
                    while ( isdigit(postfixExp[i + 1]) ) // find each decimal number
                    {
                        temp = temp + ( (static_cast<double>(postfixExp[i + 1]) - '0') / pow(10, j) );
                        i++; j++;
                    }
                    newOperand = temp; // assign the decimal number back to the Operand
                }
            }

            // Push the operand onto stack:
            if (token != '-') // if is positive operand
                aStack.push(newOperand);
            else              // if is negative operand
                aStack.push( newOperand * (-1) );
        }

        // CASE B: If the token is white space, skip it.
        else if (token == ' ') { }

        // CASE C: If the token is an operator, evaluate:
        else if ( isOperator(token) )
        {
            operatorCounter++; // is operator, increase counter by 1.

            // Retrieve and remove the top value from stack:
            op1 = aStack.top();
            aStack.pop();

            // Validation 2: if only 1 value on stack, it is an invalid RPN exp.
            if ( !aStack.empty() ) // after remove, if exists value in stack
            {
                op2 = aStack.top();
                aStack.pop();
            }
            else // if no value left in stack, display message
            {
                cout << "*** Invalid RPN Expression ***, returning garbage value: ";
                StackElement garbage = -1;
                return garbage;
            } // End of Validation 2

            // Apply operator to the two values and Push resulting value back onto stack:
            switch (token)
            {
                case '+': aStack.push(op2 + op1); break;
                case '-': aStack.push(op2 - op1); break;
                case '/': aStack.push(op2 / op1); break;
                case '*': aStack.push(op2 * op1); break;
                case '^': aStack.push( pow(op2, op1) ); break; // find op2 ^ op1
                default: break;
            } // End of Switch
        } // End of Case B
    }  // End of Exp Scanning loop

    double result = aStack.top(); // get the evaluation of the postfix exp
    aStack.pop();

    // Validation 3: check if operand # is equal to operator # + 1:
    if (operandCounter != operatorCounter + 1)
    {
        cout << "*** Invalid RPN Expression ***, returning garbage value: ";
        StackElement garbage = -1;
        return garbage;
    } // End of validation 3

    // Validation 4: check if only one value left in stack
    if ( aStack.empty() )
        return result;
    else
    {
        cout << "*** Invalid RPN Expression ***, returning garbage value: ";
        StackElement garbage = -1;
        return garbage;
    } // End of validation 4
}
