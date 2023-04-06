#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n*m) 
// Space Complexity:- O(n)

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q; // used to store index of rotten oranges.

        // storing the index of rotten oranges.
        int row = grid.size();
        int col = grid[0].size();
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 2)
                {
                    q.push({r, c});
                }
            }
        }

        q.push({-1, -1}); // pushing a delimiter that indicates the beginning of the next time frame.
        int count = 0;    // used to store minimum time required to rot all oranges..
        while (!q.empty())
        {
            // extract the index of rotten oranges from queue and rot all adjacent oranges. While rotting the adjacent oranges, make sure that the time frame is incremented only once. And the time frame is not incremented if there are no adjacent oranges.
            int i = q.front().first;  // getting the row no. (i) of rotten orange.
            int j = q.front().second; // getting the col no. (j) of rotten orange.

            if (i == -1 && j == -1 && q.size() == 1)
            {
                // when i = j = -1, it means one frame is complete and we reaches the delimiter.
                // and q.size() == 1, it means all oranges are rotten.
                // So, pop the delimiter and break the loop.
                q.pop();
                break;
            }
            else if (i == -1 && j == -1 && q.size() > 1)
            {
                // when i = j = -1, it means one frame is complete and we reaches the delimiter.
                // and q.size() > 1, it may possible that after the completion of one frame some oranges are left that are fresh.
                // so, we need to rot them also.

                // in completion of one frame, increment the count and pop the old delimiter again.
                // and push the delimiter again;
                count++;
                q.pop();
                q.push({-1, -1});
            }
            else
            {
                // rot all adjacent oranges at same time,

                // up
                if ((i - 1) >= 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j}); // push the index the newly rotten orange.
                }

                // down
                if ((i + 1) < row && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j}); // push the index the newly rotten orange.
                }

                // left
                if ((j - 1) >= 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1}); // push the index the newly rotten orange.
                }

                // right
                if ((j + 1) < col && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1}); // push the index the newly rotten orange.
                }

                q.pop(); // after rotting all the adjacent oranges, pop this rotten orange.
            }
        }

        // after the above loop ends, check if all the fresh oranges are rotten or not.
        // if yes return count, else return -1.
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    return -1;
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends