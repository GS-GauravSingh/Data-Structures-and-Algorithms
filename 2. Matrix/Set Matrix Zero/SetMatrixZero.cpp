/*
Question :-
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /*
    Approach 1 :- Using extra space.

    Algorithm,
    1. Create an auxiliary 2d vector and initialize all elements with 0.
    2. Copy all element of original matrix to auxiliary matrix/2d vector.
    3. Iterate through the original matrix and if we found the element with value 0, set it’s entire row and column element’s in auxiliary matrix with 0.
    4. Last step, update the original matrix (Copy all element of auxiliary matrix/2d vector to original matrix).

    Time Complexity:- O((N*M)*(N + M)), O(N*M) for traversing through each element and (N+M)for traversing to row and column.
    Space Complexity:- O(N*M),  because we’re using extra space i.e., our auxiliary 2D matrix.

    */
    void setZeroes_Approach_1(vector<vector<int>> &matrix)
    {
        // row and column.
        int row = matrix.size();
        int col = matrix[0].size();

        // Step 1 :- Create an auxiliary 2d vector and initialize all elements with 0.
        vector<vector<int>> auxMatrix(row, vector<int>(col, 0));

        // Step 2 :- Copy all element of original matrix to auxiliary matrix/2d vector.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                auxMatrix[i][j] = matrix[i][j];
            }
        }

        // Step 3 :- Iterate through the original matrix and when we found the element having value equals to 0, set it’s entire row and column element’s in auxiliary matrix with 0.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // setting entire row with 0.
                    for (int row = 0; row < col; row++)
                    {
                        auxMatrix[i][row] = 0;
                    }

                    // setting entire column with 0.
                    for (int col = 0; col < row; col++)
                    {
                        auxMatrix[col][j] = 0;
                    }
                }
            }
        }

        // Step 4 :- Last step, update the original matrix (Copy all element of auxiliary matrix/2d vector to original matrix).
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = auxMatrix[i][j];
            }
        }
    }

    /*
    Better Approach :- Using 1D vector.

    In the brute force approach, we are using an auxiliary 2D vector, which will increase our space complexity.

    But, in this approach, instead of using auxiliary 2D vector, we are using 2 different vector of size row and column. This will decrease our space complexity to O(n).

    Approach: Take two dummy array one of size of row and other of size of column. Now traverse through the array. If matrix[i][j]==0 then set dummy1[i]=0(for row) and dummy2[j]=0(for column).Now traverse through the array again and if dummy1[i]==0  || dummy2[j]==0 then matrix[i][j]=0,else continue.

    Time Complexity:- O((N*M) + (N * M)), O(N*M) for storing the index of element having value = 0, and (N*M) for updating our original matrix.
    Space Complexity:- O(N), because we’re using extra space i.e., our auxiliary vector.
    */

    void setZeroes_Approach_2(vector<vector<int>> &matrix)
    {
        // row and column.
        int row = matrix.size();
        int col = matrix[0].size();

        // vector to store markers.
        vector<bool> markRow(col, false);
        vector<bool> markCol(row, false);

        // iterate through the matrix and whenever we find the element having value = 0,
        // then mark it's index as true (means zero present) in markers vectors.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow[j] = true;
                    markCol[i] = true;
                }
            }
        }

        // again iterate through the matrix and update the original matrix.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (markRow[j] == true || markCol[i] == true)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    /*
    Similar Approach,
    1. Create 2 auxiliary vector, one having size = row and one having size = col .
    2. Iterate through the original matrix and store the index (i, j) of element having value =  0.
    3. Store the indexes in above 2 vectors.
    4. Now, in above 2 vectors you have indexes of element having value = 0.
    5. Now, using auxiliary vectors, update original matrix.

    Time Complexity:- O((N*M) + (N * M)), O(N*M) for storing the index of element having value = 0, and (N*M) for updating our original matrix.
    Space Complexity:- O(N), because we’re using extra space i.e., our auxiliary vector.
    */
    void setZeroes_Approach_2_Variation(vector<vector<int>> &matrix)
    {
        // row and column.
        int row = matrix.size();
        int col = matrix[0].size();
        bool zeroPresent = false;

        // auxiliary vectors.
        vector<int> rowIndex;
        vector<int> colIndex;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // if we found the element having value = 0, set the flag to true.
                // and store the index of this element having value = 0.
                if (matrix[i][j] == 0)
                {
                    zeroPresent = true;

                    // storing row index.
                    rowIndex.push_back(i);

                    // storing col index.
                    colIndex.push_back(j);
                }
            }
        }

        // At this point, we have the indexes of element having value = 0.
        // Now, set it entire row and column to 0.

        if (zeroPresent == true)
        {
            // row
            for (int i = 0; i < rowIndex.size(); i++)
            {
                int idx = rowIndex[i];

                for (int j = 0; j < col; j++)
                {
                    matrix[idx][j] = 0;
                }
            }

            // column
            for (int i = 0; i < colIndex.size(); i++)
            {
                int idx = colIndex[i];

                for (int j = 0; j < row; j++)
                {
                    matrix[j][idx] = 0;
                }
            }
        }
    }

    /*
    Optimized Approach :- Constant Space

    Intuition: Instead of taking two dummy vectors we can use the first row and column of the matrix for the same work. This will help to reduce the space complexity of the problem.

    Approach: Instead of taking two separate dummy array, take first row and column of the matrix as the array for checking whether the particular column or row has the value 0 or not.

    Since matrix[0][0] are overlapping. Therefore take separate variable’s row and col to check if the 0th column has 0 or not and use matrix[0][0] to check if the 0th row has 0 or not.

    Algorithm:-
    1. Traverse the matrix and set the markers.
    2. Again traverse the matrix and update the inner matrix.
    3. Lastly update first row and first col, if matrix[0][0] == 0, then set all element of first row and column to 0.

    Time Complexity:- O(N*M)
    Space Complexity:- O(1)
    */

    void setZeroes_Approach_3(vector<vector<int>> &matrix)
    {
        // row and column.
        int row = matrix.size();
        int col = matrix[0].size();

        // this cell matrix[0][0] are overlapping for first row and first column,
        // i am taking 2 seperate variables for first row and first column.
        bool firstRow = false;
        bool firstCol = false;

        // set markers in first row and first column.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        firstRow = true;
                    }
                    if (j == 0)
                    {
                        firstCol = true;
                    }

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // update inner matrix.
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // lastly, update first row and column.
        if (firstRow)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (firstCol)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }

    /* Method to print 2D vector. */
    void print2D(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1},
    };

    Solution S;
    S.setZeroes_Approach_3(matrix);
    S.print2D(matrix);
}