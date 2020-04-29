// Jian Zhong
// Prof. Mackay
// CS132 Lab 10
// 12/08/2019


#include <iostream>     // cin, cout

using namespace std;

#include "heap.h"       // including the heap header file
// ⚠️ 放在这里之后，header file就不用加using namespace std了。

template <class Type>                 // Function template to validate menu input
void testMenuInput(istream&, Type&);
template <class Type>
void testDataInput(istream&, Type&);  // Function template to validate item input

int main()
{
    // Creating the starting heap
    heap<int> h;                  // a heap object of type int
    for (int i = 0; i < 10; i++)  // inserting 10 different numbers into the heap
        h.insert(i * -7);
    
    // Displaying the starting heap
    cout << "My starting heap is: ";
    h.display(cout);
    
    // Displaying Menu
    int optionNum; // Menu option input by user
    do
    {
        cout << "\nPlease choose an option:"
                "\n    (1) Display the heap"
                "\n    (2) Add an Item "
                "\n    (3) Remove the Largest item"
                "\n    (4) Exit\n"
                "\nWhich Option? ";
        cin >> optionNum;                // read in Menu option
        testMenuInput(cin, optionNum);   // menu validation

        // Apply different options to different cases
        int addedItem; // item to be added
        switch (optionNum)
        {
            case 1:   // (1) Display the heap
                cout << "\nThe heap is: ";
                h.display(cout);
                cout << endl;
                break;
            case 2:   // (2) Add an Item
                cout << "\nEnter an integer to add to the heap: ";
                cin >> addedItem;
                testDataInput(cin, addedItem);  // validation
                h.insert(addedItem);
                break;
            case 3:   // (3) Remove the Largest item
                if ( h.empty() )
                    cout << "*** The heap is already empty ***\n";
                else
                {
                    cout << "\nRemoving the largest item......OK!\n";
                    h.removeTop();
                }
                break;
            default:  // (4) Exit and display the final state of the heap
                cout << "\nThis is the final state of the heap: ";
                h.display(cout);
                cout << endl;
                break;
        }
    }while (optionNum != 4); // if option is 4, exit and display the heap
    
    return 0;
}


// --- Definition of testDataInput()
template <class Type>
void testMenuInput(istream& in, Type& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();               // clear bad input
        in.ignore(9999, '\n');    // discard input
        cout << "Invalid input1, please try again: ";
        in >> input;              // update the input
        testMenuInput(in, input); // recursive validation
    }
    if (input < 1 || input > 4)   // ensure option number to be just 1 or 2 or 3 or 4
    {
        cout << "Invalid input2, please try again: ";
        in >> input;
        testMenuInput(in, input); // keep validating
    }
}

// --- Definition of testDataInput()
template <class Type>
void testDataInput(istream& in, Type& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();               // clear bad input
        in.ignore(9999, '\n');    // discard input
        cout << "Invalid input1, please try again: ";
        in >> input;              // update the input
        testDataInput(in, input); // keep validating
    }
}
