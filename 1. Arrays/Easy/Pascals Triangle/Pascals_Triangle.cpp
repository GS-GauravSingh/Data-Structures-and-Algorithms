#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Solution Class -------------------- */
class Solution
{
private:
public:
    /* Method to print Pascal's Triangle. */
    void print2DVec(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {

            for (int j = 0; j < arr.size() - i - 1; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    /* Method to generate Pascal's Triangle. */
    // Time Complexity:- O(row * col).
    // Space Complexity:- O(row * col).
    vector<vector<int>> generate(int numRows)
    {
        // 2d vector to strore answer.
        vector<vector<int>> pascalTriangle(numRows);

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    pascalTriangle[i].push_back({1});
                }
                else
                {

                    pascalTriangle[i].push_back(pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]);
                }
            }
        }

        return pascalTriangle;
    }
};

int main()
{
    Solution S;

    int numRows = 5;

    vector<vector<int>> pascalTriangle = S.generate(numRows);

    S.print2DVec(pascalTriangle);
}