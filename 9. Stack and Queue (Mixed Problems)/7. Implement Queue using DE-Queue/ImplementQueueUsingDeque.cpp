#include <bits/stdc++.h>
using namespace std;

/* Queue implementation using DE-Queue. */
class Queue
{
private:
    /* Properties / Data Members of the Queue Class. */
    deque<int> dq;

public:
    /* Behavior / Methods of the Queue Class. */

    /* Method to push data into the queue. */
    void enqueue(int data)
    {
        dq.push_back(data);
    }

    /* Method to pop the front element of the queue. */
    void dequeue()
    {
        dq.pop_front();
    }

    /* Method to get the front element of the queue. */
    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return dq.front();
    }

    /* Method to get the size of the queue. */
    int size()
    {
        if (isEmpty())
        {
            return -1;
        }
        return dq.size();
    }

    /* Method to check if the queue is empty or not. */
    bool isEmpty()
    {
        return dq.empty();
    }

    /* Method to print hte queue. */
    void printQueue()
    {
        while (!isEmpty())
        {
            cout << front() << " ";
            dequeue();
        }
        cout << endl;
    }
};

int main(void)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.printQueue();
}