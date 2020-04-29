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
 addItem:           add an item and sort it in alphabetical order by name
 erase:             Remove an item
 display:           Output the list
 <<:                Output operator
 >>:                Input operator or file Input operator
 reverse:           reverse the list
 sortFile:          read all data and sort in alphabetical order by name
 sortExistingList:  sort the existing list in alphabetical order by name
 searchName:        the location of specific item name
 searchPrice:       the location of specific item price
 searchLevel:       the location of specific item inventory level
 searchItemStock:   the location of specific item's stock number
 updateItemName:    update an exsiting item name
 updateItemPrice:   update an exsiting item price
 updateItemLevel:   update an exsiting item inventory level
 updateItemStock:   update an exsiting item's stock number
 testDataInput:     a template function to verify all kinds of valid input
 
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
    void sortExistingList(List&);
    int  searchName(string);
    int  searchPrice(double);
    int  searchLevel(int);
    int  searchItemStock(int);
    void updateItemName(List&, string);
    void updateItemPrice(List&, double);
    void updateItemLevel(List&, int);
    void updateItemStock(List&, int);
    void addItem(itemType&);
    
    
    
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
