#include <bits/stdc++.h>
using namespace std;

// A generic class for Queue.
template <typename T>
class CircularQueue
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
    CircularQueue(int sizeOfQueue = 1e5 /* default size of queue*/)
    {
        this->sizeOfArray = sizeOfQueue; // setting up the size of array.
        arr = new T[sizeOfArray];        // declaring dynamic array of given size.

        // Initially, when there is no element in the queue, frontElement and rearElement will point to -1. So, when frontElement == -1, it means queue is empty.
        this->frontElement = -1;
        this->rearElement = -1;
    }

    /* Method to check if the queue is empty or not. */
    bool isEmpty()
    {
        // If frontElement == -1, it means the queue is empty.
        if (frontElement == -1)
        {
            // means queue is empty.
            return true;
        }

        // else frontElement != -1, it means the queue is not empty.
        return false;
    }

    /* Method to push element into the queue. */
    // Whenever we are pushing something into the queue it is know as enqueue.
    void enqueue(T data)
    {
        // checking for overflow condition.
        if ((frontElement == 0 && rearElement == sizeOfArray - 1) ||
            (rearElement == (frontElement - 1) % (sizeOfArray - 1)))
        {
            cerr << "Queue is full.\n";
        }
        else if (frontElement == -1)
        {
            // means we are going to push first element into queue.
            frontElement = rearElement = 0;
            arr[rearElement] = data;
        }
        else if (rearElement == sizeOfArray - 1 && frontElement != 0)
        {
            // circular insertion.
            rearElement = 0;
            arr[rearElement] = data;
        }
        else
        {
            // for normal case, simply insert element.
            rearElement++;
            arr[rearElement] = data;
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

        // if the queue has only one element.
        else if(frontElement == rearElement)
        {
            frontElement = rearElement = -1;
        }

        // if frontElement reaches the end of array, then initialize frontElement with 0.
        else if(frontElement == sizeOfArray - 1)
        {
            // maintaining circular order.
            frontElement = 0;
        }
        else{
            // for normal cases, simply increment the frontElement.
            frontElement++;
        }
    }

    /* Method to get the front element of the queue. */
    T front()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the front element.\n";
            return -1;
        }
        else
        {
            return arr[frontElement];
        }
    }

    /* Method to get the rear element of the queue. */
    T rear()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the rear element.\n";
            return -1;
        }
        else
        {
            return arr[rearElement];
        }
    }

};
