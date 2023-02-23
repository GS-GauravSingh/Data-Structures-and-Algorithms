#include <bits/stdc++.h>
using namespace std;

/* ------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    bool isValid(int row, int col, int ch, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            // row
            if (board[row][i] == ch)
                return false;

            // col
            if (board[i][col] == ch)
                return false;

            // subMatrix
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }

        return true;
    }

public:
    bool solveSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == '.')
                {

                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(row, col, ch, board) == true)
                        {
                            board[row][col] = ch;

                            if (solveSudoku(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
};

int main(void)
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution S;
    S.solveSudoku(board);

    for (auto row : board)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}