#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    // Time Complexity :- O(m*n)
    // Space Complexity :- O(m*n)
    void floodFillAlgorithm(int i, int j, int row, int col, int oldColor, int newColor, vector<vector<int>> &image)
    {
        // Base Case.
        if (i < 0 || j < 0 || i >= row || j >= col || image[i][j] != oldColor || image[i][j] == newColor)
        {
            return;
        }

        // Recursive case.
        // change the color.
        image[i][j] = newColor;

        // up
        floodFillAlgorithm(i - 1, j, row, col, oldColor, newColor, image);

        // down
        floodFillAlgorithm(i + 1, j, row, col, oldColor, newColor, image);

        // left
        floodFillAlgorithm(i, j - 1, row, col, oldColor, newColor, image);

        // right
        floodFillAlgorithm(i, j + 1, row, col, oldColor, newColor, image);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];
        int newColor = color;

        // corner case.
        if (oldColor == newColor)
        {
            return image;
        }

        floodFillAlgorithm(sr, sc, row, col, oldColor, newColor, image);

        return image;
    }

    /* Method to print 2D vector. */
    void print2D(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };

    int oldColor_X = 1;
    int oldColor_Y = 1;
    int newColor = 2;

    Solution S;
    vector<vector<int>> ans = S.floodFill(image, oldColor_X, oldColor_Y, newColor);
    S.print2D(ans);
}