#include <bits/stdc++.h>
using namespace std;

/* Stack Implementation using DE-Queue. */
class Stack
{
private:
    /* Properties / Data Members of the Stack Class. */
    deque<int> dq;

public:
    /* Behavior / Methods of the Stack Class. */

    /* Method to push data into the stack. */
    void push(int data)
    {
        /*
        Example :-  dq = {}. Initially deque is empty.

        // Pushing data into stack,
        Note :- push element at the front of the deque. So, that dq.front() will conatin the top element of the stack.

        ==> Operation (by User),   Operation Implementation (by programmer),   Result
                push(1),                     dq.push_front(1),                 dq = {1}.
                push(2),                     dq.push_front(2),                 dq = {2, 1}.
                push(3),                     dq.push_front(3),                 dq = {3, 2, 1}.
                push(4),                     dq.push_front(4),                 dq = {4, 3, 2, 1}.
        */

        dq.push_front(data); // pushing element into the stack.
    }

    /* Method to pop the top element of the stack. */
    void pop()
    {
        /*
        Example :-  dq = {}. Initially deque is empty.

        // Pushing data into stack,
        Note :- push element at the front of the deque. So, that dq.front() will conatin the top element of the stack.

        ==> Operation (by User),   Operation Implementation (by programmer),   Result
                push(1),                     dq.push_front(1),                 dq = {1}.
                push(2),                     dq.push_front(2),                 dq = {2, 1}.
                push(3),                     dq.push_front(3),                 dq = {3, 2, 1}.
                push(4),                     dq.push_front(4),                 dq = {4, 3, 2, 1}.


        // Popping data from the stack,
        Note :- our dq.front() will contain the top element of the stack. S, perform popping from the front of the deque.

        ==> Operation (by User),   Operation Implementation (by programmer),   Result
                pop(),                         dq.pop_front(),                 dq = {3, 2, 1}
                pop(),                         dq.pop_front(),                 dq = {2, 1}
                pop(),                         dq.pop_front(),                 dq = {1}
                pop(),                         dq.pop_front(),                 dq = {}
        */

        dq.pop_front(); // popping element from the stack.
    }

    /* Method get the top element of the stack. */
    int top()
    {
        if (dq.empty())
        {
            return -1;
        }
        return dq.front();
    }

    /* Method get the size of the stack. */
    int size()
    {
        return dq.size();
    }

    /* Method to check if the stack is empty or not. */
    bool isEmpty()
    {
        return dq.empty();
    }

    /* Method to print the stack. */
    void printStack()
    {
        while (!dq.empty())
        {
            cout << dq.front() << endl;
            dq.pop_front();
        }
        cout << endl;
    }
};

int main(void)
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
}