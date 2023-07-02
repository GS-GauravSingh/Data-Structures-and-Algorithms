#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the number of ways we sum up the coin values to give us the target. */
    // Time Complexity: O(2^n), where n is the size of the array.
    // Space Complexity: O(n), recursive stack space.
    long solveRecursive(int idx, int targetSum, int *arr)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            return (targetSum % arr[0] == 0);
        }

        // Recursive case.

        // Picking the 'ith' element.
        long pick = 0;
        if (arr[idx] <= targetSum)
        {
            pick = solveRecursive(idx, targetSum - arr[idx], arr);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, targetSum, arr);

        return pick + notPick;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*targetSum), where n is the size of the array.
    // Space Complexity: O(n) + O(n*targetSum), recursive stack space and size of 'dp' vector.
    long solveMemoized(int idx, int targetSum, int *arr, vector<vector<long>> &dp)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            return (targetSum % arr[0] == 0);
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][targetSum] != -1)
        {
            return dp[idx][targetSum];
        }

        // Recursive case.

        // Picking the 'ith' element.
        long pick = 0;
        if (arr[idx] <= targetSum)
        {
            pick = solveMemoized(idx, targetSum - arr[idx], arr, dp);
        }

        // Not Picking the 'ith' element.
        long notPick = solveMemoized(idx - 1, targetSum, arr, dp);

        // Store the answer of this subproblem and then return answer.
        return dp[idx][targetSum] = pick + notPick;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*targetSum), where n is the size of the array.
    // Space Complexity: O(n*targetSum), size of 'dp' vector.
    long solveTabulized(int targetSum, int n, int *arr)
    {

        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<long>> dp(n, vector<long>(targetSum + 1, 0));

        // Base Cases.
        for (int target = 0; target <= targetSum; target++)
        {
            if (target % arr[0] == 0)
            {
                dp[0][target] = 1;
            }
        }

        // Outer loops is to traverse the dp array.
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= targetSum; target++)
            {
                // Picking the 'ith' element.
                long pick = 0;
                if (arr[idx] <= target)
                {
                    pick = dp[idx][target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                long notPick = dp[idx - 1][target];

                // Store the answer of this subproblem and then return answer.
                dp[idx][target] = (pick + notPick);
            }
        }

        return dp[n - 1][targetSum];
    }

    /* Space Optimizing the above DP Tabulation Code. */
    // Time Complexity: O(n*targetSum), where n is the size of the array.
    // Space Complexity: O(targetSum), size of both vector.
    long solveSpaceOptimized(int targetSum, int n, int *arr)
    {

        // 'prevRow' vector/array.
        vector<long> prevRow(targetSum + 1, 0);

        // Base Cases.
        for (int target = 0; target <= targetSum; target++)
        {
            if (target % arr[0] == 0)
            {
                prevRow[target] = 1;
            }
        }

        // Outer loops is to traverse the dp array.
        for (int idx = 1; idx < n; idx++)
        {
            // 'currRow' vector/array.
            vector<long> currRow(targetSum + 1, 0);

            for (int target = 0; target <= targetSum; target++)
            {
                // Picking the 'ith' element.
                long pick = 0;
                if (arr[idx] <= target)
                {
                    pick = currRow[target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                long notPick = prevRow[target];

                // Store the answer of this subproblem and then return answer.
                currRow[target] = (pick + notPick);
            }

            prevRow = currRow;
        }

        return prevRow[targetSum];
    }

public:
    /* Question: We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target. */
    long countWaysToMakeChange(int *denominations, int n, int value)
    {
        return solveSpaceOptimized(value, n, denominations);
    }
};

int main(void)
{
    int arr[] = {1, 2, 3};
    int target = 4;
    int n = sizeof(arr) / sizeof(int);

    // Solution
    Solution S;
    cout << S.countWaysToMakeChange(arr, n, target);
    return 0;
}