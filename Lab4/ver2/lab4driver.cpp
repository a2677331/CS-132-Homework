// Jian Zhong
// Prof. Mackay
// CS132 Lab 3
// 00/00/2019

#include "List.h"
#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/******** Function Prototype ********/
// Read in items in file
void storeItem(ifstream& fin, List& listOperation, itemType item, int& itemPos);
// Display menu for user
void Menu(List& listOperation, ofstream& fout, int itemPos);


/*********** Lab 3 driver **********/
int main()
{
    ifstream fin;       // input file stream
    ofstream fout;      // output file stream
    string fPath;       // file path
    itemType item;      // an item of struct type
    List listOperation; // a list of class type that can manipulate the item type
    int itemPos = 0;    // the item position
    
    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);

    fin.open(fPath);               // open the input file
    // ⚠️fout.open("NewInventory.txt");不能放这里，不然就会文件要display两次才能出显示结果，为什么？？⚠️

    while(!fin)
    {
        cout << "Invalid file Path, try again: ";
        getline(cin, fPath);
        fin.open(fPath); // open the input file
    }
    
    //Read and store the data in InventoryFile.txt
    storeItem(fin, listOperation, item, itemPos);
    
    //Pompt Memu to user
    Menu(listOperation, fout, itemPos);
    
    fin.close(); // close file
    
    return 0;
}/********* End of Lab 3 driver *********/


// Definition of storeItem ();
void storeItem(ifstream& fin, List& listOperation, itemType item, int& itemPos)
{
    while(fin >> item) // Read in items
        {
            listOperation.insert(item, itemPos); // Insert an element
            itemPos++;
        }
}


// Definition of displayMenu ();
void Menu(List& listOperation, ofstream& fout, int itemPos)
{
    int choice; // choice number
    
    do
    {
        cout << "Your options are:\n"
             << "    1: Check if the item list is empty.\n"
             << "    2: Insert a value into the list at a given position.\n"
             << "    3: Remove a value from the list at a given position.\n"
             << "    4: Display a list.\n"
             << "    5: Exit\n";
        cout << "\nWhich choice? ";
        cin >> choice; // read in a choice number
        
        // Link the choice numbers to patterns
        int chosenPos; // Chosen Position by the user
        switch (choice)
        {
            case 1:
                if (listOperation.empty())
                    cout << "\nItem list is empty.\n\n";
                else
                    cout << "\nItem list is NOT empty\n\n";
                break;
            case 2:
                cout << "You chose to insert an item, insert position: ";
                if (cin >> chosenPos)
                {
                    chosenPos--; // get the actual Index in the array
                    
                    // Test if the actual Index is valid.
                    if (chosenPos > CAPACITY || chosenPos < 0)
                    {
                        cout << "\n*** Illegal location -- " << chosenPos
                        << ". Please try again. ***\n\n";
                        Menu(listOperation, fout, itemPos); // Prompt Menu to user to try again.
                    }
                    // When valid actual Index, then read in the inserted item.
                    itemType insertItem; // temporary item for insertion
                    cin >> insertItem;
                    listOperation.insert(insertItem, chosenPos);
                }
                break;
            case 3:
                cout << "You chose to remove an item, which position: ";
                
                if(cin >> chosenPos)// the position user enter
                {
                    chosenPos--; // the position in the struct array
                    listOperation.erase(chosenPos); // Erase an item
                    cout << endl;
                }
                break;
            case 4:
                listOperation.display(fout);// // ⚠️why cout??A：因为在display的definition里没有include<iostream>,所以没有cout可以用，要pass fout才能用于输出;
                break;
            default:
                break;
        }
    }while (choice != 5); // while choosing 5, exit the do-while Menu

    cout << "You chose to EXIT, program terminated successfully!\n\n";
}
