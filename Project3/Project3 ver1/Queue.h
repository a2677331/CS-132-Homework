// Jian Zhong
// Prof. Mackay
// CS132 Project 3
// 12/11/2019
// Queue.h

/* This header file defines a template for a Queue data type.
  QueueElement is a type parameter received from a client program.

   Basic operations:
     Constructor: Constructs an empty queue
     empty:       Checks if a queue is empty
     enqueue:     Modifies a queue by adding a value at the back
     front:       Accesses the front queue value; leaves queue unchanged
     dequeue:     Modifies a queue by removing the value at the front
     display:     Displays the queue elements from front to back

   Class Invariant:
      1. The queue elements (if any) are stored in consecutive positions
         in myArray, beginning at position myFront.
      2. 0 <= myFront, myBack < QUEUE_CAPACITY
      3. Queue's size < QUEUE_CAPACITY
-------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

#ifndef QUEUE
#define QUEUE

const int QUEUE_CAPACITY = 50000;
//typedef int QueueElement;

template <typename QueueElement>
class Queue
{
 public:
  /***** Function Members *****/
  /***** Constructor *****/

  Queue();
  /*-----------------------------------------------------------------------
    Construct a Queue object.

    Precondition:  None.
    Postcondition: An empty Queue object has been constructed; myFront 
        and myBack are initialized to -1 and myArray is an array with
        QUEUE_CAPACITY elements of type QueueElement.
   ----------------------------------------------------------------------*/

  bool empty() const;
  /*-----------------------------------------------------------------------
    Check if queue is empty.

    Precondition: None.
    Postcondition: True is returned if the queue is empty and false is
        returned otherwise.
   ----------------------------------------------------------------------*/

  void enqueue(const QueueElement & value);
  /*-----------------------------------------------------------------------
    Add a value to a queue.

    Precondition:  value is to be added to this queue.
    Postcondition: value is added to back of queue provided there is space;
        otherwise, a queue-full message is displayed and execution is
        terminated.
   -----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*-----------------------------------------------------------------------
    Output the values stored in the queue.

    Precondition:  ostream out is open.
    Postcondition: Queue's contents, from front to back, have been output 
        to out.
   -----------------------------------------------------------------------*/

  QueueElement front() const;
  /*-----------------------------------------------------------------------
    Retrieve value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue is returned, unless queue is
        empty; in that case, an error message is displayed and a "garbage
        value" is returned.
   ----------------------------------------------------------------------*/

  void dequeue();
  /*-----------------------------------------------------------------------
    Remove value at front of queue (if any).

    Precondition:  Queue is nonempty.
    Postcondition: Value at front of queue has been removed, unless queue
        is empty; in that case, an error message is displayed and 
        execution is terminated.
   ----------------------------------------------------------------------*/

 private:
  /***** Data Members *****/
   int myFront,
       myBack;
   QueueElement myArray[QUEUE_CAPACITY];

}; // end of class declaration


// ********* DEFINITIONS ************ //
//--- Definition of Queue constructor
template <typename QueueElement>
Queue<QueueElement>::Queue()
        : myFront(0), myBack(0)
{}



//--- Definition of empty()
template <typename QueueElement>
bool Queue<QueueElement>::empty() const
{
    return (myFront == myBack);
}

//--- Definition of enqueue()
template <typename QueueElement>
void Queue<QueueElement>::enqueue(const QueueElement & value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // queue isn't full
    {
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
                "Must increase value of QUEUE_CAPACITY in Queue.h\n";
        exit(1);
    }
}

//--- Definition of display()
template <typename QueueElement>
void Queue<QueueElement>::display(ostream & out) const
{
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY)
        out << myArray[i] << "  ";
    cout << endl;
}

//--- Definition of front()
template <typename QueueElement>
QueueElement Queue<QueueElement>::front() const
{
    if ( !empty() )
        return (myArray[myFront]);
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage = 1;
        return garbage;
    }
}

//--- Definition of dequeue()
template <typename QueueElement>
void Queue<QueueElement>::dequeue()
{
    if ( !empty() )
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    else
    {
        cerr << "*** Queue is empty -- "
                "can't remove a value ***\n";
        exit(1);
    }
}

#endif
