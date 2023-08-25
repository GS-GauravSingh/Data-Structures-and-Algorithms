#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Spiral Order Traversal of Matrix. */
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1), excluding space used by answer vector.
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // vector to store answer.
        vector<int> ans;

        // row, col.
        int row = matrix.size();
        int col = matrix[0].size();

        // needed variables.
        int topRow = 0;
        int bottomRow = row - 1;

        int leftCol = 0;
        int rightCol = col - 1;

        // total number of elements int matrix.
        int totalElements = row * col;

        // variable to count the traversed elements.
        int count = 0;

        // we have to traverse all elements, run a while loop with condition as follows,
        while (count < totalElements)
        {
            // traversing top row.
            for (int row = leftCol; count < totalElements && row <= rightCol; row++)
            {
                // store element in answer vector.
                ans.push_back(matrix[topRow][row]);

                // increment the count.
                count++;
            }
            // top row traversed, now move to next row.
            topRow++;

            // traversing right column.
            for (int col = topRow; count < totalElements && col <= bottomRow; col++)
            {
                // store element in answer vector.
                ans.push_back(matrix[col][rightCol]);

                // increment the count.
                count++;
            }
            // right column traversed, now move to next column.
            rightCol--;

            // traversing bottom row.
            for (int row = rightCol; count < totalElements && row >= leftCol; row--)
            {
                // store element in answer vector.
                ans.push_back(matrix[bottomRow][row]);

                // increment the count.
                count++;
            }
            // bottom row traversed, now move to next row.
            bottomRow--;

            // traversing left column.
            for (int col = bottomRow; count < totalElements && col >= topRow; col--)
            {
                // store element in answer vector.
                ans.push_back(matrix[col][leftCol]);

                // increment the count.
                count++;
            }
            // left column traversed, now move to next column.
            leftCol++;
        }

        // return answer.
        return ans;
    }
};

int main(void)
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    // Solution.
    Solution obj;

    vector<int> spiral = obj.spiralOrder(matrix);

    for (auto it : spiral)
    {
        cout << it << " ";
    }
    return 0;
}