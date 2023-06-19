#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive method to find if there is a subset in “ARR” with a sum equal to K present or not. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(n), recursive stack space.
    bool solveRecursive(int idx, int target, vector<int> &arr)
    {
        // Base Case.

        // When target = 0, it means we have found the subset whose summation is equal to k. So, in this case, we return true from here.
        if (target == 0)
        {
            return true;
        }

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            return (arr[0] == target);
        }

        // Recursive Case.

        // Picking the 'ith' element.
        int pick = false; /* Initialize this with false. */

        // We only pick the current element, if the value of current element is <= target.
        if (arr[idx] <= target)
        {
            pick = solveRecursive(idx - 1, target - arr[idx], arr);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, target, arr);

        // Now, if any one of the above function calls return true, it means we are able to find the subset whose summation is equal to true.
        return (pick || notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*k), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(n) + O(n*k), recursive stack space and size of 'dp' array/vector.
    bool solveMemoized(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Base Case.

        // When target = 0, it means we have found the subset whose summation is equal to k. So, in this case, we return true from here.
        if (target == 0)
        {
            return true;
        }

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            return (arr[0] == target);
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        // Picking the 'ith' element.
        int pick = false; /* Initialize this with false. */

        // We only pick the current element, if the value of current element is <= target.
        if (arr[idx] <= target)
        {
            pick = solveMemoized(idx - 1, target - arr[idx], arr, dp);
        }

        // Not Picking the 'ith' element.
        int notPick = solveMemoized(idx - 1, target, arr, dp);

        // Now, if any one of the above function calls return true, it means we are able to find the subset whose summation is equal to true.

        // Store the answer of this subproblem and the return.
        return dp[idx][target] = (pick || notPick);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*k), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(n*k), size of 'dp' array/vector.
    bool solveTabulized(vector<int> &arr, int k)
    {
        // size of vector 'arr'.
        int n = arr.size();

        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base Case.
        // If target == 0, idx can take any value from 0 to n-1, therefore we need to set the value of the first column as true.
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell with that target will be true, so explicitly set dp[0][arr[0]] =true, (dp[0][arr[0]] means that we are considering the first element of the array with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) then set dp[0][arr[0]] = true.
        if (arr[0] <= k)
        {
            dp[0][arr[0]] = true;
        }

        // Recursive Case.

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= k; target++)
            {
                // Picking the 'ith' element.
                int pick = false; /* Initialize this with false. */

                // We only pick the current element, if the value of current element is <= target.
                if (arr[idx] <= target)
                {
                    pick = dp[idx - 1][target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = dp[idx - 1][target];

                // Store the answer of this subproblem and the return.
                dp[idx][target] = (pick || notPick);
            }
        }

        return dp[n - 1][k];
    }

    /* Space Optimizing the above DP Tabulation Code. */
    /* If we closely look the relation,

    dp[ind][target] =  dp[ind-1][target] || dp[ind-1][target-arr[ind]]

    We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it. */

    // Time Complexity: O(n*k), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(k), size of 'prevRow' and 'currRow' array/vector.
    bool solveSpaceOptimized(vector<int> &arr, int k)
    {
        // size of vector 'arr'/.
        int n = arr.size();

        // 'prevRow' vector.
        vector<bool> prevRow(k + 1, false);

        // Base Case.
        prevRow[0] = true;

        if (arr[0] <= k)
        {
            prevRow[arr[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            // 'currRow' vector.
            vector<bool> currRow(k + 1, false);
            currRow[0] = true;

            for (int target = 1; target <= k; target++)
            {
                // Picking the 'ith' element.
                int pick = false; /* Initialize this with false. */

                // We only pick the current element, if the value of current element is <= target.
                if (arr[idx] <= target)
                {
                    pick = prevRow[target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[target];

                // Store the answer of this subproblem and the return.
                currRow[target] = (pick || notPick);
            }

            // After the above loop end, our currRow will become prevRow.
            prevRow = currRow;
        }

        // return answer.
        return prevRow[k];
    }

public:
    /* Question: We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset in “ARR” with a sum equal to K. If there is, return true else return false. */
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        // // Recursive Solution.
        // return solveRecursive(n - 1, k, arr);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        // return solveMemoized(n - 1, k, arr, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(arr, k);

        // Space Optimized Solution.
        return solveSpaceOptimized(arr, k);
    }
};

int main(void)
{
    vector<int> arr{6, 1, 2, 1};
    int k = 4;
    int n = arr.size();

    // Solution.
    Solution S;
    cout << "Present or Not : " << ((S.subsetSumToK(n, k, arr)) ? "Present." : "Not Present.");

    return 0;
}