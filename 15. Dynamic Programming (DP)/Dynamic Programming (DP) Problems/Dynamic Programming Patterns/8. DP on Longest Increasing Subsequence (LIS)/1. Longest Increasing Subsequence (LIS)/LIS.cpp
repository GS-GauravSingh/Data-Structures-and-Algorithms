#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the length of the Longest Increasing Subsequence. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int prevIdx, int n, int *arr)
    {
        // Base Case

        // When idx == n, It means that we have considered all the elements of the array and there are no more elements left to explore, therefore we return 0.
        if (idx == n)
        {
            return 0;
        }

        // Recursive Solution.

        // Picking the 'ith' element.
        int pick = 0; // Initialize this with 0.

        // Now, if prevIdx = -1, it means that we have not considered any element to our subsequence. Therefore, we can always consider the current element (arr[ind]) for our subsequence.

        // Otherwise, if prevIdx != -1, in this case, we only consider the current element into our subsequence, if current element is greater than (>), previous picked element.
        if (prevIdx == -1 || (prevIdx >= 0 && arr[idx] > arr[prevIdx]))
        {
            // we are considering the current element in the subsequence, therefore the length of the subsequence will increase by 1 and the prevIndex element will be updated to the current index element.
            pick = 1 + solveRecursive(idx + 1, idx, n, arr);
        }

        // Not Picking the 'ith' element.

        //  we are not considering the current element in the subsequence, therefore the length of the subsequence will not increase and the prevIndex element will remain as it is.
        int notPick = 0 + solveRecursive(idx + 1, prevIdx, n, arr);

        // As we have to find the length of the longest increasing subsequence, we will return the maximum of the two cases.
        return max(pick, notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n*n), recursive stack space and size of dp vector.
    int solveMemoized(int idx, int prevIdx, int n, int *arr, vector<vector<int>> &dp)
    {
        // Base Case

        // When idx == n, It means that we have considered all the elements of the array and there are no more elements left to explore, therefore we return 0.
        if (idx == n)
        {
            return 0;
        }

        // Recursive Solution.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][prevIdx + 1] != -1)
        {
            return dp[idx][prevIdx + 1];
        }

        // Picking the 'ith' element.
        int pick = 0; // Initialize this with 0.

        // Now, if prevIdx = -1, it means that we have not considered any element to our subsequence. Therefore, we can always consider the current element (arr[ind]) for our subsequence.

        // Otherwise, if prevIdx != -1, in this case, we only consider the current element into our subsequence, if current element is greater than (>), previous picked element.
        if (prevIdx == -1 || (prevIdx >= 0 && arr[idx] > arr[prevIdx]))
        {
            // we are considering the current element in the subsequence, therefore the length of the subsequence will increase by 1 and the prevIndex element will be updated to the current index element.
            pick = 1 + solveMemoized(idx + 1, idx, n, arr, dp);
        }

        // Not Picking the 'ith' element.

        //  we are not considering the current element in the subsequence, therefore the length of the subsequence will not increase and the prevIndex element will remain as it is.
        int notPick = 0 + solveMemoized(idx + 1, prevIdx, n, arr, dp);

        // As we have to find the length of the longest increasing subsequence, we will return the maximum of the two cases.
        return dp[idx][prevIdx + 1] = max(pick, notPick);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n*n), size of dp vector.
    int solveTabulized(int n, int *arr)
    {
        // 'dp' vector.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base Case
        // DP vector is already initialized with 0, That's why we covered the base case.

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                // Picking the 'ith' element.
                int pick = 0; // Initialize this with 0.

                // Now, if prevIdx = -1, it means that we have not considered any element to our subsequence. Therefore, we can always consider the current element (arr[ind]) for our subsequence.

                // Otherwise, if prevIdx != -1, in this case, we only consider the current element into our subsequence, if current element is greater than (>), previous picked element.
                if (prevIdx == -1 || (prevIdx >= 0 && arr[idx] > arr[prevIdx]))
                {
                    // we are considering the current element in the subsequence, therefore the length of the subsequence will increase by 1 and the prevIndex element will be updated to the current index element.
                    pick = 1 + dp[idx + 1][idx + 1];
                }

                // Not Picking the 'ith' element.

                //  we are not considering the current element in the subsequence, therefore the length of the subsequence will not increase and the prevIndex element will remain as it is.
                int notPick = 0 + dp[idx + 1][prevIdx + 1];

                // As we have to find the length of the longest increasing subsequence, we will return the maximum of the two cases.
                dp[idx][prevIdx + 1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n), size of both vectors.
    int solveSpaceOptimized(int n, int *arr)
    {
        // 'currRow' vector.
        vector<int> currRow(n + 1, 0);

        // 'aheadRow' vector.
        vector<int> aheadRow(n + 1, 0);

        // Base Case
        // DP vector is already initialized with 0, That's why we covered the base case.

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                // Picking the 'ith' element.
                int pick = 0; // Initialize this with 0.

                // Now, if prevIdx = -1, it means that we have not considered any element to our subsequence. Therefore, we can always consider the current element (arr[ind]) for our subsequence.

                // Otherwise, if prevIdx != -1, in this case, we only consider the current element into our subsequence, if current element is greater than (>), previous picked element.
                if (prevIdx == -1 || (prevIdx >= 0 && arr[idx] > arr[prevIdx]))
                {
                    // we are considering the current element in the subsequence, therefore the length of the subsequence will increase by 1 and the prevIndex element will be updated to the current index element.
                    pick = 1 + aheadRow[idx + 1];
                }

                // Not Picking the 'ith' element.

                //  we are not considering the current element in the subsequence, therefore the length of the subsequence will not increase and the prevIndex element will remain as it is.
                int notPick = 0 + aheadRow[prevIdx + 1];

                // As we have to find the length of the longest increasing subsequence, we will return the maximum of the two cases.
                currRow[prevIdx + 1] = max(pick, notPick);
            }

            aheadRow = currRow;
        }

        return aheadRow[0];
    }

    /* Tabulation algorithm to find the length of the longest increasing subsequence. */
    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n), size of both vectors.
    int solveOptimized(int n, int *arr)
    {
        vector<int> dp(n, 1);

        for (int i = 0; i <= n - 1; i++)
        {
            for (int prev_index = 0; prev_index <= i - 1; prev_index++)
            {

                if (arr[prev_index] < arr[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prev_index]);
                }
            }
        }

        int ans = -1;
        for (int i = 0; i <= n - 1; i++)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }

public:
    /* Question:

    ‘Longest Increasing Subsequence’. Before proceeding further, let us understand the “Longest Increasing Subsequence”, or rather what is a “subsequence”?

    A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original array.
    For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.

    What is the Longest Increasing Subsequence?
    The longest increasing subsequence is described as a subsequence of an array where:
    1. All elements of the subsequence are in increasing order.
    2. This subsequence itself is of the longest length possible.

    For Example: Arr = {10, 9, 2, 5, 3, 7, 101, 18};
    Longest Increasing Subsequence: {2, 3, 7, 101} or {2, 3, 7, 18}.
    The length of the Longes Increasing Subsequence is 4.

    In this question, our task is to return the length of the longest increasing subsequence as the answer.
    */
    int longestIncreasingSubsequence(int arr[], int n)
    {
        // // Recursive Solution.
        // return solveRecursive(0, -1, n, arr);

        // DP Memoization Solution.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solveMemoized(0, -1, n, arr, dp);
    }
};

int main(void)
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;

    cout << "The length of the longest increasing subsequence is "
         << S.longestIncreasingSubsequence(arr, n);
    return 0;
}