// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// InsertionSort.h

#ifndef InsertionSort_h
#define InsertionSort_h

// Definition of Insertion Sort algorithm
template <typename Type>
void insertionSort(Type arr[], int arrSize)
{
    for (int i = 1; i < arrSize; i++)
    {
        int j = i - 1;
        Type temp = arr[i];
        while(temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

#endif /* InsertionSort_h */
