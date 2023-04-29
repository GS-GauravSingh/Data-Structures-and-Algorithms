#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Question: Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.

    If the path is not possible between source cell and destination cell, then return -1.

    Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. */

    /*
    Time Complexity: O( 4*N*M ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.

    Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.
    */
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first && source.second == destination.second)
        {
            return 0;
        }

        // Row and column of the grid.
        int row = grid.size();
        int col = grid[0].size();

        // Queue
        // Queue is of Type {distance, {rowIdx, colIdx}}
        queue<pair<int, pair<int, int>>> q;

        // Distance array.
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        distance[source.first][source.second] = 0; // distance to reach the source itself is 0.

        // Push the source node with distance 0 into the queue.
        // Queue is of Type {distance, {rowIdx, colIdx}}.
        q.push({0, source});

        // Traverse the queue.
        while (!q.empty())
        {
            // Take out the front element of the queue.
            auto topElement = q.front();

            // Pop the front element of the queue.
            q.pop();

            // Take out the node(vertex) and distance from the topElement.
            // Pair is of type {distance, {rowIdx, colIdx}}.
            int dist = topElement.first;
            int rowIdx = topElement.second.first;
            int colIdx = topElement.second.second;

            // Update the distance of neighbors of node.
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

            for (int i = 0; i < 4 /* size of both the above array is 4. */; i++)
            {
                // Row and column indexes of neighbors.
                int neighborRowIdx = rowIdx + rowCoordinate[i];
                int neighborColIdx = colIdx + colCoordinate[i];

                if ((neighborRowIdx >= 0 && neighborRowIdx < row && neighborColIdx >= 0 && neighborColIdx < col /* checking for out of bound. */) &&
                    (grid[neighborRowIdx][neighborColIdx] == 1 /* we have to visit all those neighbors that contains 1. */) &&
                    (((dist + 1 /* unit edge weights */) < distance[neighborRowIdx][neighborColIdx]) /* checking if new distance is less than old distance or not. */))
                {
                    // If new distance is < old distance, then update the distance.
                    distance[neighborRowIdx][neighborColIdx] = dist + 1;

                    // But before pushing the pair into the queue,
                    // just check if this is you destination pair or not.
                    // if this is your destination node, the return the answer.
                    if (neighborRowIdx == destination.first && neighborColIdx == destination.second)
                    {
                        return dist + 1;
                    }

                    // And push this pair into the queue.
                    q.push({(dist + 1), {neighborRowIdx, neighborColIdx}});
                }
            }
        }

        // means we are unable to reach the destination.
        return -1;
    }
};

int main(void)
{
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    // Solution.
    Solution S;
    cout << S.shortestPath(grid, source, destination);
}