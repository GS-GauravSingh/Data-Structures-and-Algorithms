#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach:  Using auxiliary 2D vector. */
    // Time Complexity: O(m*n) * O(m + n), where 'm' is the number of rows and 'n' is the number of columns of the matrix.
    // Space Complexity: O(m*n), space used by auxiliary 2D matrix.
    void setMatrixZero_BruteForce(vector<vector<int>> &matrix)
    {
        // Step 1: Make a copy of the Original matrix.
        vector<vector<int>> copyMatrix = matrix;

        /*
        Step 2: Traverse the original matrix and if any cell (i, j) contains 0, then at index (i, j) in copy matrix, set its entire row and column with 0.

        Example:

        Original Matrix:                          Copy Matrix:
        1 1 1                                     1 1 1
        1 0 1                                     1 0 1
        1 1 1                                     1 1 1

        Now, in original matrix, we found 0 at index, i = 1 and j = 1 i.e., (1, 1).
        Now at index (1,1) in copy matrix, we set the entire row and column with 0.

        Original Matrix:                          Copy Matrix:
        1 1 1                                     1 0 1
        1 0 1                                     0 0 0
        1 1 1                                     1 0 1
        */

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Setting entire row in copy matrix with 0.
                    for (int row = 0; row < matrix[0].size(); row++)
                    {
                        copyMatrix[i][row] = 0;
                    }

                    // Setting entire column in copy matrix with 0.
                    for (int col = 0; col < matrix.size(); col++)
                    {
                        copyMatrix[col][j] = 0;
                    }
                }
            }
        }

        // Step 3: Our answer is ready in copy matrix, so update the final matrix.
        matrix = copyMatrix;
    }

    /* Better Approach:  Using 2 auxiliary 1D vector to store markers. */
    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns in the matrix.
    // Space Complexity: O(m) + O(n), space used by 'topRow' and 'leftCol' vector.
    void setMatrixZero_Better(vector<vector<int>> &matrix)
    {
        // Row and column of the matrix.
        int r = matrix.size();
        int c = matrix[0].size();

        // Row vector.
        vector<bool> topRow(c, false);

        // Column vector.
        vector<bool> leftCol(r, false);

        // Traverse the original vector and store the markers.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    topRow[j] = true;
                    leftCol[i] = true;
                }
            }
        }

        // Again traverse the original vector and update the final matrix.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (topRow[j] == true || leftCol[i] == true)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    /* Optimal Approach:  Using First Row and First Column of the original matrix to store markers. */
    // Time Complexity: O(m*n), where 'm' is the number of rows and 'n' is the number of columns in the matrix.
    // Space Complexity: O(1).
    void setMatrixZero_Optimal(vector<vector<int>> &matrix)
    {
        // Row and column of the matrix.
        int r = matrix.size();
        int c = matrix[0].size();

        // This cell 'matrix[0][0]' are overlapping for first row and first column,
        // I am taking 2 seperate variables for first row and first column.
        bool firstRow = false;
        bool firstCol = false;

        // Traverse the original vector and store the markers.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        firstCol = true;
                    }

                    if (j == 0)
                    {
                        firstRow = true;
                    }

                    // Top Row.
                    matrix[0][j] = 0;

                    // Left Col.
                    matrix[i][0] = 0;
                }
            }
        }

        // Again traverse the original vector and update the final matrix.
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Now Update the first row and first column.

        // Now, if there is any 0 present in first row, then firstRow = true and if there is any 0 present in first column, then firstCol = true.
        if (firstRow)
        {
            for (int i = 0; i < r; i++)
            {
                matrix[i][0] = 0;
            }
        }

        if (firstCol)
        {
            for (int i = 0; i < c; i++)
            {
                matrix[0][i] = 0;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        // // Brute Force Solution.
        // setMatrixZero_BruteForce(matrix);

        // // Better Approach.
        // setMatrixZero_Better(matrix);

        // Optimal Approach.
        setMatrixZero_Optimal(matrix);
    }
};

int main(void)
{
    vector<vector<int>> matrix{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };

    // Solution.
    Solution obj;
    obj.setZeroes(matrix);

    for (auto row : matrix)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}