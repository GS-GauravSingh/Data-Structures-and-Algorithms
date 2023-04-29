#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search Algorithm. */
    void DepthFirstSearch(int sr, int sc, int &oldColor, int newColor, int &row, int &col, vector<vector<int>> &visited, vector<vector<int>> &image)
    {
        // Mark that starting cell as visited.
        visited[sr][sc] = true;

        // Changing color of frontNode.
        image[sr][sc] = newColor;

        // Push all the 4-neighbors of the frontNode into the queue only those neighbors who are not visited.
        // Top Neighbor
        if ((sr - 1 >= 0 /* checking for out of bound. */) &&
            (image[sr - 1][sc] == oldColor /* We only push this neighbor into the queue, if this neighbor has the same color as old color and the pixes value of this neighbor is not 0. */) &&
            (!visited[sr - 1][sc] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
        {
            DepthFirstSearch(sr - 1, sc, oldColor, newColor, row, col, visited, image);
        }

        // Bottom Neighbor
        if ((sr + 1 < row /* checking for out of bound. */) &&
            (image[sr + 1][sc] == oldColor /* We only push this neighbor into the queue, if this neighbor has the same color as old color and the pixes value of this neighbor is not 0. */) &&
            (!visited[sr + 1][sc] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
        {
            DepthFirstSearch(sr + 1, sc, oldColor, newColor, row, col, visited, image);
        }

        // Left Neighbor
        if ((sc - 1 >= 0 /* checking for out of bound. */) &&
            (image[sr][sc - 1] == oldColor /* We only push this neighbor into the queue, if this neighbor has the same color as old color and the pixes value of this neighbor is not 0. */) &&
            (!visited[sr][sc - 1] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
        {
            DepthFirstSearch(sr, sc - 1, oldColor, newColor, row, col, visited, image);
        }

        // Right Neighbor
        if ((sc + 1 < col /* checking for out of bound. */) &&
            (image[sr][sc + 1] == oldColor /* We only push this neighbor into the queue, if this neighbor has the same color as old color and the pixes value of this neighbor is not 0. */) &&
            (!visited[sr][sc + 1] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
        {
            DepthFirstSearch(sr, sc + 1, oldColor, newColor, row, col, visited, image);
        }

        /*
        // Shortcut for traversing all neighbors using a single loop.

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
            int neighborRowIdx = sr + rowCoordinate[i];
            int neighborColIdx = sc + colCoordinate[i];

            if ((neighborRowIdx >= 0 && neighborRowIdx < row && neighborColIdx >= 0 && neighborColIdx < col /* checking for out of bound. */) &&
                (image[neighborRowIdx][neighborColIdx] == oldColor /* We only push this neighbor into the queue, if this neighbor has the same color as old color and the pixel value of this neighbor is not 0. */) &&
                (!visited[neighborRowIdx][neighborColIdx] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
            {
                DepthFirstSearch(neighborRowIdx, neighborColIdx, oldColor, newColor, row, col, visited, image);
            }
        }
    }

public:
    /* Flood Fill Algorithm. */
    // Time Complexity: O(n * m), 'n' is the number of rows and 'm' is the number of columns.
    // Space Complexity: O(n * m), space used by visited 2D array.
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Row and Column of the Image.
        int row = image.size();
        int col = image[0].size();

        // Old color
        int oldColor = image[sr][sc];

        // Visited Array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        DepthFirstSearch(sr, sc, oldColor, newColor, row, col, visited, image);

        return image;
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
    // An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };

    // Coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill.
    int sr = 1;
    int sc = 1;

    // Pixel value newColor.
    int newColor = 2;

    // Solution.
    Solution S;
    vector<vector<int>> ans = S.floodFill(image, sr, sc, newColor);
    S.print2DVec(ans);
}