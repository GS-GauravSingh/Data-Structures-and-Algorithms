#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /*
    Algorithm:-

    Step 1:- first take the transpose of matrix.
    // to transpose matrix,
    //first travers in lower diagonal or upper diagonal and swap (arr[i][j], arr[j][i]);
    Step 2:- after transpose, reverse each row this will rotate your array by 90 degree.

    Time Complexity:- O(n^2)
    Space Complexity:- O(1)
    */
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

        // Step 2:- after transpose, reverse each row this will rotate your array by 90 degree.
        for(auto &row : matrix){
            reverse(row.begin(), row.end());
        }
        
    }

    /* Method to print 2D vector. */
    void print(vector<vector<int>> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            int col = arr[i].size();
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
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
    s.rotate(arr);
    s.print(arr);
}