// Jian Zhong
// Prof. Mackay
// CS132 Lab 4
// 09/24/2019


/*-- List.h ---------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 <<:       Output operator
 -------------------------------------------------------------------------*/


#ifndef LIST
#define LIST

#include "Item.h"
#include <iostream>
#include <fstream>

using namespace std;

const int CAPACITY = 1024;
typedef itemType ElementType;

class List
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    List();
    /*----------------------------------------------------------------------
     Construct a List object.

     Precondition:  None
     Postcondition: An empty List object has been constructed; mySize is 0.
     -----------------------------------------------------------------------*/

    /***** empty operation *****/
    bool empty() const;
    /*----------------------------------------------------------------------
     Check if a list is empty.

     Precondition:  None
     Postcondition: true is returned if the list is empty, false if not.
     -----------------------------------------------------------------------*/

    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    /*----------------------------------------------------------------------
     Insert a value into the list at a given position.

     Precondition:  item is the value to be inserted; there is room in
     the array (mySize < CAPACITY); and the position satisfies
     0 <= pos <= mySize.
     Postcondition: item has been inserted into the list at the position
     determined by pos (provided there is room and pos is a legal
     position).
     -----------------------------------------------------------------------*/

    void erase(int pos);
    /*----------------------------------------------------------------------
     Remove a value from the list at a given position.

     Precondition:  The list is not empty and the position satisfies
     0 <= pos < mySize.
     Postcondition: element at the position determined by pos has been
     removed (provided pos is a legal position).
     ----------------------------------------------------------------------*/

    /***** output *****/
    void display(ostream & out) const;
    /*----------------------------------------------------------------------
     Display a list.

     Precondition:  The ostream out is open.
     Postcondition: The list represented by this List object has been
     inserted into out.
     -----------------------------------------------------------------------*/

private:
    /******** Data Members ********/
    int mySize;                     // current size of list stored in myArray
    ElementType myArray[CAPACITY];  // array to store list elements

}; //--- end of List class

/* ⚠️
It will be better to move the implementation of the overload function out of the class definition.
It will allow you to implement it in a .cpp file.
*/


// ⚠️ change ofstream to ostream so you can use any ostream, not just ofstream.

//------ Prototype of output operator
ostream & operator << (ostream & out, const ElementType & aList);

//------ Prototype of input operator
istream & operator >> (istream & in, ElementType & aItem);

//--- Definition of file input operator //
ifstream & operator >> (ifstream & in, ElementType & aItem);

#endif

