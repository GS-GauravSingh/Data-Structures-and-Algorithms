#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    bool isAllStars(string &S1, int i)
    {

        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++)
        {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    /* Recursive Method to find whether string s1 and s2 matches or not. */
    // Time Complexity: O(2^n * 2^m), where n and m are the length of both the strings.
    // Space Complexity: O(n+m), recursive stack space.
    bool solveRecursive(int idx1, int idx2, string &s1, string &s2)
    {
        // Base Case
        if (idx1 < 0 && idx2 < 0)
        {
            return true;
        }

        if (idx1 < 0 && idx2 >= 0)
        {
            return false;
        }

        if (idx2 < 0 && idx1 >= 0)
        {
            for (int i = 0; i <= idx1; i++)
            {
                if (s1[i] != '*')
                {
                    return false;
                }
            }

            return true;
        }

        // Recursive Case.

        // Matching Characters.
        if (s1[idx1] == s2[idx2] || s1[idx1] == '?')
        {
            return solveRecursive(idx1 - 1, idx2 - 1, s1, s2);
        }

        // Not Matching Characters.
        else
        {
            if (s1[idx1] == '*')
            {
                return solveRecursive(idx1 - 1, idx2, s1, s2) || solveRecursive(idx1, idx2 - 1, s1, s2);
            }
            else
            {
                return false;
            }
        }
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n * m), where n and m are the length of both the strings.
    // Space Complexity: O(n+m) + O(n*m), recursive stack space and size of dp vector.
    bool solveMemoized(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base Case
        if (idx1 < 0 && idx2 < 0)
        {
            return true;
        }

        if (idx1 < 0 && idx2 >= 0)
        {
            return false;
        }

        if (idx2 < 0 && idx1 >= 0)
        {
            for (int i = 0; i <= idx1; i++)
            {
                if (s1[i] != '*')
                {
                    return false;
                }
            }

            return true;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        // Matching Characters.
        if (s1[idx1] == s2[idx2] || s1[idx1] == '?')
        {
            return dp[idx1][idx2] = solveMemoized(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        // Not Matching Characters.
        else
        {
            if (s1[idx1] == '*')
            {
                return dp[idx1][idx2] = (solveMemoized(idx1 - 1, idx2, s1, s2, dp) || solveMemoized(idx1, idx2 - 1, s1, s2, dp));
            }
            else
            {
                return false;
            }
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
    // Space Complexity: O(n*m), size of dp vector.
    bool solveTabulized(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = isAllStars(s1, i);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else
                {
                    if (s1[i - 1] == '*')
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                    else
                        dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(m*n), where n and m are the length of both the strings.
    // Space Complexity: O(m), size of vector.
    int solveSpaceOptimized(string &S1, string &S2)
    {
        int n = S1.size();
        int m = S2.size();

        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        prev[0] = true;

        for (int i = 1; i <= n; i++)
        {
            cur[0] = isAllStars(S1, i);
            for (int j = 1; j <= m; j++)
            {

                if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                    cur[j] = prev[j - 1];

                else
                {
                    if (S1[i - 1] == '*')
                        cur[j] = prev[j] || cur[j - 1];

                    else
                        cur[j] = false;
                }
            }
            prev = cur;
        }

        return prev[m];
    }

public:
    /* Question: We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters:

    1. ‘?’ can be matched to a single character of S2.
    2. ‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
    We need to check whether strings S1 and S2 match or not. */
    bool wildcardMatching(string s1, string s2)
    {
        // // Recursive Solution.
        // return solveRecursive(s1.length() - 1, s2.length() - 1, s1, s2);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        // return solveMemoized(s1.length() - 1, s2.length() - 1, s1, s2, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(s1, s2);

        // Space Optimized Solution.
        return solveSpaceOptimized(s1, s2);
    }
};

int main(void)
{
    string s1 = "**abcd";
    string s2 = "abcd";

    // Solution.
    Solution S;
    cout << "Both strings matches or not : " << ((S.wildcardMatching(s1, s2)) ? "Matches." : "Not Matches.") << "\n";
    return 0;
}