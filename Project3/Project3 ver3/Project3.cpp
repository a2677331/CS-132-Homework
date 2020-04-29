// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// Project 3.cpp

#include <iostream>          // cin, cout
#include <random>         // default_random_engine, uniform_int_distribution
#include <time.h>         // clock_t, clock(), CLOCKS_PER_SEC
#include <chrono>         // chrono::system_clock::now().time_since_epoch().count()

using namespace std;

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "Heap.h"          // for Heap sort
#include "RadixSort.h"
#include "QuickSort.h"
#include "ModifiedQuickSort.h"

const int SIZE = 50000;   // the size of array

/*-----------------------------------------
 Function Template:
   Function to copy an array into another.
 ------------------------------------------*/
template<typename Type>
void copyArr(Type[], Type[], int);

/* Declaring 5 different arrays: */
int arr[SIZE];      // an array that contains 50000 random numbers
int arrTemp[SIZE];  // a copied version of the arr[]


/*---------------------------------------- Main Function: ----------------------------------------*/
int main()
{
     unsigned long sTime = 0, iTime = 0,  // Selection elapsed time, Insertion elapsed time.
                   rTime = 0, hTime = 0,  // Radix elapsed time, Heap elasped time.
                   qTime = 0, mQTime = 0; // Quick elapsed time, Modified Quick elasped time.
    
    /* Assign 50000 random numbers into 5 arrays: */
    for (int compare = 1; compare <= 5; compare++) // 5 times of comparison
    {
        // For each comparison, display proper message:
        if (compare == 1) cout << "--------- 1st Comparison ---------\n\n";
        if (compare == 2) cout << "\n--------- 2nd Comparison ---------\n\n";
        if (compare == 3) cout << "\n--------- 3rd Comparison ---------\n\n";
        if (compare == 4) cout << "\n--------- 4th Comparison ---------\n\n";
        if (compare == 5) cout << "\n--------- 5th Comparison ---------\n\n";

        /* Initialize random seed: */
        default_random_engine generator;  // random number generator
        generator.seed(chrono::system_clock::now().time_since_epoch().count()); // generate random numbers from time moments
        uniform_int_distribution<int> distribution(1, 10000);  // limite the random numbers from 1 to 10000

        // For each comparison, assign 50000 random values into the array
        for (int pos = 0; pos < SIZE; pos++)
            arr[pos] = distribution(generator);

        /* Selection Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        clock_t start = clock();            // mark the start time clicks
        selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
        sTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Selection elapsed time:      " << sTime << " ms\n";

        /* Insertion Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
        iTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Insertion elapsed time:      " << iTime << " ms\n";

        /* Radix Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
        rTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Radix elapsed time:          " << rTime << " ms\n";

        /* Heap Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        heap<int> aHeap(arrTemp, SIZE);     // pass the arrTemp and insert into aHeap
        aHeap.heapSort();                   // Heap sort aHeap
        /*--------------------------------------------------------
         But the sorted array will be stored in myHeap[],
            use " aHeap.display(cout); " to display the sorted array.
         --------------------------------------------------------*/
        hTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Heap elapsed time:           " << hTime << " ms\n";

        /* Quick Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        quicksort(arrTemp, 0, SIZE - 1);    // sort arrTemp by Quick Sort
        qTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Quick elapsed time:          " << qTime << " ms\n";

        /* Modified Quick Sort: */
        copyArr(arr, arrTemp, SIZE);         // copy arr into arrTemp
        start = clock();                     // mark the start time clicks
        modifiedQuickSort(arrTemp, 0, SIZE - 1); // sort arrTemp by Quick Sort
        mQTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        cout << "Modified Quick elapsed time: " << mQTime << " ms\n";
    }

    /* Display the average time elapsed of each method: */
    cout << "\n---------* Average Execution Time *---------"
         << "\n    Selection:      " << (sTime + sTime + sTime + sTime + sTime) / 5 << " ms"
         << "\n    Insertion:      " << (iTime + iTime + iTime + iTime + iTime) / 5 << " ms"
         << "\n    Radix:          " << (rTime + rTime + rTime + rTime + rTime) / 5 << " ms"
         << "\n    Heap:           " << (hTime + hTime + hTime + hTime + hTime) / 5 << " ms"
         << "\n    Quick:          " << (qTime + qTime + qTime + qTime + qTime) / 5 << " ms"
         << "\n    Modified Quick: " << (mQTime + mQTime + mQTime + mQTime + mQTime) / 5 << " ms\n\n";
    
    return 0;
} /*------------------ End-of-Main ------------------*/


/* Definition of copyArr( ) */
template<typename Type>
void copyArr(Type origArr[], Type tempArr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        tempArr[i] = origArr[i];
}
