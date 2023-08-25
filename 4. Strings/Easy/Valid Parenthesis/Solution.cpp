#include <bits/stdc++.h>
using namespace std;

/* --------------- Solution class ---------------------- */
class Solution
{
private:
    /* Method to check whether a string is a valid parenthesis or not. */
    // Time Complexity :- O(n), where 'n' is the length of the string.
    // Space Complexity :- O(n), space used by stack data structure.
    bool checkForValidParanthesis(string &str)
    {
        // Stack.
        stack<char> st;

        // Iterate through the string.
        for (int i = 0; i < str.length(); i++)
        {
            // Current character.
            char currChar = str[i];

            // If currChar (currChar = str[i]) is opening bracket, then push "currChar" into the stack.
            if (currChar == '(' || currChar == '[' || currChar == '{')
            {
                st.push(currChar);
            }

            // If "currChar" is not an opening bracket, it means it's a closing bracket.
            // Now, check for correspond opening bracket on the top of the stack,
            //  If opening bracket is present, it means this pair of bracket is valid. So, pop the top element and continue the process.
            //  else if opening bracket is not present, then return false, expression Not Balanced.
            else
            {
                // But before checking the top element of the stack, first check, if the stack is empty or not.
                // Suppose if an expression contains only closing brackets (ex: str = "{{{{"), then in this case your stack is empty and when you try to check the top element it will give segmentation fault error.
                if (!st.empty())
                {
                    if ((currChar == ')' && st.top() == '(') || (currChar == ']' && st.top() == '[') || (currChar == '}' && st.top() == '{'))
                    {
                        // If opening brack is present, then pop the top element.
                        st.pop();
                    }
                    else
                    {
                        // If there is no opening bracked present at top of the stack,
                        // then it is not a balanced expression, return false.
                        return false;
                    }
                }
                else
                {
                    // If expression contains all closing brackets,
                    // then it's not a balanced expression, return false.
                    return false;
                }
            }
        }

        // At the end, if the stack is empty means expression is balanced, return true otherwise return false.
        if (st.empty())
        {
            return true;
        }
        return false;
    }

public:
    /* Main Method to check is a string is a valid parenthesis or not. */
    bool isValid(string str)
    {
        return checkForValidParanthesis(str);
    }
};

int main(void)
{
    string str = "(((({{{{[[[[]]]]}}}}))))";

    // Solution.
    Solution obj;
    if (obj.isValid(str))
    {
        cout << "Expression is Valid.";
    }
    else
    {
        cout << "Expression is not Valid.";
    }

    return 0;
}