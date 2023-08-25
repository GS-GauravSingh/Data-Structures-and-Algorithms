#include <bits/stdc++.h>
using namespace std;

// Macro.
#define INF 1e5

class Solution
{

    // Recursive Solution to find the path with minimum sum.
    // Time Complexity: O(2^(m*n)), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m+n), recursive stack space.
    int minPathSum_Recursive(int row, int col, vector<vector<int>> &grid)
    {
        // Base Case

        if (row == 0 && col == 0)
        {
            // when row == 0 && col == 0, it means we reached the destination cell so return the value present at this cell, because we need to calculate the sum of this path.
            return grid[0][0];
        }

        // if row < 0 || col < 0, it means that we have crossed the boundary of the matrix and from here there is no path towards the destination so return a larger value from here, because we need to find the path with minimum sum and larger value will help us to skip this path.
        if (row < 0 || col < 0)
        {
            return INF;
        }

        // Recursive case.

        // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

        // Moving Up.
        // Add the cost of current cell and the move up.
        int up = grid[row][col] + minPathSum_Recursive(row - 1, col, grid);

        // Moving Left.
        // Add the cost of current cell and the move left.
        int left = grid[row][col] + minPathSum_Recursive(row, col - 1, grid);

        // Now, return the path with minimum sum.
        return min(left, up);
    }

    // Optimizing the above Recursive Solution using Dynamic Programming - Memoiozation.
    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m+n) + O(m*n), recursive stack space and space used by 'dp' vector.
    int minPathSum_Memoized(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // Base Case

        if (row == 0 && col == 0)
        {
            // when row == 0 && col == 0, it means we reached the destination cell so return the value present at this cell, because we need to calculate the sum of this path.
            return grid[0][0];
        }

        // if row < 0 || col < 0, it means that we have crossed the boundary of the matrix and from here there is no path towards the destination so return a larger value from here, because we need to find the path with minimum sum and larger value will help us to skip this path.
        if (row < 0 || col < 0)
        {
            return INF;
        }

        // Recursive case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

        // Moving Up.
        // Add the cost of current cell and the move up.
        int up = grid[row][col] + minPathSum_Memoized(row - 1, col, grid, dp);

        // Moving Left.
        // Add the cost of current cell and the move left.
        int left = grid[row][col] + minPathSum_Memoized(row, col - 1, grid, dp);

        // Store the answer of this subproblem and then return the path with minimum sum.
        return dp[row][col] = min(left, up);
    }

    // Space Optimizing the above DP Memoization Solution using Dynamic Programming - Tabulation.
    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m*n), space used by 'dp' vector.
    int minPathSum_Tabulation(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int m = grid.size();
        int n = grid[0].size();

        // 'dp' vector.
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base Case

        // when row == 0 && col == 0, it means we reached the destination cell so return the value present at this cell, because we need to calculate the sum of this path.
        dp[0][0] = grid[0][0];

        // Traverse the 'dp' vector.
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // This is the Base case and we already handeled it.
                if (row == 0 && col == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

                // Moving Up.
                // Add the cost of current cell and the move up.
                int up = grid[row][col] + ((row - 1 < 0) ? INF : dp[row - 1][col]);

                // Moving Left.
                // Add the cost of current cell and the move left.
                int left = grid[row][col] + ((col - 1 < 0) ? INF : dp[row][col - 1]);

                // Store the answer of this subproblem and then return the path with minimum sum.
                dp[row][col] = min(left, up);
            }
        }

        // return answer.
        return dp[m - 1][n - 1];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // If we closely look at the relationship,
    // dp[i][j] = dp[i-1][j] + dp[i][j-1])
    // We see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.

    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(n) + O(n), space used by 'prevRow' and 'currRow' vector.
    int minPathSum_SpaceOptimized(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int m = grid.size();
        int n = grid[0].size();

        // 'prevRow' vector.
        vector<int> prevRow(n);

        // 'currRow' vector.
        vector<int> currRow(n);

        // Base Case

        // when row == 0 && col == 0, it means we reached the destination cell so return the value present at this cell, because we need to calculate the sum of this path.
        currRow[0] = grid[0][0];

        // Traverse the 'dp' vector.
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // This is the Base case and we already handeled it.
                if (row == 0 && col == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

                // Moving Up.
                // Add the cost of current cell and the move up.
                int up = grid[row][col] + ((row - 1 < 0) ? INF : prevRow[col]);

                // Moving Left.
                // Add the cost of current cell and the move left.
                int left = grid[row][col] + ((col - 1 < 0) ? INF : currRow[col - 1]);

                // Store the answer of this subproblem and then return the path with minimum sum.
                currRow[col] = min(left, up);
            }

            // After the above loop ends, our current row becomes previous row.
            // So, set prevRow = currRow.
            prevRow = currRow;
        }

        // return answer.
        return prevRow[n - 1];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {

        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // // Recursive SOlution.
        // return minPathSum_Recursive(row - 1, col - 1, grid);

        // // DP Memoization SOlution.
        // vector<vector<int>> dp(row, vector<int> (col, -1));
        // return minPathSum_Memoized(row - 1, col - 1, grid, dp);

        // // DP Tabulation Solution.
        // return minPathSum_Tabulation(grid);

        // Space Optimized Solution.
        return minPathSum_SpaceOptimized(grid);
    }
};

int main(void)
{
    vector<vector<int>> grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    // Solution.
    Solution obj;
    cout << "Minimum Path Sum: " << obj.minPathSum(grid) << ".";
    return 0;
}