#include <bits/stdc++.h>
#include "../../Stack Implementation/C++ Implementation/StackImplementationUsingArray.h"
using namespace std;

/* Solution Class. */
class Solution
{
private:
public:
    /* Recursive Method to Insert Element at bottom of the stack. */
    // Time Complexity :- O(n), n is the number of elements in stack.
    // Space Complexity :- O(n), recursive stack space.
    template <typename T>
    void insertAtBottom(Stack<T> &s, T data)
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
        T poppedElement = s.top();

        // popping the top element.
        s.pop();

        // Recursive call, moving towards the base case.
        insertAtBottom(s, data);

        // Backtracking Step (While comming back from the base case).
        // Insert the Popped Element.
        s.push(poppedElement);
    }

    /* Method to print Stack. */
    // Time Complexity :- O(n), n is the number of elements in stack.
    // Space Complexity :- O(1)
    template <typename T>
    void printStack(Stack<T> s)
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
    cout << "Before Insertion,\n";
    S.printStack(s);

    cout << "After Insertion,\n";
    S.insertAtBottom(s, 10);
    S.printStack(s);
}