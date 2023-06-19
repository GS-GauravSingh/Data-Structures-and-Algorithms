#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Method to find the find the path with minimum total energy lost.  */

    // Time Complexity: O(2^n), where n is the number of stairs.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int n, vector<int> &heights)
    {
        // Base Case
        // If n == 0, it means we are at the 0th stair, and from the 0th stair we cannot move ahead i.e., we cannot move to -1, -2 ... stair because there are invalid stairs.
        // So, return 0 from here, because we are at 0th stair and in order to reach 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        if (n == 0)
        {
            return 0;
        }

        // Recursive Case.
        // Now, from the current stair try taking both one and two steps and by taking whatever steps (oen or two steps) return the path with minimum energy lost.

        // Taking one step and after taking one step add the absolute difference of the heights of the stairs.
        int takeOneStep = solveRecursive(n - 1, heights) + abs(heights[n] - heights[n - 1]);

        int takeTwoStep = INT_MAX; // Initialize this with INT_MAX, because we have to retun the path with minimum energy lost and suppose if we are standing at the 1st stair, there is only one way to reach the 0th stair that is by taking one step and if you take 2 steps you may end up reaching the negative stair whih is basically an invalid stairs.
        // So, only take 2 steps when the value of n is greater than 1.
        if (n > 1)
        {
            // Taking two step and after taking two step add the absolute difference of the heights of the stairs.
            takeTwoStep = solveRecursive(n - 2, heights) + abs(heights[n] - heights[n - 2]);
        }

        // return the step with minimum energy lost.
        /* Example: suppose energy lost by taking one step is 10 and  energy lost by taking two step is 20, so which step is better, one step is better, that's why we have to return the step with minimum energy lost.  */
        return min(takeOneStep, takeTwoStep);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n), where n is the number of stairs.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space and size used by 'dp' array/vector.
    int solveMemoized(int n, vector<int> &heights, vector<int> &dp)
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
        // Now, from the current stair try taking both one and two steps and by taking whatever steps (oen or two steps) return the path with minimum energy lost.

        // Taking one step and after taking one step add the absolute difference of the heights of the stairs.
        int takeOneStep = solveMemoized(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);

        int takeTwoStep = INT_MAX; // Initialize this with INT_MAX, because we have to retun the path with minimum energy lost and suppose if we are standing at the 1st stair, there is only one way to reach the 0th stair that is by taking one step and if you take 2 steps you may end up reaching the negative stair whih is basically an invalid stairs.
        // So, only take 2 steps when the value of n is greater than 1.
        if (n > 1)
        {
            // Taking two step and after taking two step add the absolute difference of the heights of the stairs.
            takeTwoStep = solveMemoized(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
        }

        // store and answer of this subproblem and return the step with minimum energy lost.
        /* Example: suppose energy lost by taking one step is 10 and  energy lost by taking two step is 20, so which step is better, one step is better, that's why we have to return the step with minimum energy lost.  */
        return dp[n] = min(takeOneStep, takeTwoStep);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */
    // Time Complexity: O(n), where n is the number of stairs.
    // Space Complexity: O(n), size used by 'dp' array/vector.
    int solveTabulized(int n, vector<int> &heights)
    {
        // 'dp' array/vector to store and compute the answer of subproblem.
        vector<int> dp(n + 1, 0);

        // Base Case

        // dp[0] = 0, because we are at 0th stair and in order to reach 0 from 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        dp[0] = 0;

        // Now, from the current stair try taking both one and two steps and by taking whatever steps (oen or two steps) return the path with minimum energy lost.

        // Now, Run a loop from 1 to n and find the path with minimum total energy lost.
        for (int stair = 1; stair <= n; stair++)
        {
            // Taking one step and after taking one step add the absolute difference of the heights of the stairs.
            int takeOneStep = dp[stair - 1] + abs(heights[stair] - heights[stair - 1]);
            int takeTwoStep = INT_MAX; // Initialize this with INT_MAX, because we have to retun the path with minimum energy lost and suppose if we are standing at the 1st stair, there is only one way to reach the 0th stair that is by taking one step and if you take 2 steps you may end up reaching the negative stair whih is basically an invalid stairs.
            // So, only take 2 steps when the value of n is greater than 1.
            if (stair > 1)
            {
                // Taking two step and after taking two step add the absolute difference of the heights of the stairs.
                takeTwoStep = dp[stair - 2] + abs(heights[stair] - heights[stair - 2]);
            }

            // store and answer of this subproblem i.e., store the minimum energy lost by taking one or two step.
            /* Example: suppose energy lost by taking one step is 10 and  energy lost by taking two step is 20, so which step is better, one step is better, that's why we have to return the step with minimum energy lost.  */
            dp[stair] = min(takeOneStep, takeTwoStep);
        }

        // return answer.
        return dp[n];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // Using Variable instead of 'dp' array/vector.

    // Time Complexity: O(n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(1).
    int solveSpaceOptimized(int n, vector<int> &heights)
    {
        // Base Case

        // For stair 0, in order to reach 0 from 0 itself the energy lost is 0 i.e., |heights[0] - heights[0]| = 0.
        int twoPrevStair = 0;

        // For stair 1, there is ony one waye to reach the 0th stair from 1st stair, which is by taking one step, in order to reach 0 from 1st stair the energy lost is the absolute difference of heights of 0th stair and 1st stair i.e., |heights[0] - heights[1]|.
        int onePrevStair = abs(heights[0] - heights[1]);

        // Now, from the current stair try taking both one and two steps and by taking whatever steps (one or two steps) return the path with minimum energy lost.

        // Now, we have already cover the 0th and 1st stair, So, Run a loop from 2 to n and find the path with minimum total energy lost.
        for (int stair = 2; stair <= n; stair++)
        {
            // Taking one step and after taking one step add the absolute difference of the heights of the stairs.
            int takeOneStep = onePrevStair + abs(heights[stair] - heights[stair - 1]);
            int takeTwoStep = INT_MAX; // Initialize this with INT_MAX, because we have to retun the path with minimum energy lost and suppose if we are standing at the 1st stair, there is only one way to reach the 0th stair that is by taking one step and if you take 2 steps you may end up reaching the negative stair whih is basically an invalid stairs.
            // So, only take 2 steps when the value of n is greater than 1.
            if (stair > 1)
            {
                // Taking two step and after taking two step add the absolute difference of the heights of the stairs.
                takeTwoStep = twoPrevStair + abs(heights[stair] - heights[stair - 2]);
            }

            // store the minimum energy lost for the current stair.
            int currStair = min(takeOneStep, takeTwoStep);

            // update pointers.
            twoPrevStair = onePrevStair;
            onePrevStair = currStair;
                }

        // return answer.
        return onePrevStair;
    }

public:
    /* Question: There is a frog at '0th' stair of a 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. An array heights is given, where 'heights[i]' represent the heights of the 'ith' stair. If a frog jumps from the 'ith' stair to the 'jth' stair, the energy lost in the jump is given by absolute value of heights of 'ith' stair and 'jth' stair i.e., |heights[i] - heights[j]|. If a frog is on the 'ith' stair, he can jump either to '(i+1)th' stair or to (i+2)th stair. Your task is to find the total minimum energy used by the frog to reach the 'Nth' stair. */
    int frogJump(int n, vector<int> &heights)
    {
        // // Plain Recursive Code.
        // return solveRecursive(n, heights);

        // // DP Memoized Code.
        // vector<int> dp(n+1, -1);
        // return solveMemoized(n, heights, dp);

        // // DP Tabulized Code.
        // return solveTabulized(n, heights);

        // Space Optimized Code.
        return solveSpaceOptimized(n, heights);
    }
};

int main(void)
{
    // Out task is to find the minimum total energy used by the frog to reach the 'Nth' stair.
    int n = 3;
    vector<int> heights{10, 20, 30, 10};

    // Solution.
    Solution S;
    cout << "Minimum total energy used is : " << S.frogJump(n, heights) << ".";
    return 0;
}