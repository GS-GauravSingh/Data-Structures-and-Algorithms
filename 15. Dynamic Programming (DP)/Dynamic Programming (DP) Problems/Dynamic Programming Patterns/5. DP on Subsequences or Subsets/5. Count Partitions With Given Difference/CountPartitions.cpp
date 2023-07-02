#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive method to count the number of subsets in whose summation equals to k. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int target, vector<int> &arr)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            // Now, before doing anyting at idx 0 and just after reaching the idx 0. if our target = 0, it means we have a found a subset whose sum is equal to 0.

            // Now, for element at index 0, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).

            // Suppose if the element at index 0 is a non-zero element, in this case, our target is already 0, so we cannot consider (pick) this element into our subset. So We CANNOT PICK this element, now, only one choice is left.
            // We have to ignore this element.

            // Suppose if the element at index 0 is 0 (arr[0] = 0), in this case, our target is already 0, so if we consider this element, our target still remains 0. so we can consider this element and after considering this element into our subset, we got anoother subset whose sum is equla to target, so return 2 from here.

            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            // But, if target = 0 and arr[0] != 0, in this case we cannot consider this element at index 0. So, in this case return 1.
            // But, if target != 0 and arr[0] != 0, in this case we only consider this element at index 0. If arr[0] = target.
            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            // For rest of the case reuturn 0, it menas this subset has sum != target.
            return 0;
        }

        // Recursive Case.

        // Picking the 'ith' element.
        int pick = 0; /* Initialize this with 0. */

        // We only pick the current element, if the value of current element is <= target.
        if (arr[idx] <= target)
        {
            pick = solveRecursive(idx - 1, target - arr[idx], arr);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, target, arr);

        // As we have to return the total count of subsets with the target sum, we will return the sum of taken and notTaken from our recursive call.
        return (pick + notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*k), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(n) + O(n*k), recursive stack space and size of 'dp' array/vector.
    int solveMemoized(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Base Case.

        // As we are solving this problem from 'n' to '0'. When idx = 0, it means we are at the 0th index and for the element present at 0th index, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).
        if (idx == 0)
        {
            // Now, before doing anyting at idx 0 and just after reaching the idx 0. if our target = 0, it means we have a found a subset whose sum is equal to 0.

            // Now, for element at index 0, we again have 2 choices, first is to pick(consider it into our subsequence) and another is to skip(not consider it into our subsequence).

            // Suppose if the element at index 0 is a non-zero element, in this case, our target is already 0, so we cannot consider (pick) this element into our subset. So We CANNOT PICK this element, now, only one choice is left.
            // We have to ignore this element.

            // Suppose if the element at index 0 is 0 (arr[0] = 0), in this case, our target is already 0, so if we consider this element, our target still remains 0. so we can consider this element and after considering this element into our subset, we got anoother subset whose sum is equla to target, so return 2 from here.

            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            // But, if target = 0 and arr[0] != 0, in this case we cannot consider this element at index 0. So, in this case return 1.
            // But, if target != 0 and arr[0] != 0, in this case we only consider this element at index 0. If arr[0] = target.
            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            // For rest of the case reuturn 0, it menas this subset has sum != target.
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        // Picking the 'ith' element.
        int pick = 0; /* Initialize this with 0. */

        // We only pick the current element, if the value of current element is <= target.
        if (arr[idx] <= target)
        {
            pick = solveMemoized(idx - 1, target - arr[idx], arr, dp);
        }

        // Not Picking the 'ith' element.
        int notPick = solveMemoized(idx - 1, target, arr, dp);

        // As we have to return the total count of subsets with the target sum, we will return the sum of taken and notTaken from our recursive call.

        // Store the answer of this subproblem and then return.
        return dp[idx][target] = (pick + notPick);
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
    int solveTabulized(vector<int> &arr, int k)
    {

        // size of vector 'arr'.
        int n = arr.size();

        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        // Base Case.

        if (arr[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= k)
        {
            dp[0][arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 0; target <= k; target++)
            {
                // Picking the 'ith' element.
                int pick = 0; /* Initialize this with 0. */

                // We only pick the current element, if the value of current element is <= target.
                if (arr[idx] <= target)
                {
                    pick = dp[idx - 1][target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = dp[idx - 1][target];

                // Store the answer of this subproblem and then return.
                dp[idx][target] = (pick + notPick);
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
    int solveSpaceOptimized(vector<int> &arr, int k)
    {
        // size of vector 'arr'/.
        int n = arr.size();

        // 'prevRow' vector.
        vector<int> prevRow(k + 1, 0);

        // Base Case.
        if (arr[0] == 0)
        {
            prevRow[0] = 2;
        }
        else
        {
            prevRow[0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= k)
        {
            prevRow[arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++)
        {
            // 'currRow' vector.
            vector<int> currRow(k + 1, 0);

            for (int target = 0; target <= k; target++)
            {
                // Picking the 'ith' element.
                int pick = 0; /* Initialize this with 0. */

                // We only pick the current element, if the value of current element is <= target.
                if (arr[idx] <= target)
                {
                    pick = prevRow[target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[target];

                // Store the answer of this subproblem and then return.
                currRow[target] = (pick + notPick);
            }

            // After the above loop end, our currRow will become prevRow.
            prevRow = currRow;
        }

        // return answer.
        return prevRow[k];
    }

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {

        int totSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totSum += arr[i];
        }

        // Checking for edge cases
        if (totSum - d < 0)
            return 0;
        if ((totSum - d) % 2 == 1)
            return 0;

        int s2 = (totSum - d) / 2;

        // // Recursive Solution.
        // return solveRecursive(n-1, s2, arr);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        // return solveMemoized(n-1, s2, arr, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(arr, s2);

        // Space optimized Solution.
        return solveSpaceOptimized(arr, s2);
    }
};

int main(void)
{
    vector<int> nums{1, 2, 2, 3};
    int target = 3;

    // Solution.
    Solution S;
    cout << "Subset Count : " << S.countPartitions(nums.size(), target, nums) << ".\n";

    return 0;
}