#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the minimum number of operations required to convert S1 to S2 as our answer. */
    // Time Complexity: O(3^n * 3^m), where n and m are the length of both the strings.
    // Space Complexity: O(n+m), recursive stack space.
    int solveRecursive(int idx1, int idx2, string &s1, string &s2)
    {
        // Base Case
        if (idx1 < 0)
        {
            return idx2 + 1;
        }

        if (idx2 < 0)
        {
            return idx1 + 1;
        }

        // Recursive Case.

        // Matching Characters.
        if (s1[idx1] == s2[idx2])
        {
            // When the character matches, in this we have only only one choice and that choice is, move to next character.
            // When character matches, in this casem we don't have to perform any operation, that's why the number of operation is 0.
            return 0 + solveRecursive(idx1 - 1, idx2 - 1, s1, s2);
        }

        // Not Matching Characters.
        else
        {
            // When the character does not match, in this case, we have 3 choice,
            // 1. Deletion.
            // 2. Replacement.
            // 3. Insertion.

            // When deletion is performed on string s1, character at idx1 gets deleted, so idx1 will shrink by 1 index.
            // idx2 will stays on its position, because you have to find the s2[idx2].
            int deletion = solveRecursive(idx1 - 1, idx2, s1, s2);

            // When replacement is done, you replace s1[idx1] with s2[idx2], after the replacement both the character matches, so in this case both the pointer will shirnk by 1.
            int replacement = solveRecursive(idx1 - 1, idx2 - 1, s1, s2);

            // Insertion is done at index idx1+1 and this s1[idx1+1] = s2[idx2], because this is obvious that we insert that element that matches with s2[idx2].
            // So, in this case, idx1 will stay where it was before and idx2 will shrink with 1 index becuase we have to search for next element.
            int insertion = solveRecursive(idx1, idx2 - 1, s1, s2);

            // return the minimum number of operations.
            // One of the above operation will give you the minimum answer, that's why the nuber of operation performed is 1, thats why we have to add 1.
            return 1 + min(deletion, min(replacement, insertion));
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
    int solveMemoized(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base Case
        if (idx1 < 0)
        {
            return idx2 + 1;
        }

        if (idx2 < 0)
        {
            return idx1 + 1;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }

        // Matching Characters.
        if (s1[idx1] == s2[idx2])
        {
            // When the character matches, in this we have only only one choice and that choice is, move to next character.
            // When character matches, in this casem we don't have to perform any operation, that's why the number of operation is 0.
            return dp[idx1][idx2] = 0 + solveMemoized(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        // Not Matching Characters.
        else
        {
            // When the character does not match, in this case, we have 3 choice,
            // 1. Deletion.
            // 2. Replacement.
            // 3. Insertion.

            // When deletion is performed on string s1, character at idx1 gets deleted, so idx1 will shrink by 1 index.
            // idx2 will stays on its position, because you have to find the s2[idx2].
            int deletion = solveMemoized(idx1 - 1, idx2, s1, s2, dp);

            // When replacement is done, you replace s1[idx1] with s2[idx2], after the replacement both the character matches, so in this case both the pointer will shirnk by 1.
            int replacement = solveMemoized(idx1 - 1, idx2 - 1, s1, s2, dp);

            // Insertion is done at index idx1+1 and this s1[idx1+1] = s2[idx2], because this is obvious that we insert that element that matches with s2[idx2].
            // So, in this case, idx1 will stay where it was before and idx2 will shrink with 1 index becuase we have to search for next element.
            int insertion = solveMemoized(idx1, idx2 - 1, s1, s2, dp);

            // return the minimum number of operations.
            // One of the above operation will give you the minimum answer, that's why the nuber of operation performed is 1, thats why we have to add 1.
            return dp[idx1][idx2] = 1 + min(deletion, min(replacement, insertion));
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
    int solveTabulized(string &s1, string &s2)
    {
        // Length of strings.
        int s1Len = s1.length();
        int s2Len = s2.length();

        // 'dp' vector to store and computer the answer of subproblems.
        vector<vector<int>> dp(s1Len + 1, vector<int>(s2Len + 1, 0));

        // Base Cases
        for (int i = 0; i <= s1Len; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 0; i <= s2Len; i++)
        {
            dp[0][i] = i;
        }

        // Outer loops is used to traverse the dp vector.
        for (int idx1 = 1; idx1 <= s1Len; idx1++)
        {
            for (int idx2 = 1; idx2 <= s2Len; idx2++)
            {
                // Matching Characters.
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    // When the character matches, in this we have only only one choice and that choice is, move to next character.
                    // When character matches, in this casem we don't have to perform any operation, that's why the number of operation is 0.
                    dp[idx1][idx2] = 0 + dp[idx1 - 1][idx2 - 1];
                }

                // Not Matching Characters.
                else
                {
                    // When the character does not match, in this case, we have 3 choice,
                    // 1. Deletion.
                    // 2. Replacement.
                    // 3. Insertion.

                    // When deletion is performed on string s1, character at idx1 gets deleted, so idx1 will shrink by 1 index.
                    // idx2 will stays on its position, because you have to find the s2[idx2].
                    int deletion = dp[idx1 - 1][idx2];

                    // When replacement is done, you replace s1[idx1] with s2[idx2], after the replacement both the character matches, so in this case both the pointer will shirnk by 1.
                    int replacement = dp[idx1 - 1][idx2 - 1];

                    // Insertion is done at index idx1+1 and this s1[idx1+1] = s2[idx2], because this is obvious that we insert that element that matches with s2[idx2].
                    // So, in this case, idx1 will stay where it was before and idx2 will shrink with 1 index becuase we have to search for next element.
                    int insertion = dp[idx1][idx2 - 1];

                    // return the minimum number of operations.
                    // One of the above operation will give you the minimum answer, that's why the nuber of operation performed is 1, thats why we have to add 1.
                    dp[idx1][idx2] = 1 + min(deletion, min(replacement, insertion));
                }
            }
        }

        return dp[s1Len][s2Len];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(m*n), where n and m are the length of both the strings.
    // Space Complexity: O(m), size of vector.
    int solveSpaceOptimized(string &s1, string &s2)
    {
        // Length of strings.
        int s1Len = s1.length();
        int s2Len = s2.length();

        // 'prevRow' and 'currRow' vector.
        vector<int> prevRow(s2Len + 1, 0);
        vector<int> currRow(s2Len + 1, 0);

        // Base Cases

        for (int i = 0; i <= s2Len; i++)
        {
            prevRow[i] = i;
        }

        // Outer loops is used to traverse the dp vector.
        for (int idx1 = 1; idx1 <= s1Len; idx1++)
        {
            currRow[0] = idx1;

            for (int idx2 = 1; idx2 <= s2Len; idx2++)
            {
                // Matching Characters.
                if (s1[idx1 - 1] == s2[idx2 - 1])
                {
                    // When the character matches, in this we have only only one choice and that choice is, move to next character.
                    // When character matches, in this casem we don't have to perform any operation, that's why the number of operation is 0.
                    currRow[idx2] = 0 + prevRow[idx2 - 1];
                }

                // Not Matching Characters.
                else
                {
                    // When the character does not match, in this case, we have 3 choice,
                    // 1. Deletion.
                    // 2. Replacement.
                    // 3. Insertion.

                    // When deletion is performed on string s1, character at idx1 gets deleted, so idx1 will shrink by 1 index.
                    // idx2 will stays on its position, because you have to find the s2[idx2].
                    int deletion = prevRow[idx2];

                    // When replacement is done, you replace s1[idx1] with s2[idx2], after the replacement both the character matches, so in this case both the pointer will shirnk by 1.
                    int replacement = prevRow[idx2 - 1];

                    // Insertion is done at index idx1+1 and this s1[idx1+1] = s2[idx2], because this is obvious that we insert that element that matches with s2[idx2].
                    // So, in this case, idx1 will stay where it was before and idx2 will shrink with 1 index becuase we have to search for next element.
                    int insertion = currRow[idx2 - 1];

                    // return the minimum number of operations.
                    // One of the above operation will give you the minimum answer, that's why the nuber of operation performed is 1, thats why we have to add 1.
                    currRow[idx2] = 1 + min(deletion, min(replacement, insertion));
                }
            }

            prevRow = currRow;
        }

        return prevRow[s2Len];
    }


public:
    /* Question: We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

    1. Deletion of a character.
    2. Replacement of a character with another one.
    3. Insertion of a character.
    We have to return the minimum number of operations required to convert S1 to S2 as our answer. */
    int editDistance(string str1, string str2)
    {
        // Length of strings.
        int s1Len = str1.length();
        int s2Len = str2.length();

        // // // Recursive Solution.
        // return solveRecursive(s1Len - 1, s2Len - 1, str1, str2);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(s1Len, vector<int>(s2Len, -1));
        // return solveMemoized(s1Len - 1, s2Len - 1, str1, str2, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(str1, str2);

        // Space Optimized Solution.
        return solveSpaceOptimized(str1, str2);
    }
};

int main(void)
{
    string s1 = "horse";
    string s2 = "ros";

    // Solution.
    Solution S;
    cout << "Minimum Operation required is " << S.editDistance(s1, s2) << ".\n";
    return 0;
}