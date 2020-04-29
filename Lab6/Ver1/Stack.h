//
//  Stack.h
//  Lab5

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
    void push(int);
    
    // Display the all elements of the stack array
    void display() const;
    
    // Function that tests it is empty
    bool empty() const;
    
private:
    int* stackPtr;  // pointer to stack array of int type
    int length;     // current length of the stack
    int capacity;   // the capacity of the stack array
};

#endif /* Stack_h */
