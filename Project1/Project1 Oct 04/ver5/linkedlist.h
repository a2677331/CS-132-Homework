// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019

/*-- linkedlist.h ---------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic Operations are:
 
 Constructor
 Desturctor
 Copy constructor
 empty:             Check if list is empty
 insert:            Insert an item
 addItem:           Add an item and sort it in alphabetical order by name
 erase:             Remove an item
 display:           Output the list
 <<:                Output operator
 >>:                Input operator or file Input operator, which can verify the input itemType object and read it in.
 reverse:           reverse the list
 sortFile:          read a txt upcoming file in alphabetical order by name
 sortExistingList:  sort the existing list in alphabetical order by name
 searchName:        Function to return the location of a item name
 searchPrice:       Function to return the location of a item price
 searchLevel:       Function to return the location of a item inventory level
 searchItemStock:   Function to return the location of a item stock number
 updateItemName:    Function to update an exsiting item name
 updateItemPrice:   Function to update an exsiting item price
 updateItemLevel:   Function to update an exsiting item inventory level
 updateItemStock:   Function to update an exsiting item's stock number
 testDataInput:     Template function to verify valid input
 
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
