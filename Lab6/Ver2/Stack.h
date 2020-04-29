// Jian Zhong
// Prof. Mackay
// CS132 Lab 5
//
//  Stack.h

#ifndef Stack_h
#define Stack_h

#include <iostream>
using namespace std;

class stack
{
    // Overload stream insertion operator: <<.
    friend ostream& operator << (ostream&, const stack&);
    
public:
    /***** Constructor *****/
    stack();
    
    // Copy constructor
    stack(const stack&);
    
    // Destructor
    ~stack();
    
    /***** Assignment *****/
    const stack& operator = (const stack&);
    
    // Top: retrieve the fisrt element from the stack
    int top() const;
    
    // Pop: remove an element from the top of the stack
    void pop();
    
    // Push: add an element to the top of the stack
    void push(const int&); //⚠️注意是const int&，不是int
    
    // Display the all elements of the stack array
    void display() const;
    
    // Function that tests it is empty
    bool empty() const;
    
private:
    int* stackPtr;  // dynamic array to store elements
    int myTop,      // top of stack
        capacity;   // capacity of stack
};

#endif /* Stack_h */
