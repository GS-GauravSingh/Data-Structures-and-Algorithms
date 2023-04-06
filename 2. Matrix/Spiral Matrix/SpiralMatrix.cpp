#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(m*n).
    // Space Complexity:- O(1).
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // necessary variables.
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int totalElements = row * col;

        int upperRow = 0;
        int bottomRow = row - 1;
        int leftCol = 0;
        int rightCol = col - 1;

        vector<int> ans;

        while (count < totalElements)
        {
            // printing upper row.
            for (int row = leftCol; count < totalElements && row <= rightCol; row++)
            {
                ans.push_back(matrix[upperRow][row]);
                // cout<<matrix[upperRow][i]<<" ";
                count++;
            }
            upperRow++;

            // printing right column.
            for (int col = upperRow; count < totalElements && col <= bottomRow; col++)
            {
                ans.push_back(matrix[col][rightCol]);
                // cout<<matrix[i][rightCol]<<" ";
                count++;
            }
            rightCol--;

            // printing bottom row.
            for (int row = rightCol; count < totalElements && row >= leftCol; row--)
            {
                ans.push_back(matrix[bottomRow][row]);
                // cout<<matrix[bottomRow][i]<<" ";
                count++;
            }
            bottomRow--;

            // printing left column.
            for (int col = bottomRow; count < totalElements && col >= upperRow ; col--)
            {
                ans.push_back(matrix[col][leftCol]);
                // cout<<matrix[i][leftCol]<<" ";
                count++;
            }
            leftCol++;

            
        }
        return ans;
        
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    Solution s;
    vector<int> ans = s.spiralOrder(arr);
    s.print(ans);
}