#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive method to find the minimum total energy used. */
    // Time Complexity: O(n^k), where n is the number of stairs and k is the number of steps allowed.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int n, int k, vector<int> &heights)
    {
        // Base Case
        // If n == 0, it means we are at the 0th stair, and from the 0th stair we cannot move ahead i.e., we cannot move to -1, -2 ... stair because there are invalid stairs.
        // So, return 0 from here, because we are at 0th stair and in order to reach 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        if (n == 0)
        {
            return 0;
        }

        // Recursive Case.
        // Now, from the current stair try taking all the k steps one by one and by taking whatever steps  return the path with minimum energy lost.
        // variable to store minimum energy lost.
        int minEnergyLost = INT_MAX;

        // Run a loop from 1 to k, because we have to take 'k' jump.
        for (int step = 1; step <= k; step++)
        {
            // check whether this jump is a valid jump or not.
            if (n - step >= 0)
            {
                int jump = solveRecursive(n - step, k, heights) + abs(heights[n] - heights[n - step]);
                minEnergyLost = min(minEnergyLost, jump);
            }
        }

        // return the step with minimum energy lost.
        return minEnergyLost;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*k), where n is the number of stairs and k is the number of steps allowed.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space and size used by 'dp' array/vector.
    int solveMemoized(int n, int k, vector<int> &heights, vector<int> &dp)
    {
        // Base Case
        // If n == 0, it means we are at the 0th stair, and from the 0th stair we cannot move ahead i.e., we cannot move to -1, -2 ... stair because there are invalid stairs.
        // So, return 0 from here, because we are at 0th stair and in order to reach 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        if (n == 0)
        {
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[n] != -1)
        {
            // If dp[n] == -1, it means this is not an overlapping subproblem.
            // but If dp[n] != -1, it means this is an overlapping subproblem and the dp[n] contains the answer of this subproblem.
            return dp[n];
        }

        // Now, from the current stair try taking all the k steps one by one and by taking whatever steps  return the path with minimum energy lost.

        // variable to store minimum energy lost.
        int minEnergyLost = INT_MAX;

        // Run a loop from 1 to k, because we have to take 'k' jump.
        for (int step = 1; step <= k; step++)
        {
            // check whether this jump is a valid jump or not.
            if (n - step >= 0)
            {
                int jump = solveMemoized(n - step, k, heights, dp) + abs(heights[n] - heights[n - step]);
                minEnergyLost = min(minEnergyLost, jump);
            }
        }

        // return the step with minimum energy lost.
        return dp[n] = minEnergyLost;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */
    // Time Complexity: O(n*k), where n is the number of stairs and k is the number of steps allowed.
    // Space Complexity: O(n), size used by 'dp' array/vector.
    int solveTabulized(int n, int k, vector<int> &heights)
    {
        // 'dp' array/vector to store and compute answer of subproblems.
        vector<int> dp(n + 1);

        // Base Case
        // If n == 0, it means we are at the 0th stair, and from the 0th stair we cannot move ahead i.e., we cannot move to -1, -2 ... stair because there are invalid stairs.
        // So, return 0 from here, because we are at 0th stair and in order to reach 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        dp[0] = 0;

        // Now, from the current stair try taking all the k steps one by one and by taking whatever steps  return the path with minimum energy lost.

        for (int stair = 1; stair <= n; stair++)
        {
            int minEnergyLost = INT_MAX;

            for (int step = 1; step <= k; step++)
            {
                // check whether this jump is a valid jump or not.
                if (stair - step >= 0)
                {
                    int jump = solveMemoized(stair - step, k, heights, dp) + abs(heights[stair] - heights[stair - step]);
                    minEnergyLost = min(minEnergyLost, jump);
                }
            }

            dp[stair] = minEnergyLost;
        }

        // return the step with minimum energy lost.
        return dp[n];
    }

public:
    /* Question: This is a follow-up question to “Frog Jump”. In the previous question, the frog was allowed to jump either one or two steps at a time. In this question, the frog is allowed to jump up to ‘K’ steps at a time. If K = 4, the frog can jump 1, 2, 3, or 4 steps at every index. */
    int frogJump(int n, int k, vector<int> &heights)
    {
        // // Plain Recursove Code.
        // return solveRecursive(n, k, heights);

        // // DP Memoization Code.
        // vector<int> dp(n+1, -1);
        // return solveMemoized(n, k, heights, dp);

        // DP Tabulation Code.
        return solveTabulized(n, k, heights);
    }
};

int main(void)
{
    // Out task is to find the minimum total energy used by the frog to reach the 'Nth' stair by taking 'k' steps from each stair.
    int n = 5;
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int k = 2;

    // Solution.
    Solution S;
    cout << "Minimum total energy used is : " << S.frogJump(n, k, heights) << ".";
    return 0;
}