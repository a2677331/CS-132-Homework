// Jian Zhong
// Prof. Mackay
// CS132 Lab 7
// 10/23/2019

#include "DStack.h"

#include <iostream>
#include <cmath>            // pow()
#include <string>           // string, ==, find,
#include <cctype>           // isalnum()

using namespace std;

// Function Prototypes
bool isOperator(const char&);
int evaluatePostfix(const string&);


// Driver Function
int main()
{
    string postfixExp;
    cout << "NOTE: Enter # for Postfix expression to stop.\n";
    for (;;)
    {
        cout << "Postfix expression for evaluation: ";
        getline(cin, postfixExp);

        if (postfixExp == "#") break;

        cout << "The result is: " << evaluatePostfix(postfixExp)
             << endl << endl;
    }
    return 0;
} // End of Driver


// Definition of isOperator ()
bool isOperator(const char& c)
{
    return ( c == '+' || c == '-' ||
             c == '*' || c == '/' ||
             c == '^');
}

// Definition of evaluatePostfix ()
int evaluatePostfix(const string& postfixExp)
{
    Stack aStack;
    int op1,   // the first retrieved operand
        op2;   // the second retrieved operand

    // Scan the character one by one.
    for (int i = 0; i < postfixExp.length(); i++)
    {
        char token = postfixExp[i]; // each character of the Postfix expression

        // Case A:  If the scanned character is an positive digit, or a negative digit.
        if ( isalnum(token) || (token == '-' && isalnum(postfixExp[i + 1])) )
        {
            if (token == '-') // if is negative number
                i++; // increase i by 1 because '-' had been scanned.

            int newOperand = postfixExp[i] - '0'; // a variable to store the token's int value

            for (;;)
            {
                // case 1: single-digit integer, quit the loop.
                if ( !isalnum(postfixExp[i + 1]) ) break;

                // case 2: not single single-digit integer, do following:
                newOperand = newOperand * 10 + (postfixExp[i + 1] - '0'); // update digit
                i++;
            }

            if (token != '-')
                aStack.push(newOperand); // push the positive digit onto stack
            else
                aStack.push( newOperand * (-1) ); // push the negative digit onto stack
        }

        // Case B: If the scanned character is an operator
        else if ( isOperator(token) )
        {
            // Push and Pop 2 values from stack.
            op1 = aStack.top();
            aStack.pop();

            if ( !aStack.empty() )  // Validation: if not just 1 value on stack.
            {
                op2 = aStack.top();
                aStack.pop();
            }
            else // only 1 value on stack, display message.
            {
                cout << "invalid RPN expression, returning garbage value: ";
                StackElement garbage;
                return (garbage);
            }

            /* Apply operator to the two values,
            and Push resulting value back onto stack */
            switch (token)
            {
                case '+': aStack.push(op2 + op1); break;
                case '-': aStack.push(op2 - op1); break;
                case '/': aStack.push(op2 / op1); break;
                case '*': aStack.push(op2 * op1); break;
                case '^': aStack.push( pow(op2, op1) ); break; // find op2 ^ op1
                default: break;
            } // End of Switch
        } // End of Case B: if Operator
    }  // End of the Expression scanning

    int result = aStack.top(); // get the evaluation of the postfix exp
    aStack.pop();

    // check if value of expression is the only number left in stack
    if (aStack.empty())
        return (result);
    else
    {
        cout << "Invalid RPN expression, returning garbage value: ";
        StackElement garbage;
        return (garbage);
    }
}
