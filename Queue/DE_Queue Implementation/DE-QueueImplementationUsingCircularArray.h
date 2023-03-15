#include <bits/stdc++.h>
using namespace std;

// A generic class for Queue.
template <typename T>
class DE_Queue
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
    DE_Queue(int sizeOfQueue = 1e5 /* default size of queue*/)
    {
        this->sizeOfArray = sizeOfQueue; // setting up the size of array.
        arr = new T[sizeOfArray];        // declaring dynamic array of given size.

        // Initially, when there is no element in the queue, frontElement and rearElement will point to -1.
        this->frontElement = -1;
        this->rearElement = -1;
    }

    /* Method to check if dequeue is empty or not. */
    bool isEmpty()
    {
        // If frontElement == -1, it means the Dequeue is empty.
        if (frontElement == -1)
        {
            // means queue is empty.
            return true;
        }
        else
        {
            // else frontElement != -1, it means the Dequeue is not empty.
            return false;
        }
    }

    /* Method to check if dequeue is full or not. */
    bool isFull()
    {
        if ((frontElement == 0 && rearElement == sizeOfArray - 1) ||
            (rearElement == (frontElement - 1) % (sizeOfArray - 1)))
        {
            // queue is full.
            return true;
        }
        else
        {
            // queue is not full.
            return false;
        }
    }

    /* Method to push element in front of deque. */
    void push_front(T data)
    {
        // checking for overflow.
        if (isFull())
        {
            cerr << "DE-Queue is full.\n";
        }
        else if (frontElement == -1)
        {
            // means, we are going to push the first element into deque.
            frontElement = rearElement = 0;
            arr[frontElement] = data;
        }

        // maintaining circular order.
        else if (frontElement == 0 && rearElement != sizeOfArray - 1)
        {
            frontElement = sizeOfArray - 1;
            arr[frontElement] = data;
        }
        else
        {
            // for normal cases, simply decrement frontElement and then insert element.
            frontElement--;
            arr[frontElement] = data;
        }
    }

    /* Method to push element at the back or rear of deque. */
    void push_back(T data)
    {
        // checking for overflow.
        if (isFull())
        {
            cerr << "DE-Queue is full.\n";
        }
        else if (frontElement == -1)
        {
            // means, we are going to push the first element into deque.
            frontElement = rearElement = 0;
            arr[rearElement] = data;
        }

        // maintaining circular order.
        else if (rearElement == sizeOfArray - 1 && frontElement != 0)
        {
            rearElement = 0;
            arr[rearElement] = data;
        }
        else
        {
            // for normal cases, simply increment rearElement and then insert element.
            rearElement++;
            arr[rearElement] = data;
        }
    }

    /* Method to pop element from the front deque. */
    void pop_front()
    {
        // checking for underflow.
        if (isEmpty())
        {
            cerr << "DE-Queue is empty.\n";
        }
        else if (frontElement == rearElement)
        {
            // means, single element is present.
            frontElement = rearElement = -1;
        }

        // maintaining circular order.
        else if (frontElement == sizeOfArray - 1)
        {
            // while popping, if front reaches the end of array.
            frontElement = 0;
        }
        else
        {
            // in normal case simply pop the element.
            frontElement++;
        }
    }

    /* Method to pop element from the back / rear of deque. */
    void pop_back()
    {
        // checking for underflow.
        if (isEmpty())
        {
            cerr << "DE-Queue is empty.\n";
        }
        else if (frontElement == rearElement)
        {
            // means, single element is present.
            frontElement = rearElement = -1;
        }

        // maintaining circular order.
        else if (rearElement == 0)
        {
            // while popping, if front reaches the start of array.
            rearElement = sizeOfArray - 1;
        }
        else
        {
            // in normal case simply pop the element.
            rearElement--;
        }
    }

    /* Method to get the front element of the Deque. */
    T getFront()
    {
        if (isEmpty())
        {
            cout << "DE-Queue is empty.\n";
            return -1;
        }
        else
        {
            return arr[frontElement];
        }
    }

    /* Method to get the rear / back element of the Deque. */
    T getRear()
    {
        if (isEmpty())
        {
            cout << "DE-Queue is empty.\n";
            return -1;
        }
        else
        {
            return arr[rearElement];
        }
    }
};
