// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 10/04/2019

#include "linkedlist.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototypes:
void Menu(ifstream&, List&, ofstream&, itemType& aItem); // Main menu
void itemInfoMenu(List&); // Item Info's update Menu
void getFilePath(ifstream&, ofstream&, string&); // Function to Read in the file path
void testFilePathInput(ifstream&, string&);            // Function to test valid file path




// --- driver --- //
int main()
{
    ifstream fin;   // input file stream
    ofstream fout;  // output file stream
    
    itemType aItem;
    List aList;
    string fPath;
    
    // Read in the file path
    getFilePath(fin, fout, fPath);
    
    // Sort the while inventory file
    aList.sortFile(fin, aList, aItem);
    
    // Display the sorted inventory data
    aList.display(cout);
    
    // Display Menu
    Menu(fin, aList, fout, aItem);

    fin.close();
    fout.close();

    return 0;
}  // --- end of driver --- //


// Definition of readFilePath ()
void getFilePath(ifstream& fin, ofstream& fout, string& fPath)
{
    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);
    fin.open(fPath);          // Open the input file
    
    // testInput (): Verify valid file path input
    testFilePathInput(fin, fPath);
    
    fout.open("NewList.txt"); // Open the output file
}


// Definition of testInput ()
void testFilePathInput(ifstream& fin, string& fPath)
{
    while(!fin)
    {
        cout << "Invalid file path, try again: ";
        getline(cin, fPath);
        fin.open(fPath);  // open the input file
    }
}


// Definition of Menu ()
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
        testDataInput(cin, choice); // ⚠️


        switch (choice) // Link the choice numbers to related functions
        {
            case 1:
                cout << "\nInventory in Alphabetical order: \n\n";
                aList.sortExistingList(aList);
                aList.display(cout);
                cout << endl;
                break;
            case 2:
                cout << "\nInventory in REVERSE alphabetical order: \n\n";
                aList.reverse(); // reverse the order
                aList.display(cout);
                cout << endl;
                break;
            case 3:
                cout << "You chose to ADD an item, enter item information:\n";
                cin >> aItem;
                // have the list sorted
                aList.sortExistingList(aList);
                // insert item
                aList.addItem(aItem);
                cout << endl;
                aList.display(cout);
                break;
            case 4:
                cout << "You chose to Delete an item, which line number: ";
                int erasePos;  // delete position 
                cin >> erasePos;
                testDataInput(cin, erasePos);
                aList.eraseItem(--erasePos); // actual index
                cout << endl;
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


// Definition of itemInfoMenu ()
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
            cout << "    1: Update item name\n"
                 << "    2: Update Unit price\n"
                 << "    3: Update Minimum inventory level\n"
                 << "    4: Update Number in stock\n"
                 << "    5: Back to the main menu\n"
                 << "\nWhich option? ";
            cin  >> option; // read in option from user
            testDataInput(cin, option);

            switch (option)
            {
                case 1:
                    cout << "Enter the exsiting item's Name: ";
                    cin >> origItemName; // exsiting item info
                    testDataInput(cin, origItemName);
                    aList.updateItemName(aList, origItemName);
                    break;
                case 2:
                    cout << "Enter the exsiting item's Unit Price: ";
                    cin >> origUnitPrice; // exsiting item info
                    testDataInput(cin, origUnitPrice);
                    aList.updateItemPrice(aList, origUnitPrice);
                    break;
                case 3:
                    cout << "Enter the exsiting item's Minimum Level: ";
                    cin >> origMinimumLevel; // exsiting item info
                    testDataInput(cin, origMinimumLevel);
                    aList.updateItemLevel(aList, origMinimumLevel);
                    break;
                case 4:
                    cout << "Enter the exsiting item's Stock Number: ";
                    cin >> origNumberInStock; // exsiting item info
                    testDataInput(cin, origMinimumLevel);
                    aList.updateItemStock(aList, origNumberInStock);
                    break;
                default:
                    break;
            }
        }while (option != 5); // input 5 to exit the do-while Menu
}





/*
case 3:
    cout << "You chose to ADD an item, enter item information:\n";
    cin >> aItem;
    // have the list sorted
    aList.sortExistingList(aList);
    // insert the added item into the list
    aList.sortItem(aList, aItem);
    cout << endl;
    aList.display(cout);
    break;
*/
