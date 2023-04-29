#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Question: Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
    The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid. */

    /* Method to find distance of nearest 1 in the grid for each cell. */
    // Time Complexity: O(row * col)
    // Space Complexity: O(row * col)
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Row and Column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // Visited array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Distance array or answer array.
        vector<vector<int>> distance(row, vector<int>(col, 0));

        // BFS Traversal.
        // queue.
        queue<pair<pair<int, int>, int>> q;

        // Push all the cells into the queue that contains 1 and mark them a visited.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Push those cells that has a value 1.
                    // and the distance of nearest cell 1 for these cell that contains 1 is 0.
                    q.push({{i, j}, 0});

                    // Mark these cells as visited.
                    visited[i][j] = true;
                }
            }
        }

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front Node from the queue.
            pair<pair<int, int>, int> frontNode = q.front();

            // Pop the front node of the queue.
            q.pop();

            // Take out the row and column index and steps from frontNode.
            int rowIdx = frontNode.first.first;
            int colIdx = frontNode.first.second;
            int steps = frontNode.second;

            // store the distance.
            distance[rowIdx][colIdx] = steps;

            // Push all neighbors whic are not visited in the past.
            // Top neighbor.
            if (rowIdx - 1 >= 0 && !visited[rowIdx - 1][colIdx])
            {
                q.push({{rowIdx - 1, colIdx}, steps + 1});
                visited[rowIdx - 1][colIdx] = true;
            }

            // Bottom neighbor.
            if (rowIdx + 1 < row && !visited[rowIdx + 1][colIdx])
            {
                q.push({{rowIdx + 1, colIdx}, steps + 1});
                visited[rowIdx + 1][colIdx] = true;
            }

            // Left neighbor.
            if (colIdx - 1 >= 0 && !visited[rowIdx][colIdx - 1])
            {
                q.push({{rowIdx, colIdx - 1}, steps + 1});
                visited[rowIdx][colIdx - 1] = true;
            }

            // Right neighbor.
            if (colIdx + 1 < col && !visited[rowIdx][colIdx + 1])
            {
                q.push({{rowIdx, colIdx + 1}, steps + 1});
                visited[rowIdx][colIdx + 1] = true;
            }

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
                int neighborRowIdx = rowIdx + rowCoordinate[i];
                int neighborColIdx = colIdx + colCoordinate[i];

                if ((neighborRowIdx >= 0 && neighborRowIdx < row && neighborColIdx >= 0 && neighborColIdx < col /* checking for out of bound. */) &&
                    (!visited[neighborRowIdx][neighborColIdx] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
                {
                    q.push({{neighborRowIdx, neighborColIdx}, steps + 1}); // Push this neighbor into the queue.
                    visited[neighborRowIdx][neighborColIdx] = true;        // mark this neighbor as visited.
                }
            }
        }

        // return answer array.
        return distance;
    }

    /* Method to print 2D Vector. */
    void print2DVector(vector<vector<int>> grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
    };

    // Solution.
    Solution S;
    vector<vector<int>> ans = S.nearest(grid);
    S.print2DVector(ans);
}