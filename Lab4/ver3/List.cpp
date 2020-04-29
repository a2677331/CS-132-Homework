// Jian Zhong
// Prof. Mackay
// CS132 Lab 4
// 09/25/2019


/*-- List.cpp------------------------------------------------------------

 This file implements List member functions.

 -------------------------------------------------------------------------*/


#include "List.h"

#include <cassert>
#include <iomanip>
#include <fstream>

/*⚠️：Don't use "using namespace std" in a header file, Bad pratice!
 Remove using namespace std (since your code is a class definition,
 which often properly belongs in a header file if you want to use your class types in multiple source files, and using namespace std is bad practice in a header file)
*/

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
void List::display(ostream & out) const
{
    for(int i = 0; i < mySize; i++)
        out << myArray[i];
    out << endl;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
    if (mySize == CAPACITY)
    {
        cerr << "*** No space for list element -- terminating "
                "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "*** Illegal location to insert -- "
             << pos + 1 << ".  List unchanged. ***\n\n";
        return;
    }

    // First shift array elements right to make room for item
    for (int i = mySize; i > pos; i--)
        myArray[i] = myArray[i - 1];

    // Now insert item at position pos and increase list size
    myArray[pos] = item;
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
        cerr << "*** Illegal location to delete -- "
             << pos + 1 << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for (int i = pos; i < mySize; i++)
        myArray[i] = myArray[i + 1];

    // Decrease list size
    mySize--;
}

//--- Definition of output operator
ostream & operator << (ostream & out, const ElementType & aItem)
{
    // format the output
    out << fixed << showpoint << setprecision(2);

    // output all info of intemType
    out << setw(4) << right << aItem.itemNumber
        << setw (3) << aItem.numberInStock
        << setw (7) << aItem.unitPrice
        << setw (4) << aItem.minimumInventoryLevel << ' '
        << aItem.itemName << endl;

    return out;
}

//--- Definition of input operator //
istream & operator >> (istream & in, ElementType & aItem)
{
    cout << "Item number: ";
    in >> aItem.itemNumber;
    cout << "Number in stock: ";
    in >> aItem.numberInStock;
    cout << "Unit price: ";
    in >> aItem.unitPrice;
    cout << "Minimum inventory level: ";
    in >> aItem.minimumInventoryLevel;
    cout << "Item name: ";
    in >> aItem.itemName;

    return in;
}

//--- Definition of file input operator // ⚠️ For the use of first reading in data from .txt file.
ifstream& operator >> (ifstream& in, ElementType& aItem)
{
    in >> aItem.itemNumber;
    in >> aItem.numberInStock;
    in >> aItem.unitPrice;
    in >> aItem.minimumInventoryLevel;
    in >> aItem.itemName;

    return in;
}
