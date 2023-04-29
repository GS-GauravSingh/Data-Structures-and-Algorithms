#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search (DFS). */
    void DFS(int startRow, int startCol, int &baseRow, int &baseCol, int &row, int &col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &Island)
    {
        // Mark the starting cell as visited.
        visited[startRow][startCol] = true;

        // Store the coordinates of this particular connected component (Island).
        int x_coordinate = startRow - baseRow; // This will helps us to identify the duplicate islands.
        int y_coordinate = startCol - baseCol; // This will helps us to identify the duplicate islands.
        Island.push_back({x_coordinate, y_coordinate});

        // Make a recursive call for all the unvisited adjaceent neighbors (top, down, left and right) that has value 1 (1 means Islands).
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
                (grid[neighborRowIdx][neighborColIdx] == 1 /* we have to visit all those neighbors that contains 1 (1 means 'Island').*/) &&
                (!visited[neighborRowIdx][neighborColIdx] /* We only visit this neighbor if this neighbor is not visited in the past.*/))
            {
                DFS(neighborRowIdx, neighborColIdx, baseRow, baseCol, row, col, grid, visited, Island);
            }
        }
    }

public:
    /* Question: Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected). */

    // Time Complexity: O(n * m), n is the number of rows and m is the number of columns.
    // Space Complexity: O(n * m).
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // Row and Column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // Visited Array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Set is used to store the number of distince Islands.
        set<vector<pair<int, int>>> totalIslands;

        // Traverse the grid.
        for (int i = 0; i < row; i++)
        {

            for (int j = 0; j < col; j++)
            {

                // Traverese all the components of the graphs and store the coordinates of islands (connected components) into our set.
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    // vector is used to store coordinates of a particular connected component (Island).
                    vector<pair<int, int>> Island;

                    // DFS Call.
                    DFS(i, j, i, j, row, col, grid, visited, Island);

                    // Storing this particular connected component (Island) into our set.
                    totalIslands.insert(Island);
                }
            }
        }

        // Store or return the cound of distinct islands.
        int distinctIslands = totalIslands.size();

        // return answer.
        return distinctIslands;
    }
};

int main(void)
{
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};

    // Solution.
    Solution S;
    cout << S.countDistinctIslands(grid);
}