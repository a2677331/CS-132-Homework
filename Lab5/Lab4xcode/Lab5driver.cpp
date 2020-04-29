// Jian Zhong
// Prof. Mackay
// CS132 Lab 5
// 10/01/2019

#include "DList.h"
#include <iostream>
using namespace std;

int main()
{
    List aList;    // create a new list
    int nLSize = 3; // the size of the new list
    
    int item = 66; // the first intem to be inserted in the list
    
    // Insert 10 elements into the List
    for(int i = 0; i < nLSize; i++)
    {
        aList.insert(item, i);
        item++;
    }
    
    // display the list
    cout << "The list is: "
         << aList << endl;
    
    // reverse the list
    aList.reverse(aList); // ⚠️Copy Constructor is called When an object of the class is returned by value.
    
    // ⚠️ Why destructor displays here? 答：因为alist被reverse function pass进去，执行完reverse function后alist这个object就会被摧毁！
    
    // display the list again
    cout << "After reversion, the list is: "
         << aList << endl;
    
    return 0;
}
