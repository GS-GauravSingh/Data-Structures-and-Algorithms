/*
Stack implementation using array or you can use vector, it's upto you.
In vector:- you can simply insert element using push_back and pop element using pop back.

We're going to use templated class. So, that we can create stack of any data type.

Time Complexity :- All Methods having constant i.e., O(1) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

/* Stack Class. */
template <typename T>
class Stack
{
private:
    /* Data Members / Properties of Stack Class. */

    // Pointer to Dynamic array.
    // We are using a Dynamic array, so that user can create the stack of size they want.
    T *arr;

    // index to push elements in stack and to track if stack is empty or full.
    int topElementIdx;

    // to store size of stack/array.
    int sizeOfStack;

public:
    /* Methods / Behavior of Stack Class. */

    // Default Constructor.
    Stack()
    {
        // setting up the default size of array/stack.
        sizeOfStack = 1e5;

        // initializing array with default size.
        arr = new T[sizeOfStack];

        // initially there is no top element in stack.
        topElementIdx = -1;

    }

    // Paramterized Constructor.
    // If the user does not provide the size of the array/stack, in this case, the default constructor will initialize all the properties of the stack class.
    // But If the user provides the size of array/stack, in this case, the parameterized constructor will initialize all the properties of the stack class with the user-given values.
    Stack(int sizeOfStack)
    {
        // setting up the size of the array/stack with user-given value.
        this->sizeOfStack = sizeOfStack;

        // initializing array/stack with user-given size.
        arr = new T[sizeOfStack];

        // initially there is no top element in stack.
        topElementIdx = -1;

    }

    /* Method to Push element in stack. */
    void push(T data)
    {
        // Checking for overflow.
        if (topElementIdx >= sizeOfStack)
        {
            // means, stack is full.
            cerr << "Stack Overflow.\n";
        }
        else
        {

            // if stack is not full then insert the element.
            // To insert, First increment the topElementIdx, because when stack is empty topElementIdx will point to -1 and we cannot insert element at -1th index.
            topElementIdx++;

            // Now insert the element.
            arr[topElementIdx] = data;
        }
    }

    /* Method to Pop element from stack. */
    void pop()
    {
        // Checking for underflow.
        if (isEmpty())
        {
            // means, stack is already empty.
            cerr << "Stack Underflow.\n";
        }
        else
        {

            // if stack is not empty then pop the top element, because we have perform insertion and deletion in LIFO / FILO Order.
            // To pop / delete the top element, just decrement the topElementIdx.
            // It will not delete the value, but the next time if the user inserts a new value, then the new value will rewrite the value at this index.
            topElementIdx--;
        }
    }

    /* Method to check if stack is empty of not. */
    bool isEmpty()
    {
        // if topElementIdx is -1, it means stack is empty.
        if (topElementIdx == -1)
        {
            // means, stack is already empty.
            return true;
        }
        else
        {
            // if topElementIdx is not -1, it means stack is not empty.
            return false;
        }
    }

    /* Method to get the Top element of the stack. */
    T top()
    {
        // Checking for underflow.
        // if isEmpty() return true, means stack is empty.
        if (isEmpty())
        {
            // means, stack is already empty.
            cout << "Stack is empty, Please insert some elements to get the top element.\n";
            return -1;
        }
        else
        {
            // if stack is not empty, then simply return the top element using topElementIdx.
            return arr[topElementIdx];
        }
    }

    /* Method to get the total number of element in stack. */
    int size()
    {
        // Checking for underflow.
        // if isEmpty() return true, means stack is empty.
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            // means, stack is not empty.
            return (sizeOfStack + 1); // returning size in 1-based indexing.
        }
    }
};