// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// Project 3.cpp 

#include <iostream>
#include <random>       // generate random numbers
#include <time.h>       // count program execution time

using namespace std;
const int SIZE = 50000; // for the size of array elements

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "Heap.h"
#include "RadixSort.h"
#include "QuickSort.h"
#include "ModifiedQuickSort.h"

/* Function Template: */
template<typename Type>
void copyArr(Type[], Type[], int); // Function to copy an array to another array.

/* Main Function: */
int main()
{
    /* Declaring 5 different arrays: */
    int arr1[SIZE], arr2[SIZE],
        arr3[SIZE], arr4[SIZE], arr5[SIZE];
    
    /* Initialize random seed: */
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,10000);

    /* Assign 50000 random numbers into 5 arrays: */
    for (int i = 0; i < SIZE; i++)
    {
        arr1[i] = distribution(generator);
        arr2[i] = distribution(generator);
        arr3[i] = distribution(generator);
        arr4[i] = distribution(generator);
        arr5[i] = distribution(generator);
    }
    
    clock_t startClicks, finishClicks;  // start time clicks and finish time clicks
    double executionTime;               // time clicks during program execution
    int arrTemp[SIZE];                  // the actual array for sorting

    cout << "--------- 1st Comparison ---------\n\n"; /* ------------------ 1st Comparison ------------------ */
    /* Selection Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);       // copy arr1 into arrTemp
    startClicks = clock();              // mark the start time clicks
    selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double sTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Selection elapsed time:      " << sTime1 << " ms\n\n";
    
    /* Insertion Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);       // copy arr1 into arrTemp
    startClicks = clock();              // mark the start time clicks
    insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double iTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Insertion elapsed time:      " << iTime1 << " ms\n\n";
    
    /* Radix Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);       // copy arr1 into arrTemp
    startClicks = clock();              // mark the start time clicks
    radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double rTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Radix elapsed time:          " << rTime1 << " ms\n\n";
    
    /* Heap Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);       // copy arr1 into arrTemp
    startClicks = clock();              // mark the start time clicks
    heap<int> heap1(arrTemp, SIZE);     // heapify the arrTemp
    heap1.heapSort();                   // heap sort the heap
    finishClicks = clock();             // mark the start time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double hTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Heap elapsed time:           " << hTime1 << " ms\n\n";
    
    /* Quick Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);       // copy arr1 into arrTemp
    startClicks = clock();              // mark the start time clicks
    quicksort(arrTemp, 0, SIZE);        // sort arrTemp by Quick Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double qTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Quick elapsed time:          " << qTime1 << " ms\n\n";
    
    /* Modified Quick Sort(1st): */
    copyArr(arr1, arrTemp, SIZE);        // copy arr1 into arrTemp
    startClicks = clock();               // mark the start time clicks
    modifiedQuickSort(arrTemp, 0, SIZE); // sort arrTemp by Quick Sort
    finishClicks = clock();              // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double mQTime1 = executionTime * 1000; // convert the time to millisecond
    cout << "Modified Quick elapsed time: " << mQTime1 << " ms\n\n";
    
    cout << "--------- 2nd Comparison ---------\n\n"; /* ------------------ 2nd Comparison ------------------ */
    /* Selection Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);       // copy arr2 into arrTemp
    startClicks = clock();              // mark the start time clicks
    selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double sTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Selection elapsed time:      " << sTime2 << " ms\n\n";
    
    /* Insertion Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);       // copy arr2 into arrTemp
    startClicks = clock();              // mark the start time clicks
    insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double iTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Insertion elapsed time:      " << iTime2 << " ms\n\n";
    
    /* Radix Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);       // copy arr2 into arrTemp
    startClicks = clock();              // mark the start time clicks
    radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double rTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Radix elapsed time:          " << rTime2 << " ms\n\n";
    
    /* Heap Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);       // copy arr2 into arrTemp
    startClicks = clock();              // mark the start time clicks
    heap<int> heap2(arrTemp, SIZE);     // heapify the arrTemp
    heap2.heapSort();                   // heap sort the heap
    finishClicks = clock();             // mark the start time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double hTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Heap elapsed time:           " << hTime2 << " ms\n\n";
    
    /* Quick Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);       // copy arr2 into arrTemp
    startClicks = clock();              // mark the start time clicks
    quicksort(arrTemp, 0, SIZE);        // sort arrTemp by Quick Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double qTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Quick elapsed time:          " << qTime2 << " ms\n\n";
    
    /* Modified Quick Sort(2nd): */
    copyArr(arr2, arrTemp, SIZE);        // copy arr2 into arrTemp
    startClicks = clock();               // mark the start time clicks
    modifiedQuickSort(arrTemp, 0, SIZE); // sort arrTemp by Quick Sort
    finishClicks = clock();              // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double mQTime2 = executionTime * 1000; // convert the time to millisecond
    cout << "Modified Quick elapsed time: " << mQTime2 << " ms\n\n";
    
    
    cout << "--------- 3rd Comparison ---------\n\n"; /* ------------------ 3rd Comparison ------------------ */
    /* Selection Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);       // copy arr3 into arrTemp
    startClicks = clock();              // mark the start time clicks
    selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double sTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Selection elapsed time:      " << sTime3 << " ms\n\n";
    
    /* Insertion Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);       // copy arr3 into arrTemp
    startClicks = clock();              // mark the start time clicks
    insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double iTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Insertion elapsed time:      " << iTime3 << " ms\n\n";
    
    /* Radix Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);       // copy arr3 into arrTemp
    startClicks = clock();              // mark the start time clicks
    radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double rTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Radix elapsed time:          " << rTime3 << " ms\n\n";
    
    /* Heap Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);       // copy arr3 into arrTemp
    startClicks = clock();              // mark the start time clicks
    heap<int> heap3(arrTemp, SIZE);     // heapify the arrTemp
    heap3.heapSort();                   // heap sort the heap
    finishClicks = clock();             // mark the start time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double hTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Heap elapsed time:           " << hTime3 << " ms\n\n";
    
    /* Quick Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);       // copy arr3 into arrTemp
    startClicks = clock();              // mark the start time clicks
    quicksort(arrTemp, 0, SIZE);        // sort arrTemp by Quick Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double qTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Quick elapsed time:          " << qTime3 << " ms\n\n";
    
    /* Modified Quick Sort(3rd): */
    copyArr(arr3, arrTemp, SIZE);        // copy arr3 into arrTemp
    startClicks = clock();               // mark the start time clicks
    modifiedQuickSort(arrTemp, 0, SIZE); // sort arrTemp by Quick Sort
    finishClicks = clock();              // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double mQTime3 = executionTime * 1000; // convert the time to millisecond
    cout << "Modified Quick elapsed time: " << mQTime3 << " ms\n\n";
    
    cout << "--------- 4th Comparison ---------\n\n"; /* ------------------ 4th Comparison ------------------ */
    /* Selection Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);       // copy arr4 into arrTemp
    startClicks = clock();              // mark the start time clicks
    selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double sTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Selection elapsed time:      " << sTime4 << " ms\n\n";
    
    /* Insertion Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);       // copy arr4 into arrTemp
    startClicks = clock();              // mark the start time clicks
    insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double iTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Insertion elapsed time:      " << iTime4 << " ms\n\n";
    
    /* Radix Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);       // copy arr4 into arrTemp
    startClicks = clock();              // mark the start time clicks
    radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double rTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Radix elapsed time:          " << rTime4 << " ms\n\n";
    
    /* Heap Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);       // copy arr4 into arrTemp
    startClicks = clock();              // mark the start time clicks
    heap<int> heap4(arrTemp, SIZE);     // heapify the arrTemp
    heap4.heapSort();                   // heap sort the heap
    finishClicks = clock();             // mark the start time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double hTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Heap elapsed time:           " << hTime4 << " ms\n\n";
    
    /* Quick Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);       // copy arr4 into arrTemp
    startClicks = clock();              // mark the start time clicks
    quicksort(arrTemp, 0, SIZE);        // sort arrTemp by Quick Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double qTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Quick elapsed time:          " << qTime4 << " ms\n\n";
    
    /* Modified Quick Sort(4th): */
    copyArr(arr4, arrTemp, SIZE);        // copy arr4 into arrTemp
    startClicks = clock();               // mark the start time clicks
    modifiedQuickSort(arrTemp, 0, SIZE); // sort arrTemp by Quick Sort
    finishClicks = clock();              // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double mQTime4 = executionTime * 1000; // convert the time to millisecond
    cout << "Modified Quick elapsed time: " << mQTime4 << " ms\n\n";
    
    cout << "--------- 5th Comparison ---------\n\n"; /* ------------------ 5th Comparison ------------------ */
    /* Selection Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);       // copy arr5 into arrTemp
    startClicks = clock();              // mark the start time clicks
    selectionSort(arrTemp, SIZE);       // sort arrTemp by Selection Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double sTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Selection elapsed time:      " << sTime5 << " ms\n\n";
    
    /* Insertion Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);       // copy arr5 into arrTemp
    startClicks = clock();              // mark the start time clicks
    insertionSort(arrTemp, SIZE);       // sort arrTemp by Insertion Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double iTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Insertion elapsed time:      " << iTime5 << " ms\n\n";
    
    /* Radix Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);       // copy arr5 into arrTemp
    startClicks = clock();              // mark the start time clicks
    radixSort(arrTemp, SIZE);           // sort arrTemp by Radix Sort
    finishClicks = clock();             // mark the  finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double rTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Radix elapsed time:          " << rTime5 << " ms\n\n";
    
    /* Heap Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);       // copy arr5 into arrTemp
    startClicks = clock();              // mark the start time clicks
    heap<int> heap5(arrTemp, SIZE);     // heapify the arrTemp
    heap5.heapSort();                   // heap sort the heap
    finishClicks = clock();             // mark the start time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double hTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Heap elapsed time:           " << hTime5 << " ms\n\n";
    
    /* Quick Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);       // copy arr5 into arrTemp
    startClicks = clock();              // mark the start time clicks
    quicksort(arrTemp, 0, SIZE);        // sort arrTemp by Quick Sort
    finishClicks = clock();             // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double qTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Quick elapsed time:          " << qTime5 << " ms\n\n";
    
    /* Modified Quick Sort(5th): */
    copyArr(arr5, arrTemp, SIZE);        // copy arr5 into arrTemp
    startClicks = clock();               // mark the start time clicks
    modifiedQuickSort(arrTemp, 0, SIZE); // sort arrTemp by Quick Sort
    finishClicks = clock();              // mark the finish time clicks
    executionTime = (double)(finishClicks - startClicks) / CLOCKS_PER_SEC;
    double mQTime5 = executionTime * 1000; // convert the time to millisecond
    cout << "Modified Quick elapsed time: " << mQTime5 << " ms\n\n";
    
    /* Average time elapsed: */
    double selectionAve = (sTime1 + sTime2 + sTime3 + sTime4 + sTime5) / 5;
    double insertionAve = (iTime1 + iTime2 + iTime3 + iTime4 + iTime5) / 5;
    double radixAve     = (rTime1 + rTime2 + rTime3 + rTime4 + rTime5) / 5;
    double heapAve      = (hTime1 + hTime2 + hTime3 + hTime4 + hTime5) / 5;
    double quickAve     = (qTime1 + qTime2 + qTime3 + qTime4 + qTime5) / 5;
    double mQuickAve    = (mQTime1 + mQTime2 + mQTime3 + mQTime4 + mQTime5) / 5;
    
    /* Display the Average results: */
    cout << "*--------- Average Execution Time ---------*\n"
         << "\n     Selection:      " << selectionAve << " ms"
         << "\n     Insertion:      " << insertionAve << " ms"
         << "\n     Radix:          " << radixAve << " ms"
         << "\n     Heap:           " << heapAve << " ms"
         << "\n     Quick:          " << quickAve << " ms"
         << "\n     Modified Quick: " << mQuickAve<< " ms\n\n";
    
    return 0;
} /*------------------ End-of-Main ------------------*/


/* Definition of copyArr( ) */
template<typename Type>
void copyArr(Type origArr[], Type tempArr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        tempArr[i] = origArr[i];
}


