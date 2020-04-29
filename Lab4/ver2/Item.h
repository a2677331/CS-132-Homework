// Jian Zhong
// Prof. Mackay
// CS132 Lab 3

#ifndef ITEM_H
#define ITEM_H


#include "Item.h"
#include <string>
using namespace std;


// itemType struct
struct itemType
{
    int itemNumber;
    int numberInStock;
    double unitPrice;
    int minimumInventoryLevel;
    string itemName;
};

//------ Prototype of input operator
// output one item
istream& operator>>(istream& in, itemType& aItem);

//------ Prototype of input operator
//input one item
ofstream& operator<<(ofstream& out, const itemType& aItem);


#endif //ITEM_H
