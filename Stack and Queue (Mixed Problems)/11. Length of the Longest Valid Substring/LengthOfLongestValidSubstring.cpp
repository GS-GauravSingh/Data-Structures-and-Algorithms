/*
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring.

Examples:
Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()()

Input:  ()(()))))
Output: 6
Explanation:  ()(())
*/

#include <bits/stdc++.h>
using namespace std;

/* ----------------------------- Solution Class ------------------------------ */
class Solution
{
private:
public:
    /* Method that return the length of the longest valid substring. */
    // Time Complexity :- O(n), n is the length of the string (str).
    // Space Complexity :- O(n), stack size.
    int longestValidParentheses(string str)
    {
        stack<char> st;   // used to find valid pairs.
        stack<int> index; // used to store index  and to calculate length of valid substring.
        index.push(-1);

        int maxLen = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                st.push('(');
                index.push(i);
            }
            else
            {
                // closing bracket.
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    index.pop();
                    maxLen = max(maxLen, i - index.top());
                }
                else
                {
                    index.push(i);
                }
            }
        }
        return maxLen;
    }
};

int main(void)
{
    string expression = "))()()()((((()()"; // Output = 6.

    Solution S;
    cout << "Maximum Length of Longest Valid Substring is " << S.longestValidParentheses(expression) << ".\n";
}