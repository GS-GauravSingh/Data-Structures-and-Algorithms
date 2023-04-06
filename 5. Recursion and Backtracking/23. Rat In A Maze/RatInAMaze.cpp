#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    // Time Complexity :- O(4^n*n)
    // Space Complexity :- O(n*n)
    void generateAllPaths(int i, int j, int row, int col, string &path, vector<string> &allPaths, vector<vector<int>> &grid)
    {

        // Base Case

        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0)
        {
            return;
        }

        else if (i == row - 1 && j == col - 1)
        {
            // means, we reached the last cell.
            allPaths.push_back(path);
            return;
        }
        else
        {

            // Recursive Case.
            // mark this cell as visited.
            grid[i][j] = 0;

            // Down
            path.push_back('D');
            generateAllPaths(i + 1, j, row, col, path, allPaths, grid);
            path.pop_back();

            // Left
            path.push_back('L');
            generateAllPaths(i, j - 1, row, col, path, allPaths, grid);
            path.pop_back();

            // Right
            path.push_back('R');
            generateAllPaths(i, j + 1, row, col, path, allPaths, grid);
            path.pop_back();

            // Up
            path.push_back('U');
            generateAllPaths(i - 1, j, row, col, path, allPaths, grid);
            path.pop_back();

            // undo the changes.
            grid[i][j] = 1;
        }
    }

public:
    vector<string> searchMaze(vector<vector<int>> &grid, int n)
    {
        vector<string> allPaths;
        string path;

        generateAllPaths(0, 0, n, n, path, allPaths, grid);

        return allPaths;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1},
    };

    Solution S;
    vector<string> allPaths = S.searchMaze(grid, grid.size());

    for (string str : allPaths)
    {
        cout << str << " ";
    }
}