#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Time Complexity: O(9).
    // Space Complexity: O(1).
    bool isValid(vector<vector<char>> &board, int row, int col, int ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // Checking Row.
            // If we found any other occurrence of 'ch' in the row, then we return false.
            if (i != col /* Ignoring curent cell. */ && board[row][i] == ch)
            {
                return false;
            }

            // Checking Column.
            // If we found any other occurrence of 'ch' in the column, then we return false.
            if (i != row /* Ignoring curent cell. */ && board[i][col] == ch)
            {
                return false;
            }

            // Checking Sub-Matrix.
            // Formula for Finding Row index = 3 * (row / 3) + i / 3.
            // Formula for Finding Column index = 3 * (col / 3) + i % 3.
            int rowIdx = 3 * (row / 3) + i / 3;
            int colIdx = 3 * (col / 3) + i % 3;
            if (rowIdx != row && colIdx != col /* Ignoring curent cell. */ && board[rowIdx][colIdx] == ch)
            {
                return false;
            }
        }

        return true;
    }

public:
    // Time Complexity: O(row * col) * O(9).
    // Space Complexity: O(1).
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // Traverse the board and find whether this sudoku is valid or not.
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // Now, to check whether this sudoku is valid or not.
                // To check the validity of a Sudoku, you need to ensure that no value is repeated in its row, column, or submatrix. If you find any value that appears more than once, the Sudoku is not valid.

                // We have to check on prefilled cells. So ignore unfilled cels.

                // Prefilled Cell.
                if (board[row][col] != '.')
                {
                    // store the character present at current cell.
                    char ch = board[row][col];

                    // If there is no repetition  of 'ch' either in its row, column, or submatrix. then the below function return true.
                    // But, if there is any repetition of 'ch' present either in its row, column, or submatrix. then the below function return false and it means this sudoku is not a valid sudoku.
                    if (isValid(board, row, col, ch) == false)
                    {
                        return false;
                    }
                }
            }
        }

        // Now, at this point, if the above loop does not return false, it means his is a valid sudoku. So return true.
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
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    // Solution.
    Solution obj;
    cout << obj.isValidSudoku(board);
    return 0;
}