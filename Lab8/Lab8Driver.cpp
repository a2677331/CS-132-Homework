// Jian Zhong
// Prof. Mackay
// CS132 Lab 8
// 11/02/2019

#include "Queue.h"

#include <iostream>

using namespace std;

int main()
{
    Queue<int> intQueue; // Queue of type int
    Queue<char> strQueue; // Queue of type string
    char c = 'a';

    cout << " *** Inputting 10 values into int type Queue *** \n";
    for (int i = 10; i < 20; i++)
        intQueue.enqueue(i); // add values into intQueue
    cout << "Now the int Queue is: ";
    intQueue.display(cout); // display intQueue



    cout << "\n *** Inputting 10 values into char type Queue *** \n";
    for (int i = 10; i < 20; i++)
    {
        strQueue.enqueue(c); // add values into strQueue
        c++;
    }
    cout << "Now the char Queue is: ";
    strQueue.display(cout); // display strQueue




    return 0;
}
