#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search (DFS). */
    void DFS(int startRow, int startCol, int &row, int &col, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        // Mark the starting cell as visited.
        visited[startRow][startCol] = true;

        // Make a recursive call for all adjacent unvisited neighbors (top, down, left and right) that has a value 1 (land).
        /*
            // Shortcut for traversing all 4 neighbors (top, bottom, left and right) using a single loop.

            coordinates for top neighbour is :   row - 1, col
            coordinates for right neighbour is : row    , col + 1
            coordinates for bottom neighbour is: row + 1, col
            coordinates for left neighbour is:   row    , col - 1

            Basically all the row coordinates are = {-1, 0, +1, 0};
            Basically all the col coordinates are = {0, +1, 0, -1};

            Using the above 2 array we can easily find all the neighbours,

            Row Coordinate   Column Coordinate  =>   Neighbour (row + row coordinate[i], col + col coordinate[i])
            ------------------------------------------------------------------------------------------------------
                -1                  0                   row + (-1), col + 0 ==>  (row - 1, col), coordinates of top neighbor.
                0                   +1                  row + 0, col + 1 ==>  (row, col + 1), coordinates of right neighbor.
                +1                  0                   row + 1, col + 0 ==>  (row + 1, col), coordinates of bottom neighbor.
                0                   -1                  row + 0, col + (-1) ==>  (row, col - 1), coordinates of left neighbor.
        */

        int rowCoordinate[] = {-1, 0, +1, 0};
        int colCoordinate[] = {0, +1, 0, -1};

        for (int i = 0; i < 4 /* size of both the array is 4. */; i++)
        {
            // Row and column indexes of neighbors.
            int neighborRowIdx = startRow + rowCoordinate[i];
            int neighborColIdx = startCol + colCoordinate[i];

            if ((neighborRowIdx >= 0 && neighborRowIdx < row && neighborColIdx >= 0 && neighborColIdx < col /* checking for out of bound. */) &&
                (grid[neighborRowIdx][neighborColIdx] == 1 /* we have to visit all those neighbors that contains 1 (1 means 'land cell').*/) &&
                (!visited[neighborRowIdx][neighborColIdx] /* We only visit this neighbor if this neighbor is not visited in the past.*/))
            {
                DFS(neighborRowIdx, neighborColIdx, row, col, visited, grid);
            }
        }
    }

public:
    /* Question: You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
    A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
    Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves. */

    /*
    Intuition:
    The land cells present in the boundary cannot be counted in the answer as we will walk off the boundary of the grid. Also, land cells connected to the boundary land cell can never be the answer. 

    Start BFS or DFS traversal from boundary land cells and go through their connected land cells and mark them as visited. The sum of all the remaining land cells will be the answer.
    */

    // Time Complexity: O(n * m), n is the number of rows and m is the number of columns.
    // Space Complexity: O(n * m).
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // Visited array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Traversing the boundary of the given matrix and calling dfs for land cells.
        // Traversing the first and last row.
        for (int i = 0; i < col; i++)
        {
            // Check for unvisited 1s in the boundary rows.
            // First Row.
            if (grid[0][i] == 1 && !visited[0][i])
            {
                DFS(0, i, row, col, visited, grid);
            }

            // Last Row.
            if (grid[row - 1][i] == 1 && !visited[row - 1][i])
            {
                DFS(row - 1, i, row, col, visited, grid);
            }
        }

        // Traversing the first and last column.
        for (int i = 0; i < row; i++)
        {
            // Check for unvisited Os in the boundary columns.
            // First Column.
            if (grid[i][0] == 1 && !visited[i][0])
            {
                DFS(i, 0, row, col, visited, grid);
            }

            // Last Column.
            if (grid[i][col - 1] == 1 && !visited[i][col - 1])
            {
                DFS(i, col - 1, row, col, visited, grid);
            }
        }

        // Update the final matrix.
        // If unvisited 1 then count this land cell.
        int cnt = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main(void)
{
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};

    // Solution.
    Solution S;
    cout << S.numberOfEnclaves(grid);
}