#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Question: You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route. */

    /*
    Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue }

    Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.

    Space Complexity: O( N*M ) { Distance matrix containing N*M cells + priority queue in the worst case containing all the nodes ( N*M) }.

    Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.
    */
    int MinimumEffort(vector<vector<int>> &heights)
    {
        // Row and column of the matrix.
        int row = heights.size();
        int col = heights[0].size();

        // Using Dijkstra's Algorithm for finding shortes path with minimum efforts.

        // Priority Queue (Min heap).
        /* Priority queue will store the pairs of cell and their respective distance from the source cell. */
        /* Priority queue is of type {difference, {row index, column index}}. */
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Distance Array.
        // Declaring distance of size 'row*col', because we have to store the shortest distance from source node to all the other nodes in the graph.
        // Initializing distance array with 'INT_MAX', initially "INT_MAX" represent that the node is unreachable and as we traverse the graph, "INT_MAX" is used to update the distance array with the shortest distance to reach a particular node from source.
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        distance[0][0] = 0; // Update the distance of source node (source cell is (0, 0)) with 0, because we are starting from cell (0, 0) and in order to reach cell (0, 0) itself we need to travel 0 distance.

        // Push the starting cell into the queue with the distance 0.
        /* Priority queue is of type {difference, {row index, column index}}. */
        pq.push({0, {0, 0}});

        // Traverse the priority queue.
        while (!pq.empty())
        {
            // Take out the top element of the priority queue.
            auto topElement = pq.top();

            // Pop the top element of the priority queue.
            pq.pop();

            // Take out the row and column index of the cell and the difference.
            int diff = topElement.first;
            int rowIdx = topElement.second.first;
            int colIdx = topElement.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            if (rowIdx == row - 1 && colIdx == col - 1)
            {
                return diff;
            }

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

                if ((neighborRowIdx >= 0 && neighborRowIdx < row && neighborColIdx >= 0 && neighborColIdx < col /* checking for out of bound. */))
                {
                    // Effort can be calculated as the max value of differences
                    // between the heights of the node and its adjacent nodes.
                    int currentNode = heights[rowIdx][colIdx];
                    int neighborNode = heights[neighborRowIdx][neighborColIdx];

                    // A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
                    int newEfforts = max(abs(currentNode - neighborNode), diff);

                    // If the calculate efforts is less than the previous value,
                    // then we update the value with this efforts
                    // because we need minimum efforts.
                    if (newEfforts < distance[neighborRowIdx][neighborColIdx])
                    {
                        distance[neighborRowIdx][neighborColIdx] = newEfforts;

                        // push the pair into the queue.
                        pq.push({newEfforts, {neighborRowIdx, neighborColIdx}});
                    }
                }
            }
        }

        // If the above loop does not return the answer, it means the dextination cell (row-1, col-1) is unreachable and
        // in this case we have to return 0;
        return 0;
    }
};

int main(void)
{
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5},
    };

    // Solution.
    Solution S;
    cout << S.MinimumEffort(heights);
}