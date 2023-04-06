#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Solution Class --------------------------- */
class Solution
{
private:
    bool isSafe(int row, int col, int n, vector<string> &board)
    {
        // checking upper diagonal.
        int copyRow = row;
        int copyCol = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        // checking row.
        row = copyRow;
        col = copyCol;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }

            col--;
        }

        // checking lower diagonal.
        row = copyRow;
        col = copyCol;

        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        // Base Case.
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        // Recursive Case.
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string str(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = str;
        }

        solve(0, n, board, ans);

        return ans;
    }
};

int main(void)
{
    int n = 4;

    Solution S;
    vector<vector<string>> ans = S.solveNQueens(n);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << endl;
        }
        cout << endl;
    }
}