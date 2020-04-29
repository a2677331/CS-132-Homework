// Jian Zhong
// Prof. Mackay
// CS132 Lab 4
// 09/25/2019

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// itemType struct
struct itemType
{
    int itemNumber = 0; // item Number
    int numberInStock = 0; //number in stock
    double unitPrice = 0.0; // unit price
    int minimumInventoryLevel = 0; // minimum inventory level
    string itemName = ""; // item name
};

#endif //ITEM_H
