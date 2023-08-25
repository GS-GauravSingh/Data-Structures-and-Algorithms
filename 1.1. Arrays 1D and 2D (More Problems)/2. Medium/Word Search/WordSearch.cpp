#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Recursive Method to check whether a given 'word' is present in the 'board' or not. */
    // Time Complexity: O(m*n * 4^k), where 'm' is the number of row and 'n' is the number of column of the matrix 'board'.= and 'k' is the length of the string 'word'.
    // Space Complexity: O(k), recursive stack space.
    bool isWordExist(int i, int j, int idx, string word, vector<vector<char>> &board)
    {
        // Base Case.

        // Checking for out of bounds.
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }

        // When idx >= word.length(), it means we have traverse all the character of the word and it means that the 'word 'is present in the board. So return true from here.
        if (idx >= word.length())
        {
            return true;
        }

        // Now, check whether the character present at this cell, matches with the character 'word[idx]' or not.
        // If not matches, then return false.
        if (board[i][j] != word[idx])
        {
            return false;
        }

        // else, if the above if condition does not evaluate to true, it means both the character matches. Now, search for the next character of the word (increment idx).

        // Now, we can search for a character in adjacent cell, where adjacent cells are horizontally or vertically neighboring.
        // It means, in total we have 4-neighbors, Top, Down, left and Right.

        // After the current character is matched, set this character to some other different character, so that the same letter cell is not used more than once.
        board[i][j] = '#';

        // Top-Neighbor.
        bool top_neighbor = isWordExist(i - 1, j, idx + 1, word, board);

        // Right-Neighbor.
        bool right_neighbor = isWordExist(i, j + 1, idx + 1, word, board);

        // Bottom-Neighbor.
        bool bottom_neighbor = isWordExist(i + 1, j, idx + 1, word, board);

        // Left-Neighbor.
        bool left_neighbor = isWordExist(i, j - 1, idx + 1, word, board);

        // After exploring all the neighbors, in search for the character 'word[idx]'. Revert back this cell into its original state.
        board[i][j] = word[idx];

        // Now, from any of the above 4 options, if we are able to find the word, in that case we return true.
        return (top_neighbor || right_neighbor || bottom_neighbor || left_neighbor);
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {

        // Corner Case.
        if (board.size() == 1 && board[0].size() == 1 && word.length() == 1)
        {
            return board[0][0] == word[0];
        }

        // Now, first we have to find the first character of the word, because if the word is present in the board, then all the character of words are present in sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    // first character was found, now search for the rest of the characters of word.
                    if (isWordExist(i, j, 0, word, board) == true)
                    {
                        return true;
                    }
                }
            }
        }

        // If word is not present, then return false.
        return false;
    }
};

int main(void)
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "ABCCED";

    // SOlution.
    Solution obj;
    cout << ((obj.exist(board, word) == true) ? "Word Exist." : "Word not Exist.");

    return 0;
}