// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019


/*-- linkedlist.h ---------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 <<:       Output operator
 -------------------------------------------------------------------------*/


#ifndef LINKEDLIST
#define LINKEDLIST

#include "Item.h"
#include <iostream>
#include <fstream>

using namespace std;

typedef itemType ElementType;

// CLASS LIST
class List
{
private:
    //------ Node data type
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
    List();  // List's Constructor
    List(const List& origList); // List's Copy Constructor,
    ~List(); // List's Destructor
    const List& operator = (const List&);
    void insert(ElementType, int);
    void display(ostream&) const;
    void addItem(ElementType);
    void erase(int);
    void reverse();
    void sortFile(ifstream&, List&, itemType);
    void sortItem(List&, itemType);
    void sortExistingList(List&);
    int searchName(string);
    int searchPrice(double);
    int searchLevel(int);
    int searchItemStock(int);
    void updateItemName(List&, string);
    void updateItemPrice(List&, double);
    void updateItemLevel(List&, int);
    void updateItemStock(List&, int);
    
    
//------ DATA MEMBERS
private:
    int mySize; // count the numbers of nodes in Linked list
    NodePtr first; // first pointer points to the first node of Linked list
}; // --- end of List class


// Overloading operators
ifstream& operator >> (ifstream & in, ElementType & aItem);
istream& operator >> (istream & in, ElementType & aItem);
ostream & operator << (ostream & out, const ElementType & aItem);

#endif
