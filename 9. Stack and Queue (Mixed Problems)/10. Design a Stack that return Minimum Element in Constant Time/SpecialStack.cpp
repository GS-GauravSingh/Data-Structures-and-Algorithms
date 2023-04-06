#include <bits/stdc++.h>
using namespace std;

/* Stack Class that return Minimum Element of the Stack in Constant Time Complexity. */
// Time Complexity :- O(1), all methods is having constant time complexity.
// Space Complexity :- O(n), because we are using an additional data structure stack to store minimum elements.
class SpecialStack
{
private:
    /* Data Members or Properties of Special Stack Class. */
    stack<int> st;       // this is used to push and pop element.
    stack<int> minStack; // this is used to store minimum elements.

public:
    /* Methods or Behavior of Special Stack Class. */

    /* Method to push element into the stack. */
    void push(int data)
    {
        if (st.empty())
        {
            st.push(data);
            minStack.push(data);
        }
        else
        {

            st.push(data);
            minStack.push(min(data, minStack.top()));
        }
    }

    /* Method to pop element from the stack. */
    int pop()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            st.pop();
            minStack.pop();
        }
    }

    /* Method to get the top element of the stack. */
    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            return st.top();
        }
    }

    /* Method to check if the stack is empty or not. */
    bool isEmpty()
    {
        return st.empty();
    }

    /* Method that return the minimum element of the stack. */
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        else
        {
            return minStack.top();
        }
    }
};

int main(void)
{
    SpecialStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Minimum Element is " << st.getMin() << ".\n";
}