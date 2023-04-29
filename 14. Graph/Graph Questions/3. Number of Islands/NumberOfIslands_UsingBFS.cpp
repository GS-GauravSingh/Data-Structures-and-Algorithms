#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Breadth First Search Algorithm (BFS). */
    void BreadthFirstSearch(int startRow, int startCol, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        // Queue
        queue<pair<int, int>> q;

        // Pushing the starting cell into the queue.
        q.push({startRow, startCol});

        // Mark this starting cell as visited.
        visited[startRow][startCol] = true;

        // Row and Column of the Grid.
        int row = grid.size();
        int col = grid[0].size();

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front Node from the queue.
            pair<int, int> frontNode = q.front();

            // Pop that frontNode from the Queue.
            q.pop();

            // Taking the row and column index from front node.
            int rowIdx = frontNode.first;
            int colIdx = frontNode.second;

            // Push all the 8 neighbors of frontNode into the queue only when the neighbors is not visited and the neighbors is not water.
            // Top neighbour
            if ((rowIdx - 1 >= 0 /* checking for out of bound. */) &&
                (grid[rowIdx - 1][colIdx] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx - 1][colIdx]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx - 1, colIdx});       // pushing neighbor into the queue.
                visited[rowIdx - 1][colIdx] = true; // mark this neighbor as visited.
            }

            // Top-Left neighbour
            if (((rowIdx - 1 >= 0) && (colIdx - 1 >= 0) /* checking for out of bound. */) &&
                (grid[rowIdx - 1][colIdx - 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx - 1][colIdx - 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx - 1, colIdx - 1});       // pushing neighbor into the queue.
                visited[rowIdx - 1][colIdx - 1] = true; // mark this neighbor as visited.
            }

            // Top-Right neighbour
            if (((rowIdx - 1 >= 0) && (colIdx + 1 < col) /* checking for out of bound. */) &&
                (grid[rowIdx - 1][colIdx + 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx - 1][colIdx + 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx - 1, colIdx + 1});       // pushing neighbor into the queue.
                visited[rowIdx - 1][colIdx + 1] = true; // mark this neighbor as visited.
            }

            // Left neighbour
            if ((colIdx - 1 >= 0 /* checking for out of bound. */) &&
                (grid[rowIdx][colIdx - 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx][colIdx - 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx, colIdx - 1});       // pushing neighbor into the queue.
                visited[rowIdx][colIdx - 1] = true; // mark this neighbor as visited.
            }

            // Right neighbour
            if ((colIdx + 1 < col /* checking for out of bound. */) &&
                (grid[rowIdx][colIdx + 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx][colIdx + 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx, colIdx + 1});       // pushing neighbor into the queue.
                visited[rowIdx][colIdx + 1] = true; // mark this neighbor as visited.
            }

            // Bottom neighbour
            if ((rowIdx + 1 < row /* checking for out of bound. */) &&
                (grid[rowIdx + 1][colIdx] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx + 1][colIdx]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx + 1, colIdx});       // pushing neighbor into the queue.
                visited[rowIdx + 1][colIdx] = true; // mark this neighbor as visited.
            }

            // Bottom-Left neighbour
            if (((rowIdx + 1 < row) && (colIdx - 1 >= 0) /* checking for out of bound. */) &&
                (grid[rowIdx + 1][colIdx - 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx + 1][colIdx - 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx + 1, colIdx - 1});       // pushing neighbor into the queue.
                visited[rowIdx + 1][colIdx - 1] = true; // mark this neighbor as visited.
            }

            // Bottom-Right neighbour
            if (((rowIdx + 1 < row) && (colIdx + 1 < col) /* checking for out of bound. */) &&
                (grid[rowIdx + 1][colIdx + 1] == '1' /* We only push this neighbor into the queue, If is a land */) &&
                (!visited[rowIdx + 1][colIdx + 1]) /* If this neighbor is not visited, then only we push this into the queue.*/)
            {
                q.push({rowIdx + 1, colIdx + 1});       // pushing neighbor into the queue.
                visited[rowIdx + 1][colIdx + 1] = true; // mark this neighbor as visited.
            }

            // Shortcut to push all the 8 neighbors into the queue.
            // Top Neighbor: (row - 1, col).
            // Top-Left Neighbor: (row - 1, col - 1).
            // Top-Right Neighbor: (row - 1, col + 1).
            // Left Neighbor: (row, col - 1).
            // Right Neighbor: (row, col + 1).
            // Bottom Neighbor: (row + 1, col).
            // Bottom-Left Neighbor: (row + 1, col - 1).
            // Bottom-Right Neighbor: (row + 1, col + 1).

            // So if we carefully see, the value of row is varying from row - 1 to row + 1 i.e., row - 1, row + 0 and row + 1.
            // So if we carefully see, the value of col is varying from col - 1 to col + 1 i.e., col - 1, col + 0 and col + 1.
            // So both row and col is varying from -1 to 1.
            for (int rowRange = -1; rowRange <= 1; rowRange++)
            {
                for (int colRange = -1; colRange <= 1; colRange++)
                {
                    // Index of neighbors.
                    int neighborRowIdx = rowIdx + rowRange;
                    int neighborColIdx = colIdx + colRange;

                    if (
                        ((neighborRowIdx >= 0 && neighborRowIdx < row) && (neighborColIdx >= 0 && neighborColIdx < col) /* checking for out of bound */) &&
                        (grid[neighborRowIdx][neighborColIdx] == '1' /* We only push this neighbor into the queue, If this neighbor is a land */) &&
                        (!visited[neighborRowIdx][neighborColIdx] /* If this neighbor is not visited, then only we push this neighbor into the queue.*/))
                    {
                        q.push({neighborRowIdx, neighborColIdx});       // pushing neighbor into the queue.
                        visited[neighborRowIdx][neighborColIdx] = true; // mark this neighbor as visited.
                    }
                }
            }

            /* If you print the value of rowRange and colRange in above loop, the pairs will print like this,

            1st Pair: -1, -1
            2nd Pair: -1, 0
            3rd Pair: -1, +1
            4th Pair: 0, -1
            5th Pair: 0, 0
            6th Pair: 0, +1
            8th Pair: +1, -1
            9th Pair: +1, 0
            10th Pair: +1, +1

            and if you add these value from row and col, you will get all the iedices of neighbors.
            1st Pair: (-1, -1), (row + (-1) = row - 1, col + (-1) = col - 1) = row - 1, col - 1 => top-left neighbor.

            2nd Pair: -1, 0, (row + (-1) = row - 1, col + 0 = col) = row - 1, col => top neighbor.

            3rd Pair: -1, +1, (row + (-1) = row - 1) = row - 1, col + 1 => top - right neighbor.

            4th Pair: 0, -1, (row + 0 = row, col + (-1) = col - 1) = row, col - 1 => left neighbor.

            5th Pair: 0, 0, (row + 0 = row, col + 0 = co) = row, col => Actual Cell, we have to ignore this case and this cell is automatically ignored because this cell is already marked as visited and we have to push only those neighbors who are not visited.

            6th Pair: 0, +1, = row, col +1 => right neighbor.

            8th Pair: +1, -1, (row + 1, col + (-1) = col - 1) = row + 1, col - 1 => bottom-left neighbor.

            9th Pair: +1, 0, = row + 1, col + 0 => row + 1, col => bottom neighbor.

            10th Pair: +1, +1, row + 1, col + 1 => bottom-right neighbor.

            So, using this short you can actually traverse across all the neighbors.
            */
        }
    }

public:
    /* Question: Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
    Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

    Approach: we have to find the total number of connected components in the graph.
    */

    /* Method to find the number of islands. */
    // Time Complexity: O(row*col).
    // Space Complexity: O(row*row), space used by visited array + space used by queue in BFS.
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
                    // counting this component of the graph.
                    cnt++;

                    BreadthFirstSearch(i, j, visited, grid);
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