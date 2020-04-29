// Jian Zhong
// Prof. Mackay
// CS132 Lab 3
// 00/00/2019
//
// 做成问用户来获取txt地址
// 解决有感叹号的问题



#include "List.h"
#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/******** Function Prototype ********/
// Read in items in file
void storeItem(ifstream& fin, List& listOperation, itemType item[], int CAPACITY, int& size);
// Display menu for user
void Menu(List& listOperation, ofstream& fout, int size);


/*********** Lab 3 driver **********/
int main()
{
    ifstream fin;
    ofstream fout;
    
    fin.open("InventoryFile.txt"); // open file
    
    List listOperation;
    itemType item[CAPACITY]; // total places that can hold items
    int size = 0; // the item size
    
    //Read and store the data in InventoryFile.txt
    storeItem(fin, listOperation, item, CAPACITY, size);
    
    //Pompt Memu to user
    Menu(listOperation, fout, size);
    
    fin.close(); // close file
    
    return 0;
}
/******** end of Lab 3 driver ********/



// Definition of storeItem ();
void storeItem(ifstream& fin, List& listOperation, itemType item[], int CAPACITY, int& size)
{
    // Read in items in file
    for(int i = 0; i < CAPACITY; i++)
    {
        if (!fin)
        {
            // Because if(!fin) would reads one more line than actual condition,
            // size and mySize need to be decreased by 1.
            size--; // ⚠️因为if（!fin）读多了一次size，所以这里size要减1.
            listOperation.decrease(); // ⚠️因为if（!fin）读多了一次mySize，所以这里mySize要减1.
            break;
        }
        else
        {
            fin >> item[i].itemNumber
            >> item[i].numberInStock
            >> item[i].unitPrice
            >> item[i].minimumInventoryLevel
            >> item[i].itemName;
            // Insert an element when read in an item.
            listOperation.insert(item, size);
            size++;
        }
    }
}


// Definition of displayMenu ();
void Menu(List& listOperation, ofstream& fout, int size)
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
        
        
        //Executes the loop if invalid choices input
        while (!cin || (choice > 5) || (choice <= 0) || (cin.peek() != '\n'))
        {
            if(cin && (cin.peek() == '\n')) // when entering valid integer, display a message
            {
                cin.clear(); // clear bad input
                cin.ignore(200, '\n'); // discard input
                cout << "Not a valid choice, choose 1 - 5\n";
                cout << "Which choice? ";
                cin >> choice; // update the choice
            }
            else // when not entering an integer, display a message
            {
                cin.clear(); // clear bad input
                cin.ignore(200, '\n'); // discard input
                cout << "Not an integer, please enter an integer!\n";
                cout << "Which choice? ";
                cin >> choice; // update the choice
            }
        }
        
        
        // Link the choice numbers to patterns
        itemType tempItem[CAPACITY]; // temporary item for insertion
        //⚠️是array，但忘记加[]，导致133行call了&tempItem，搞了很久！！！
        int pos;
        
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
                
                if (cin >> pos)
                {
                    pos--; // the actual Index in the array
                    
                    if (pos > CAPACITY || pos < 0) // test if the actual Index is valid.
                    {
                        cout << "\n*** Illegal location -- " << pos
                        << ". Please try again. ***\n\n";
                        Menu(listOperation, fout, size); // Prompt Menu to user to try again.
                    }
                    
                    // When valid actual Index, then read in the inserted item.
                    cout << "Item Number: ";
                    cin >>  tempItem[pos].itemNumber;
                    cout << "Number in Stock:  ";
                    cin >>  tempItem[pos].numberInStock;
                    cout << "Unit Price : ";
                    cin >> tempItem[pos].unitPrice;
                    cout << "Minimum Inventory Level: ";
                    cin >> tempItem[pos].minimumInventoryLevel;
                    cout << "Item Name: ";
                    cin >> tempItem[pos].itemName;
                    
                    //⚠️问题出在这里，call了&tempItem而不是tempItem。
                    listOperation.insert(tempItem, pos); // Function Call
                    cout << endl;
                }
                break;
            case 3:
                cout << "You chose to remove an item, which position: ";
                
                if(cin >> pos)// the position user enter
                {
                    pos--; // the position in the struct array
                    listOperation.erase(pos); // Function Call
                    cout << endl;
                }
                break;
            case 4:
                listOperation.display(fout);// ⚠️why cout??
                break;
            default:
                break;
        }
    }while (choice != 5); // while choosing 5, exit the do-while loop
    
    cout << "You chose to EXIT, program exited successfully!\n\n";
}
