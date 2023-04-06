#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach: The approach is quite simple: we start by iterating through the characters of the first string, and compare them with the characters at the same position in the other strings. If they match, we append the character to our prefix string, otherwise we return the prefix we have found so far. */

    // Time Complexity: O(n*m), n is the size of strs and m is the length of the first string.
    // Space Complexity: O(1), if we exclude the space used is storing the answer.
    string longestCommonPrefix(vector<string> &strs)
    {

        // Base Case
        if (strs.empty())
        {
            return "";
        }

        // string to store answer.
        string prefix = "";

        // Iterate through characters of first string.
        for (int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];

            // Iterate through other strings.
            for (int j = 1; j < strs.size(); j++)
            {
                // check if character at position i is the same for all strings.
                if (i >= strs[j].size() || strs[j][i] != ch)
                {
                    return prefix;
                }
            }

            // append character to prefix
            prefix += ch;
        }

        return prefix;
    }
};

int main(void)
{
}