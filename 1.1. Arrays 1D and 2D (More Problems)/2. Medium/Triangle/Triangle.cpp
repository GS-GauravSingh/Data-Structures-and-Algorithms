#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Recursive Code to find the path with minimum cost. */
    // Time Complexity: O(2^(n*(n+1)/2)), where 'n' is the number of rows in the triangle. We have total (n*(n+1)/2) elements in the triangle and for each element we have couple of options, one to go to the bottom cell(↓) other to the bottom-right cell(↘). That's why the TC is O(2^(n*(n+1)/2)).
    // Space Complexity: O(n), recursive stack space.
    int minimumCostPath_Recursive(int i, int j, vector<vector<int>> &triangle)
    {
        // Base Case
        // When i == triangle.size() - 1, it means we have reached the last row, so we have to include the cost of destination cell, so return the cost of this cell.
        if (i == triangle.size() - 1)
        {
            return triangle[i][j];
        }

        // Recursive Case.
        // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).

        // Bottom.
        int bottom = triangle[i][j] /* add the cost of current cell. */ + minimumCostPath_Recursive(i + 1, j, triangle);

        // Bottom Right.
        int bottom_right = triangle[i][j] /* add the cost of current cell. */ + minimumCostPath_Recursive(i + 1, j + 1, triangle);

        // As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(down and diagonal).
        return min(bottom, bottom_right);
    }

    /* Optimizing above Recursive Code using Dynamic Programming - Memoization. */
    // Time Complexity: O(n*(n+1)/2), where 'n' is the number of rows in the triangle.
    // Space Complexity: O(n) + O(n*n), recursive stack space and space used by 'dp' vector.
    int minimumCostPath_Memoized(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        // Base Case
        // When i == triangle.size() - 1, it means we have reached the last row, so we have to include the cost of destination cell, so return the cost of this cell.
        if (i == triangle.size() - 1)
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
        int bottom = triangle[i][j] /* add the cost of current cell. */ + minimumCostPath_Memoized(i + 1, j, triangle, dp);

        // Bottom Right.
        int bottom_right = triangle[i][j] /* add the cost of current cell. */ + minimumCostPath_Memoized(i + 1, j + 1, triangle, dp);

        // As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(down and diagonal).
        // Before returning, First store the answer of this subproblem.
        return dp[i][j] = min(bottom, bottom_right);
    }

    /* Optimizing above Dynamic Programming - Memoization Code using Dynamic Programming - Tabulation. */
    // Time Complexity: O(n*(n+1)/2), where 'n' is the number of rows in the triangle.
    // Space Complexity: O(n*n), space used by 'dp' vector.
    int minimumCostPath_Tabulized(vector<vector<int>> &triangle)
    {
        // 'dp' vector.
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

        // Base Case
        // When i == triangle.size() - 1, it means we have reached the last row, so we have to include the cost of destination cell, so return the cost of this cell.
        for (int j = 0; j < triangle.size(); j++)
        {
            dp[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];
        }

        // Traverse the 'dp' vector.

        // Start traversing from second last row, because we already handeled the case of last row (it's a base case).
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).

                // Bottom.
                int bottom = triangle[i][j] /* add the cost of current cell. */ + dp[i + 1][j];

                // Bottom Right.
                int bottom_right = triangle[i][j] /* add the cost of current cell. */ + dp[i + 1][j + 1];

                // First store the answer of this subproblem.
                dp[i][j] = min(bottom, bottom_right);
            }
        }

        return dp[0][0];
    }

    /* Space Optimizing the above DP Tabulation code. */
    /* If we closely look the relation,
    dp[i][j] = matrix[i][j] + min(dp[i+1][j] + dp[i+1][j+1]))
    We see that we only need the next row, in order to calculate the answers for current row 'dp[i][j]'. Therefore we can space optimize it. */

    // Time Complexity: O(n*(n+1)/2), where 'n' is the number of rows in the triangle.
    // Space Complexity: O(n) + O(n), space used by 'nextRow' and 'currRow' vector.
    int minimumCostPath_SpaceOptimized(vector<vector<int>> &triangle)
    {
        // 'nextRow' vector.
        vector<int> nextRow(triangle.size(), 0);

        // 'currRow' vector.
        vector<int> currRow(triangle.size());

        // Base Case
        // When i == triangle.size() - 1, it means we have reached the last row, so we have to include the cost of destination cell, so return the cost of this cell.
        for (int j = 0; j < triangle.size(); j++)
        {
            nextRow[j] = triangle[triangle.size() - 1][j];
        }

        // Traverse the 'dp' vector.

        // Start traversing from second last row, because we already handeled the case of last row (it's a base case).
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                // At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘).

                // Bottom.
                int bottom = triangle[i][j] /* add the cost of current cell. */ + nextRow[j];

                // Bottom Right.
                int bottom_right = triangle[i][j] /* add the cost of current cell. */ + nextRow[j + 1];

                // First store the answer of this subproblem.
                currRow[j] = min(bottom, bottom_right);
            }

            // After the above loop ends, our current row become next row.
            nextRow = currRow;
        }

        return nextRow[0];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        // // Recursive Solution.
        // return minimumCostPath_Recursive(0, 0, triangle);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        // return minimumCostPath_Memoized(0, 0, triangle, dp);

        // // DP Tabulation Solution.
        // return minimumCostPath_Tabulized(triangle);

        // Space Optimized Solution.
        return minimumCostPath_SpaceOptimized(triangle);
    }
};

int main(void)
{
    vector<vector<int>> triangle{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };

    // SOlution.
    Solution obj;
    cout << "Minimum Cost Path: " << obj.minimumTotal(triangle) << ".";
    return 0;
}