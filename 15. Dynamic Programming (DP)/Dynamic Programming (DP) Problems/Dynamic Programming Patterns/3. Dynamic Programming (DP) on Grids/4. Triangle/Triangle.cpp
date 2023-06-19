#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Code to find the path with minimum cost. */
    // Time Complexity: O(2^N), 'n' is the number of rows.
    // Space Complexity: O(N), recursive stack space.
    int solveRecursive(int i, int j, int n, vector<vector<int>> &triangle)
    {
        // Base Case.
        // When i == N-1, it means we have reached the last row, so we have to includ the cost of destination cell, so return the cost of this cell.
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        // Recursive Case.
        // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).

        // Bottom.
        int bottom = triangle[i][j] /* add the cost of current cell. */ + solveRecursive(i + 1, j, n, triangle);

        // Bottom Right.
        int bottom_right = triangle[i][j] /* add the cost of current cell. */ + solveRecursive(i + 1, j + 1, n, triangle);

        // As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(down and diagonal).
        return min(bottom, bottom_right);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(N*N), 'n' is the number of rows.
    // Space Complexity: O(N) + O(N*N), recursive stack space and size of dp array.
    int solveMemoized(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        // Base Case.
        // When i == N-1, it means we have reached the last row, so we have to includ the cost of destination cell, so return the cost of this cell.
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).

        // Bottom.
        int bottom = triangle[i][j] /* add the cost of current cell. */ + solveMemoized(i + 1, j, n, triangle, dp);

        // Bottom Right.
        int bottom_right = triangle[i][j] /* add the cost of current cell. */ + solveMemoized(i + 1, j + 1, n, triangle, dp);

        // As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(down and diagonal).

        // store the answer of this subproblem and then return the minimum.
        return dp[i][j] = min(bottom, bottom_right);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(N*N), 'n' is the number of rows.
    // Space Complexity: O(N*N), size of dp array.
    int solveTabulized(int n, vector<vector<int>> &triangle)
    {
        // 'dp' array/vector to store and compute the answer of subproblems.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base Case.
        // When i = 0 and j = 0, it means we have reached the first row and this is a triangle, so first row contains only single element, so we have to include the cost of this cell. So dp[0][0] = triangle[0][0].
        dp[0][0] = triangle[0][0];

        for (int i = 0; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                // This is the base case and we already handeled it.
                if (i == 0 && j == 0)
                {
                    // so simply move to next case.
                    continue;
                }

                // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).
                // and we are optimizing this problem using tabulation and tabulation is bottom-up dynamic programming, so we have to move from (0 to n).
                // So from now, At every index we have two choices, one to go to the top cell(⬆) other to the top-left cell(↖).
                int top = 0;
                int top_left = 0;

                // Top.
                // Last element of current row cannot move in upward direction because this is a triangle.
                if (j != triangle[i].size() - 1)
                {
                    top = triangle[i][j] /* add the cost of current cell. */ + dp[i - 1][j];
                }
                else
                {
                    // when the case of last element arise, in this case, we add 1e8 in our top, so that it will automatically ignore while chosing the minimum path.
                    top = triangle[i][j] /* add the cost of current cell. */ + 1e8;
                }

                // Top Right.
                // First element of current row cannot move in top-right direction because this is a triangle.
                if (j != 0)
                {
                    top_left = triangle[i][j] /* add the cost of current cell. */ + dp[i - 1][j - 1];
                }
                else
                {
                    // when the case of first element arise, in this case, we add 1e8 in our top_left, so that it will automatically ignore while chosing the minimum path.
                    top_left = triangle[i][j] /* add the cost of current cell. */ + 1e8;
                }

                // store the minimum to path current cell to cell (0,0).
                dp[i][j] = min(top, top_left);
            }
        }


        // returning the minimum path.
        int minPath = INT_MAX;
        for (int i = 0; i < dp[n - 1].size(); i++)
        {
            minPath = min(minPath, dp[n - 1][i]);
        }
        return minPath;
    }

    /* Space Optimizing the above DP Tabulation code. */
    /* If we closely look the relation,
    dp[i][j] = matrix[i][j] + min(dp[i-1][j] + dp[i-1][j-1]))
    We see that we only need the previous row, in order to calculate dp[i][j]. Therefore we can space optimize it. */

    // Time Complexity: O(N*N), 'n' is the number of rows.
    // Space Complexity: O(N), size of dp array.
    int solveSpaceOptimized(int n, vector<vector<int>> &triangle)
    {
        // Previous array, it is used to calculate answers for top and top-left direction.
        vector<int> prevRow(n, 0);


        for (int i = 0; i < triangle.size(); i++)
        {
            // vector to store answers of current row.
            vector<int> currRow(n, 0);

            for (int j = 0; j < triangle[i].size(); j++)
            {
                // This is the base case.
                if (i == 0 && j == 0)
                {
                    currRow[0] = triangle[0][0];
                    continue;
                }

                // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).
                // and we are optimizing this proble using tabulation and tabulation is bottom-up dynamic programming, so we have to move from (0 to n).
                // So from now, At every index we have two choices, one to go to the top cell(⬆) other to the top-left cell(↖).
                int top = 0;
                int top_left = 0;

                // Top.
                // Last element of current row cannot move in upward direction because this is a triangle.
                if (j != triangle[i].size() - 1)
                {
                    top = triangle[i][j] /* add the cost of current cell. */ + prevRow[j];
                }
                else
                {
                    // when the case of last element arise, in this case, we add 1e8 in our top, so that it will automatically ignore while chosing the minimum path.
                    top = triangle[i][j] /* add the cost of current cell. */ + 1e8;
                }

                // Top Right.
                // First element of current row cannot move in top-right direction because this is a triangle.
                if (j != 0)
                {
                    top_left = triangle[i][j] /* add the cost of current cell. */ + prevRow[j-1];
                }
                else
                {
                    // when the case of first element arise, in this case, we add 1e8 in our top_left, so that it will automatically ignore while chosing the minimum path.
                    top_left = triangle[i][j] /* add the cost of current cell. */ + 1e8;
                }

                // store the minimum to path current cell to cell (0,0).
                currRow[j] = min(top, top_left);
            }

            // after the end of above for loop, our prevRow will become currRow.
            prevRow = currRow;
        }


        // returning the minimum path.
        int minPath = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            minPath = min(minPath, prevRow[i]);
        }
        return minPath;
    }

public:
    /* Question: We are given an "Triangular" matrix of integers. Each cell (i, j) in the matrix has some costs asscociated with it. We need to find a path with minimum cost from the top-row to the bottom-row of the matrix.

    Note: At every cell we can move in only two directions: either to the bottom cell (↓) or to the bottom-right cell(↘)
    */
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {
        // // Recursive Solution.
        // return solveRecursive(0, 0, n, triangle);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMemoized(0, 0, n, triangle, dp);

        // DP Tabulation SOlution.
        return solveTabulized(n, triangle);
    }
};

int main(void)
{
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};

    int row = triangle.size();

    // Solution.
    Solution S;
    cout << "Cost of Minimum Path : " << S.minimumPathSum(triangle, row) << ".\n";

    return 0;
}