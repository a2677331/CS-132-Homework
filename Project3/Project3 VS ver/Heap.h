// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// Heap.h

#ifndef HEAP_H
#define HEAP_H

template <typename datatype>
class heap
{
public:
	void insert(datatype);      // inserts at the end, rearranges to keep a heap
	void display(ostream &);    // displays the heap
	void removeTop();           // removes the top value, rearranges to keep a heap
	datatype top();             // returns the value at the top
	datatype getValue(int);     // returns the value at a certain position
	bool empty();               // returns true if the heap is empty
	heap();			            // default constructor
	heap(int);		            // constructor passing in size of array
	heap(datatype[], int);	    // constructor, passing in array, and size
	~heap();                    // destructor
    void heapSort();

private:
	void percolateDown(int);
	void percolateUp(int);
	int size = 0;
	int maxSize;
	int * myHeap;
};

template <typename datatype>
void heap<datatype>::heapSort()
{
    int tempSize = size; // store the orig size
    
    // when size is 1, stop
    while (size != 1)
    {
        // swap root with last element
        datatype temp = myHeap[1];
        myHeap[1] = myHeap[size];
        myHeap[size] = temp;
        
        // size is decreased by 1
        size--; // ⚠️ 注意要比percolate down先执行！
        
        // percolate down the root
        percolateDown(1);
    }
    size = tempSize; // after sorting, assign the orig size back
}


template <typename datatype>
datatype heap<datatype>::getValue(int position)
{
	return myHeap[position];
}

template <typename datatype>
bool heap<datatype>::empty()
{
	return size == 0;
}
template <typename datatype>
heap<datatype>::heap()
{
	maxSize = 100;
	myHeap= new datatype[maxSize + 1];
}

template <typename datatype>
heap<datatype>::heap(int size)
{
	maxSize = size;
	myHeap = new datatype[maxSize + 1];
}

template <typename datatype>
heap<datatype>::heap(datatype orig[], int arrSize)
{
	maxSize = arrSize * 2;
	myHeap = new datatype[maxSize];
	for (int i = 0; i < arrSize; i++)
		insert(orig[i]);  // ⚠️ 注意是吧复制来的array[0] copy to myheap[1]!
}

template <typename datatype>
heap<datatype>::~heap()
{
	delete []  myHeap;
}

template <typename datatype>
void heap<datatype>::insert(datatype entry)
{
	if (size < maxSize)
	{
		size++;
		myHeap[size] = entry;
		percolateUp(size);
	}
	else
		cout << "No room, couldn't insert\n";
}

template <typename datatype>
void heap<datatype>::percolateUp(int position)
{
	bool done = false;
	while (position/2 > 0 &&!done)
	{
		if (myHeap[position / 2] < myHeap[position])
		{
			datatype temp = myHeap[position / 2];
			myHeap[position/2] = myHeap[position];
			myHeap[position] = temp;
	
			position = position / 2;
		}
		else
			done = true;
	}
}

template <typename datatype>
void heap<datatype>::display(ostream &out)
{
	for (int i = 1; i < size + 1; i++)
	{
		cout << myHeap[i] << ' ';
	}
	cout << endl;
}

template <typename datatype>
void heap<datatype>::removeTop()
{
	if (size > 0)
	{
		myHeap[1] = myHeap[size];
		size--;
		percolateDown(1);
	}
	else
		cout << "Heap empty, nothing to remove\n";
}

template <typename datatype>
void heap<datatype>::percolateDown(int position)
{
	if (position * 2 > size)    // no children
		return;

	//set 'bigger child' to be left-child
	int bigChild = position * 2;

	if (position * 2 < size)		//if 2 children
	{   //if right > left, set 'bigger child' to be right
		if (myHeap[position * 2 + 1]>myHeap[position * 2])
			bigChild++;
	}
	//swap value with that of bigger child, IF NECESSARY
	if (myHeap[bigChild] > myHeap[position])
	{
		//swap value with that of bigger child
		datatype temp = myHeap[position];
		myHeap[position] = myHeap[bigChild];
		myHeap[bigChild] = temp;

		// call percolateDown with the new position (bigChild);
		percolateDown(bigChild);
	}
}

template <typename datatype>
datatype heap<datatype>::top()
{
	if (size>0)
		return myHeap[1];
	datatype junk;
	return junk;
}
#endif
