// Jian Zhong
// Prof. Mackay
// CS132 Project 2
// 11/25/2019
// Program Name: Text Concordance Program
// Used for: a program that reads a text file and constructs the concordance

// ⚠️ 这个是将word里的非字母全部忽略。

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "BST.h"

using namespace std;

// A struct that contains information of a word
struct wordType
{
    string word;     // word name
    int lineNum = 0; // the line number of the first occurrence
    int concord = 1; // the total number of the word in the file
};

void getFilePath(ifstream&, ofstream&, string&);   // Function to Read in the file path input
void testFilePathInput(ifstream&, string&);        // Function to Verify valid file path input
void wordCheck(string&);                           // Function to Uppercase a word and Remove its non-alphabetic characters
void displayResults(BST<wordType> []);             // Function to print out a list of all the distinct words in the concordance
template <class Type>
void testDataInput(istream&, Type&);
void testDataInput(istream&, string&);



// * ---------------------------------------- main function ---------------------------------------- *
int main()
{
    ifstream fin;   // input file stream
    ofstream fout;  // output file stream
    string fPath;
    BST<wordType> BSTArr[26]; // creating an array of 26 trees
    wordType wordInfo;
    int lineNumCounter = 1;   // the default line number of each word in file

    getFilePath(fin, fout, fPath); // Open an inventory file

    while (fin >> wordInfo.word)
    {
        wordCheck(wordInfo.word);        // Processing each word

        // Adding each word into the array of Binary Search Trees
        char charKey = wordInfo.word[0];                                 // the first char of the input word
        if (charKey >= 'A' && charKey <= 'Z')
        {
            int BSTArrPos = charKey - 'A';                          // the position in the array of Binary Search Trees
            if (BSTArr[BSTArrPos].search(wordInfo))                   // if word exists
                BSTArr[BSTArrPos].increaseConcordance(cout, wordInfo);  // just increase the concordance by 1
            else                                                         // if the word Does Not Exist
            {
                BSTArr[BSTArrPos].insert(wordInfo);    // first, create and insert the new word into the Tree
                BSTArr[BSTArrPos].updateLineNum(cout, wordInfo,
                                                lineNumCounter); // second, assign the new line number into that Bin Node
            }
        }
        // Counting line number in file
        while (fin.peek() == '\n' || fin.peek() == ' ') // if read '\n' symbol
        {
            if (fin.peek() == '\n')
            {
                lineNumCounter++; // increase line number
                fin.ignore();     // skip the '\n' symbol
            }
            else
                fin.ignore();
        }
    }
    // Displaying Menu
    int optionNum;
    do
    {
        cout << "\n*** Welcome to the Text Concordance Program ***"
                "\n    (1) Search for a word"
                "\n    (2) Display "
                "\n    (3) Exit"
                "\nPlease choose an option: ";
        cin >> optionNum;
        testDataInput(cin, optionNum);

        // Apply different options to different cases
        string aWord;           // a word input by user for searching
        wordType targetWord;
        BST<wordType> tempTree[26]; // ⚠️ ⚠️ ⚠️ temperay tree for search item list?
        switch (optionNum)
        {
            case 1:  // Search for a word
                cout << "\nWhat word do you like to search for: ";
                cin >> aWord; // read a word for searching
                testDataInput(cin, aWord);
                wordCheck(aWord);
                targetWord.word = aWord;
                // Searching the word

                if (aWord[0] >= 'A' && aWord[0] <= 'Z')                           // judge if it is a legal word
                {
                    if ( BSTArr[aWord[0] - 'A'].search(targetWord))               // if found, display the Concordance of that word
                    {
                        cout <<  "\nText"
                             << setw(30) << "First occur line number"
                             << setw(20) << "Concordance\n";
                        BSTArr[aWord[0] - 'A'].displayAnItem(cout, targetWord);
                    }
                    else                                                          // if not found, display message
                        cout << "\nThe word \"" << aWord << "\" does not exist.\n";
                }
                else
                    cout << "The word is not a legal word.\n";                    // if not legal word, display message
                break;
            case 2:  // Display
                cout << "\n*** Displaying the whole list ***\n";
                displayResults(BSTArr);  // Displaying the whole list
                break;
            default:
                cout << "\nProgram terminated successfully!\n\n";
                break;
        }
    }while (optionNum != 3);

    fin.close();

    return 0;
} // * ---------------------------------------- End of main ---------------------------------------- *




// **************************************** Function Definitions *********************************************

// Definition of readFilePath ()
void getFilePath(ifstream& fin, ofstream& fout, string& fPath)
{
    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);
    fin.open(fPath);          // Open the input file

    // Verify valid the file path input
    testFilePathInput(fin, fPath);
}

// Definition of testInput ()
void testFilePathInput(ifstream& fin, string& fPath)
{
    while(!fin)
    {
        fin.clear();           // clear bad input
        fin.ignore(10000, '\n'); // discard input
        cout << "Invalid file path, try again: ";
        getline(cin, fPath);
        fin.open(fPath);  // open the input file
    }
}

// --- Definition of testDataInput()
template <class Type>
void testDataInput(istream& in, Type& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();           // clear bad input
        in.ignore(10000, '\n'); // discard input
        cout << "Not a positive integer, please try again: ";
        in >> input;          // update the input
        testDataInput(in, input);
    }
    if (input < 1 || input > 3) // ensure option number to be just 1 or 2
    {
        cout << "Option number should be from 1 to 3, please try again: ";
        in >> input;
        testDataInput(in, input);
    }
}

void testDataInput(istream& in, string& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();           // clear bad input
        in.ignore(10000, '\n'); // discard input
        cout << "Invalid input, please try again: ";
        in >> input;          // update the input
        testDataInput(in, input);
    }
}

// Definition of wordCheck ()
void wordCheck(string& word)
{
    for (int i = 0; i < word.length(); i++)
        if (!isalpha(word[i]))
        {
            word.erase(i, 1);
            i = i - 1;
        }
    for (int i = 0; i < word.length(); i++)
        word[i] = toupper(word[i]);
}

// Definition of displayResults ()
void displayResults(BST<wordType> BSTArr[])
{
    cout <<  "\nText"
         << setw(30) << "First occur line number"
         << setw(20) << "Concordance\n";
    for (int i = 0; i < 26; i++)
        BSTArr[i].inorder(cout);
    cout << endl;
}
