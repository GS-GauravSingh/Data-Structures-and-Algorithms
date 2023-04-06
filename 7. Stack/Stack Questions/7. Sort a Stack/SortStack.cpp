#include <bits/stdc++.h>
#include "../../Stack Implementation/C++ Implementation/StackImplementationUsingArray.h"
using namespace std;

/* ----------------- Solution Class --------------------------- */
class Solution
{
private:
    /* Method to insert the element at its correct position. */
    // Time Complexity :- O(n), n is the size of stack.
    // Space Complexity :- O(n), recursive stack space.
    void insertAtCorrectPosition(Stack<int> &s, int element)
    {
        // Base Case.
        if (s.isEmpty() || s.top() > element)
        {
            s.push(element);
            return;
        }

        // Recursive case.
        // storing the top element of a stack.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // recursive call, moving toward the base case.
        insertAtCorrectPosition(s, element);

        // Backtracking Step (While comming back from the base case).
        // Insert the popped element.
        s.push(poppedElement);
    }

public:
    /* Method to sort stack. */
    // Time Complexity :- O(n^2), n is the size of stack.
    // Space Complexity :- O(n), recursive stack space.
    void sortStack(Stack<int> &s)
    {
        // Base Case
        if (s.isEmpty())
        {
            // when stack is empty, simply return from there.
            return;
        }

        // Recursive Case.
        // storing the top element of a stack.
        int poppedElement = s.top();

        // popping the top element.
        s.pop();

        // recursive call, moving toward the base case.
        sortStack(s);

        // Backtracking Step (While comming back from the base case).
        // Insert each element into its correct position.
        insertAtCorrectPosition(s, poppedElement);
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
    // Note :- sort a stack in such a way that minimum is present at the top of the stack and largest element at the bottom of the stack.

    Stack<int> s;
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(3);
    s.push(6);

    // Solution.
    Solution S;
    cout << "Before Sorting,\n";
    S.printStack(s);

    cout << "After Sorting,\n";
    S.sortStack(s);
    S.printStack(s);
}