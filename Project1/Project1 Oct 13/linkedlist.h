// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/12/2019

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
 >>:                Input operator or file Input operator to verify and input itemType object.
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
 checkSameItemName: Function to check if new item's name already exists, return ture if so.
 
 -------------------------------------------------------------------------*/

//***********************************************************
// Function Name:
// Purpose:
// Parameters:
//     Input
//     Input and Output:
//     Output:
// Return Value:
// Data Members Accessed:  (if the function is a class member)
// Data Members Modified:  (if the function is a class member)
// Non-Local variables used:
// Functions Called
//***********************************************************


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
    void eraseItem(int);
    void reverse();
    void sortFile(ifstream&, List&, itemType);
    void sortExistingList(List&);
    void display(ostream&) const;
    int  searchName(string) const;
    int  searchPrice(double) const;
    int  searchLevel(int) const;
    int  searchItemStock(int) const;
    bool checkSameItemName(List&, itemType) const;
    void updateItemName(List&, string);
    void updateItemPrice(List&, string);
    void updateItemLevel(List&, string);
    void updateItemStock(List&, string);
    void addItem(itemType&);
    
//------ DATA MEMBERS
private:
    int mySize;    // current size of the list
    NodePtr first; // pointer of the first node of the list
}; // --- end of List class

// Operators  Overloading Functions
ifstream& operator >> (ifstream & in, ElementType & aItem);
istream& operator >> (istream & in, ElementType & aItem);
ostream & operator << (ostream & out, const ElementType & aItem);

#endif
