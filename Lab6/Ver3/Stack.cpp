// Jian Zhong
// Prof. Mackay
// CS132 Lab 6
// 10/17/2019

/*-- Stack.cpp-------------------------------------------------------------
 This file implements Stack member functions.
 --------------------------------------------------------------------------*/

#include "Stack.h"

//--- Definition of Constructor
stack::stack()
{
    myTop = -1;
    capacity = 1024;
    stackPtr = new int [capacity];
}

//--- Definition of Copy Constructor
stack::stack(const stack& rightObj)
{
    myTop = rightObj.myTop;
    capacity = rightObj.capacity;
    
    stackPtr = new int [capacity]; // avoid shallow copy
    for (int i = 0; i < myTop; i++)
        stackPtr[i] = rightObj.stackPtr[i];
}

//--- Definition of empty()
bool stack::empty() const
{
    return (myTop == -1);
}

//--- Definition of Destructor
stack::~stack()
{
    delete [] stackPtr;
}

//--- Definition of operator =
const stack& stack::operator = (const stack& otherObj)
{
    if(this != &otherObj) // avoid self-assignment
    {
        delete [] stackPtr;
        myTop = otherObj.myTop;
        capacity = otherObj.capacity;
        
        stackPtr = new int [capacity]; // avoid shallow copy
        for (int i = 0; i < myTop ; i++)
            stackPtr[i] = otherObj.stackPtr[i];
    }
    
    return *this;
}

//--- Definition of top()
int stack::top() const
{
    if( !empty() )
        return stackPtr[myTop];
    else
    {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        return (stackPtr[capacity - 1]);
    }
}

//--- Definition of pop()
void stack::pop()
{
    if ( !empty() )
        myTop--;
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}

//--- Definition of push()
void stack::push(const int& item)
{
    if (myTop < capacity - 1) // check if the stack is full
    {
        ++myTop;
        stackPtr[myTop] = item;
    }
    else
    {
        cerr << "*** Stack full -- can't add new value ***\n"
        "Must increase value of STACK_CAPACITY in Stack.h\n";
        exit(1);
    }
}

//--- Definition of display()
void stack::display() const
{
    for(int i = myTop; i >= 0; i--)
        if(i == myTop)  // do not want to display '*' before the first prime factor
            cout << stackPtr[i];
        else
            cout << " * " << stackPtr[i];
    
    cout << endl;
}

//--- Definition of operator <<
ostream& operator << (ostream& out, const stack& rightObj)
{
    rightObj.display();
    return out;
}
