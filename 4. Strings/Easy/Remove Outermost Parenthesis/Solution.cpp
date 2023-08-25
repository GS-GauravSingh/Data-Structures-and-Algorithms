#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using Stack Data Structure. */
    // Time Complexity: O(n), where 'n' is the length of the string.
    // Space Complexity: O(n/2), because in valid parenthesis, count of opening parenthesis = count of closing parenthesis.
    string removeOuterParentheses_BruteForce(string str)
    {

        stack<char> st;
        string ans;
        for (auto currChar : str)
        {
            if (currChar == '(')
            {
                st.push(currChar);
                // When stack.size() == 1, it means the opening parenthesis present inside the stack, that opening parenthesis is a opening parenthesis of outermost parenthesis.
                if (st.size() > 1)
                {
                    ans.push_back(currChar);
                }
            }
            else
            {
                // currChar == ')'.

                // When stack.size() == 1, it means that only one opening parenthesis is present inside the stack and this closing parenthesis is a closing parenthesis of outermost parenthesis.
                if (st.size() > 1)
                {
                    ans.push_back(currChar);
                }
                st.pop();
            }
        }

        return ans;
    }

    /* Optimized Approach: See, stack is used to count the number of opening brackets, so instead of stack we can use variables. */
    // Time Complexity: O(n), where 'n' is the length of the string.
    // Space Complexity: O(1).
    string removeOuterParentheses_Optimized(string str)
    {

        int openParenthesisCount = 0;
        string ans;
        for (auto currChar : str)
        {
            if (currChar == '(')
            {
                openParenthesisCount++;
                if (openParenthesisCount > 1)
                {
                    ans.push_back(currChar);
                }
            }
            else
            {
                // currChar == ')'.
                if (openParenthesisCount > 1)
                {
                    ans.push_back(currChar);
                }
                openParenthesisCount--;
            }
        }

        return ans;
    }

public:
    string removeOuterParentheses(string str)
    {
        // // Brute Force Solution.
        // return removeOuterParentheses_BruteForce(str);

        // Optimized Solution.
        return removeOuterParentheses_Optimized(str);
    }
};

int main(void)
{
    string str = "()(((())))(()())(())";

    // Solution.
    Solution obj;
    cout << obj.removeOuterParentheses(str);

    return 0;
}