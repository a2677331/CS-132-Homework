//
//  Stack.cpp
//  Lab5

#include "Stack.h"


//--- Definition of Constructor
stack::stack()
{
    length = 0;
    capacity = 128;
    stackPtr = new int [capacity]; //⚠️ 这里要记得new创造一个pointer array，因为是constructor
}

//--- Definition of Copy Constructor
stack::stack(const stack& rightObj)
{
    length = rightObj.length;
    capacity = rightObj.capacity;
    
    stackPtr = new int [capacity]; //⚠️
    for (int i = 0; i < length; i++)
        stackPtr[i] = rightObj.stackPtr[i];
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
        length = otherObj.length;
        capacity = otherObj.capacity;
        
        stackPtr = new int [capacity];  //⚠️
        for (int i = 0; i < length ; i++)
            stackPtr[i] = otherObj.stackPtr[i];
    }
    
    return *this;
}

//--- Definition of top()
int stack::top() const
{
    if( !empty() ) //⚠️不要忘记判断empty
        return stackPtr[length];
    else
    {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        return (stackPtr[length - 1]); // ⚠️make sure return garbage value because index is now negative
    }
}

//--- Definition of pop()
void stack::pop() //⚠️记得：只要让array的index减一即可！
{
    if ( !empty() )
        length--;
    else
        cerr << "*** Stack is empty -- can't remove a value ***\n";
}

//--- Definition of push()
void stack::push(int item)
{
    if(length <= capacity - 1)
    {
        stackPtr[length] = item; // put item on the top of the stack
        ++length;
    }
    else
    {
        cerr << "The stack is full, cannot store any more datas.\n";
        exit(1);
    }
}

//--- Definition of display()
void stack::display() const
{
    for(int i = length; i > 0; i--)
        if(i == length)
            cout << stackPtr[i - 1];
        else
            cout << " * " << stackPtr[i - 1];
    
    cout << endl;
}

//--- Definition of empty()
bool stack::empty() const
{
    return (length == 0); //⚠️
}

//--- Definition of operator <<
ostream& operator << (ostream& out, const stack& rightObj)
{
    rightObj.display();
    return out;
}
