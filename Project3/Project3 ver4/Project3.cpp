// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// Project 3.cpp

// ⚠️ updates: 修正了平均数的计算错误，不是5个相同的相加，而是累计的average。

#include <iostream>		  // cin, cout
#include <random>         // default_random_engine, uniform_int_distribution
#include <time.h>         // clock_t, clock(), CLOCKS_PER_SEC
#include <chrono>         // chrono::system_clock::now().time_since_epoch().count()

using namespace std;

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "Heap.h"		  // for Heap sort
#include "RadixSort.h"  
#include "QuickSort.h"
#include "ModifiedQuickSort.h"
#include "MergeSort.h"

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
     unsigned long totalSTime = 0,  STime = 0,
                   totalITime = 0,  ITime = 0,  // Selection elapsed time, Insertion elapsed time.
                   totalRTime = 0,  RTime = 0,
                   totalHTime = 0,  HTime = 0,  // Radix elapsed time, Heap elasped time.
                   totalQTime = 0,  QTime = 0,
                   totalMQTime = 0, MQTime = 0, // Quick elapsed time, Modified Quick elasped time.
                   totalMTime  = 0, MTime = 0;
    
    /* Assign 50000 random numbers into 5 arrays: */
	for (int compare = 1; compare <= 5; compare++) // 5 times of comparison loop
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
		clock_t start = clock();		    // mark the start time clicks
		selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
        STime = ( clock() - start ) * 1000 / CLOCKS_PER_SEC;
        totalSTime = STime + totalSTime;
		cout << "Selection elapsed time:      " << STime << " ms\n";
        
        /* Insertion Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
        ITime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalITime = ITime + totalITime;
        cout << "Insertion elapsed time:      " << ITime << " ms\n";

        /* Radix Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
        RTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalRTime = RTime + totalRTime;
        cout << "Radix elapsed time:          " << RTime << " ms\n";

        /* Heap Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        heap<int> aHeap(arrTemp, SIZE);     // pass the arrTemp and insert into aHeap
        aHeap.heapSort();                   // Heap sort aHeap
        /*--------------------------------------------------------
         But the sorted array will be stored in myHeap[],
            use " aHeap.display(cout); " to display the sorted array.
         --------------------------------------------------------*/
        HTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalHTime = HTime + totalHTime;
        cout << "Heap elapsed time:           " << HTime << " ms\n";

        /* Quick Sort: */
        copyArr(arr, arrTemp, SIZE);        // copy arr into arrTemp
        start = clock();                    // mark the start time clicks
        quicksort(arrTemp, 0, SIZE - 1);    // sort arrTemp by Quick Sort
        QTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalQTime = QTime + totalQTime;
        cout << "Quick elapsed time:          " << QTime << " ms\n";

        /* Modified Quick Sort: */
        copyArr(arr, arrTemp, SIZE);             // copy arr into arrTemp
        start = clock();                         // mark the start time clicks
        modifiedQuickSort(arrTemp, 0, SIZE - 1); // sort arrTemp by Modified Quick Sort
        MQTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalMQTime = MQTime + totalMQTime;
        cout << "Modified Quick elapsed time: " << MQTime << " ms\n";
        
        /* Merge Sort: */
        copyArr(arr, arrTemp, SIZE);           // copy arr into arrTemp
        start = clock();                       // mark the start time clicks
        mergeSort(arrTemp, SIZE, 0, SIZE - 1); // sort arrTemp by Merge Sort
        MTime = (clock() - start) * 1000 / CLOCKS_PER_SEC;
        totalMTime = MTime + totalMTime;
        cout << "Merge      elapsed time:     " << MTime << " ms\n";
        
	} // ---- End of comparison loop

    /* Display the average time elapsed of each method: */
    cout << "\n---------* Average Execution Time *---------"
         << "\n    Selection:      " << totalSTime  / 5.0 << " ms"
         << "\n    Insertion:      " << totalITime  / 5.0 << " ms"
         << "\n    Radix:          " << totalRTime  / 5.0 << " ms"
         << "\n    Heap:           " << totalHTime  / 5.0 << " ms"
         << "\n    Quick:          " << totalQTime  / 5.0 << " ms"
         << "\n    Modified Quick: " << totalMQTime / 5.0 << " ms"
         << "\n    Merge:          " << totalMTime  / 5.0 << " ms\n\n";
    
    return 0;
} /*------------------ End-of-Main ------------------*/


/* Definition of copyArr( ) */
template<typename Type>
void copyArr(Type origArr[], Type tempArr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        tempArr[i] = origArr[i];
}
