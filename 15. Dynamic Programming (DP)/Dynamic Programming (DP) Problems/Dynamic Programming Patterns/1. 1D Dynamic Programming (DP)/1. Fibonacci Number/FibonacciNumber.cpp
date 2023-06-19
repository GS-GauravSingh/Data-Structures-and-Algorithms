#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Recursive Method to find the 'nth' Fibonacci number of the Fibonacci series. */
    // Time Complexity: O(2^n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(n), recursive stack space.
    int fibRecursive(int n)
    {
        // Base Case
        // The First term of the Fibonacci series is 0.
        // The Second term of the Fibonacci series is 1.
        // and the next term of the fibonacci series is the summation of previous 2 terms.
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Recursive Case.

        // The next term or the nth term of the Fibonacci series is the summation of previous 2 terms.
        int nextTerm = fibRecursive(n - 1) + fibRecursive(n - 2);
        return nextTerm;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space and size used by 'dp' array/vector.
    int fibMemoized(int n, vector<int> &dp)
    {
        // Base Case
        // The First term of the Fibonacci series is 0.
        // The Second term of the Fibonacci series is 1.
        // and the next term of the fibonacci series is the summation of previous 2 terms.
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[n] != -1)
        {
            // If dp[n] == -1, it means this is not an overlapping subproblem.
            // but If dp[n] != -1, it means this is an overlapping subproblem and the dp[n] contains the answer of this subproblem.
            return dp[n];
        }

        // The next term or the nth term of the Fibonacci series is the summation of previous 2 terms.
        dp[n] = fibRecursive(n - 1) + fibRecursive(n - 2);
        return dp[n];
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(n), size used by 'dp' array/vector.
    int fibTabulized(int n)
    {
        // 'dp' array to calculate and store the result of particular subproblem.
        vector<int> dp(n + 1);

        // Base Case
        // The First term of the Fibonacci series is 0.
        dp[0] = 0;

        // The Second term of the Fibonacci series is 1.
        dp[1] = 1;

        // Now, run a loop from 2 to n and find the 'nth' Fibonacci Number.
        for (int i = 2; i <= n; i++)
        {
            // The next term or the nth term of the Fibonacci series is the summation of previous 2 terms.
            // Previous 2 terms are already stored in our 'dp' array.
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // return the 'nth' Fibonacci number.
        return dp[n];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // Using Variable instead of 'dp' array/vector.

    // Time Complexity: O(n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(1).
    int fibSpaceOptimized(int n)
    {
        // The First term of the Fibonacci series is 0.
        int firstTerm = 0;

        // The Second term of the Fibonacci series is 1.
        int secondTerm = 1;

        // and the next term of the fibonacci series is the summation of previous 2 terms.
        int nextTerm = -1;

        // Now, run a loop from 2 to n and find the 'nth' Fibonacci Number.
        for (int i = 2; i <= n; i++)
        {
            // The next term or the nth term of the Fibonacci series is the summation of previous 2 terms.
            nextTerm = firstTerm + secondTerm;

            // Update the pointers.
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }

        // return the 'nth' Fibonacci number.
        return nextTerm;
    }
};

int main(void)
{
    // Our task is to find the nth Fibonacci Number in the Fibonacci Series.
    int n = 10;

    // Solution.
    Solution S;

    cout << n << "th term of Fibonacci Series [Using Recursion] : " << S.fibRecursive(n) << ".\n";

    vector<int> dp(n + 1, -1);
    cout << n << "th term of Fibonacci Series [Using DP Memoization] : " << S.fibMemoized(n, dp) << ".\n";

    cout << n << "th term of Fibonacci Series [Using DP Tabulation] : " << S.fibTabulized(n) << ".\n";

    cout << n << "th term of Fibonacci Series [Space Optimization] : " << S.fibSpaceOptimized(n) << ".\n";

    return 0;
}