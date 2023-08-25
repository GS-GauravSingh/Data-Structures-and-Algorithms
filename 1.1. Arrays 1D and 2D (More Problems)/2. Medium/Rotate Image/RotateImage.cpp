#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Algorithm:-
    Step 1: First take the transpose of matrix.
    ==> To transpose a matrix,
        1. First traverse in lower diagonal or upper diagonal and,
        2. Swap (arr[i][j], arr[j][i]);

    Step 2: After transpose, reverse each row, this will rotate the matrix by 90 degree.
    */

    // Time Complexity: O(n*n) is for transposing the matrix + O(n*n) is for reversing each row.
    // Space Comlexity: O(1).
    void rotate(vector<vector<int>> &matrix)
    {
        // Step 1:- first take the transpose of matrix.
        // to transpose matrix,
        // first traverse in lower diagonal or upper diagonal and swap (arr[i][j], arr[j][i]);

        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2:- after transpose, reverse each row.
        for (auto &row : matrix)
        {
            reverse(row.begin(), row.end());
        }
    }
};

int main(void)
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // Solution.
    Solution obj;
    obj.rotate(matrix);

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