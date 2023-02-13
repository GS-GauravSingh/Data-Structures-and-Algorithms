#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    // Time Complexity:- O(n log(n)), n is the size of vector.
    // Space Complexity:- O(N) to return the answer of the merged intervals.
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int k = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[k][1] >= intervals[i][0])
            {
                ans[k][1] = max(ans[k][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
                k++;
            }
        }
        return ans;
    }

    /* Method to print 2D vector. */
    void print(vector<vector<int>> arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            int col = arr[i].size();
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18},
    };

    Solution s;
    vector<vector<int>> ans;
    ans = s.merge(intervals);
    s.print(ans);
}