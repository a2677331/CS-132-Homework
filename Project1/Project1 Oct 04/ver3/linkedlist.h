// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019


/*-- linkedlist.h ---------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 Desturctor
 Copy constructor
 empty:             Check if list is empty
 insert:            Insert an item
 erase:             Remove an item
 display:           Output the list
 <<:                Output operator
 >>:                Input operator or file Input operator
 reverse:           reverse the list
 sortFile:          read all data and sort in alphabetical order by name
 sortItem:          insert an item into the list and sort in alphabetical order by name
 sortExistingList:  sort the existing list in alphabetical order by name
 searchName:        the location of specific item name
 searchPrice:       the location of specific item price
 searchLevel:       the location of specific item inventory level
 searchItemStock:   the location of specific item's stock number
 updateItemName:    update an exsiting item name
 updateItemPrice:   update an exsiting item price
 updateItemLevel:   update an exsiting item inventory level
 updateItemStock:   update an exsiting item's stock number
 -------------------------------------------------------------------------*/


#ifndef LINKEDLIST
#define LINKEDLIST

#include "Item.h"
#include <iostream>
#include <fstream>

using namespace std;

typedef itemType ElementType;

// --- Definition of testDataInput()
template <class Type>
void testDataInput(istream& in, Type& input)
{
    while (!in || (in.peek() != '\n'))
    {
        in.clear();           // clear bad input
        in.ignore(200, '\n'); // discard input
        cout << "Invalid input, please enter again: ";
        in >> input;          // update the input
    }
}

// CLASS LIST
class List
{
private:
    //------ Linkedlist's Node data type
    class Node
    {
    public:
        ElementType data;
        Node * next;
        
        Node(ElementType dataVal)  // Node's Constructor with parameter
        : next(0), data(dataVal)
        { }
        Node() // Node's default Constructor
        : next(0)
        { }
    }; // --- end of Node struct
    
    typedef Node* NodePtr;
    
//------ LIST OPERATIONS
public:
    List();                     // List's Constructor
    List(const List& origList); // List's Copy Constructor,
    ~List();                    // List's Destructor
    const List& operator = (const List&);
    void insert(ElementType, int);
    void display(ostream&) const;
    void eraseItem(int);
    void reverse();
    void sortFile(ifstream&, List&, itemType);
    void sortItem(List&, itemType);
    void sortExistingList(List&);
    int  searchName(string);
    int  searchPrice(double);
    int  searchLevel(int);
    int  searchItemStock(int);
    void updateItemName(List&, string);
    void updateItemPrice(List&, double);
    void updateItemLevel(List&, int);
    void updateItemStock(List&, int);
    
    void addItem(itemType& addedItem)
    {
        List::NodePtr prePtr, // traverse pointer
                      Ptr, // traverse pointer
                      newNode = new Node(addedItem); // new node
        
        // Case 1: if empty list
        if (mySize == 0)
        {
            first = new Node(addedItem);
            mySize++;
            cout << "Case 1: if empty list\n";
        }
        
        // Case 2: if added note is the smallest
        if (addedItem.itemName < first->data.itemName)
        {
            newNode->next = first;
            first = newNode;
            mySize++;
            cout << "Case 2: if is smallest\n";
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
                    cout << "Case 3a: if not smallest, but not largest\n";
                    break;
                }
                prePtr = prePtr->next;
                Ptr = Ptr->next;
            }
            
            // Case 3b: if largest
            if (Ptr == 0)
            {
                cout << "Case 3b: if largest\n";
                newNode->next = Ptr;
                prePtr->next = newNode;
                mySize++;
            }
        }
}
    
    
    
//------ DATA MEMBERS
private:
    int mySize;    // current size of the list
    NodePtr first; // pointer of the first node of the list
}; // --- end of List class


// Overloading operators
ifstream& operator >> (ifstream & in, ElementType & aItem);
istream& operator >> (istream & in, ElementType & aItem);
ostream & operator << (ostream & out, const ElementType & aItem);

#endif
