// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019


/*-- linkedlist.cpp------------------------------------------------------------

 This file implements linkedlist member functions.

 -------------------------------------------------------------------------*/

#include "linkedlist.h"

#include <cassert>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <iostream>


// Definition of Constructor
List::List()
: mySize(0), first(0)
{ }


// Definition of Copy Constructor
List::List(const List& origList)
{
    // send first and mySize vals from oriList object into this object.
    first = 0;
    mySize = origList.mySize;
    if (mySize == 0) return;
    
    List::NodePtr last, origPtr;
    
    first = new Node(origList.first->data); // allocate memory and copy data into the allocated memory
    last = first; // set last pointer point to the first node
    origPtr = origList.first->next; // set origPtr point to the next original Node, waiting to be copied
    while (origPtr != 0)
    {
        last->next = new Node(origPtr->data); // set last point to a new allocated memory and store data into that memory
        last = last->next; // update the last pointer to be the actually last node
        origPtr = origPtr->next; // update the origPtr point to next node in the original linked list.
    }
}


// Definition of Destructor ()
List::~List()
{
    List::NodePtr prePtr = first, Ptr;
    while (prePtr != 0)
    {
        Ptr = prePtr->next;
        delete prePtr;
        prePtr = Ptr;
    }
}


// Definition of reverse ()
void List::reverse()
{
    // If empty list, display message and exit.
    if (mySize == 0)
    {
        cout << "The list is empty.\n";
        return;
    }
    else
    {
        List::NodePtr tempPtr = new Node(first->data), // reverse list pointer
                      origPtr,  // pointer traverses the original list
                      newNode;  // new allocated note
        
        origPtr = first;
        origPtr = origPtr->next;
        while (origPtr != 0)
        {
            newNode = new Node(origPtr->data);
            newNode->next = tempPtr;
            tempPtr = newNode;
            origPtr = origPtr->next;
        }
        
        // Deallocate the original list
        this->~List();
        
        // first pointer point to the reverse list
        first = tempPtr;
    }
}


// Definition of erase ()
void List::eraseItem(int index)
{
    if (index < 0 || index >= mySize)
    {
        cout << "Illegal location to insert -- " << index << endl;
        return;
    }
    
    mySize--;
    List::NodePtr Ptr,
                  prePtr = first; // pointer points to the first and traverse
    
    if (index == 0)
    {
        first = prePtr->next;
        delete prePtr;
    }
    
    else
    {
        for(int i = 1; i < index; i++)
            prePtr = prePtr->next;
        Ptr = prePtr->next;
        prePtr->next = Ptr->next;
        delete Ptr;
    }
}


// Definition of insert ()
void List::insert(ElementType newData, int index)
{
    if (index < 0 || index > mySize) // if illegal index
    {
        cout << "Illegal location to insert -- " << index << endl;
        return;
    }
    
    mySize++;
    List::NodePtr newPtr = new Node(newData),
        prePtr = first;
    
    if (index == 0) // if insert item at the first place
    {
        newPtr->next = first;
        first = newPtr;
    }
    else
    {
        for(int i = 1; i < index; i++)
            prePtr = prePtr->next;
        newPtr->next = prePtr->next;
        prePtr->next = newPtr;
    }
}


//--- Definition of input operator
ifstream& operator >> (ifstream & in, ElementType & aItem)
{
    in >> aItem.itemName;
    in >> aItem.unitPrice;
    in >> aItem.minimumLevel;
    in >> aItem.numberInStock;
    
    return in;
}

//--- Definition of input operator //
istream& operator >> (istream & in, ElementType & aItem)
{
    cout << "Item name: ";
    in >> aItem.itemName;
    testDataInput(in, aItem.itemName);
    cout << "Unit price: ";
    in >> aItem.unitPrice;
    testDataInput(in, aItem.unitPrice);
    cout << "Minimum inventory level: ";
    in >> aItem.minimumLevel;
    testDataInput(in, aItem.minimumLevel);
    cout << "Number in stock: ";
    in >> aItem.numberInStock;
    testDataInput(in, aItem.numberInStock);
    
    return in;
}

// Definition of display
void List::display(ostream & out) const
{
    if (mySize == 0)
        out << "The list is empty.\n";
    else
    {
        // format the output
        out << fixed << showpoint << setprecision(2);
        List::NodePtr Ptr = first;
        
        while(Ptr != 0)
        {
            out << left << setw (30) << Ptr->data.itemName
            << right << setw (10) << Ptr->data.unitPrice
            << setw (6) << Ptr->data.minimumLevel
            << setw (6) << Ptr->data.numberInStock << endl;
            Ptr = Ptr->next;
        }
        
    }
}

//--- Definition of output operator
ostream& operator << (ostream & out, const List & aList)
{
    aList.display(out);
    return out;
}


//----- Definition of sortFile ()
void List::sortFile(ifstream& in, List& aList, itemType aItem)
{
    if(!in) { return; }
    else
    {
        in >> aItem;  // read item
        aList.insert(aItem, 0); // insert first item
        
        
        List::NodePtr last = first, // last node in the list
                      newNode,
                      c1, // traverse node
                      c2; // traverse node after c1
        
        while (in >> aItem)
        {
            newNode = new Node(aItem);
            c1 = first;
            c2 = c1->next;
            
            // CASE 1: if smallest, make it the first node
            if (newNode->data.itemName < c1->data.itemName)
            {
                newNode->next = c1;
                first = newNode;
                mySize++;
            }
                
            // CASE 2: newNode is larger than the first node:
            while (newNode->data.itemName >= c1->data.itemName && c1 != 0)
            {
                // CASE 2a: if only one node in the list, build node after that node
                if (mySize == 1)
                {
                    last->next = newNode;
                    last = newNode;
                    mySize++;
                    break;
                }
                    
                // CASE 2b: newNode is larger than c1 less than c2, add in between.
                else if (newNode->data.itemName <= c2->data.itemName)
                {
                        newNode->next = c2;
                        c1->next = newNode;
                        mySize++;
                        break;
                }

                // traverse c1 and c2
                c1 = c1->next;
                c2 = c1->next;
                    
                // CASE 2c: when c2 reaches the end of the list, add to the end.
                if (c2 == 0)
                {
                    c1->next = newNode;
                    last = newNode; // update last node
                    mySize++;
                    break;
                }
            }
        }
    }
}


//----- Definition of sortExistingList ()
void List::sortExistingList(List& aList)
{
    if (mySize == 0) {return;}
    
    else
    {
        List::NodePtr current = first; // pointer to traverse the linked list
        itemType* tempArr = new itemType [mySize]; // dynamic array to store the data of the linked list
        
        // copy all the data from linked list to tempArr
        for(int i = 0; i < mySize; i++)
        {
            tempArr[i] = current->data;
            current = current->next;
        }
        
        // insertion sort the tempArr array
        for(int i = 1; i < mySize; i++)
        {
           itemType temp = tempArr[i];
           int j = i - 1;
            
            while(j >= 0 && tempArr[j].itemName > temp.itemName) // ⚠️ first add 133, then add 444, why [5] > [6] can go in the while loop? 因为字符串比较规则！！
            {
                tempArr[j + 1] = tempArr[j];
                j--;
            }
            
            tempArr[j + 1] = temp;
        }
        
        // copy back the sorted tempArry into linked list
        current = first;
        
        for(int i = 0; i< mySize; i++)
        {
            current->data = tempArr[i];
            current = current->next;
        }
        
        // deallocate the tempArr
        delete [] tempArr;
        
    } // --- end of else statement
}


//-- Definition of searchName ()
int List::searchName(string name)
{
    List::NodePtr current = first;
    
    for(int loc = 0; loc < mySize; loc++)
        if(current->data.itemName == name)
            return loc;
        else
            current = current->next;
    
    return -1;
}


//-- Definition of searchPrice ()
int List::searchPrice(double uPrice)
{
    List::NodePtr current = first;
    
    for(int loc = 0; loc < mySize; loc++)
        if(current->data.unitPrice == uPrice)
            return loc;
        else
            current = current->next;
    
    return -1;
}


//-- Definition of searchLevel ()
int List::searchLevel(int level)
{
    List::NodePtr current = first;

    for(int loc = 0; loc < mySize; loc++)
        if(current->data.minimumLevel == level)
            return loc;
        else
            current = current->next;

    return -1;
}


//-- Definition of searchItemStock ()
int List::searchItemStock(int stockNum)
{
    List::NodePtr current = first;

    for(int loc = 0; loc < mySize; loc++)
        if(current->data.numberInStock == stockNum)
            return loc;
        else
            current = current->next;

    return -1;
}


//-- Definition of updateItemName ()
void List::updateItemName(List& aList, string origItemName)
{
    string newItemName;     // new item info for update

    // test if origItemName exists in the list
    if (aList.searchName(origItemName) != -1)
    {
        cout << "\n *** The item info exists *** \n\n";
        cout << "New name for the item is: ";
        cin >> newItemName; // new name for the item
        testDataInput(cin, newItemName);
        

        // if exists, find the positin in the linked list.
        List::NodePtr current = first; // pointer to traverse
        for (int i = 0; i < aList.searchName(origItemName); i++)
            current = current->next;

        // update the item info in the linked list
        current->data.itemName = newItemName;
        cout << "\n *** Update completed! *** \n\n";
    }
    // not found display message.
    else
        cout << "Item info not found.\n";
}


//-- Definition of updateItemPrice ()
void List::updateItemPrice(List& aList, double origItemPrice)
{
    double newItemPrice;     // new item info for update

    // test if origItemName exists in the list
    if (aList.searchPrice(origItemPrice) != -1)
    {
        cout << "\n *** The item info exists *** \n\n";
        cout << "New price for the item is: ";
        cin >> newItemPrice; // new item info for the item
        testDataInput(cin, newItemPrice);

        // if exists, find the positin in the linked list.
        List::NodePtr current = first; // pointer to traverse
        for (int i = 0; i < aList.searchPrice(origItemPrice); i++)
            current = current->next;

        // update the item info in the linked list
        current->data.unitPrice = newItemPrice;
        cout << "\n *** Update completed! *** \n\n";
    }
    // not found display message.
    else
        cout << "Item info not found.\n";
}


//-- Definition of updateItemLevel ()
void List::updateItemLevel(List& aList, int origItemLevel)
{
    int newItemLevel;     // new item info for update

    // test if origItemName exists in the list
    if (aList.searchLevel(origItemLevel) != -1)
    {
        cout << "\n *** The item info exists *** \n\n";
        cout << "New minimum inventory level for the item is: ";
        cin >> newItemLevel; // new item info for the item
        testDataInput(cin, newItemLevel);

        // if exists, find the positin in the linked list.
        List::NodePtr current = first; // pointer to traverse
        for (int i = 0; i < aList.searchLevel(origItemLevel); i++)
            current = current->next;

        // update the item info in the linked list
        current->data.minimumLevel = newItemLevel;
        cout << "\n *** Update completed! *** \n\n";
    }
    // not found display message.
    else
        cout << "Item info not found.\n";
}


//-- Definition of updateItemStock ()
void List::updateItemStock(List& aList, int origItemStock)
{
    int newItemStock;     // new item info for update

    // test if origItemName exists in the list
    if (aList.searchItemStock(origItemStock) != -1)
    {
        cout << "\n *** The item info exists *** \n\n";
        cout << "New number in stock for the item is: ";
        cin >> newItemStock; // new item info for the item
        testDataInput(cin, newItemStock);

        // if exists, find the positin in the linked list.
        List::NodePtr current = first; // pointer to traverse
        for (int i = 0; i < aList.searchItemStock(origItemStock); i++)
            current = current->next;

        // update the item info in the linked list
        current->data.numberInStock = newItemStock;
        cout << "\n *** Update completed! *** \n\n";
    }
    // not found display message.
    else
        cout << "Item info not found.\n";
}


//-- Definition of addItem ()
void List::addItem(itemType& addedItem)
    {
        List::NodePtr prePtr, // traverse pointer
                      Ptr, // traverse pointer
                      newNode = new Node(addedItem); // new node
        
        // Case 1: if empty list
        if (mySize == 0)
        {
            first = new Node(addedItem);
            mySize++;
        }
        
        // Case 2: if added note is the smallest
        if (addedItem.itemName < first->data.itemName)
        {
            newNode->next = first;
            first = newNode;
            mySize++;
        }
        else
        {
            prePtr = first;
            Ptr = prePtr->next;
            // Case 3a: if added note is not the smallest but not largest
            while (Ptr != 0)
            {
                if ( (addedItem.itemName >= prePtr->data.itemName) && (addedItem.itemName <= Ptr->data.itemName) ) // ⚠️ why add 10 has bug? 答：注意字符串比较时按第一个第二个轮流比较的：ABC比ACD小！！
                {
                    newNode->next = Ptr;
                    prePtr->next = newNode;
                    mySize++;
                    break;
                }
                prePtr = prePtr->next;
                Ptr = Ptr->next;
            }
            
            // Case 3b: if largest
            if (Ptr == 0)
            {
                newNode->next = Ptr;
                prePtr->next = newNode;
                mySize++;
            }
        }
}
