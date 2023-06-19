#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the length of the 'Longest Common Subsequence'. */
    // Time Complexity: O(2^n * 2^m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(n+m), recursive stack space.
    int solveRecursive(int idx1, int idx2, string &s1, string &s2)
    {
        // Base Cases

        // Negative index simply means that there are no more indexes to be explored, so we simply return 0.
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }

        // Recursive Case

        // if(S1[idx1] == S2[idx2]). In this case this common element will represent a unit length common subsequence, so we can say that we have found one character which is common in both the strings and we can shrink both the strings by 1 to find the longest common subsequence in the remaining pair of strings.
        if (s1[idx1] == s2[idx2])
        {
            return 1 + solveRecursive(idx1 - 1, idx2 - 1, s1, s2);
        }

        // if(S1[idx1] != S2[idx2]). In this case we know that the current characters represented by ind1 and ind 2 will be different. So, we need to compare the ind1 character with shrunk S2 and ind2 with shrunk S1. But how do we make this comparison ?  If we make a single recursive call as we did above to f(ind1-1,ind2-1), we may lose some characters of the subsequence. Therefore we make two recursive calls: one to f(ind1,ind2-1) (shrinking only S1) and one to f(ind1-1,ind2) (shrinking only S2). Then when we return max of both the calls.
        else
        {
            return 0 + max(solveRecursive(idx1, idx2 - 1, s1, s2), solveRecursive(idx1 - 1, idx2, s1, s2));
        }
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(n+m) + O(n*m), recursive stack space and size of 'dp' vector.
    int solveMemoized(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base Cases

        // Negative index simply means that there are no more indexes to be explored, so we simply return 0.
        if (idx1 < 0 || idx2 < 0)
        {
            return 0;
        }

        // Recursive Case

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        // if(S1[idx1] == S2[idx2]). In this case this common element will represent a unit length common subsequence, so we can say that we have found one character which is common in both the strings and we can shrink both the strings by 1 to find the longest common subsequence in the remaining pair of strings.
        if (s1[idx1] == s2[idx2])
        {
            return dp[idx1][idx2] = 1 + solveMemoized(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        // if(S1[idx1] != S2[idx2]). In this case we know that the current characters represented by ind1 and ind 2 will be different. So, we need to compare the ind1 character with shrunk S2 and ind2 with shrunk S1. But how do we make this comparison ?  If we make a single recursive call as we did above to f(ind1-1,ind2-1), we may lose some characters of the subsequence. Therefore we make two recursive calls: one to f(ind1,ind2-1) (shrinking only S1) and one to f(ind1-1,ind2) (shrinking only S2). Then when we return max of both the calls.
        else
        {
            return dp[idx1][idx2] = 0 + max(solveMemoized(idx1, idx2 - 1, s1, s2, dp), solveMemoized(idx1 - 1, idx2, s1, s2, dp));
        }
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

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
                    dp[idx1][idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : dp[idx1 - 1][idx2 - 1]);
                }

                // Not Matches.
                else
                {
                    dp[idx1][idx2] = 0 + max(
                                             ((idx2 - 1 < 0) ? 0 : dp[idx1][idx2 - 1]),
                                             ((idx1 - 1 < 0) ? 0 : dp[idx1 - 1][idx2]));
                }
            }
        }

        return dp[s1.length() - 1][s2.length() - 1];
    }

    /* Space Optimizing the above DP Tabulation Code. */
    /* If we closely we are using two rows: dp[ind1-1][ ], dp[ind][ ],

    So we are not required to contain an entire array, we can simply have two rows prev and cur where prev corresponds to dp[ind-1] and cur to dp[ind]. */

    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(m) + O(m), size of 'prevRow' and 'currRow' vector.
    int solveSpaceOptimized(string &s1, string &s2)
    {
        // 'prevRow' vector.
        vector<int> prevRow(s2.length(), 0);

        // 'currRow' vector.
        vector<int> currRow(s2.length(), 0);

        // Outer loops is used to traverse the 'dp' vector.
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                // Matches.
                if (s1[idx1] == s2[idx2])
                {
                    currRow[idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : prevRow[idx2 - 1]);
                }

                // Not Matches.
                else
                {
                    currRow[idx2] = 0 + max(
                                             ((idx2 - 1 < 0) ? 0 : currRow[idx2 - 1]),
                                             ((idx1 - 1 < 0) ? 0 : prevRow[idx2]));
                }
            }

            prevRow = currRow;
        }

        return prevRow[s2.length() - 1];
    }

public:
    /* Question: Given 2 strings 's' and 't', your task is to find the length of the 'Longest Common Subsequence'. */
    int lcs(string s, string t)
    {
        // // Recursive Solution.
        // return solveRecursive(s.length() - 1, t.length() - 1, s, t);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        // return solveMemoized(s.length() - 1, t.length() - 1, s, t, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(s, t);

        // Space Optimized Solution.
        return solveSpaceOptimized(s, t);

    }
};

int main(void)
{
    string s1 = "acd";
    string s2 = "ced";

    // Solution.
    Solution S;
    cout << "The Length of Longest Common Subsequence is " << S.lcs(s1, s2) << ".\n";
    return 0;
}