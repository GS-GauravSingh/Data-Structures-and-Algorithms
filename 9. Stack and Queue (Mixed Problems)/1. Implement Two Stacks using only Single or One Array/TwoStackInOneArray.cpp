#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Two Stack Class ----------------------------- */
// Time Complexity :- O(1), All methods having constant time complexity.
// Space Complexity :- O(sizeOfArray).
class TwoStack
{
private:
    /* Properties / Data Members of Two Stack Class. */
    int *arr;        // pointer to dynamic array.
    int sizeOfArray; // to store the size of array.
    int stackOneTop; // top element for stack one.
    int stackTwoTop; // top element for stack two.

public:
    /* Behavior / Methods of Two Stack Class. */

    // Parameterized Constructor.
    // I'm setting the default size of the stack/array as 1e5 (1e5 means 10^5, e is the scientific notation for writing the power of 10).
    // If the user does not provide the size of stack/array, then constructor will initialize the size with the default size, but If the user provides the size of stack/array, then constructor will initialize the size with the user given size.
    TwoStack(int sizeOfStack = 1e5)
    {
        this->sizeOfArray = sizeOfStack; // setting up the size of stack/array.
        arr = new int[sizeOfArray];      // allocating dynamic memory for array.

        // For stack one we perform insertion and deletion of elements from index 0 to sizeOfArray - 1.
        // and For stack two we perform insertion and deletion of elements from index sizeOfArray - 1 to 0.

        this->stackOneTop = -1;          // Initially, when there is not element in the stack, the stackOneTop will point to -1.
        this->stackTwoTop = sizeOfArray; // Initially, when there is not element in the stack, the stackTwoTop will point to sizeOfArray.
    }

    /* Method to push an integer into the stack 1. */
    void push1(int data)
    {
        // Checking for the Stack Overflow.
        // if the difference between both the pointers is less than or equal to 1,
        // it means there is no space left for insertion.
        if (stackTwoTop - stackOneTop <= 1)
        {
            cout << "Stack Overflow.\n";
        }
        else
        {
            // Insert element in the stack 1.

            // first Increment stackOneTop and then push element.
            stackOneTop++;

            // storing element in array/stack.
            arr[stackOneTop] = data;
        }
    }

    /* Method to push an integer into the stack 2. */
    void push2(int data)
    {
        // Checking for the Stack Overflow.
        // if the difference between both the pointers is less than or equal to 1,
        // it means there is no space left for insertion.
        if (stackTwoTop - stackOneTop <= 1)
        {
            cout << "Stack Overflow.\n";
        }
        else
        {
            // Insert element in the stack 2.

            // first decrement stackTwoTop and then push element.
            stackTwoTop--;

            // storing element in array/stack.
            arr[stackTwoTop] = data;
        }
    }

    /* Method to remove an element from the top of the stack 1. */
    int pop1()
    {
        // Checking for the Stack Underflow.
        if (stackOneTop == -1)
        {
            cout << "Stack One is already empty.\n";
            return -1;
        }
        else
        {

            int poppedElement = arr[stackOneTop]; // storing the element which we are going to pop from stack one.
            stackOneTop--;                        // pop it.
            return poppedElement;                 // return popped element.
        }
    }

    /* Method to remove an element from the top of the stack 2. */
    int pop2()
    {
        // Checking for the Stack Underflow.
        if (stackTwoTop == sizeOfArray)
        {
            cout << "Stack Two is already empty.\n";
            return -1;
        }
        else
        {

            int poppedElement = arr[stackTwoTop]; // storing the element which we are going to pop from stack one.
            stackTwoTop++;                        // pop it.
            return poppedElement;                 // return popped element.
        }
    }

    /* Method to print array. */
    void printArray()
    {
        for (int i = 0; i < sizeOfArray; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    TwoStack ts(10);

    ts.push1(2);
    ts.push1(3);
    ts.push2(4);
    ts.push2(5);

    ts.printArray();
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
}