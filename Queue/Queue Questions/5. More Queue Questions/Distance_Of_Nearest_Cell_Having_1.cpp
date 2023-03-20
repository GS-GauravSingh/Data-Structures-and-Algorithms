//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*  Brute force code:-
    Time Complexity: O(N^2*M^2).
    Space Complexity: O(1).
    */

    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        // Initializing the answer matrix with INT_MAX.
        vector<vector<int>> ans(grid.size(), vector<int>(c, INT_MAX));

        // For each cell, traverse the whole matrix and find minimum distance.
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                // Traversing the whole matrix
                // to find the minimum distance.
                for (int k = 0; k < r; k++)
                    for (int l = 0; l < c; l++)
                    {
                        // If cell contain 1, check
                        // for minimum distance.
                        if (grid[k][l] == 1)
                        {
                            ans[i][j] = min(ans[i][j], abs(i - k) + abs(j - l));
                        }
                    }
            }

        return ans;
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
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends