#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Solution to find the maximum number of chocolates that Bob and Alice can together collect. */
    // Time Complexity: O(3^n * 3^n), where 'n' is the number of rows.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int i, int j1, int j2, int &row, int &col, vector<vector<int>> &grid)
    {
        // Now, At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙).

        // To move to the bottom-right cell(↘) or to the bottom-left cell(↙), it can happen that we may go out of bound. So we need to handle it, we can return -1e8, whenever we go out of bound, in this way this path will not be selected by the calling function as we have to return the maximum chocolates.
        if (j1 < 0 || j1 > col - 1 || j2 < 0 || j2 > col - 1)
        {
            return -1e8;
        }

        // Base Case
        // When i = row - 1, it means we reached the last row. So, return the number of chocolates.
        if (i == row - 1)
        {
            // Now it can happen that at the last row, both Alice and Bob are at the same cell, in this condition, only one of them is allowed to collect the chocolates, so we will return only chocolates collected by Alice, mat[i][j1]( as question states that the chocolates cannot be doubly calculated).
            if (j1 == j2)
            {
                return grid[i][j1];
            }

            // Now it can happen that at the last row, both Alice and Bob are at the different cell, in this condition, both of them will collect the chocolate and we return the summation of chocolates collected by both of them.
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }

        // Recursive Case.

        // Explore all paths.
        int maxChocolate = INT_MIN;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int sum = 0;

                if (j1 == j2)
                {
                    sum = grid[i][j1] + solveRecursive(i + 1, j1 + di, j2 + dj, row, col, grid);
                }
                else
                {
                    sum = grid[i][j1] + grid[i][j2] + solveRecursive(i + 1, j1 + di, j2 + dj, row, col, grid);
                }

                maxChocolate = max(maxChocolate, sum);
            }
        }

        return maxChocolate;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n * m * m) * 9, where 'n' is the number of rows and 'm' is the number of columns.
    // Space Complexity: O(n) + O(n*m*m), recursive stack space and size of 'dp' array.
    int solveMemoized(int i, int j1, int j2, int &row, int &col, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        // Now, At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙).

        // To move to the bottom-right cell(↘) or to the bottom-left cell(↙), it can happen that we may go out of bound. So we need to handle it, we can return -1e8, whenever we go out of bound, in this way this path will not be selected by the calling function as we have to return the maximum chocolates.
        if (j1 < 0 || j1 > col - 1 || j2 < 0 || j2 > col - 1)
        {
            return -1e8;
        }

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        // Base Case
        // When i = row - 1, it means we reached the last row. So, return the number of chocolates.
        if (i == row - 1)
        {
            // Now it can happen that at the last row, both Alice and Bob are at the same cell, in this condition, only one of them is allowed to collect the chocolates, so we will return only chocolates collected by Alice, mat[i][j1]( as question states that the chocolates cannot be doubly calculated).
            if (j1 == j2)
            {
                return grid[i][j1];
            }

            // Now it can happen that at the last row, both Alice and Bob are at the different cell, in this condition, both of them will collect the chocolate and we return the summation of chocolates collected by both of them.
            else
            {
                return (grid[i][j1] + grid[i][j2]);
            }
        }

        // Recursive Case.

        // Explore all paths.
        int maxChocolate = INT_MIN;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int sum = 0;

                if (j1 == j2)
                {
                    sum = grid[i][j1] + solveMemoized(i + 1, j1 + di, j2 + dj, row, col, grid, dp);
                }
                else
                {
                    sum = grid[i][j1] + grid[i][j2] + solveMemoized(i + 1, j1 + di, j2 + dj, row, col, grid, dp);
                }

                maxChocolate = max(maxChocolate, sum);
            }
        }

        return dp[i][j1][j2] = maxChocolate;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * m * m) * 9, where 'n' is the number of rows and 'm' is the number of columns.
    // Space Complexity: O(n*m*m), recursive stack space and size of 'dp' array.
    int solveTabulized(int &row, int &col, vector<vector<int>> &grid)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, 0)));

        // First we need to convert the base case.
        for (int j1 = 0; j1 < col; j1++)
        {
            for (int j2 = 0; j2 < col; j2++)
            {
                if (j1 == j2)
                {
                    dp[row - 1][j1][j2] = grid[row - 1][j1];
                }
                else
                {
                    dp[row - 1][j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
                }
            }
        }

        // Outer 3 loops used for traversing dp array.
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    // Explore all paths.
                    int maxChocolate = INT_MIN;
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            int sum = 0;

                            if (j1 == j2)
                            {
                                sum = grid[i][j1];
                            }
                            else
                            {
                                sum = grid[i][j1] + grid[i][j2];
                            }

                            // check for out of bound.
                            if (j1 + di < 0 || j1 + di > col - 1 || j2 + di < 0 || j2 + dj > col - 1)
                            {
                                sum += -1e8;
                            }
                            else
                            {
                                sum += dp[i + 1][j1 + di][j2 + dj];
                            }

                            maxChocolate = max(maxChocolate, sum);
                        }
                    }

                    dp[i][j1][j2] = maxChocolate;
                }
            }
        }

        return dp[0][0][col-1];
    }

    /* Space Optimizing above DP Tabulation Code. */
    // Time Complexity: O(n * m * m) * 9, where 'n' is the number of rows and 'm' is the number of columns.
    // Space Complexity: O(m*m) + O(m*m), size of 'currRow' and 'prevRow' array.
    int solveSpaceOptimized(int &row, int &col, vector<vector<int>> &grid)
    {
        // prevRow vector.
        vector<vector<int>> prevRow(col, vector<int>(col, 0));

        vector<vector<int>> currRow(col, vector<int>(col, 0));

        // First we need to convert the base case.
        for (int j1 = 0; j1 < col; j1++)
        {
            for (int j2 = 0; j2 < col; j2++)
            {
                if (j1 == j2)
                {
                    prevRow[j1][j2] = grid[row - 1][j1];
                }
                else
                {
                    prevRow[j1][j2] = grid[row - 1][j1] + grid[row - 1][j2];
                }
            }
        }

        // Outer 3 loops used for traversing dp array.
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < col; j1++)
            {
                for (int j2 = 0; j2 < col; j2++)
                {
                    // Explore all paths.
                    int maxChocolate = INT_MIN;
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            int sum = 0;

                            if (j1 == j2)
                            {
                                sum = grid[i][j1];
                            }
                            else
                            {
                                sum = grid[i][j1] + grid[i][j2];
                            }

                            // check for out of bound.
                            if (j1 + di < 0 || j1 + di > col - 1 || j2 + di < 0 || j2 + dj > col - 1)
                            {
                                sum += -1e8;
                            }
                            else
                            {
                                sum += prevRow[j1 + di][j2 + dj];
                            }

                            maxChocolate = max(maxChocolate, sum);
                        }
                    }

                    currRow[j1][j2] = maxChocolate;
                }
            }
            prevRow = currRow;
        }

        return prevRow[0][col-1];
    }

public:
    /* Question: We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

    When Alica and Bob visit a cell, they take all the chocolates from that cell with them, and then the number of chocolates in that cell will become zero. If both stay in the same cell, then only one of them will pick the chocolates.

    They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect. */
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {
        // // Recursive Solution.
        // return solveRecursive(0, 0, c - 1, r, c, grid);

        // // DP Memoization Solution.
        // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        // return solveMemoized(0, 0, c - 1, r, c, grid, dp);

        // // DP Tabulation SOlution.
        // return solveTabulized(r, c, grid);

        // Space Optimized Solution.
        return solveSpaceOptimized(r, c, grid);
    }

};

int main(void)
{
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int row = matrix.size();
    int col = matrix[0].size();

    // Solution.
    Solution S;
    cout << "Maximum Chocolate : " << S.maximumChocolates(row, col, matrix) << ".\n";

    return 0;
}