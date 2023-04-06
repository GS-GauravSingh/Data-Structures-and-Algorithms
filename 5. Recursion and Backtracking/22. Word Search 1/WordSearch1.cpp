#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    bool search(int i, int j, int row, int col, int k, string word, vector<vector<char>> &board)
    {
        // Base Case.
        if (k >= word.size())
        {
            // means, we found all character of word.
            return true;
        }

        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[k])
        {
            return false;
        }

        // Recursive case.
        // marking current characte as visited.
        char ch = board[i][j];
        board[i][j] = '#';

        // up
        bool op1 = search(i - 1, j, row, col, k + 1, word, board);

        // down
        bool op2 = search(i + 1, j, row, col, k + 1, word, board);

        // left
        bool op3 = search(i, j - 1, row, col, k + 1, word, board);

        // right
        bool op4 = search(i, j + 1, row, col, k + 1, word, board);

        // undo the changes.
        board[i][j] = ch;

        return (op1 || op2 || op3 || op4);
    }

public:
    // Time Complexity :- O(m*n*4^k)
    // Space Complexity :- O(k)
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    // we got the first character of given word.
                    // Now search rest of the using recursion.
                    if (search(i, j, board.size(), board[0].size(), 0, word, board) == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    string word = "ABCCED";

    Solution S;
    cout << S.exist(board, word);
}