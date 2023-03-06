#include <bits/stdc++.h>
using namespace std;

/* Two Stack Class. */
class TwoStack
{
private:
public:
    /* Data Members */
    int *arr;            // pointer to dynamic array.
    int sizeOfStack;     // size of dynamic array.
    int topElementIdx_1; // index for stack 1.
    int topElementIdx_2; // index for stack 2.

    // All methods have constant time complexity.
    // Parameterized Constructor.
    TwoStack(int sizeOfStack)
    {
        this->sizeOfStack = sizeOfStack; // setting up the size of array/stack.
        arr = new int[sizeOfStack];      // declaring array of given size.
        topElementIdx_1 = -1;            // for stack 1, topElementIdx_1 point to -1.
        topElementIdx_2 = sizeOfStack;   // for stack 2, topElementIdx_2 point to sizeOfStack.
    }

    /* Method to Push element in stack 1. */
    void push1(int num)
    {
        // check for overflow condition.
        // if the difference between both the pointer is less that or equal to 1,
        // it means there is no space left for insertion.
        if (topElementIdx_2 - topElementIdx_1 <= 1)
        {
            cerr << "Stack Overflow.\n";
        }
        else
        {
            topElementIdx_1++;
            arr[topElementIdx_1] = num;
        }
    }

    /* Method to Push element in stack 2. */
    void push2(int num)
    {
        // check for overflow condition.
        // if the difference between both the pointer is less that or equal to 1,
        // it means there is no space left for insertion.
        if (topElementIdx_2 - topElementIdx_1 <= 1)
        {
            cerr << "Stack Overflow.\n";
        }
        else
        {
            topElementIdx_2--;
            arr[topElementIdx_2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Checking for Underflow.
        if (topElementIdx_1 == -1)
        {
            cout << "Stack Unerflow.\n";
            return -1;
        }
        else
        {
            int poppedElement = arr[topElementIdx_1];
            topElementIdx_1--;
            return poppedElement;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Checking for Underflow.
        if (topElementIdx_2 == sizeOfStack)
        {
            cout << "Stack Unerflow.\n";
            return -1;
        }
        else
        {
            int poppedElement = arr[topElementIdx_2];
            topElementIdx_2++;
            return poppedElement;
        }
    }
};

int main(void)
{
    TwoStack ts(10);
    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push1(4);
    ts.push2(5);
    ts.push2(6);
    ts.push2(7);
    ts.push2(8);


    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
}