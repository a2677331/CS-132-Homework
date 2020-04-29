// Jian Zhong
// Prof. Mackay
// CS132 Lab 3

#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;


// itemType struct
struct itemType
{
    int itemNumber = 0;
    int numberInStock = 0;
    double unitPrice = 0.00;
    int minimumInventoryLevel = 0.0;
    string itemName = "";
};


#endif //ITEM_H
