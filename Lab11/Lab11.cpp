// Jian Zhong
// Prof. Mackay
// CS132 Lab11
// 12/13/2019

#include <iostream> // cin, cout
#include <fstream>  // fin
#include <string>

using namespace std;

void getFilePath(ifstream&, string&);              // Function to Read in the file path input
void testFilePathInput(ifstream&, string&);        // Function to Verify valid file path input

struct nameType // struct of name type
{
    string fname = ""; // first name
    string lname = ""; // last name
};

// Quick sort algorithm
void split(nameType[], int, int, int& );
void quicksort(nameType[], int, int);

// * ---------------------------------------- main function ---------------------------------------- *
int main()
{
    ifstream fin;             // input file stream
    string  fPath;            // intput file path
    nameType nameArr [50];    // array for storing names
    
    getFilePath(fin, fPath);  // Open a file

    // Keep reading until the end of the input file
    int pos = 0; // index of the nameArr[]
    while (fin >> nameArr[pos].fname) // when read in first name
    {
        fin >> nameArr[pos].lname;    // also read in last name
        pos++;                        // increase pos by 1
    }
    
    // Quick Sort by last name:
    quicksort(nameArr, 0, pos - 1);
    
    
    // After sort, display last name and the first name:
    cout << "\nLAST   FIRST: \n\n";
    for (int i = 0; i < pos; i++)
        cout << nameArr[i].lname << " " << nameArr[i].fname << endl;
    cout << endl;

    fin.close(); // close text file
    
    return 0;
} // * ---------------------------------------- End of main ---------------------------------------- *



// Function Definitions

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

void split(nameType x[], int first, int last, int & pos)
    /*--------------------------------------------------------
    Rearrange x[first], ... , x[last] to position pivot.

    Precondition:   < and == are defined for ElementType;
        first <= pos <= last.  Note that this version
        chooses pivot = x[first];
     
    Postcondition: Elements of sublist are rearranged and
        pos returned so x[first], ... , x[pos-1] <= pivot
        and pivot < x[pos + 1], ... , x[last].
    ----------------------------------------------------------*/
{
    string pivot = x[first].lname;    // pivot element
    int left = first,                // index for left search
        right = last;                // index for right search
    while(left < right)
    {
        while (pivot < x[right].lname) // Search from right for
            right--;                   // element <= pivot
                                       // Search from left for
        while (left < right &&         // element > pivot
              (x[left].lname < pivot || x[left].lname == pivot))
            left++;

        if (left < right)             // If searches haven't met
            swap(x[left], x[right]);  // interchange elements
    }
    // End of searches; place pivot in correct position
    pos = right;
    x[first] = x[pos];
    x[pos].lname = pivot;
}

void quicksort(nameType x[], int first, int last)
/*-------------------------------------------------------
Quicksort array elements x[first], ..., x[last] so
they are in ascending order.

Precondition: < and == are defined for ElementType.
Note: Client programs call quicksort with first = 0
and last = n - 1, where n is the list size
Postcondition: x[first], ..., x[last] is sorted
---------------------------------------------------------*/
{
    int pos;                         // pivot's final position
    if (first < last)                // list size is > 1
    {
        split(x, first, last, pos);   // Split into 2 sublists
        quicksort(x, first, pos - 1); // Sort left sublist
        quicksort(x, pos + 1, last);   // Sort right sublist
    }
    // else list has 0 or 1 element and requires no sorting
}

