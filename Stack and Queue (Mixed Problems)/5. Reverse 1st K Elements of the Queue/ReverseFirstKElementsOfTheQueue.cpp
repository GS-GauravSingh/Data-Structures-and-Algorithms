#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach : Using Stack data structure. */
    // Time Complexity :- O(n), n is the number of elements in the queue.
    // Space Complexity :- O(k), because we use an additional data structure (stack).
    void reverseFirstKElements(queue<int> &q, int K)
    {
        /*
        Let's dry run winth one example,
        Exmaple :- queue = {1,2,3,4,5,6}, K = 3.

        ## Step 1: Insert first K elements of the queue into the stack.

        Stack
          3
          2
          1

        After inserting first K elements into the stack our queue would look like this,
        Queue : 4,5,6

        ## Step 2:- Extract all elements from stack and push it into the queue.
        As we know that whatever we push into the stack, it came out in the reverse order because the stack is a LIFO (Last In First Out) or FILO (First In Last Out) data structure.

        After inserting all elements of the stack into the queue, our queue would look like this,
        queue : 4,5,6,3,2,1

        ## Step 3 :- In Step 3, simply move the rest (N-K, N is the size of the queue) elements to the back of the queue.

        After moving the rest (N-K, N is the size of the queue) elements to the back of the queue, our queue would look like this,
        queue : 3,2,1,4,5,6
        */

        // Step 1 :- Insert first K elements of the queue into the stack.
        stack<int> st;
        for (int i = 0; i < K; i++)
        {
            st.push(q.front());
            q.pop();
        }

        // Step 2 :- Extract all elements from stack and push it into the queue.
        // As we know that whatever we push into the stack, it came out in the reverse order because the stack is a LIFO (Last In First Out) or FILO (First In Last Out) data structure.
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        // Step 3 :- In Step 3, simply move the rest (N-K, N is the size of the queue) elements to the back of the queue.
        for (int i = 0; i < q.size() - K; i++)
        {
            int poppedElement = q.front(); // storing the front element.
            q.pop();                       // popping the front element.
            q.push(poppedElement);         // pushing the poppedElement into the queue, as we know that in the queue, insertion of the elements takes place at the rear side. So, rest N-K element are appended at the end of the queue.
        }
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
    int K = 3;

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
    S.reverseFirstKElements(q, K);
    S.printQueue(q);
}