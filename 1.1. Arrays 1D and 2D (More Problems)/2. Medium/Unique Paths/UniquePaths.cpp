#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Recursive code to find the the total unique path from top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]). */
    // Time Complexity: O(2^(m*n)), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m+n), recursive stack space.
    int uniquePaths_Recursive(int row, int col)
    {
        // Base Case
        // As I am starting from the bottom-right cell (m-1, n-1), then our destination cell is the top-left cell (0, 0). You can start from the cell (0,0) also but you need to carry 2 more parameters (m and n) to identify the destination cell.

        // As I am starting from the bottom-right cell (m-1, n-1), our destination is fixed i.e., (0,0), so there is no need to carry 2 more variables.
        if (row == 0 && col == 0)
        {
            // when row == 0 && col == 0, it means we reached the destination cell so return 1 from here, where 1 means there exist a path from source to destination and returning 1 means we are counting this path.
            return 1;
        }

        // if row < 0 || col < 0, it means that we have crossed the boundary of the matrix and from here there is no path towards the destination so return 0 from here.
        if (row < 0 || col < 0)
        {
            return 0;
        }

        // Recursive case.

        // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

        // Moving Up.
        int up = uniquePaths_Recursive(row - 1, col);

        // Moving Left.
        int left = uniquePaths_Recursive(row, col - 1);

        // Now, return all possible path by taking up and left from current cell.
        return left + up;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m+n) + O(m*n), recursive stack space and space used by 'dp' vector.
    int uniquePaths_Memoized(int row, int col, vector<vector<int>> &dp)
    {
        // Base Case
        // As I am starting from the bottom-right cell (m-1, n-1), then our destination cell is the top-left cell (0, 0). You can start from the cell (0,0) also but you need to carry 2 more parameters (m and n) to identify the destination cell.

        // As I am starting from the bottom-right cell (m-1, n-1), our destination is fixed i.e., (0,0), so there is no need to carry 2 more variables.
        if (row == 0 && col == 0)
        {
            // when row == 0 && col == 0, it means we reached the destination cell so return 1 from here, where 1 means there exist a path from source to destination and returning 1 means we are counting this path.
            return 1;
        }

        // if row < 0 || col < 0, it means that we have crossed the boundary of the matrix and from here there is no path towards the destination so return 0 from here.
        if (row < 0 || col < 0)
        {
            return 0;
        }

        // Recursive case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

        // Moving Up.
        int up = uniquePaths_Memoized(row - 1, col, dp);

        // Moving Left.
        int left = uniquePaths_Memoized(row, col - 1, dp);

        // Store the answer of this subproblem and then return all possible path by taking up and left from current cell.
        return dp[row][col] = left + up;
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns.
    // Space Complexity: O(m*n), space used by 'dp' vector.
    int uniquePaths_Tabulized(int m, int n)
    {

        // 'dp' vector.
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Base Case

        // when row == 0 && col == 0, it means we reached the destination cell so return 1 from here, where 1 means there exist a path from source to destination and returning 1 means we are counting this path.
        dp[0][0] = 1;

        // Traverse the 'dp' vector.
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // row == 0 && col == 0, This is the base case and we already handeled it.
                if (row == 0 && col == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

                // Moving Up.
                int up = (row - 1 < 0) ? 0 : dp[row - 1][col];

                // Moving Left.
                int left = (col - 1 < 0) ? 0 : dp[row][col - 1];

                // Store the answer of this subproblem.
                dp[row][col] = left + up;
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
    // Space Complexity: O(n) + O(n), space used by 'prevRow' and 'currentRow' vector.
    int uniquePaths_SpaceOptimized(int m, int n)
    {

        // 'prevRow' vector.
        vector<int> prevRow(n);

        // 'currentRow' vector.
        vector<int> currentRow(n);

        // Base Case

        // when row == 0 && col == 0, it means we reached the destination cell so return 1 from here, where 1 means there exist a path from source to destination and returning 1 means we are counting this path.
        currentRow[0] = 1;

        // Traverse the 'dp' vector.
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // row == 0 && col == 0, This is the base case and we already handeled it.
                if (row == 0 && col == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // From each cell we have 2 choices, we can either move right or down. As I am starting from the bottom-right cell (m-1, n-1), at every index we have two choices, one to go up(↑) and the other to go left(←).

                // Moving Up.
                int up = (row - 1 < 0) ? 0 : prevRow[col];

                // Moving Left.
                int left = (col - 1 < 0) ? 0 : currentRow[col - 1];

                // Store the answer of this subproblem.
                currentRow[col] = left + up;
            }

            // after the above loop ends, our current row becomes previous row.
            // So, updated the previous row to current row.
            prevRow = currentRow;
        }

        // return answer.
        return prevRow[n - 1];
    }

public:
    int uniquePaths(int m, int n)
    {

        // // Recursive Solution.
        // return uniquePaths_Recursive(m-1, n-1);

        // // Dynamic Programming (DP) Memoization Solution.
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return uniquePaths_Memoized(m-1, n-1, dp);

        // // Dynamic Programming (DP) Tabulation Solution.
        // return uniquePaths_Tabulized(m, n);

        // Space Optimized Solution.
        return uniquePaths_SpaceOptimized(m, n);
    }
};

int main(void)
{
    int row = 3, col = 7;

    // Solution.
    Solution obj;
    cout << "Total Unique Paths: " << obj.uniquePaths(row, col) << ".";
    return 0;
}