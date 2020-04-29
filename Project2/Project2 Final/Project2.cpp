// Jian Zhong
// Prof. Mackay
// CS132 Project 2
// 11/25/2019
// Program Name: Text Concordance Program
// Used for: a program that reads a text file and constructs the concordance

#include <iostream> // cin, cout
#include <fstream>  // fin: read text in input file
#include <string>   // word type and word process

#include "BST.h"    // BST data structure

using namespace std;

// A struct that contains necessary information of a word
struct wordType
{
    string word;     // word name
    int lineNum = 0; // the line number of the first occurrence
    int concord = 1; // the total number of the word in the file
};

void getFilePath(ifstream&, string&);              // Function to Read in the file path input
void testFilePathInput(ifstream&, string&);        // Function to Verify valid file path input
void wordCheck(string&);                           // Function to Uppercase a word and Remove its non-alphabetic characters
void displayResults(BST<wordType> []);             // Function to print out a list of all the distinct words in the concordance
template <class Type>                              // Function template for validating legal input data type
void testDataInput(istream&, Type&);
void testDataInput(istream&, string&);             // Function to validate the legal searching word(string) input by user


// * ---------------------------------------- main function ---------------------------------------- *
int main()
{
    ifstream fin;             // input file stream
    string fPath;             // intput file path
    BST<wordType> BSTArr[26]; // creating an array of 26 trees
    wordType wordInfo;        // creating a wordType type for each word in input file
    int lineNumCounter = 1;   // the default line number of each word in file

    getFilePath(fin, fPath);  // Open an inventory file

    // Keep reading words until the end of the input file
    while (fin >> wordInfo.word)
    {
        wordCheck(wordInfo.word);                                        // Processing each word

        // Adding each word into the array of Binary Search Trees
        char charKey = wordInfo.word[0];                                 // the first char of the input word
        if (charKey >= 'A' && charKey <= 'Z')
        {
            int BSTArrPos = charKey - 'A';                               // the position in the array of Binary Search Trees
            if (BSTArr[BSTArrPos].search(wordInfo))                      // if word exists
                BSTArr[BSTArrPos].increaseConcordance(cout, wordInfo);   // just increase the concordance by 1
            else                                                         // if the word Does Not Exist
            {
                BSTArr[BSTArrPos].insert(wordInfo);                      // first, create and insert the new word into the Tree
                BSTArr[BSTArrPos].updateLineNum(cout, wordInfo,
                                                lineNumCounter);         // second, assign the new line number into that Bin Node
            }
        }
        
        // Counting line number in file
        while (fin.peek() == '\n' || fin.peek() == '\r' || fin.peek() == ' ')
        {
            if (fin.peek() == '\n') // if read '\n'(newline character in Mac or Linux)
            {
                lineNumCounter++;   // increase line number
                fin.ignore();       // skip the '\n'(10)
            }
            else if (fin.peek() == '\r') // if read "\n\r"(newline character in Windows)
            {
                lineNumCounter++;   // increase line number
                fin.ignore();       // skip the "\n\r"(13 10)
                fin.ignore();
            }
            else                    // if read white space
                fin.ignore();       // ignore white space
        }
    }
    
    // Displaying Menu
    int optionNum; // Menu option input by user
    do
    {
        cout << "\n*** Welcome to the Text Concordance Program ***"
                "\n    (1) Search for a word"
                "\n    (2) Display "
                "\n    (3) Exit"
                "\nPlease choose an option: ";
        cin >> optionNum;               // read in Menu option
        testDataInput(cin, optionNum);  // validate the option input

        // Apply different options to different cases
        string aWord;                   // a word input by user for searching
        wordType targetWord;            // a wordType(struct) type for the input word
        switch (optionNum)
        {
            case 1:  // To search a word
                cout << "\nWhat word do you like to search for: ";
                cin >> aWord;              // read in a word input by user
                testDataInput(cin, aWord); // validate the word
                wordCheck(aWord);          // clean and uppcase the word
                if (aWord[0] >= 'A' && aWord[0] <= 'Z')               // check if the word starts with letter
                {
                    targetWord.word = aWord;                          // assign the word into a wordType object for comparison
                    if ( BSTArr[aWord[0] - 'A'].search(targetWord))   // search the BST array for the word
                    {
                        cout <<  "\nText"
                             << setw(30) << "First occur line number"
                             << setw(20) << "Concordance\n";
                        BSTArr[aWord[0] - 'A'].displayAnItem(cout, targetWord);  // word found, display concordance of that word
                    }
                    else                                              // if not found, display message
                        cout << "\nThe word \"" << aWord << "\" does not exist.\n";
                }
                else
                    cout << "The word is not a legal word.\n";        // if not legal word, display message
                break;
            case 2:   // Display Results
                cout << "\n------------- Displaying the whole list -------------";
                displayResults(BSTArr);  // Displaying the whole list
                cout << "-----------------------------------------------------\n";
                break;
            default:  // if option is 3, end the swtich option loop
                cout << "\nProgram terminated successfully!\n\n";
                break;
        }
    }while (optionNum != 3); // if option is 3, exit the do-while Menu loop

    fin.close(); // close text file
    return 0;
} // * ---------------------------------------- End of main ---------------------------------------- *



// **************************************** Function Definitions *********************************************

// Definition of getFilePath ()
void getFilePath(ifstream& fin, string& fPath)
{
    cout << "Enter the file path of the input file: ";
    getline(cin, fPath);           // get the file path
    fin.open(fPath);               // Open the input file
    testFilePathInput(fin, fPath); // Veridation for file path input
}

// Definition of testFilePathInput ()
void testFilePathInput(ifstream& fin, string& fPath)
{
    while(!fin)
    {
        fin.clear();             // clear bad input
        fin.ignore(10000, '\n'); // discard input
        cout << "Invalid file path, try again: ";
        getline(cin, fPath);     // get the file path
        fin.open(fPath);         // open the input file
    }
}

// --- Definition of testDataInput()
template <class Type>
void testDataInput(istream& in, Type& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();               // clear bad input
        in.ignore(10000, '\n');   // discard input
        cout << "Not a positive integer, please try again: ";
        in >> input;              // update the input
        testDataInput(in, input); // validation
    }
    if (input < 1 || input > 3) // ensure option number to be just 1 or 2 or 3
    {
        cout << "Option number should be from 1 to 3, please try again: ";
        in >> input;
        testDataInput(in, input);
    }
}

// Definition of testDataInput ()
void testDataInput(istream& in, string& input)
{
    if (!in || (in.peek() != '\n'))
    {
        in.clear();               // clear bad input
        in.ignore(10000, '\n');   // discard input
        cout << "Invalid input, please try again: ";
        in >> input;              // update the input
        testDataInput(in, input); // validation
    }
}

// Definition of wordCheck ()
void wordCheck(string& word)
{
    
    // Remove non-letter from the front of the word
    for (int i = 0; i < word.length(); i++) // scan from the front
    {
        // advoid assertion fail in visual studio if text is copied directly from Microsoft Word file
        if (static_cast<int>(word[i]) < -1 || static_cast<int>(word[i]) > 255) break;

        if (!isalpha(word[i]))            // if the character is not a letter
        {
            word.erase(i, 1);             // remove it from the word string
            i--;
        }
        else
            break;
    }
    
    // Remove non-letter from the back of the word
    for (unsigned long j = word.length(); j > 0; j--) // scan from the back
    {
        // advoid assertion fail in visual studio if text is copied directly from Microsoft Word file
        if (static_cast<int>(word[j]) < -1 || static_cast<int>(word[j]) > 255) break;

        if (!isalpha(word[j]))                     // if the character is not a letter
            word.erase(j, 1);                      // remove it from the word string
        else
            break;
    }
    
    // Convert the all the letters to Uppercase
    for (int i = 0; i < word.length(); i++) // scan each character
    {
        // advoid assertion fail in visual studio if text is copied directly from Microsoft Word file
        if (static_cast<int>(word[i]) < -1 || static_cast<int>(word[i]) > 255) break;

        if (isalpha(word[i]))               // if the character is letter
            word[i] = toupper(word[i]);     // uppercase
    }
}

// Definition of displayResults ()
void displayResults(BST<wordType> BSTArr[])
{
    bool empty = true;
    
    for (int i = 0; i < 26; i++)   // scan if 26 elements in the BST array are all empty
        if ( !BSTArr[i].empty() )  // if not
        {
            empty = false; // change empty value
            break;         // exit the loop
        }
    
    if (empty)  // if all trees are all empty
        cout << "\n*** Couldn't find any legal words ***\n"; // display message
    else        // if not empty
    {
        cout <<  "\nWord"
             << setw(30) << "First Occur Line Number"
             << setw(20) << "Total Count\n";
        for (int i = 0; i < 26; i++)  // traverse every element in the BST array
            BSTArr[i].inorder(cout);  // print results
    }
}
