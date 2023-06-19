#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    int mod = 1e9 + 7;

    /* Recursive Method to find how many distinct subsequences of S2 are present in S1. */
    // Time Complexity: O(2^n * 2^m), where n and m are the length of both the strings.
    // Space Complexity: O(n+m), recursive stack space.
    int solveRecursive(int idx1, int idx2, string &s1, string &s2)
    {
        // Base Case

        // If idx2 < 0, it means we traversed all the character of string s2 and if we traversed all the character of string s2, it menas we have found a one occurence of s2 in string s1. So count this occurence and return 1 from here.
        if (idx2 < 0)
        {
            return 1;
        }

        // If idx1 < 0, it means we traversed all the character of string s1 and if we traversed all the character of string s1, it menas we have not found a occurence of s2 in string s1. So return 0 from here.
        if (idx1 < 0)
        {
            return 0;
        }

        // Recursive Case.

        // Matching Characterse.
        if (s1[idx1] == s2[idx2])
        {
            // Now, we have 2 choices,

            // First is to take this matched character and try searching for next character.
            int include = solveRecursive(idx1 - 1, idx2 - 1, s1, s2);

            // Second is to not take this matched character and try searching for another occurence of this matched character.
            int notInclude = solveRecursive(idx1 - 1, idx2, s1, s2);

            return (include + notInclude) % mod;
        }

        // Unmatched Characters.
        else
        {
            return solveRecursive(idx1 - 1, idx2, s1, s2);
        }
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n * m), where n and m are the length of both the strings.
    // Space Complexity: O(n+m) + O(n*m), recursive stack space and size of 'dp' vector.
    int solveMemoized(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base Case

        // If idx2 < 0, it means we traversed all the character of string s2 and if we traversed all the character of string s2, it menas we have found a one occurence of s2 in string s1. So count this occurence and return 1 from here.
        if (idx2 < 0)
        {
            return 1;
        }

        // If idx1 < 0, it means we traversed all the character of string s1 and if we traversed all the character of string s1, it menas we have not found a occurence of s2 in string s1. So return 0 from here.
        if (idx1 < 0)
        {
            return 0;
        }

        // Recursive Case.
        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        // Matching Characterse.
        if (s1[idx1] == s2[idx2])
        {
            // Now, we have 2 choices,

            // First is to take this matched character and try searching for next character.
            int include = solveMemoized(idx1 - 1, idx2 - 1, s1, s2, dp);

            // Second is to not take this matched character and try searching for another occurence of this matched character.
            int notInclude = solveMemoized(idx1 - 1, idx2, s1, s2, dp);

            return dp[idx1][idx2] = (include + notInclude) % mod;
        }

        // Unmatched Characters.
        else
        {
            return dp[idx1][idx2] = solveMemoized(idx1 - 1, idx2, s1, s2, dp);
        }
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * m), where n and m are the length of both the strings.
    // Space Complexity: O(n*m), size of 'dp' vector.
    int solveTabulized(string &s1, string &s2)
    {
        // Length of strings.
        int s1Len = s1.length();
        int s2Len = s2.length();

        // 'dp' vector to store and computer the answer of subproblems.
        vector<vector<int>> dp(s1Len + 1, vector<int>(s2Len + 1, 0));

        // Base Case

        // If idx1 < 0, it means we traversed all the character of string s1 and if we traversed all the character of string s1, it menas we have not found a occurence of s2 in string s1. So return 0 from here.
        for (int i = 0; i <= s2Len; i++)
        {
            dp[0][i] = 0;
        }

        // If idx2 < 0, it means we traversed all the character of string s2 and if we traversed all the character of string s2, it menas we have found a one occurence of s2 in string s1. So count this occurence and return 1 from here.
        for (int i = 0; i <= s1Len; i++)
        {
            dp[i][0] = 1;
        }

        // Outer loops is used to traverse the dp vector.
        for (int idx1 = 1; idx1 <= s1Len; idx1++)
        {
            for (int idx2 = 1; idx2 <= s2Len; idx2++)
            {
                // Matching Characterse.
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    // Now, we have 2 choices,

                    // First is to take this matched character and try searching for next character.
                    int include = dp[idx1 - 1][idx2 - 1];

                    // Second is to not take this matched character and try searching for another occurence of this matched character.
                    int notInclude = dp[idx1 - 1][idx2];

                    dp[idx1][idx2] = (include + notInclude) % mod;
                }

                // Unmatched Characters.
                else
                {
                    dp[idx1][idx2] = dp[idx1 - 1][idx2];
                }
            }
        }

        return dp[s1Len][s2Len];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n * m), where n and m are the length of both the strings.
    // Space Complexity: O(m), size of vector.
    int solveSpaceOptimized(string &s1, string &s2)
    {
        // Length of strings.
        int s1Len = s1.length();
        int s2Len = s2.length();

        // 'prevRow' and 'currRow' vector.
        vector<int> prevRow(s2Len + 1, 0);
        vector<int> currRow(s2Len + 1, 0);

        // Base Case

        // If idx1 < 0, it means we traversed all the character of string s1 and if we traversed all the character of string s1, it menas we have not found a occurence of s2 in string s1. So return 0 from here.
        for (int i = 0; i <= s2Len; i++)
        {
            prevRow[i] = 0;
        }
        

        // Outer loops is used to traverse the dp vector.
        for (int idx1 = 1; idx1 <= s1Len; idx1++)
        {
            prevRow[0] = 1;

            for (int idx2 = 1; idx2 <= s2Len; idx2++)
            {
                // Matching Characterse.
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    // Now, we have 2 choices,

                    // First is to take this matched character and try searching for next character.
                    int include = prevRow[idx2 - 1];

                    // Second is to not take this matched character and try searching for another occurence of this matched character.
                    int notInclude = prevRow[idx2];

                    currRow[idx2] = (include + notInclude) % mod;
                }

                // Unmatched Characters.
                else
                {
                    currRow[idx2] = prevRow[idx2];
                }
            }

            prevRow = currRow;
        }

        return prevRow[s2Len];
    }

    /* Space Optimizing the above DP Tabulation Code. */
    // Using only single array.

    // Time Complexity: O(n * m), where n and m are the length of both the strings.
    // Space Complexity: O(m), size of vector.
    int solveSpaceOptimized2(string &s1, string &s2)
    {
        // Length of strings.
        int s1Len = s1.length();
        int s2Len = s2.length();

        // 'prevRow' and 'currRow' vector.
        vector<int> prevRow(s2Len + 1, 0);

        // Base Case

        // If idx1 < 0, it means we traversed all the character of string s1 and if we traversed all the character of string s1, it menas we have not found a occurence of s2 in string s1. So return 0 from here.
        for (int i = 0; i <= s2Len; i++)
        {
            prevRow[i] = 0;
        }
        

        // Outer loops is used to traverse the dp vector.
        for (int idx1 = 1; idx1 <= s1Len; idx1++)
        {
            prevRow[0] = 1;

            for (int idx2 = s2Len; idx2 > 0; idx2--)
            {
                // Matching Characterse.
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    // Now, we have 2 choices,

                    // First is to take this matched character and try searching for next character.
                    int include = prevRow[idx2 - 1];

                    // Second is to not take this matched character and try searching for another occurence of this matched character.
                    int notInclude = prevRow[idx2];

                    prevRow[idx2] = (include + notInclude) % mod;
                }

                // Unmatched Characters.
                else
                {
                    prevRow[idx2] = prevRow[idx2];
                }
            }


        }

        return prevRow[s2Len];
    }

public:
    /* Question: We are given two strings S1 and S2, we want to know how many distinct subsequences of S2 are present in S1. */
    int subsequenceCounting(string &s1, string &s2, int s1Len, int s2Len)
    {
        // // Recursive Solution.
        // return solveRecursive(s1Len - 1, s2Len - 1, s1, s2);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(s1Len, vector<int>(s2Len, -1));
        // return solveMemoized(s1Len - 1, s2Len - 1, s1, s2, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(s1, s2);

        // Space Optimized Solution.
        // return solveSpaceOptimized(s1, s2);
        return solveSpaceOptimized2(s1, s2);
    }
};

int main(void)
{
    string s1 = "babgbag";
    string s2 = "bag";

    // Solution.
    Solution S;
    cout << "The Count of Distinct Subsequences is " << S.subsequenceCounting(s1, s2, s1.size(), s2.size()) << ".\n";
    return 0;
}