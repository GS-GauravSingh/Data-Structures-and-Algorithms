#include <bits/stdc++.h>
#include "../../Stack Implementation/StackImplementationUsingArray.h"
using namespace std;

/* Solution Class. */
class Solution
{
private:
    /* Recursive Method to Insert Element at bottom of the stack. */
    // Time Complexity :- O(n), n is the number of elements in stack.
    // Space Complexity :- O(n), recursive stack space.
    void insertAtBottom(Stack<int> &s, int data)
    {
        // Base Case.
        if (s.isEmpty())
        {
            // When stack is empty, simply push data into stack and return from here.
            s.push(data);
            return;
        }

        /* Recursive Case:

        To Insert element at bottom, first we go to the base case and when the base case encounters the stack becomes empty. Now simply phus the elements into stack and reutrn from the base case.

        And to go toward the base case, you need to pop the top element and store it somewhere. SO, the while comming back from the base case, we can insert that popped element again into stack.

        */
        // storing the top element of the stack.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // Recursive call, moving towards the base case.
        insertAtBottom(s, data);

        // Backtracking Step (While comming back from the base case).
        // Insert the Popped Element.
        s.push(poppedElement);
    }

public:
    /* Recursive Method to reverse a stack. */
    // To reverse a stack, you must know how to insert element at the bottom of the stack.

    // Time Complexity :- O(n^2), n is the number of elements in stack.
    // Space Complexity :- O(n), recursive stack space.
    void reverse(Stack<int> &s)
    {
        // Base Case.
        if (s.isEmpty())
        {
            // when stack is empty, simple return from there.
            return;
        }

        // Recursive case.
        // First we go to the base case and while comming back from the base case, we insert each element at the bottom of the stack.

        // storing the top element.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // Recursive Call, moning towards the base case.
        reverse(s);

        // Backtracking Step (While comming back from the base case).
        // Insert popped element at bottom of the stack.
        insertAtBottom(s, poppedElement);
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
    Stack<int> s(10);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    // Solution.
    Solution S;
    cout << "Before Reverse,\n";
    S.printStack(s);

    cout << "After Reverse,\n";
    S.reverse(s);
    S.printStack(s);
}