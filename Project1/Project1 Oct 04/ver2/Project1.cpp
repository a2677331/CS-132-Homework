// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019

#include "linkedlist.h"
#include "Item.h"
#include <iostream>
#include <fstream>

using namespace std;


// Function Prototype:
void Menu(ifstream&, List&, ofstream&, itemType& aItem);
void itemInfoMenu(List&);


// --- driver --- //

int main()
{
    ifstream fin;          // input file stream
    ofstream fout;         // output file stream
    
    itemType aItem;
    List aList;
    
    fin.open("inventory.txt");
    fout.open("newlist.txt");
        
    // Sort the inventory file in advance
    aList.sortFile(fin, aList, aItem);\
    
    // Display the sorted inventory data
    aList.display(cout);
    
    // Display Menu
    Menu(fin, aList, fout, aItem);

    fin.close();
    fout.close();

    return 0;
}  // --- end of driver --- //


// Definition of Menu ();
void Menu(ifstream& fin, List& aList, ofstream& fout, itemType& aItem)
{
    int choice; // Choice number
    
    do    // Display Menu
    {
        cout << "\nYour options are:\n"
             << "    1: Display in alphabetical order by name\n"
             << "    2: Display in reverse alphabetical order\n"
             << "    3: Add an item to the inventory\n"
             << "    4: Delete an item from inventory\n"
             << "    5: Change any info for an item\n"
             << "    6: Exit and output data to a txt file\n";
        cout << "\nWhich choice? ";
        cin >> choice; // read in a choice number


        switch (choice) // Link the choice numbers to related functions
        {
            case 1:
                cout << "\nInventory in Alphabetical order: \n";
                aList.sortExistingList(aList);
                aList.display(cout);
                cout << endl;
                break;
            case 2:
                cout << "\nInventory in REVERSE alphabetical order: \n";
                aList.reverse(); // reverse the order
                aList.display(cout);
                cout << endl;
                break;
            case 3:
                cout << "You chose to ADD an item, enter item information:\n";
                cin >> aItem;
                aList.sortItem(aList, aItem); // insert an item and sort it
                cout << endl;
                aList.display(cout);
                break;
            case 4:
                cout << "You chose to REMOVE an item, which position: ";
                int index;  // delete index
                if (cin >> index)
                    aList.erase(--index); // actual index
                cout << "*** The item has been removed successfully. ***\n\n";
                aList.display(cout);
                break;
            case 5:
                cout << "Which item info would you like to change:\n";
                itemInfoMenu(aList); // goes to the menu of item change
                aList.sortExistingList(aList);
                break;
            default:
                break;
        }
    }while (choice != 6); // input 5 to exit the do-while Menu

    aList.display(fout); // output data to the output file
    cout << "You chose to EXIT, program terminated successfully!\n\n";
}


void itemInfoMenu(List& aList)
{
    int option;            // user's option for changing item info
    
    string origItemName;   // original item name
    double origUnitPrice;  // original unit price
    int origMinimumLevel;  // original minimum inventory level
    int origNumberInStock; // original number in stock
    
    // Menu for changin item infos
    do
        {
            cout << "    1: Change item name\n"
                 << "    2: Change Unit price\n"
                 << "    3: Change Minimum inventory level\n"
                 << "    4: Change Number in stock\n"
                 << "    5: Back to the main menu\n"
                 << "\nWhich option? ";
            cin  >> option; // read in option from user

            switch (option)
            {
                case 1:
                    cout << "Enter the exsiting item's name: ";
                    cin >> origItemName; // exsiting item info
                    aList.updateItemName(aList, origItemName);
                    break;
                case 2:
                    cout << "Enter the exsiting item's unit price: ";
                    cin >> origUnitPrice; // exsiting item info
                    aList.updateItemPrice(aList, origUnitPrice);
                    break;
                case 3:
                    cout << "Enter the exsiting item's Minimum Level: ";
                    cin >> origMinimumLevel; // exsiting item info
                    aList.updateItemLevel(aList, origMinimumLevel);
                    break;
                case 4:
                    cout << "Enter the exsiting item's number in stock: ";
                    cin >> origNumberInStock; // exsiting item info
                    aList.updateItemStock(aList, origNumberInStock);
                    break;
                default:
                    break;
            }
        }while (option != 5); // input 5 to exit the do-while Menu
}
