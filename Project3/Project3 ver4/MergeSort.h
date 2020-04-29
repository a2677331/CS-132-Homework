//
//  MergeSort.h
#ifndef MergeSort_h
#define MergeSort_h

#include <iostream>

using namespace std;

// Definition of merge1 ( ) 模版的版本
void merge1(int arr[], int f, int m, int l)
{
    // Size for two temp arrays
    int n1 = m - f + 1; // ⚠️ 注：从arr index里找前半段容量的方法！ 搞了好久
    int n2 = l - m;     // ⚠️ 注：从arr index里找后半段容量的方法！

    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays Left[] and Right[] */
    for (int i = 0; i < n1; i++)
        L[i] = arr[f + i];
    /* ⚠️ !! 搞了很久 为什么不是arr[i]？
     因为每次recursive时，arr的第一个pos是不同的，要从f参数开始！*/
    for (int j = 0; j < n2; j++)
        R[j] = arr[j + m + 1];
    
    int i = 0,  // index of first subarray
        j = 0,  // index of second subarray
        k  = f; // Initial index of merged subarray
    /* ⚠️ !! 搞了很久 为什么不是k = 0？
     因为每次recursive时，arr的第一个pos是不同的，要从f参数开始！*/
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++; // ⚠️
    }
    
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++; // ⚠️
    }
}

// Definition of merge2 ( ) 自己摸索的版本
void merge2(int arr[], int f, int m, int l)
{
    // Size for two temp arrays
    int n1 = m - f + 1; // ⚠️ 注：从arr index里找前半段容量的方法！ 搞了好久
    int n2 = l - m;     // ⚠️ 注：从arr index里找后半段容量的方法！

    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < n1; i++)
        L[i] = arr[f + i]; // ⚠️ !! 搞了很久 为什么不是arr[i]？ 从f开始和 i（计数）
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; // ⚠️ !! 搞了很久，这里是m+1（中间加一开始）和 j（计数）
    
    /* Merge the temp arrays back into arr[f..l]*/
    int i = 0; // index of first subarray
    int j = 0; // index of second subarray
    int k = f;
//    for (int k = f; k < arrLength; k++)
        // ⚠️ 哪里错❌了？
        /* 不能用k < arrlength,因为f=2开始，
         arrlength也是2，而for loop 中的2<2会不执行，导致全错！！*/
    
    while (i < n1 && j < n2) // when both L and R'S index are smaller than n1,n2
    {
        // Compare, and assign the Smaller one
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        
        // ⚠️因为i和j在while里面有变化，所以可以在下面加if重新判断i和j！
        if (i >= n1) // ⚠️这里！
        {
            while (j < n2)
            {
                arr[k] = R[j];
                k++;
                j++;
            }
        }

        if (j >= n2) // ⚠️这里！
        {
            while (i < n1)
            {
                arr[k] = L[i];
                k++;
                i++;
            }
        }
    }
}


void mergeSort(int arr[], int arrSize, int f, int l)
{
    if (f < l) // ⚠️ 别忘了base case和recursive case啊！！ 搞了好久
    {
        int m = (f + l) / 2; // ⚠️ 搞了好久
        mergeSort(arr, arrSize, f, m);      // sort left
        mergeSort(arr, arrSize, m + 1, l);  // sort right
        merge2(arr, f, m, l);               // merge
    }
}

#endif /* MergeSort_h */
