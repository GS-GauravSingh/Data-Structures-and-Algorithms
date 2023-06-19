#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(n*m), size of 'dp' vector.
    int solveTabulized(string &s1, string &s2)
    {
        // 'dp' vector to store and computer the answer of subproblems.
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));

        // Outer loops is used to traverse the 'dp' vector.
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                // Matches.
                if (s1[idx1] == s2[idx2])
                {
                    // if(S1[i-1] == S2[j-1]), then the characters match and we simply set its value to 1+dp[i-1][j-1]. We have done so because dp[i-1][j-1] gives us the longest common substring till the last cell character. As the current cell’s character is matching we are adding 1 to the consecutive chain.
                    dp[idx1][idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : dp[idx1 - 1][idx2 - 1]);
                }

                // Not Matches.
                else
                {
                    // If the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value (dp[i][j]) as 0.
                    dp[idx1][idx2] = 0;
                }
            }
        }

        // Note: dp[n][m] will not give us the answer; rather the maximum value in the entire dp array will give us the length of the longest common substring.

        int maxLen = 0;
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                maxLen = max(maxLen, dp[idx1][idx2]);
            }
        }

        return maxLen;
    }

    /* Space Optimizing Above Code. */

    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(m), size of vector.
    int solveSpaceOptimized(string &s1, string &s2)
    {
        // 'prevRow' vector.
        vector<int> prevRow(s2.length(), 0);

        // 'currRow' vector.
        vector<int> currRow(s2.length(), 0);

        // variable to store the length of longest common substring.
        int maxLen = 0;

        // Outer loops is used to traverse the 'dp' vector.
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                // Matches.
                if (s1[idx1] == s2[idx2])
                {
                    // if(S1[i-1] == S2[j-1]), then the characters match and we simply set its value to 1+dp[i-1][j-1]. We have done so because dp[i-1][j-1] gives us the longest common substring till the last cell character. As the current cell’s character is matching we are adding 1 to the consecutive chain.
                    currRow[idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : prevRow[idx2 - 1]);

                    maxLen = max(maxLen, currRow[idx2]);
                }

                // Not Matches.
                else
                {
                    // If the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value (dp[i][j]) as 0.
                    currRow[idx2] = 0;
                }
            }
            
            prevRow = currRow;
        }

        return maxLen;
    }

public:
    /* Question: Given 2 strings 's' and 't', your task is to find the length of the 'Longest Common Substring'. */
    int lcs(string s, string t)
    {
        // // DP Tabulation Solution.
        // return solveTabulized(s, t);

        // Space Optimization.
        return solveSpaceOptimized(s, t);
    }
};

int main(void)
{
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Solution.
    Solution S;
    cout << "The length of the Longest Common Substring is " << S.lcs(s1, s2) << ".\n";
    return 0;
}