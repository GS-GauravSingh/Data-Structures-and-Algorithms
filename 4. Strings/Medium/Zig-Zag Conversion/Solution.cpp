#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // Time Complexity: O(n^2), where 'n' is the length of the string.
    // Space Complexity: O(numRows * 1000), space used by auxiliary vector. 
    string convert(string str, int numRows)
    {
        // Base Case
        if (numRows == 1)
        {
            return str;
        }

        // Length of the string "str".
        int n = str.length();

        // 2D vector to store Zig-Zag Traversal.
        vector<vector<char>> matrix(numRows, vector<char>(1000, ' '));

        // Variable to keep track of the traversed characters of string "str".
        int cnt = 0;

        // Important Variables.
        // I am using these variables to store all the character in Zig-Zag Order.
        int row = 0, col = 0;

        // string to store answer.
        string ans = "";

        while (cnt < n)
        {
            // Down.
            for (int down = 0; cnt < n && down < matrix.size(); down++)
            {
                if (matrix[row][col] == ' ')
                {
                    matrix[row][col] = str[cnt++];
                    row++;
                }
                else
                {
                    row++;
                }
            }

            row = row - 1;

            // Diagonal.
            for (int diag = 0; cnt < n && diag < matrix.size(); diag++)
            {
                if (matrix[row][col] == ' ')
                {
                    matrix[row][col] = str[cnt++];

                    row--;
                    col++;
                }
                else
                {

                    row--;
                    col++;
                }
            }

            row = row + 1;
            col = col - 1;
        }

        // Storing the answer.
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < 1000; j++)
            {
                if (matrix[i][j] == ' ')
                {
                    continue;
                }
                else
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};

int main(void)
{
    string str = "PAYPALISHIRING";
    int numRows = 4;

    // Solution.
    Solution obj;
    cout << obj.convert(str, numRows);
    return 0;
}