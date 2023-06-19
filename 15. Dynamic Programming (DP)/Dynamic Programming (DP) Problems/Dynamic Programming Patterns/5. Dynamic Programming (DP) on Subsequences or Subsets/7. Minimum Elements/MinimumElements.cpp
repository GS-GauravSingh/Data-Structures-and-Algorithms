#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the minimum number of coins required to reach the target sum. */
    // Time Complexity: O(2^n), where n is the size of the array.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int targetSum, vector<int> &arr)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            if (targetSum % arr[0] == 0)
            {
                return targetSum / arr[0];
            }

            return 1e9;
        }

        // Recursive case.

        // Picking the 'ith' element.
        int pick = 1e9;
        if (arr[idx] <= targetSum)
        {
            pick = 1 + solveRecursive(idx, targetSum - arr[idx], arr);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, targetSum, arr);

        return min(pick, notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*targetSum), where n is the size of the array.
    // Space Complexity: O(n) + O(n*targetSum), recursive stack space and size of 'dp' vector.
    int solveMemoized(int idx, int targetSum, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            if (targetSum % arr[0] == 0)
            {
                return targetSum / arr[0];
            }

            return 1e9;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][targetSum] != -1)
        {
            return dp[idx][targetSum];
        }

        // Recursive case.

        // Picking the 'ith' element.
        int pick = 1e9;
        if (arr[idx] <= targetSum)
        {
            pick = 1 + solveMemoized(idx, targetSum - arr[idx], arr, dp);
        }

        // Not Picking the 'ith' element.
        int notPick = solveMemoized(idx - 1, targetSum, arr, dp);

        // Store the answer of this subproblem and then return answer.
        return dp[idx][targetSum] = min(pick, notPick);
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
    int solveTabulized(int targetSum, vector<int> &arr)
    {
        // sioze of array.
        int n = arr.size();

        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<int>> dp(n, vector<int>(targetSum + 1, 0));

        // Base Cases.
        for (int target = 0; target <= targetSum; target++)
        {
            if (target % arr[0] == 0)
            {
                dp[0][target] = (target / arr[0]);
            }
            else
            {

                dp[0][target] = 1e9;
            }
        }

        // Outer loops is to traverse the dp array.
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= targetSum; target++)
            {
                // Picking the 'ith' element.
                int pick = 1e9;
                if (arr[idx] <= target)
                {
                    pick = 1 + dp[idx][target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = dp[idx - 1][target];

                // Store the answer of this subproblem and then return answer.
                dp[idx][target] = min(pick, notPick);
            }
        }

        int ans = dp[n - 1][targetSum];
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }

    /* Space Optimizing the above DP Tabulation Code. */
    // Time Complexity: O(n*targetSum), where n is the size of the array.
    // Space Complexity: O(targetSum), size of both vector.
    int solveSpaceOptimized(int targetSum, vector<int> &arr)
    {
        // sioze of array.
        int n = arr.size();

        // 'prevRow' vector/array.
        vector<int> prevRow(targetSum + 1, 0);

        // Base Cases.
        for (int target = 0; target <= targetSum; target++)
        {
            if (target % arr[0] == 0)
            {
                prevRow[target] = (target / arr[0]);
            }
            else
            {

                prevRow[target] = 1e9;
            }
        }

        // Outer loops is to traverse the dp array.
        for (int idx = 1; idx < n; idx++)
        {
            // 'currRow' vector/array.
            vector<int> currRow(targetSum + 1, 0);

            for (int target = 0; target <= targetSum; target++)
            {
                // Picking the 'ith' element.
                int pick = 1e9;
                if (arr[idx] <= target)
                {
                    pick = 1 + currRow[target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[target];

                // Store the answer of this subproblem and then return answer.
                currRow[target] = min(pick, notPick);
            }

            prevRow = currRow;
        }

        int ans = prevRow[targetSum];
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }

public:
    /* Question: We are given a target sum of ‘X’ and ‘N’ distinct numbers denoting the coin denominations. We need to tell the minimum number of coins required to reach the target sum. We can pick a coin denomination for any number of times we want. */
    int minimumElements(vector<int> &arr, int targetSum)
    {
        int n = arr.size();

        // // Recursive Solution.
        // int ans = solveRecursive(n - 1, targetSum, arr);
        // if (ans >= 1e9)
        // {
        //     return -1;
        // }
        // return ans;

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));
        // int ans = solveMemoized(n - 1, targetSum, arr, dp);
        // if (ans >= 1e9)
        // {
        //     return -1;
        // }
        // return ans;

        // DP Tabulation Solution.
        return solveTabulized(targetSum, arr);
    }
};

int main(void)
{
    vector<int> arr{1, 2, 3};
    int target = 7;

    // Solution.
    Solution S;
    cout << "Minimum Coins Needed : " << S.minimumElements(arr, target) << ".\n";
    return 0;
}