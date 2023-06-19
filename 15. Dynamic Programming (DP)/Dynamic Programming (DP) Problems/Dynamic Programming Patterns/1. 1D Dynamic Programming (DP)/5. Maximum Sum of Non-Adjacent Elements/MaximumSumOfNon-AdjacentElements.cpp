#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the maximum sum of the subsequence  with the constraint that no two elements are adjacent. */
    // Time Complexity: O(2^n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), recursive stack space.
    int maxSumSubsequence_Recursive(int idx, vector<int> &nums)
    {
        // Base Case
        if (idx < 0)
        {
            return 0;
        }

        // Recursive Case.

        // Picking the ith element, Now when we are picking the ith element, then the sum has to increase by nums[i] and when we are picking the ith element, we have to skip the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
        // So, when we are picking the ith element then the next element we are going to pick is i+2th element.
        int pickSum = nums[idx] + maxSumSubsequence_Recursive(idx - 2, nums);

        // Not Picking the ith element, Now when we are skipping the ith element, then the sum will not increase and when we are skipping the ith element, we can pick the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
        // So, when we are skipping the ith element then the next element we are going to pick is i+1th element.
        int notPickSum = maxSumSubsequence_Recursive(idx - 1, nums);

        // Return the maximum sum.
        return max(pickSum, notPickSum);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space + size of 'dp' array.
    int maxSumSubsequence_Memoized(int idx, vector<int> &nums, vector<int> &dp)
    {
        // Base Case
        if (idx < 0)
        {
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx] != -1)
        {
            // If dp[n] == -1, it means this is not an overlapping subproblem.
            // but If dp[n] != -1, it means this is an overlapping subproblem and the dp[n] contains the answer of this subproblem.
            return dp[idx];
        }

        // Picking the ith element, Now when we are picking the ith element, then the sum has to increase by nums[i] and when we are picking the ith element, we have to skip the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
        // So, when we are picking the ith element then the next element we are going to pick is i+2th element.
        int pickSum = nums[idx] + maxSumSubsequence_Memoized(idx - 2, nums, dp);

        // Not Picking the ith element, Now when we are skipping the ith element, then the sum will not increase and when we are skipping the ith element, we can pick the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
        // So, when we are skipping the ith element then the next element we are going to pick is i+1th element.
        int notPickSum = maxSumSubsequence_Memoized(idx - 1, nums, dp);

        // Store the answer (maximum sum) of this subproblem and then Return the maximum sum.
        return dp[idx] = max(pickSum, notPickSum);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), size of 'dp' array.
    int maxSumSubsequence_Tabulized(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // 'dp' array to store and computer the result of subproblem.
        vector<int> dp(n, 0);

        for (int idx = 0; idx < n; idx++)
        {
            // Picking the ith element, Now when we are picking the ith element, then the sum has to increase by nums[i] and when we are picking the ith element, we have to skip the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are picking the ith element then the next element we are going to pick is i+2th element.
            int pickSum = nums[idx] + ((idx - 2 < 0) ? 0 : dp[idx - 2]);

            // Not Picking the ith element, Now when we are skipping the ith element, then the sum will not increase and when we are skipping the ith element, we can pick the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are skipping the ith element then the next element we are going to pick is i+1th element.
            int notPickSum = ((idx - 1 < 0) ? 0 : dp[idx - 1]);

            // Store the answer (maximum sum).
            dp[idx] = max(pickSum, notPickSum);
        }

        // return the maximum sum.
        return dp[n-1];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // Using Variable instead of 'dp' array/vector.

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int maxSumSubsequence_SpaceOptimized(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // pointers.
        int prevOne = 0;
        int prevTwo = 0;

        for (int idx = 0; idx < n; idx++)
        {
            // Picking the ith element, Now when we are picking the ith element, then the sum has to increase by nums[i] and when we are picking the ith element, we have to skip the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are picking the ith element then the next element we are going to pick is i+2th element.
            int pickSum = nums[idx] + ((idx - 2 < 0) ? 0 : prevTwo);

            // Not Picking the ith element, Now when we are skipping the ith element, then the sum will not increase and when we are skipping the ith element, we can pick the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are skipping the ith element then the next element we are going to pick is i+1th element.
            int notPickSum = ((idx - 1 < 0) ? 0 : prevOne);

            // store the maximum sum.
            int curr = max(pickSum, notPickSum);

            // update the pointers.
            prevTwo = prevOne;
            prevOne = curr;
        }

        // return the maximum sum.
        return prevOne;
    }

public:
    /* Question: Given an array of integers. You are supposed to to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list. */
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // // Recursive Code.
        // return maxSumSubsequence_Recursive(n - 1, nums);

        // // DP Memoization Solution.
        // vector<int> dp(n, -1);
        // return maxSumSubsequence_Memoized(n - 1, nums, dp);

        // // DP Tabulation Solution.
        // return maxSumSubsequence_Tabulized(nums);

        // Space Optimized Solution.
        return maxSumSubsequence_SpaceOptimized(nums);
    }
};

int main(void)
{
    vector<int> nums{1, 2, 4};

    // Solution.
    Solution S;
    cout << "Maximum Sum of Subsequence is : " << S.maximumNonAdjacentSum(nums) << ".\n";
    return 0;
}