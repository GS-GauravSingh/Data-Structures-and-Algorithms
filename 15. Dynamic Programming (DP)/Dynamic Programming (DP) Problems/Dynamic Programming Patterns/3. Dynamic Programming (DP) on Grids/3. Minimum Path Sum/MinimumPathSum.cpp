#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Code to find the path with minimum cost. */
    // Time Complexity: O(2^(M*N)), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O((M-1)+(N-1)), recursive stack space.
    int solveRecursive(int row, int col, vector<vector<int>> &grid)
    {
        // Base Case
        if (row == 0 && col == 0)
        {
            // if row = 0 && col = 0, it means we reached the destination cell.
            // When row = 0 and col = 0, this means that we have reached the destination cell, hence we return the cost of the destination cell.
            return grid[0][0];
        }

        // Checking for out of bounds.
        // When row < 0 and col < 0, it means that we have crossed the boundary of the matrix and we don’t want to find a path from here, so we return a very large number( say, 1e8) so that this path is rejected by the calling function.
        if (row < 0 || col < 0)
        {
            return 1e8;
        }

        // Recursive Case
        // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
        // Moving left.
        // Add the cost of current cell and the move left.
        int left = grid[row][col] + solveRecursive(row, col - 1, grid);

        // Moving up.
        // Add the cost of current cell and the move up.
        int up = grid[row][col] + solveRecursive(row - 1, col, grid);

        // return the minimum path.
        return min(left, up);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(M*N), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O((M-1)+(N-1)) + O(M*N), recursive stack space and size of dp array.
    int solveMemoized(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // Base Case
        if (row == 0 && col == 0)
        {
            // if row = 0 && col = 0, it means we reached the destination cell.
            // When row = 0 and col = 0, this means that we have reached the destination cell, hence we return the cost of the destination cell.
            return grid[0][0];
        }

        // Checking for out of bounds.
        // When row < 0 and col < 0, it means that we have crossed the boundary of the matrix and we don’t want to find a path from here, so we return a very large number( say, 1e8) so that this path is rejected by the calling function.
        if (row < 0 || col < 0)
        {
            return 1e8;
        }

        // Recursive Case

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
        // Moving left.
        // Add the cost of current cell and the move left.
        int left = grid[row][col] + solveMemoized(row, col - 1, grid, dp);

        // Moving up.
        // Add the cost of current cell and the move up.
        int up = grid[row][col] + solveMemoized(row - 1, col, grid, dp);

        // store the answer of this subproble and then return the minimum path.
        return dp[row][col] = min(left, up);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(M*N), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(M*N), size of dp array.
    int solveTabulized(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Base Case
        // When row = 0 and col = 0, this means that we are at the destination cell, hence we return the cost of the destination cell.
        dp[0][0] = grid[0][0];

        // Loop to traverse the grid.
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

                // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
                // variables.
                int left = 0;
                int up = 0;

                // Up.
                // When i == 0, in this case, we only move in one direction, which is left. But if we move up then we end up reaching negative indexes that's why we cannot move up when i = 0.

                // That's why we only move up, when i > 0.
                if (i > 0)
                {
                    up = grid[i][j] /* add the cost of current cell. */ + dp[i-1][j];
                }
                else{
                    // If we move up then we end up reaching negative indexes that's why we cannot move up when i = 0. SO we have to ignore this path. Thats why we add 1e8. so that this path is rejected autumatically while chossing the minimum path.
                    up = grid[i][j] /* add the cost of current cell. */ + 1e8;

                }

                // Left.
                // When j == 0, in this case, we only move in one direction, which is up. But if we move left then we end up reaching negative indexes that's why we cannot move left when j = 0.

                // That's why we only move left, when j > 0.
                if (j > 0)
                {
                    left = grid[i][j] /* add the cost of current cell. */ + dp[i][j-1];
                }
                else{
                    // If we move left then we end up reaching negative indexes that's why we cannot move left when j = 0. So we have to ignore this path. Thats why we add 1e8. so that this path is rejected autumatically while chossing the minimum path.
                    left = grid[i][j] /* add the cost of current cell. */ + 1e8;

                }

                // from cell (i, j), store the minimum path to reach the destination cell.
                dp[i][j] = min(up, left);

            }
        }

        // return the path with minimum cost.
        return dp[row-1][col-1];
    }

    /* Space Optimizing the above DP Tabulation code. */
    /* If we closely look at the relation,
    dp[i][j] = matrix[i][j] + min(dp[i-1][j] + dp[i][j-1]))
    We see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it. */

    // Time Complexity: O(M*N), 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(N), size of dp array, N is the number of columns.
    int solveSpaceOptimized(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // vector for previous row, it is used to calculate answers for 'up' direction.
        vector<int> prevRow(col, 0);

        // Loop to traverse the grid.
        for (int i = 0; i < row; i++)
        {
            // vector for current row, it is used to calculate answers for 'left' direction.
            vector<int> currRow(col, 0);

            for (int j = 0; j < col; j++)
            {
                // This is the base case.
                if (i == 0 && j == 0)
                {
                    currRow[j] = grid[0][0];
                    continue;
                }

                // From each cell we have 2 choices, we can either move right or down. As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←).
                // variables.
                int left = 0;
                int up = 0;

                // Up.
                // When i == 0, in this case, we only move in one direction, which is left. But if we move up then we end up reaching negative indexes that's why we cannot move up when i = 0.

                // That's why we only move up, when i > 0.
                if (i > 0)
                {
                    up = grid[i][j] /* add the cost of current cell. */ + prevRow[j];
                }
                else{
                    // If we move up then we end up reaching negative indexes that's why we cannot move up when i = 0. SO we have to ignore this path. Thats why we add 1e8. so that this path is rejected autumatically while chossing the minimum path.
                    up = grid[i][j] /* add the cost of current cell. */ + 1e8;

                }

                // Left.
                // When j == 0, in this case, we only move in one direction, which is up. But if we move left then we end up reaching negative indexes that's why we cannot move left when j = 0.

                // That's why we only move left, when j > 0.
                if (j > 0)
                {
                    left = grid[i][j] /* add the cost of current cell. */ + currRow[j-1];
                }
                else{
                    // If we move left then we end up reaching negative indexes that's why we cannot move left when j = 0. So we have to ignore this path. Thats why we add 1e8. so that this path is rejected autumatically while chossing the minimum path.
                    left = grid[i][j] /* add the cost of current cell. */ + 1e8;

                }

                // from cell (i, j), store the minimum path to reach the destination cell.
                currRow[j] = min(up, left);

            }

            prevRow = currRow;
        }

        // return the path with minimum cost.
        return prevRow[col-1];
    }

public:
    /* Question: We are given an “N*M” matrix of integers. Each cell (i, j) in the matrix has some costs asscociated with it. We need to find a path with minimum cost from the top-left (0, 0) corner to the bottom-right (N-1, M-1) corner of the matrix.

    Note: You can only move down or right at any point of time.
    */
    int minSumPath(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // Corner Case (when grid only contains single element).
        if (row == 1 && col == 1)
        {
            return grid[0][0];
        }

        // // Recursive Solution.
        // return solveRecursive(row - 1, col - 1, grid);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(row, vector<int>(col, -1));
        // return solveMemoized(row-1, col-1, grid, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(grid);

        // Space Optimized Solution.
        return solveSpaceOptimized(grid);

    }
};

int main(void)
{
    vector<vector<int>> matrix{{5, 9, 6},
                               {11, 5, 2}};

    int row = matrix.size();
    int col = matrix[0].size();

    // Solution.
    Solution S;
    cout << "Minimum Cost : " << S.minSumPath(matrix) << ".\n";

    return 0;
}