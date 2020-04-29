// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019

#ifndef ITEM
#define ITEM

#include <string>

using namespace std;

// itemType struct
struct itemType
{
    string itemName  = "hey!";   // item name
    double unitPrice = 0;        // unit price
    int minimumLevel = 0;        // minimum inventory level
    int numberInStock= 0;        // number in stock
};

#endif //ITEM_H
