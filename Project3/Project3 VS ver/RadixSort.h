// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// RadixSort.h

#ifndef RadixSort_h
#define RadixSort_h

#include <cmath>
#include "Queue.h"

// the Defenition of buildArrByQueue( )
template <typename Type>
void buildArrByQueue(Type arr[], int arrSize, Queue<Type> queueArr[], int queueSize = 10)
{
    int j = 0;
    for (int i = 0; i < queueSize; i++)
    {
        while ( !queueArr[i].empty() )    // if the queue element is not empty
        {
            arr[j] = queueArr[i].front(); // assign that element to arr[i]
            queueArr[i].dequeue();        // remove the element from queueArr[i]
            j++;
        }
    }
}

Queue<int> queueArr[10];  // an array of queue for Radix Sort

// the Defenition of radixSort( )
template <typename Type>
void radixSort(Type arr[], int arrSize)
{
    int numDigit = 5;         // the maximum number 10000 has 5 digits
    int power = 1;            // the power number of 10
    
    // Sort according to the total digit number
    for (int k = numDigit; k > 0; k--)
    {
        // Scan each element in the arr[](50000 elements).
        for (int i = 0; i < arrSize; i++)
        {
            // get the digit of each arr[i] from right to left
            int digit = (arr[i] % static_cast<int>(pow(10, power))) /
                        static_cast<int>(pow(10, power - 1));
            
            // insert to arr[i] into the proper array of Queue
            for (int j = 0; j < 10; j++)
                if (j == digit)
                    queueArr[j].enqueue(arr[i]); // insert
        }
        // build an array according to the current queue
        buildArrByQueue(arr, arrSize, queueArr);
        power++;
    }
}

#endif /* RadixSort_h */
