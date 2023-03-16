#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 : Using Stack data structure. */
    // Time Complexity :- O(n), n is the number of elements in the queue.
    // Space Complexity :- O(n) because we use an additional data structure (stack).
    void reverseQueue_UsingStack(queue<int> &q)
    {
        // Step 1 :- Insert all elements of the queue into the stack.
        stack<int> st;
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }

        // As we know that whatever we push into the stack, it came out in the reverse order because the stack is a LIFO (Last In First Out) or FILO (First In Last Out) data structure.

        // Step 2 :- Extract all elements from stack and push it into the queue.
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
    }

    /* Recursive Method to reverse the queue. */
    // Time Complexity :- O(n), n is the number of elements in the queue.
    // Space Complexity :- O(n), recursive stack space.
    void reverseQueue(queue<int> &q)
    {
        // Base Case
        if (q.empty())
        {
            // When the queue becomes empty simply return from there.
            return;
        }

        // Recurive Case.
        // First we go to the base case and while returning back from the base case we start pushing the elements into the queue.
        int poppedElement = q.front(); // storing the front element.
        q.pop();                       // popping the front element.

        // Recursive Call, moving towards the base case.
        reverseQueue(q);

        // Backtracking step (while comming back from the base case).
        // Push the popped element into the queue.
        q.push(poppedElement);
    }

    /* Method to print the queue. */
    void printQueue(queue<int> q)
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
};

int main(void)
{
    // STL Queue.
    queue<int> q;

    // pushing elements into the queue.
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // Solution.
    Solution S;
    S.printQueue(q);
    S.reverseQueue(q);
    S.printQueue(q);
    S.reverseQueue_UsingStack(q);
    S.printQueue(q);
}