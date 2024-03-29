#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Solution to to find the maximum revenue that can be generated by selling the rod after cutting (if required) into pieces. In this question, you can pick any item any number of times. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int N, vector<int> &prices)
    {
        // Base Cases.

        if (idx == 0)
        {
            return (N * prices[0]);
        }

        // Recursive Case.

        // Picking the 'ith' element.
        int pick = INT_MIN;

        // Note: we only pick this element, if rod length is <= N.
        int rodLength = idx + 1;
        if (rodLength <= N)
        {
            // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
            pick = prices[idx] + solveRecursive(idx, N - rodLength, prices);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, N, prices);

        // return the maximum value that can generate by picking or not Picking the 'ith' element.
        return max(pick, notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n*n), recursive stack space and size of 'dp' array/vector.
    int solveMemoized(int idx, int N, vector<int> &prices, vector<vector<int>> &dp)
    {
        // Base Cases.

        if (idx == 0)
        {
            return N * prices[0];
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][N] != -1)
        {
            return dp[idx][N];
        }

        // Picking the 'ith' element.
        int pick = INT_MIN;

        // Note: we only pick this element, if rod length is <= N.
        int rodLength = idx + 1;
        if (rodLength <= N)
        {
            // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
            pick = prices[idx] + solveMemoized(idx, N - rodLength, prices, dp);
        }

        // Not Picking the 'ith' element.
        int notPick = solveMemoized(idx - 1, N, prices, dp);

        // return the maximum value that can generate by picking or not Picking the 'ith' element.
        // Store the answer of this subproblem and then return answer.
        return dp[idx][N] = max(pick, notPick);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n*n), size of 'dp' array/vector.
    int solveTabulized(int N, vector<int> &prices)
    {
        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));

        // Base Cases.
        for (int i = 0; i <= N; i++)
        {
            dp[0][i] = i * prices[0];
        }

        
        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < N; idx++)
        {
            for (int length = 0; length <= N; length++)
            {
                // Picking the 'ith' element.
                int pick = INT_MIN;

                // Note: we only pick this element, if rod length is <= N.
                int rodLength = idx + 1;
                if (rodLength <= length)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = prices[idx] + dp[idx][length - rodLength];
                }

                // Not Picking the 'ith' element.
                int notPick = dp[idx - 1][length];

                // Store the answer of this subproblem and then return answer.
                dp[idx][length] = max(pick, notPick);
            }
        }

        return dp[N - 1][N];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n), size of both the array/vector.
    int solveSpaceOptimized(int N, vector<int> &prices)
    {
        // prevRow vector/array.
        vector<int> prevRow(N + 1, 0);

        // currRow vector/array.
        vector<int> currRow(N + 1, 0);

        // Base Cases.
        for (int i = 0; i <= N; i++)
        {
            prevRow[i] = i * prices[0];
        }

        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < N; idx++)
        {
            for (int length = 0; length <= N; length++)
            {
                // Picking the 'ith' element.
                int pick = INT_MIN;

                // Note: we only pick this element, if rod length is <= N.
                int rodLength = idx + 1;
                if (rodLength <= length)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = prices[idx] + currRow[length - rodLength];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[length];

                // Store the answer of this subproblem and then return answer.
                currRow[length] = max(pick, notPick);
            }

            prevRow = currRow;
        }

        return prevRow[N];
    }

    /* Space Optimizing the above Space Optimized Code. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n), size of the array/vector.
    int solveSpaceOptimized2(int N, vector<int> &prices)
    {
        // prevRow vector/array.
        vector<int> prevRow(N + 1, 0);

        // Base Cases.
        for (int i = 0; i <= N; i++)
        {
            prevRow[i] = i * prices[0];
        }

        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < N; idx++)
        {
            for (int length = 0; length <= N; length++)
            {
                // Picking the 'ith' element.
                int pick = INT_MIN;

                // Note: we only pick this element, if rod length is <= N.
                int rodLength = idx + 1;
                if (rodLength <= length)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = prices[idx] + prevRow[length - rodLength];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[length];

                // Store the answer of this subproblem and then return answer.
                prevRow[length] = max(pick, notPick);
            }

        }

        return prevRow[N];
    }

public:
    /* Question: We are given a rod of size ‘N’. It can be cut into pieces. Each length of a piece has a particular price given by the price array. Our task is to find the maximum revenue that can be generated by selling the rod after cutting (if required) into pieces. */
    int cutRod(vector<int> &price, int n)
    {
        // // Recursive Solution.
        // return solveRecursive(n - 1, n, price);

        // DP Memoization Solution.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMemoized(n - 1, n, price, dp);
    }
};

int main(void)
{
    vector<int> price = {2, 5, 7, 8, 10};
    int n = price.size();

    // Solution.
    Solution S;
    return 0;
}