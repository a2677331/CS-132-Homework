// Jian Zhong
// Prof. Mackay
// CS132 Lab 3


/*-- List.cpp------------------------------------------------------------
 
 This file implements List member functions.
 
 -------------------------------------------------------------------------*/
#include "List.h"
#include "Item.h"

#include <cassert>
#include <iomanip>
using namespace std;

//--- Definition of class constructor
List::List()
: mySize(0)
{}

//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}

//--- Definition of display()
void List::display(ofstream & out) const
{
    out.open("NewInventory.txt"); // open file
    
    out << fixed << showpoint << setprecision(2);
    for (int i = 0; i < mySize; i++)  //⚠️i < mySize - 1： 为了避免把多输出一行全是0的输出到文本，为什么可以这样？
        out << right << myArray[i].itemNumber << ' '
        << setw (2) << myArray[i].numberInStock << ' '
        << setw (6) << myArray[i].unitPrice << ' '
        << setw (3) << myArray[i].minimumInventoryLevel << ' '
        << myArray[i].itemName << endl;
    
    out.close(); //close file
}

//--- Definition of output operator
ofstream & operator<< (ofstream & out, const List & aList)
{
    aList.display(out);
    return out;
}

//--- Definition of insert()
void List::insert(ElementType item[], int pos)
{
    if (mySize == CAPACITY)
    {
        cerr << "*** No space for list element -- terminating "
        "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "*** Illegal location to insert -- " << pos
        << ".  List unchanged. ***\n\n";
        return;
    }
    
    // First shift array elements right to make room for item
    for (int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];
    
    // Now insert item at position pos and increase list size
    myArray[pos] = item[pos];
    mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cerr << "*** Illegal location to delete -- " << pos
        << ".  List unchanged. ***\n";
        return;
    }
    
    // Shift array elements left to close the gap
    for (int i = pos; i < mySize; i++)
        myArray[i] = myArray[i + 1];
    
    // Decrease list size
    mySize--;
}

//--- Definition of decrease()
void List::decrease() // ⚠️我自己加的：因为if（!fin）读多了一次mySize，所以这里mySize要减1.
{
    mySize--;
}
