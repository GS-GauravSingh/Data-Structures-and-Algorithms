#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive code to find the the total unique path from top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]). */
    // Time Complexity: O(2^(M*N)), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O((M-1)+(N-1)), recursive stack space.
    int solveRecursive(int row, int col)
    {
        // Base Case
        if (row == 0 && col == 0)
        {
            // if row = 0 && col = 0, it means we reached the destination cell.
            // When row = 0 and col = 0, this means that we have reached the destination so we can count the current path that is going on, hence we return 1.
            return 1;
        }

        // Checking for out of bounds.
        // When row < 0 and col < 0, it means that we have crossed the boundary of the matrix and we couldn’t find a right path, hence we return 0.
        if (row < 0 || col < 0)
        {
            // when this condition becomes true, it means we have not reached the destination cell and we are going out of the grid.
            // so return 0 from here.
            return 0;
        }

        // Recursive case.

        // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
        // Moving left.
        int left = solveRecursive(row, col - 1);

        // Moving up.
        int up = solveRecursive(row - 1, col);

        // return all the possible path you find by taking left and up.
        return left + up;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(M*N), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O((M-1)+(N-1)) + O(M*N), recursive stack space and size of dp array.
    int solveMemoized(int row, int col, vector<vector<int>> &dp)
    {
        // Base Case
        if (row == 0 && col == 0)
        {
            // if row = 0 && col = 0, it means we reached the destination cell.
            // When row = 0 and col = 0, this means that we have reached the destination so we can count the current path that is going on, hence we return 1.
            return 1;
        }

        // Checking for out of bounds.
        // When row < 0 and col < 0, it means that we have crossed the boundary of the matrix and we couldn’t find a right path, hence we return 0.
        if (row < 0 || col < 0)
        {
            // when this condition becomes true, it means we have not reached the destination cell and we are going out of the grid.
            // so return 0 from here.
            return 0;
        }

        // Recursive case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
        // Moving left.
        int left = solveMemoized(row, col - 1, dp);

        // Moving up.
        int up = solveMemoized(row - 1, col, dp);

        // store the answer of this subproblem and then return all the possible path you find by taking left and up.
        return dp[row][col] = left + up;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(M*N), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity:O(M*N), size of dp array.
    int solveTabulized(int row, int col)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // When row = 0 && col = 0, it means we are at the destination cell.
        // So, set dp[0][0] = 1.
        dp[0][0] = 1;

        // traverse the dp array.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // This is the base case and we already handeled it.
                if (i == 0 && j == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // variables.
                int up = 0;
                int left = 0;

                // Up.
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }

                // Left.
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }

                // from cell (i, j), up+left is the total unique paths to reach the destination cell (0, 0).
                dp[i][j] = up + left;
            }
        }

        // return all unique paths.
        return dp[row - 1][col - 1];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // If we closely look at the relationship,
    // dp[i][j] = dp[i-1][j] + dp[i][j-1])
    // We see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.
    int solveSpaceOptimized(int row, int col)
    {
        vector<int> prevRow(col, 0);

        // traverse the dp array.
        for (int i = 0; i < row; i++)
        {
            vector<int> currRow(col, 0);

            for (int j = 0; j < col; j++)
            {
                // This is the base case.
                if (i == 0 && j == 0)
                {
                    currRow[j] = 1;
                    continue;
                }

                // variables.
                int up = 0;
                int left = 0;

                // Up.
                if (i > 0)
                {
                    up = prevRow[j];
                }

                // Left.
                if (j > 0)
                {
                    left = currRow[j - 1];
                }

                // from cell (i, j), up+left is the total unique paths to reach the destination cell (0, 0).
                currRow[j] = up + left;
            }

            prevRow = currRow;
        }

        return prevRow[col - 1];
    }

public:
    /* Question: Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]). */
    int uniquePaths(int m, int n)
    {
        // // Recursive Solution.
        // return solveRecursive(m - 1, n - 1);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveMemoized(m - 1, n - 1, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(m, n);

        // Space Optimized Solution.
        return solveSpaceOptimized(m, n);
    }
};

int main(void)
{
    int m = 3;
    int n = 2;

    // Solution.
    Solution S;
    cout << "Unique Paths : " << S.uniquePaths(m, n) << ".\n";
    return 0;
}