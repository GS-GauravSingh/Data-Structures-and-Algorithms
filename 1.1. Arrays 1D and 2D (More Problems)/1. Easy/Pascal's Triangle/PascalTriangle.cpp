#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n^2), where 'n' is the 'numRows'.
    // Space Complexity: O(n^2), space used by 'ans' vector to store pascal's triangle.
    vector<vector<int>> generate(int numRows)
    {

        // Create a 2D vector ans with numRows rows. Each row will store the elements of Pascal's Triangle.
        vector<vector<int>> ans(numRows);

        // Iterate i from 0 to numRows-1 to generate each row of Pascal's Triangle.
        for (int i = 0; i < numRows; i++)
        {
            // Within each row, iterate j from 0 to i (inclusive) to generate the elements of that row.
            for (int j = 0; j <= i; j++)
            {
                // If j is either the first element (j == 0) or the last element (j == i) of the row, set the value to 1, as those elements in Pascal's Triangle are always 1.
                if (j == 0 || j == i)
                {
                    ans[i].push_back(1);
                }

                // For other elements in the row, their values are calculated by summing the top and top-left elements of the previous row.
                else
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
        }

        // return final answer.
        return ans;
    }
};

int main(void)
{
    int numRows = 5;

    // Solution.
    Solution obj;
    vector<vector<int>> pascalTriangle = obj.generate(numRows);

    for (int i = 0; i < pascalTriangle.size(); i++)
    {
        // Printing Spaces.
        for (int k = 0; k < pascalTriangle.size() - i - 1; k++)
        {
            cout << " ";
        }

        for (int j = 0; j < pascalTriangle[i].size(); j++)
        {
            cout << pascalTriangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}