#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Breadth First Search Algorithm. */
    int BreadthFirstSearch(vector<pair<int, int>> &rottenOrangesIdx, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        // Queue.
        // pair<int, int> is used to store the indexes of rotton oranges.
        // Second block of int in pair is used to store the time.
        queue<pair<pair<int, int>, int>> q;

        // Push all the indexes of rotton oranges into the queue and mark them as visited.
        for (auto rottonOrange : rottenOrangesIdx)
        {
            // Row and Column index of rotton oranges.
            int row = rottonOrange.first;
            int col = rottonOrange.second;

            // Push it into the queue, with time = 0.
            q.push({{row, col}, 0});

            // Mark this rotton orange as visited.
            visited[row][col] = true;
        }

        // Row and Column of the Grid.
        int row = grid.size();
        int col = grid[0].size();

        // Variable to store minimum time required to rot all the fresh oranges.
        int minTime = 0;

        // Travering the Queue.
        while (!q.empty())
        {
            // Take out the frontNode form the queue.
            pair<pair<int, int>, int> frontNode = q.front();

            // Pop that frontNode from the queue.
            q.pop();

            // Take out the row and column index of rotton orange from the  frontNode.
            int rowIdx = frontNode.first.first;
            int colIdx = frontNode.first.second;

            // Take out the Time.
            int time = frontNode.second;

            // Store the minimum time.
            minTime = max(minTime, time);

            // Push all the 4 neighbors into the queue only when the neighbors are not an empty cell and  the neighbors are not visited in the past.

            // Top neighbor.
            if (
                (rowIdx - 1 >= 0 /* checking for out of bound. */) &&
                (grid[rowIdx - 1][colIdx] == 1 /* We push this neighbor into the queue only when this neighbor has a fresh orange, because we only have to rot the fresh ornages. */) &&
                (!visited[rowIdx - 1][colIdx] /* We push this neighbor into the queue only when this neighbor is not visited. */))
            {
                q.push({{rowIdx - 1, colIdx}, time + 1});
                visited[rowIdx - 1][colIdx] = true;
            }

            // Bottom neighbor.
            if (
                (rowIdx + 1 < row /* checking for out of bound. */) &&
                (grid[rowIdx + 1][colIdx] == 1 /* We push this neighbor into the queue only when this neighbor has a fresh orange, because we only have to rot the fresh ornages. */) &&
                (!visited[rowIdx + 1][colIdx] /* We push this neighbor into the queue only when this neighbor is not visited. */))
            {
                q.push({{rowIdx + 1, colIdx}, time + 1});
                visited[rowIdx + 1][colIdx] = true;
            }

            // Left neighbor.
            if (
                (colIdx - 1 >= 0 /* checking for out of bound. */) &&
                (grid[rowIdx][colIdx - 1] == 1 /* We push this neighbor into the queue only when this neighbor has a fresh orange, because we only have to rot the fresh ornages. */) &&
                (!visited[rowIdx][colIdx - 1] /* We push this neighbor into the queue only when this neighbor is not visited. */))
            {
                q.push({{rowIdx, colIdx - 1}, time + 1});
                visited[rowIdx][colIdx - 1] = true;
            }

            // Right neighbor.
            if (
                (colIdx + 1 < col /* checking for out of bound. */) &&
                (grid[rowIdx][colIdx + 1] == 1 /* We push this neighbor into the queue only when this neighbor has a fresh orange, because we only have to rot the fresh ornages. */) &&
                (!visited[rowIdx][colIdx + 1] /* We push this neighbor into the queue only when this neighbor is not visited. */))
            {
                q.push({{rowIdx, colIdx + 1}, time + 1});
                visited[rowIdx][colIdx + 1] = true;
            }
        }

        // Before returning the time, check if we successfully rot all the fresh oranges or not.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // Below condition means that, if the cell (i,j) is not visited and having value = 1, it means this cell is not rechable and we had not rotten this cell.
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    // return -1, our task is to rot all the fresh oranges but some fresh oranges are still there in the grid.
                    return -1;
                }
            }
        }

        return minTime;
    }

public:
    /* Question: Given a grid of dimension nxm, where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
    0 : Empty cell.
    1 : Cells have fresh oranges.
    2 : Cells have rotten oranges.

    We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.
    */

    /* Method to find minimum time required to rot all oranges. */
    // Time Complexity: O(n * m), 'n' is the number of rows and 'm' is the number of columns.
    // Space Complexity: O(n * m), space used by visited 2D array.
    int orangesRotting(vector<vector<int>> &grid)
    {

        // Row and Column fo the Grid.
        int row = grid.size();
        int col = grid[0].size();

        // Now, we have to store the indices of all the rotten oranges, because all the rotten oranges start rotting the fresh oranges at the same time.
        vector<pair<int, int>> rottenOrangesIdx;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    // Store the index of rotten oranges.
                    rottenOrangesIdx.push_back({i, j});
                }
            }
        }

        // Visited Array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        return BreadthFirstSearch(rottenOrangesIdx, visited, grid);
    }

    /* Method to print 2D vector. */
    void print2DVec(vector<vector<int>> &image)
    {
        for (auto row : image)
        {
            for (auto col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<vector<int>> grid = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1},
    };

    // Solution.
    Solution S;

    int time = S.orangesRotting(grid);
    if (time != -1)
    {
        cout << "Minimum time Required to rot all the fresh oranges : " << time << " sec.\n";
    }
    else
    {
        cout << "We cannot rot all the fresh oranges.\n";
    }
}