// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// ModifiedQuickSort.h

#ifndef ModifiedQuickSort_h
#define ModifiedQuickSort_h

template <typename Type>
void insertionS(Type arr[], int arrSize)
/*--------------------------------------------------------
Insertion Sort Algorithm:
will be used by modifiedQuickSort( )
----------------------------------------------------------*/
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

template <typename ElementType>
void modifiedSplit(ElementType x[], int first, int last, int & pos)
    /*--------------------------------------------------------
    Rearrange x[first], ... , x[last] to position pivot.

    Precondition:   < and == are defined for ElementType;
    first <= pos <= last.  Note that this version
    chooses pivot = x[first]; better pivot choices
    are described later in this section.
    Postcondition: Elements of sublist are rearranged and
    pos modified so x[first], ... , x[pos-1] <= pivot
    and pivot < x[pos + 1], ... , x[last].
    ----------------------------------------------------------*/
{
    ElementType pivot = x[first];    // pivot element
    int left = first,                // index for left search
        right = last;                // index for right search
    while(left < right)
    {
        while (pivot < x[right])      // Search from right for
            right--;                  // element <= pivot
                                      // Search from left for
        while (left < right &&        // element > pivot
              (x[left] < pivot || x[left] == pivot))
            left++;

        if (left < right)             // If searches haven't met
            swap(x[left], x[right]);  // interchange elements
    }
    // End of searches; place pivot in correct position
    pos = right;
    x[first] = x[pos];
    x[pos] = pivot;
}

template <typename ElementType>
void modifiedQuickSort(ElementType x[], int first, int last)
/*-------------------------------------------------------
Quicksort array elements x[first], ..., x[last] so
they are in ascending order.

Precondition: < and == are defined for ElementType.
Note: Client programs call quicksort with first = 0
and last = n - 1, where n is the list size
Postcondition: x[first], ..., x[last] is sorted
---------------------------------------------------------*/
{
    int pos;  // pivot's final position
    if (last - first < 20)  // if <= 20 elements
        insertionS(x, 20);   // use Insertion Sort
    else      // still large enough to use the quicksort
    {
        modifiedSplit(x, first, last, pos);   // Split into 2 sublists
        modifiedQuickSort(x, first, pos - 1); // Sort left sublist
        modifiedQuickSort(x, pos + 1, last);  // Sort right sublist
    }
    // else list has 0 or 1 element and requires no sorting
}


#endif /* ModifiedQuickSort_h */
