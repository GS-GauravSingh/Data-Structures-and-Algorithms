#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Code to find the maximum path sum. */
    // Time Complexity: O(3^(N*M)), 'N' is the number of rows and 'M' is the number of columns.
    // Space Complexity: O(N), recursive stack space.
    int solveRecursive(int i, int j, int &row, int &col, vector<vector<int>> &matrix)
    {
        // Corner Cases (Check for out of bound).
        if (j < 0 || j >= col)
        {
            // From each cell, we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
            // So, suppose the value of j is 0 and we try to move bottom-left, in this case the value of j becomes -ve and this is invalid.
            // So, return -1e8, because from -ve indexes we cannot find any path to reach the last row.
            // -1e8 will helps us to ignore this path, when we are chosing the path with maximum cost/sum.
            return -1e8;
        }

        // Base Case
        // When i = row-1, it means we reached the last row.
        if (i == row - 1)
        {
            // Simply return the cost of this cell because we have to add the cost of this cell to our path sum.
            return matrix[i][j];
        }

        // Recursive case.

        // At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

        // Bottom Cell.
        int bottom = matrix[i][j] /* adding the cost of current cell. */ + solveRecursive(i + 1, j, row, col, matrix);

        // Bottom-Left Cell.
        int bottomLeft = matrix[i][j] /* adding the cost of current cell. */ + solveRecursive(i + 1, j - 1, row, col, matrix);

        // Bottom-Right Cell.
        int bottomRight = matrix[i][j] /* adding the cost of current cell. */ + solveRecursive(i + 1, j + 1, row, col, matrix);

        // Return the path with maximum sum.
        return max(bottom, max(bottomLeft, bottomRight));
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(N*M), 'N' is the number of rows and 'M' is the number of columns.
    // Space Complexity: O(N) + O(N*M), recursive stack space and size of 'dp' array/vector.
    int solveMemoized(int i, int j, int &row, int &col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // Corner Cases (Check for out of bound).
        if (j < 0 || j >= col)
        {
            // From each cell, we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
            // So, suppose the value of j is 0 and we try to move bottom-left, in this case the value of j becomes -ve and this is invalid.
            // So, return -1e8, because from -ve indexes we cannot find any path to reach the last row.
            // -1e8 will helps us to ignore this path, when we are chosing the path with maximum cost/sum.
            return -1e8;
        }

        // Base Case
        // When i = row-1, it means we reached the last row.
        if (i == row - 1)
        {
            // Simply return the cost of this cell because we have to add the cost of this cell to our path sum.
            return matrix[i][j];
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

        // Bottom Cell.
        int bottom = matrix[i][j] /* adding the cost of current cell. */ + solveMemoized(i + 1, j, row, col, matrix, dp);

        // Bottom-Left Cell.
        int bottomLeft = matrix[i][j] /* adding the cost of current cell. */ + solveMemoized(i + 1, j - 1, row, col, matrix, dp);

        // Bottom-Right Cell.
        int bottomRight = matrix[i][j] /* adding the cost of current cell. */ + solveMemoized(i + 1, j + 1, row, col, matrix, dp);

        // Store the answer of this subproblem and then Return the path with maximum sum.
        return dp[i][j] = max(bottom, max(bottomLeft, bottomRight));
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(N*M), 'N' is the number of rows and 'M' is the number of columns.
    // Space Complexity: O(N*M), size of 'dp' array/vector.
    int solveTabulized(int &row, int &col, vector<vector<int>> &matrix)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Fill the first row of 'dp' vector same as the first row of 'matrix' vector.
        // Because the firs row remains the same (no change).
        for (int j = 0; j < col; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        // Traverse the 'dp' array and find the maximum path sum.
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
                // and we are optimizing this problem using tabulation and tabulation is bottom-up dynamic programming, so we have to move from (0 to n).
                // So from now, At every index we have three choices, 1st is to go to the top cell(⬆), 2nd is to the top-left cell(↖) and 3rd is to go to the top-right(↗) cell.

                // Top Cell.
                int top = matrix[i][j] /* adding the cost of current cell. */ + dp[i - 1][j];

                // Top-Left Cell.
                int topLeft = (j - 1 >= 0) ? (matrix[i][j] /* adding the cost of current cell. */ + dp[i-1][j-1]) : -1e8;

                // Top-Right Cell.
                int topRight = (j + 1 < col) ? (matrix[i][j] /* adding the cost of current cell. */ + dp[i - 1][j + 1]) : -1e8;

                // Store the answer (maximum path) of this subproblem.
                dp[i][j] = max(top, max(topLeft, topRight));
            }
        }

        // Traverse the last row of 'dp' array and return the path with maximum sum.
        int maxSum = INT_MIN;
        for (int j = 0; j < col; j++)
        {
            int sum = dp[row-1][j];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

    /* Space Optimizing the above DP Tabulation code. */
    /* If we closely look the relation,
    dp[i][j] = matrix[i][j] + max(dp[i-1][j],dp[i-1][j-1], dp[i-1][j+1]))
    We see that we only need the previous row, in order to calculate dp[i][j]. Therefore we can space optimize it. */

    // Time Complexity: O(N*M), 'N' is the number of rows and 'M' is the number of columns.
    // Space Complexity: O(M), size of 'dp' array/vector.
    int solveSpaceOptimized(int &row, int &col, vector<vector<int>> &matrix)
    {
        // Previous array, it is used to calculate answers for top, top-left and top-right direction.
        vector<int> prevRow(col, 0);

        // Fill the previous row same as the first row of 'matrix' vector.
        // Because the firs row remains the same (no change).
        for (int j = 0; j < col; j++)
        {
            prevRow[j] = matrix[0][j];
        }

        // Traverse the 'dp' array and find the maximum path sum.
        for (int i = 1; i < row; i++)
        {
            // vector to store answers of current row.
            vector<int> currRow(col, 0);

            for (int j = 0; j < col; j++)
            {
                // At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
                // and we are optimizing this problem using tabulation and tabulation is bottom-up dynamic programming, so we have to move from (0 to n).
                // So from now, At every index we have three choices, 1st is to go to the top cell(⬆), 2nd is to the top-left cell(↖) and 3rd is to go to the top-right(↗) cell.

                // Top Cell.
                int top = matrix[i][j] /* adding the cost of current cell. */ + prevRow[j];

                // Top-Left Cell.
                int topLeft = (j - 1 >= 0) ? (matrix[i][j] /* adding the cost of current cell. */ + prevRow[j-1]) : -1e8;

                // Top-Right Cell.
                int topRight = (j + 1 < col) ? (matrix[i][j] /* adding the cost of current cell. */ + prevRow[j+1]) : -1e8;

                // Store the answer (maximum path) of this subproblem.
                currRow[j] = max(top, max(topLeft, topRight));
            }

            // after the end of above for loop, our prevRow will become currRow.
            prevRow = currRow;
        }

        // Traverse the prevRow array and return the path with maximum sum.
        int maxSum = INT_MIN;
        for (int j = 0; j < col; j++)
        {
            int sum = prevRow[j];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

public:
    /* Question:  We are given an ‘N*M’ matrix. We need to find the maximum path sum from any cell of the first row to any cell of the last row.
    Note: At every cell we can move in three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).*/
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        // Row and column of the matrix.
        int row = matrix.size();
        int col = matrix[0].size();

        // // Recursive Solution.
        // int maxSum = INT_MIN;

        // // Start from each cell of the first row and find the starting cell which gives the maximum path.
        // // and store the maximum.
        // for (int j = 0; j < col; j++)
        // {
        //     int sum = solveRecursive(0, j, row, col, matrix);
        //     cout << sum << endl;
        //     maxSum = max(maxSum, sum);
        // }
        // return maxSum;

        // // DP Memoization Solution.
        // int maxSum = INT_MIN;

        // // Start from each cell of the first row and find the starting cell which gives the maximum path.
        // // and store the maximum.
        // vector<vector<int>> dp(row, vector<int>(col, -1));
        // for (int j = 0; j < col; j++)
        // {
        //     int sum = solveMemoized(0, j, row, col, matrix, dp);
        //     cout << sum << endl;
        //     maxSum = max(maxSum, sum);
        // }
        // return maxSum;

        // // DP Tabulation Solution.
        // return solveTabulized(row, col, matrix);

        // Space Optimized Solution.
        return solveSpaceOptimized(row, col, matrix);
    }
};

int main(void)
{
    vector<vector<int>> matrix{
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1},
    };

    // Solution.
    Solution S;
    cout << "Maximum Path Sum : " << S.getMaxPathSum(matrix) << ".\n";

    return 0;
}