#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Time Complexity: O(n^2), where 'n' is the 'numRows'.
    // Space Complexity: O(n^2), space used by 'ans' vector to store pascal's triangle.
    vector<int> generate_Brute(int numRows)
    {

        // Create a 2D vector ans with numRows rows. Each row will store the elements of Pascal's Triangle.
        // We have to return the 'numRow'th row, that's why we have to declare 2D vector that contains total numRows+1 rows.
        vector<vector<int>> ans(numRows + 1);

        // Iterate i from 0 to numRows (because we have to return the 'numRow'th row) to generate each row of Pascal's Triangle.
        for (int i = 0; i <= numRows; i++)
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

        // return the 'rowIndex' row of the pascal triangle.
        return ans[numRows];
    }

    // Space optimizations.
    // We can optimize the above code, instead of using 2D vector to store entire pascal triangle, we can use 2, 1D arrays to store the previous row and current row.
    // Time Complexity: O(n^2), where 'n' is the 'numRows'.
    // Space Complexity: O(n) + O(n) ~ O(n), space used by vector to store pascal's triangle.
    vector<int> generate_Better(int numRows)
    {

        // Previous Row
        vector<int> prevRow(1, 1);

        // Iterate i from 0 to numRows (because we have to return the 'numRow'th row) to generate each row of Pascal's Triangle.
        for (int i = 1; i <= numRows; i++)
        {
            // Current Row
            vector<int> currRow(i + 1, 0);

            // Within each row, iterate j from 0 to i (inclusive) to generate the elements of that row.
            for (int j = 0; j <= i; j++)
            {
                // If j is either the first element (j == 0) or the last element (j == i) of the row, set the value to 1, as those elements in Pascal's Triangle are always 1.
                if (j == 0 || j == i)
                {
                    currRow[j] = 1;
                }

                // For other elements in the row, their values are calculated by summing the top and top-left elements of the previous row.
                else
                {
                    currRow[j] = prevRow[j - 1] + prevRow[j];
                }
            }

            // After the above loop ends, our current row will become previous row.
            // So, update the vectors.
            prevRow = currRow;
        }

        // return the 'prevRow'.
        // prevRow will contains the element os the last row of pascal triangle.
        return prevRow;
    }

    // Space optimizations.
    // We can optimize the above code, instead of using 2, 1D vectors, we can use only a single 1D array.
    // Time Complexity: O(n^2), where 'n' is the 'numRows'.
    // Space Complexity: O(n), space used by vector to store pascal's triangle.
    vector<int> generate_Optimal(int numRows)
    {

        // Previous Row
        vector<int> prevRow(numRows + 1, 1);

        // Iterate i from 0 to numRows (because we have to return the 'numRow'th row) to generate each row of Pascal's Triangle.
        for (int i = 1; i <= numRows; i++)
        {
            // Within each row, iterate j from 0 to i (inclusive) to generate the elements of that row.
            for (int j = i; j >= 0; j--)
            {
                // If j is either the first element (j == 0) or the last element (j == i) of the row, set the value to 1, as those elements in Pascal's Triangle are always 1.
                if (j == 0 || j == i)
                {
                    prevRow[j] = 1;
                }

                // For other elements in the row, their values are calculated by summing the top and top-left elements of the previous row.
                else
                {
                    prevRow[j] = prevRow[j - 1] + prevRow[j];
                }
            }
        }

        // return the 'prevRow'.
        // prevRow will contains the element os the last row of pascal triangle.
        return prevRow;
    }

public:
    vector<int> getRow(int rowIndex)
    {
        // return the 'rowIndex' row of the pascal triangle.
        return generate_Optimal(rowIndex);
    }
};

int main(void)
{
    int rowIdx = 5;

    // Solution.
    Solution obj;
    vector<int> row = obj.getRow(rowIdx);

    for (auto i : row)
    {
        cout << i << " ";
    }
    return 0;
}