#include <bits/stdc++.h>
#include "../../Stack Implementation/StackImplementationUsingArray.h"
using namespace std;

/* -------------------------- Solution Class ------------------------------ */
class Solution
{
private:
public:
    /* Method to reverse a string.

    Note:-
    1. Whatever you push into the stack, it came out in a reverse order.
    2. This is not a best/optimal way to reverse a string.
    */

    // Time Complexity :- O(n), n is the number of elements in stack.
    // Space Complexity :- O(n), recursive stack space.
    void reverseString(string &str)
    {
        // Step 1 :- insert all characters of a string into stack.
        Stack<char> s;
        int i;
        for (i = 0; i < str.length(); i++)
        {
            s.push(str[i]);
        }

        // Step 2 :- from index 0 to n, copy back all elements from stack into string.
        i = 0;
        while (!s.isEmpty())
        {
            str[i++] = s.top();
            s.pop();
        }
    }

    /* Method to print String. */
    // Time Complexity :- O(n), n is the number of character in string.
    // Space Complexity :- O(1)
    void printString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            cout << str[i] << " ";
        }

        cout << endl;
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
    string str = "abcd";

    Solution S;
    cout << "Before Reverse : ";
    S.printString(str);

    cout << "After Reverse : ";
    S.reverseString(str);
    S.printString(str);
}