// Jian Zhong
// Prof. Mackay
// CS132 Lab 7
// 10/23/2019
// ⚠️updates: 有 A B C三个cases，将A和C的算法分成两个部分，啰嗦一点。

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
}

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
    int op1, op2;

    // Scan the character one by one.
    for (int i = 0; i < postfixExp.length(); i++)
    {
        char token = postfixExp[i]; // each character of the Postfix expression

        // Case A:  If the scanned character is an positive digit, or a negative digit.
        if ( isalnum(token) )
        {
            int newOperand = postfixExp[i] - '0'; // a variable to store the token's int value
            
            for (;;)
            {
                // case 1): single-digit integer, quit the loop.
                if ( !isalnum(postfixExp[i + 1]) ) break;

                // case 2): not single single-digit integer
                newOperand = newOperand * 10 + (postfixExp[i + 1] - '0'); // update digit // ⚠️：这里是转换char 1 到int 1的方法. 或者直接减去48。
                i++;
            }
            
            aStack.push(newOperand); // push the positive digit onto stack
        }

        
        
        
        // Case C:  If the scanned character is a negative number.
        else if ( token == '-' && isalnum(postfixExp[i + 1]) )
        {
            i++; // ⚠️：别忘了加1，因为读多了一个负号。
            int newOperand = postfixExp[i] - '0'; // an integer variable to store the token's int value
            for(;;)
            {
                // case 1): quit the loop if single-digit integer
                if ( !isalnum(postfixExp[i + 1]) ) break;

                // case 2): not single single-digit integer
                newOperand = newOperand * 10 + (postfixExp[i + 1] - '0'); // update operand
                i++;
            }

            aStack.push( newOperand * (-1) ); // push the operand onto stack
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
                cout << "Invalid RPN expression: only 1 value on stack.\n";
                exit(1);
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

    return ( aStack.top() );
}
