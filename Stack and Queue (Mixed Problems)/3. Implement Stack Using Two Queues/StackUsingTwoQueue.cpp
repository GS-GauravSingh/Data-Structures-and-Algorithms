#include <bits/stdc++.h>
using namespace std;

/* Implementing Stack class using only 2 Queues. */
class MyStack
{
private:
    // Declaring 2 Queue's.
    queue<int> q1;
    queue<int> q2;

public:
    /* Method to push data into Stack. */
    void push(int x)
    {
        // flag to check which queue is empty.
        string whichQueueIsEmpty = "";

        // if q1 is empty push data into queue 1.
        if (q1.empty())
        {
            q1.push(x);
            whichQueueIsEmpty = "queue 1";
        }
        else
        {
            // if q2 is empty push data into queue 2.
            q2.push(x);
            whichQueueIsEmpty = "queue 2";
        }

        // Important step.
        // If data is pushed in queue 1, then push all elements of queue 2 into queue 1.
        if (whichQueueIsEmpty == "queue 1")
        {
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }

        // If data is pushed in queue 2, then push all elements of queue 1 into queue 2.
        else
        {
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop()
    {
        // if queue 1 is empty, it means all the data is present in queue 2 and queue 2 will contain all elements in LIFO order. So, pop the front element from queue 2.
        if (q1.empty())
        {
            q2.pop();
        }
        else
        {
            // if queue 1 is not empty, it means all the data is present in queue 1 and queue 1 will contain all elements in LIFO order. So, pop the front element from queue 1.
            q1.pop();
        }
    }

    int top()
    {
        // if queue 1 is empty, it means all the data is present in queue 2 and queue 2 will contain all elements in LIFO order. So, the top elements of stack is present at the front of the queue 2.
        if (q1.empty())
        {
            return q2.front();
        }
        else
        {
            // if queue 1 is not empty, it means all the data is present in queue 1 and queue 1 will contain all elements in LIFO order. So, the top elements of stack is present at the front of the queue 1.
            return q1.front();
        }
    }

    bool empty()
    {
        // Out of the 2 queues. one of the queue is always empty.
        // if there is no insertion happen, then both the queues is empty but if there is any insertion happen in this case one of the queue is empty.
        return q1.empty() && q2.empty();
    }
};

int main(void)
{
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
}