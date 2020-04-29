// Jian Zhong
// Prof. Mackay
// 09/17/2019
// Lab 3

#include<iostream>

using namespace std;

//function prototype goes here
int *addSize(int*, int&);


int main()
{
    int SIZE = 10, currentSize;
    int *arrPtr = new int[SIZE];
    
    for (int i = 0; i < SIZE; i++)
        arrPtr[i] = i;
    
    currentSize = SIZE;            //why is this here, what is it for?? A: update the SIZE to the current size.
    
    //What does the function call in the next line tell you about the function?? A: the return type is a pointer of type int.
    arrPtr = addSize(arrPtr, SIZE);       //SIZE now has the new size
    
    
    //ADD VALUES TO THE ARRAY TO FILL IN THE EXTRA SPACE CREATED
    int addedValue;
    cout << "What extra integer do you want to be stored in the array? ";
    cin >> addedValue;
    arrPtr[currentSize++] = addedValue;   // add value and update the currentSize by one.
    

    // This just displays the array
    for (int i = 0; i < SIZE; i++)
        cout << arrPtr[i]<<' ';
    
    return 0;
}

//function definition goes here
int *addSize(int *arrPtr, int& SIZE)
{
    int *updatedArr = new int [SIZE++]; // allocate an updated array.
    
    for(int i = 0; i < SIZE; i++)
        updatedArr[i] = arrPtr[i];  // assign the original values to the updated array.
    
    delete arrPtr;       // deallocate the old spot arrPtr points to.
    arrPtr = updatedArr; // let arrPtr point to the updated array.
    
    return arrPtr;
}
