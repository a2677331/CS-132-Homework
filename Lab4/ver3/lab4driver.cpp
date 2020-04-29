// Jian Zhong
// Prof. Mackay
// CS132 Lab 4
// 09/25/2019

#include "List.h"
#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Prototype
void storeItem(ifstream&, List&, itemType); // Function to store items data in file
void Menu(ifstream&, List&, ofstream&); // Function to display the menu

/*--- LAB 4 driver ---*/
int main()
{
    ifstream fin;          // input file stream
    ofstream fout;         // output file stream
    string fPath;          // file path
    itemType item;         // an item of struct type
    List listOperation;    // a list of class type that can manipulate the item type

    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);           // Read in the file path
    fin.open(fPath);               // Open the input file
    fout.open("NewInventory.txt"); // Open the output file

    // Test for valid file path
    while(!fin)
    {
        cout << "Invalid file path, try again: ";
        getline(cin, fPath);
        fin.open(fPath);  // open the input file
    }

    // Read and Store the data in InventoryFile.txt
    storeItem(fin, listOperation, item);

    // Display Menu options
    Menu(fin, listOperation, fout);

    fin.close();  // close input file
    fout.close(); // close the output file

    return 0;
}/*--- End of LAB 4 driver ---*/


// Definition of storeItem ();
void storeItem(ifstream& fin, List& listOperation, itemType item)
{
    int itemPos = 0; // The position that each item would be placed

    while(fin >> item) // Read in item
    {
        listOperation.insert(item, itemPos); // Insert an element
        itemPos++;
    }
}


// Definition of displayMenu ();
void Menu(ifstream& fin, List& listOperation, ofstream& fout)
{
    int choice; // Choice number

    do    // Display menu
    {
        cout << "Your options are:\n"
             << "    1: Check if the item list is empty.\n"
             << "    2: Insert a value into the list at a given position.\n"
             << "    3: Remove a value from the list at a given position.\n"
             << "    4: Display a list.\n"
             << "    5: Exit and output data to a file called \"NewInventory\".\n";
        cout << "\nWhich choice? ";
        cin >> choice; // read in a choice number


        int chosenPos;  // Chosen Position by the user
        switch (choice) // Link the choice numbers to related functions
        {
            case 1:
                if (listOperation.empty())
                    cout << "\nItem list is empty.\n\n";
                else
                    cout << "\nItem list is NOT empty\n\n";
                break;
            case 2:
                cout << "You chose to insert an item, which position: ";
                if (cin >> chosenPos)
                {
                    itemType tempItem; // temporary item for insertion
                    cin >> tempItem; // ⚠️why use cin here? Because you are entering these data from keyboard, not file, so use cin instead of ifstream(fin)!
                    listOperation.insert(tempItem, --chosenPos); // insert the item
                }
                cout << "*** The item has been inserted successfully. ***\n\n";
                break;
            case 3:
                cout << "You chose to remove an item, which position: ";
                if(cin >> chosenPos)// the position user enter
                    listOperation.erase(--chosenPos); // erase the item
                cout << "*** The item has been removed successfully. ***\n\n";
                break;
            case 4:
                listOperation.display(cout);
            default:
                break;
        }
    }while (choice != 5); // input 5 to exit the do-while Menu

    listOperation.display(fout); // output data to the output file
    
    cout << "You chose to EXIT, program terminated successfully!\n\n";
}
