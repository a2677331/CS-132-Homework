// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// RadixSort.h

#ifndef RadixSort_h
#define RadixSort_h

#include <cmath>          // pow( )
#include "LQueue.h"       // used by Radix Sort
Queue<int> queueArr[10];  // an array of queue that represents 0 ~ 9.


// Defenition of buildArrByQueue( )
template <typename Type>
void buildArrByQueue(Type arr[], int arrSize, Queue<Type> queueArr[], int queueSize = 10)
{
    int pos = 0; // position of the arr[] starts with 0.
    for (int i = 0; i < queueSize; i++)
    {
        while ( !queueArr[i].empty() )    // if the queue element is not empty
        {
            arr[pos] = queueArr[i].front(); // assign that element to arr[i]
            queueArr[i].dequeue();        // remove an element from queueArr[i]
            pos++; // increase position by 1
        }
    }
}


// Defenition of RadixSort algorithm
template <typename Type>
void radixSort(Type arr[], int arrSize)
{
    int numDigit = 5;         // the maximum number 10000 has 5 digits
    int power = 1;            // the power number of 10
    
    for (int k = numDigit; k > 0; k--)     // Sort according to the # of digits
    {
        for (int i = 0; i < arrSize; i++)  // Scan each element in the arr[](50000 elements).
        {
            // get the digit of each arr[i]
            int digit = (arr[i] % static_cast<int>( pow(10, power) ) ) /
                            static_cast<int>( pow(10, power - 1) );
        
            for (int j = 0; j < 10; j++)   // see if the digit matches digit Queue[ ]
                if (j == digit)
                {
                    queueArr[j].enqueue(arr[i]); // insert
                    break;
                }
        }
        buildArrByQueue(arr, arrSize, queueArr); // reset arr[ ] and Queue[ ]
        power++; // increase 10's power by 1.
    }
}


#endif /* RadixSort_h */
