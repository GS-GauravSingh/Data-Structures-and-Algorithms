#include <bits/stdc++.h>
using namespace std;

// A generic class for Queue.
template <typename T>
class Queue
{
private:
    /* Properties / Data Members. */
    T *arr;           // as we don't know the size of the queue, I'm using a dynamic array to implement  the queue.
    int sizeOfArray;  // variable to store the size of array.
    int rearElement;  // points to the last element of the queue and we perform Insertion of elements from rear becaue initially when there is no element in the queue both the pointers (rearElement and frontElement point to index 0 in array).
    int frontElement; // represents front element of the queue and we perform popping of elements from the front (First Come First Serve).

public:
    /* Behavior / Methods. */

    // Parameterized Constructor.
    // If the user does not provide the size of the queue, in this case, we set the default size of the array (The default size is of the programmer's choice).
    // I am setting the default size = 1e5 [1e5 means 10^5, e is a scientific notations to write the power of 10].
    Queue(int sizeOfQueue = 1e5 /* default size of queue*/)
    {
        this->sizeOfArray = sizeOfQueue; // setting up the size of array.
        arr = new T[sizeOfArray];        // declaring dynamic array of given size.

        // Initially, when there is no element in the queue, frontElement and rearElement will point to 0. So, when frontElement == rearElement, it means queue is empty.
        // As we are going to perform insertion form rear, when rearElement == sizeOfArray, it means Queue is full.
        this->frontElement = 0;
        this->rearElement = 0;
    }

    /* Method to check if the queue is empty or not. */
    bool isEmpty()
    {
        // If frontElement == rearElement, it means the queue is empty.
        if (frontElement == rearElement)
        {
            // means queue is empty.
            return true;
        }

        // else frontElement != rearElement, it means the queue is not empty.
        return false;
    }

    /* Method to push element into the queue. */
    // Whenever we are pushing something into the queue it is know as enqueue.
    void enqueue(T data)
    {
        // checking for overflow condition.
        // If rearElement == sizeOfArray, it means the Queue is full and you cannot insert more elements into the queue.
        if (rearElement == sizeOfArray)
        {
            cerr << "Queue is Full.\n";
        }
        else
        {

            // It means the Queue is not full.
            // Insert element into the queue.
            // Performing Insertion from rear.
            arr[rearElement] = data;
            rearElement++;
        }
    }

    /* Method to pop element form the queue. */
    // Whenever we are popping something from the queue it is know as dequeue.
    void dequeue()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means, the Queue is empty.
            cerr << "Queue is empty.\n";
        }
        else
        {
            // If the queue is not empty, simply pop the front element.
            // I am not actually deleting the value from the array, because deletion in array is a time-consuming task.
            // What i am doing is, I will simply increment the frontElement pointer.
            frontElement++;

            // CORNER CASE.
            // Suppose, the user repeatedly pops the element from the queue and because of this our pointer (frontElement) points to the pointer (rearElement), it means that the queue becomes empty and in this case, reinitialize both the pointers (rearElement and frontElement) with 0.
            if(frontElement == rearElement)
            {
                frontElement = rearElement = 0;
            }
        }
    }

    /* Method to get the front element of the queue. */
    T front()
    {
        // Checking for underflow condition.
        if(isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the front element.\n";
            return -1;
        }
        else{
            return arr[frontElement];
        }
    }
    
    /* Method to get the rear element of the queue. */
    T rear()
    {
        // Checking for underflow condition.
        if(isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the rear element.\n";
            return -1;
        }
        else{
            return arr[rearElement];
        }
    }

    /* Method to get the size of the queue. */
    int size()
    {
        return rearElement;
    }

};
