#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search Algorithm (DFS). */
    void DepthFirstSearch(int startRow, int startCol, int &row, int &col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        // Mark this starting cell as visited.
        visited[startRow][startCol] = true;

        // For this question there is no need for printing or storing nodes.

        // Make a dfs call for all the 8 neighbors only when the neighbors is not visited and the neighbors is not water.
        for (int rowRange = -1; rowRange <= 1; rowRange++)
        {
            for (int colRange = -1; colRange <= 1; colRange++)
            {
                // Index of neighbors.
                int neighborRowIdx = startRow + rowRange;
                int neighborColIdx = startCol + colRange;

                if (
                    ((neighborRowIdx >= 0 && neighborRowIdx < row) && (neighborColIdx >= 0 && neighborColIdx < col) /* checking for out of bound */) &&
                    (grid[neighborRowIdx][neighborColIdx] == '1' /* We only push this neighbor into the queue, If this neighbor is a land */) &&
                    (!visited[neighborRowIdx][neighborColIdx] /* If this neighbor is not visited, then only we push this neighbor into the queue.*/))
                {
                    DepthFirstSearch(neighborRowIdx, neighborColIdx, row, col, visited, grid);
                }
            }
        }
        }

public:
    /* Question: Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
    Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

    Approach: we have to find the total number of connected components in the graph.
    */

    /* Method to find the number of islands. */
    // Time Complexity: O(row*col).
    // Space Complexity: O(row*row), space used by visited array + Recursive stack space in DFS.
    int numIslands(vector<vector<char>> &grid)
    {
        // Row and Column of the Grid.
        int row = grid.size();
        int col = grid[0].size();

        // 2D array to check if a particular cell(i,j) is visited or not.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Variable to count total number of connected components.
        int cnt = 0;

        // Travering the Grid.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    // counting this component go the graph.
                    cnt++;

                    DepthFirstSearch(i, j, row, col, visited, grid);
                }
            }
        }

        return cnt;
    }
};

int main(void)
{
    vector<vector<char>> grid = {
        {0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 1, 0}};

    // Solution.
    Solution S;
    cout << S.numIslands(grid);
}