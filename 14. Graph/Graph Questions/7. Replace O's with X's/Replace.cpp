#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search (DFS). */
    void DFS(int startRow, int startCol, int &row, int &col, vector<vector<char>> &mat, vector<vector<int>> &visited)
    {
        // mark this starting cell as visited.
        visited[startRow][startCol] = true;

        // Make a recursive call for all the adjacent neighbors having value equal to O.
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
                (mat[neighborRowIdx][neighborColIdx] == 'O' /* we have to visit all those neighbors that contains 'O'.*/) &&
                (!visited[neighborRowIdx][neighborColIdx] /* We only push this neighbor into the queue, if this neighbor is not pushed or visited in the past. */))
            {
                DFS(neighborRowIdx, neighborColIdx, row, col, mat, visited);
            }
        }
    }

public:
    /* Question: Given a matrix mat of size N x M where every element is either O or X.
    Replace all O with X that are surrounded by X.
    A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it. */

    /*
    Intuition:.
    The boundary elements (boundary 'O's) in the matrix cannot be replaced with ‘X’ as they are not surrounded by ‘X’ from all 4 directions. This means if ‘O’ (or a set of ‘O’) is connected to a boundary ‘O’ then it can’t be replaced with ‘X’. 

    The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’. 

    After marking all the boundary 'O's and all the 'O's that are connected to these boundary 'O's as visited. You can replace all the remaining unvisited 'O's with 'X'.
    */

    // Time Complexity: O(n * m), n is the number of rows and m is the number of columns.
    // Space Complexity: O(n * m).
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Row and column of the matrix.
        int row = n;
        int col = m;

        // visited array.
        vector<vector<int>> visited(row, vector<int>(col, 0));

        // Traversing the boundary of the given matrix and calling dfs for those cell that contains 'O'.

        // Traversing the first and last row.
        for (int i = 0; i < col; i++)
        {
            // Check for unvisited Os in the boundary rows.
            // First Row.
            if (mat[0][i] == 'O' && !visited[0][i])
            {
                DFS(0, i, row, col, mat, visited);
            }

            // Last Row.
            if (mat[row - 1][i] == 'O' && !visited[row - 1][i])
            {
                DFS(row - 1, i, row, col, mat, visited);
            }
        }

        // Traversing the first and last column.
        for (int i = 0; i < row; i++)
        {
            // Check for unvisited Os in the boundary columns.
            // First Column.
            if (mat[i][0] == 'O' && !visited[i][0])
            {
                DFS(i, 0, row, col, mat, visited);
            }

            // Last Column.
            if (mat[i][col - 1] == 'O' && !visited[i][col - 1])
            {
                DFS(i, col - 1, row, col, mat, visited);
            }
        }

        // Update the final matrix.
        // If unvisited 'O' then convert to 'X'.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 'O' && !visited[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }

    /* Method to print 2D Vector. */
    void print2DVec(vector<vector<char>> matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    // Solution.
    Solution S;
    vector<vector<char>> ans = S.fill(mat.size(), mat[0].size(), mat);
    S.print2DVec(ans);
}