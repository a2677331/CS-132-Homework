// Jian Zhong
// Prof. Mackay
// CS132 Lab 3


#include "Item.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ⚠️definition of >>: 只要用在itemType上面，读入itemType里的所有元素。
// ⚠️记得是istream，不是ifstream！！
istream& operator>>(istream& in, itemType& aItem)
{
//    cout << "Item Number: "; // ⚠️这里怎么改才能避免第一行出现东西
    in >> aItem.itemNumber;
//    cout << "Number in Stock:  ";
    in >> aItem.numberInStock;
//    cout << "Unit Price : ";
    in >> aItem.unitPrice;
//    cout << "Minimum Inventory Level: ";
    in >> aItem.minimumInventoryLevel;
//    cout << "Item Name: ";
    in >> aItem.itemName;
    return in;
}

// ⚠️definition of <<: 只要用在itemType上面，输出itemType里的所有元素。
// ⚠️记得是ostream，不是ofstream！！
ofstream& operator<<(ofstream& out, const itemType& aItem)
{
    out << fixed << showpoint << setprecision(2);
    
    out << right << aItem.itemNumber << ' '
    << setw (2) << aItem.numberInStock << ' '
    << setw (6) << aItem.unitPrice << ' '
    << setw (3) << aItem.minimumInventoryLevel << ' '
    << aItem.itemName << endl;
    return out;
}
