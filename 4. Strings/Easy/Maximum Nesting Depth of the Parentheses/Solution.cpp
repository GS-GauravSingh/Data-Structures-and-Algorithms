#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the length of the string "str".
    // Space Complexity: O(1).
    int maxDepth(string str)
    {
        // This variable is used to keep track of the count of open parentheses encountered while iterating through the string.
        int openParenthesisCnt = 0;

        //  This variable stores the maximum nesting depth encountered.
        int depth = 0;

        // Iterate through each character in the input string str.
        for (int i = 0; i < str.length(); i++)
        {
            // When you encounter an opening parenthesis '(', it means you're starting to go deeper inside a group of parentheses. So, you increase the count of open parentheses to keep track of this.
            if (str[i] == '(')
            {
                openParenthesisCnt++;
            }

            // When you encounter a closing parenthesis ')', it means you're coming out of a group of parentheses that you entered earlier. So, you decrease the count of open parentheses to indicate that you're moving back up a level.
            else if (str[i] == ')')
            {
                openParenthesisCnt--;
            }

            // Update the maximum depth encountered so far.
            depth = max(depth, openParenthesisCnt);
        }

        // return answer.
        return depth;
    }
};

int main(void)
{
    string str = "(1)+((2))+(((3)))";

    // Solution.
    Solution obj;
    cout << "Maximum Nesting Depth: " << obj.maxDepth(str) << ".";
    return 0;
}