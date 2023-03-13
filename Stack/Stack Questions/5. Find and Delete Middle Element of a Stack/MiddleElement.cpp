#include <bits/stdc++.h>
#include "../../Stack Implementation/C++ Implementation/StackImplementationUsingArray.h"
using namespace std;

/* ----------------- Solution Class -------------------------- */
class Solution
{
private:
    /* method to find the size of stack. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int size(Stack<int> s)
    {
        int sz = 0;
        while (!s.isEmpty())
        {
            s.pop();
            sz++;
        }
        return sz;
    }

    /* (Helper) Recursive method to find the middle element. */
    // Time Complexity :- O(n/2) => O(n), n is the number of elements in stack.
    // Space Complexity :- O(n/2) => O(n), recursive stack space.
    int getMid(Stack<int> &s, int &midIdx)
    {
        // Base Case
        if (midIdx == 0)
        {
            // we got the middle element.
            return s.top();
        }

        // Recursive Case.
        // storing the top element of a stack.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // recursive call, moving towards the base case and stroing the middle element.
        midIdx--;
        int middleElement = getMid(s, midIdx);

        // Backtracking Step (While Comming back from the base case).
        // Insert the popped element.
        s.push(poppedElement);

        // return the middle element.
        return middleElement;
    }

    /* (Helper) Recursive method to delete the middle element. */
    // Time Complexity :- O(n/2) => O(n), n is the number of elements in stack.
    // Space Complexity :- O(n/2) => O(n), recursive stack space.
    void deleteMiddleElement(Stack<int> &s, int &midIdx)
    {
        // Base Case
        if (midIdx == 0)
        {
            // we got the middle element.
            // pop the middle element and return.
            s.pop();
            return;
        }

        // Recursive Case.
        // storing the top element of a stack.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // recursive call, moving towards the base case.
        midIdx--;
        deleteMiddleElement(s, midIdx);

        // Backtracking Step (While Comming back from the base case).
        // Insert the popped element.
        s.push(poppedElement);

    }

public:
    /* Main Method to find middle element of a Stack. */
    int findMid(Stack<int> &s)
    {
        // getting the size of stack.
        int sizeOfStack = size(s);

        // middle element index.
        int midIdx = sizeOfStack / 2;

        // just iterate through the midIdx and find the middle element.
        int middleElement = getMid(s, midIdx);

        // return middle element.
        return middleElement;
    }

    /* Main Method to delete middle element of a Stack. */
    void deleteMid(Stack<int> &s)
    {
        // getting the size of stack.
        int sizeOfStack = size(s);

        // middle element index.
        int midIdx = sizeOfStack / 2;

        // just iterate through the midIdx and delete the middle element.
        // deleting middle element.
        deleteMiddleElement(s, midIdx);
    }

    /* Method to print Stack. */
    // Time Complexity :- O(n), n is the number of elements in stack.
    // Space Complexity :- O(1)
    void printStack(Stack<int> s)
    {
        while (!s.isEmpty())
        {
            cout << s.top() << endl;
            s.pop();
        }
        cout << endl;
    }
};

int main(void)
{
    Stack<int> s;
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    // Solution.
    Solution S;
    S.printStack(s);
    cout << "Middle Element is " << S.findMid(s) << ".\n";
    S.deleteMid(s);
    S.printStack(s);
    cout << "Middle Element is " << S.findMid(s) << ".\n";
}