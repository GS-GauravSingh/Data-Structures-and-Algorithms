#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Time Complexity: O(9).
    // Space Complexity: O(1).
    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // Checking Row.
            // If we found any other occurrence of 'ch' in the row, then we return false.
            if (board[row][i] == ch)
            {
                return false;
            }

            // Checking Column.
            // If we found any other occurrence of 'ch' in the column, then we return false.
            if (board[i][col] == ch)
            {
                return false;
            }

            // Checking Sub-Matrix.
            // Formula for Finding Row index = 3 * (row / 3) + i / 3.
            // Formula for Finding Column index = 3 * (col / 3) + i % 3.
            int rowIdx = 3 * (row / 3) + i / 3;
            int colIdx = 3 * (col / 3) + i % 3;
            if (board[rowIdx][colIdx] == ch)
            {
                return false;
            }
        }

        return true;
    }

    /* Recursive Method to solve Sudoku. */
    // Time Complexity: O(row * col) * O(9).
    // Space Complexity: O(1).
    bool sudokuSolver(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // Empty Cell.
                if (board[row][col] == '.')
                {
                    // Try all possible values (1 to 9).
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        // Checking whether is it safe to put 'ch' in this cell or not.
                        if (isValid(board, row, col, ch) == true)
                        {
                            board[row][col] = ch;

                            // Call recursion and it will fill rest of the empty cells.
                            if (sudokuSolver(board))
                            {
                                return true;
                            }
                            else
                            {
                                // Backtracking step.
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

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        sudokuSolver(board);
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
    return 0;
}