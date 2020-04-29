// Jian Zhong
// Prof. Mackay
// CS132 Lab 7
// 10/25/2019
// ⚠️ Updates： validation 都弄好了，就是decimal number判定是无效的， 还需要修改double的计算。


#include "DStack.h"         // a stack class

#include <iostream>         // <<, >>, cout, cin
#include <cmath>            // pow()
#include <string>           // string, ==, find,
#include <cctype>           // isalnum()
using namespace std;

// Function Prototypes
bool isOperator(const char&);       // prototype of isOperator() function
int evaluatePostfix(const string&); // prototype of evaluatePostfix() function

// Driver
int main()
{
    string postfixExp;
    cout << "NOTE: Enter # for Postfix expression to stop.\n";
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
             c == '^' || c == ' ');
}


// Definition of evaluatePostfix ()
/*-------------------------------------------------------------------------
   Function to evaluate an postfix expression exp.

   Precondition:  None.
   Postcondition: an evaluation of the Postfix expression is returned
       or an error message displayed if exp is not well-formed.
-------------------------------------------------------------------------*/
int evaluatePostfix(const string& postfixExp)
{
    Stack aStack;   // declare a stack
    int op1, op2;   // the first and the second retrieved operand.
    int operatorCounter = 0, operandCounter = 0;
    
    // Scan the character one by one.
    for (int i = 0; i < postfixExp.length(); i++)
    {
        // Validation 1: check if the scanned character contains invalid operator or invalid operand.
        if ( !isOperator(postfixExp[i]) && !isdigit(postfixExp[i]) )
        {
            cout << "*** Invalid RPN Expression: "
            << "invalid operator or invalid operand exists. ***, returning garbage value:";
            StackElement garbage;
            return (garbage);
        } // End of Validation 1
        
        char token = postfixExp[i]; // scanned character of the postfix exp

        // CASE A:  If the scanned character is a digit or negative digit:
        if ( isdigit(token) || (token == '-' && isdigit(postfixExp[i + 1])) )
        {
            operandCounter++; // is operand, increase counter by 1.
             
            if (token == '-')
                i++; // increase i by 1 if scanned '-'

            int newOperand = postfixExp[i] - '0'; // the token's int value

            for (;;)
            {
                // case A1: single-digit integer, quit the loop.
                if ( !isdigit(postfixExp[i + 1]) ) break;

                // case A2: not single single-digit integer, do following:
                newOperand = newOperand * 10 + (postfixExp[i + 1] - '0'); // update digit
                i++;
            }

            if (token != '-')
                aStack.push(newOperand); // push the positive operand onto stack
            else
                aStack.push( newOperand * (-1) ); // push the negative operand onto stack
        }
        
        // CASE B: If the scanned character is white space, skip it.
        else if (token == ' ') { }
        
        // CASE C: If the scanned character is an operator, evaluate:
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
                cout << "*** Invalid RPN Expression: "
                << "invalid format. ***, returning garbage value: ";
                StackElement garbage;
                return (garbage);
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
    
    int result = aStack.top(); // get the evaluation of the postfix exp
    aStack.pop();

    // Validation 3: check if operand # is equal to operator # + 1:
    if (operandCounter != operatorCounter + 1)
    {
        cout << "*** Invalid RPN Expression: "
        << "operand # and operator # does not match. ***, returning garbage value: ";
        StackElement garbage;
        return (garbage);
    } // End of validation 3
    
    // Validation 4: check if only one value left in stack
    if (aStack.empty())
        return (result);
    else
    {
        cout << "*** Invalid RPN Expression: "
        << "failed to fine enough operand to evaluate. ***, returning garbage value: ";
        StackElement garbage;
        return (garbage);
    } // End of validation 4
}
