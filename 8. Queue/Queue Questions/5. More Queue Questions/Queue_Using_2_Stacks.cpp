//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int B);
    int pop();
};
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

/* The structure of the class is
class StackQueue{
private:

    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

// Function to push an element in queue by using 2 stacks.
/*
Steps for push operation:-
1:- transfer all elemnts of s1 into s2.
2:- insert x in s1.
3:- transfer all elements of s2 into s1.

Note:- Dry run these steps for more understanding.

// Time complexity:- (N)
// Space Complexity:- O(2*N)

*/
void StackQueue ::push(int x)
{
    // step 1:- transfer all elemnts of s1 into s2.
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    // step 2:- insert x in s1.
    s1.push(x);

    // step 3:- transfer all elements of s2 into s1.
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    // for pop operation, just pop the top element of s1.
    if (s1.empty())
    {
        return -1;
    }
    int ans = s1.top();
    s1.pop();
    return ans;
}
