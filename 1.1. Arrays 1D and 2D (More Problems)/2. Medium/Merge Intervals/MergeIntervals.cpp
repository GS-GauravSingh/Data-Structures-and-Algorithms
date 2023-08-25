#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n log(n)) is for sorting the intervals vector + O(n) is for merging overlapping intervals, where 'n' is the number of rows in intervals vector.
    // Space Complexity: O(n*2), space used by answer vector to store intervals.
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        // size of intervals vector.
        int n = intervals.size();

        // sort the givne intervals vector.
        sort(intervals.begin(), intervals.end());

        // vector to store answer.
        vector<vector<int>> ans;

        // Push the first interval (0th interval) into answer vector.
        ans.push_back(intervals[0]);

        // Traverse the intervals vector and merge the overlapping intervals.
        for (int i = 1; i < n; i++)
        {
            // checking for overlapping intervals
            if (ans.back()[1] >= intervals[i][0])
            {
                // If the above condition evaluates to true, it means this (ans.back() and intervals[i]) is a overlapping intervals and we have to merge it into a single one.
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                // If the above condition evaluates to false, it means this 'intervals[i]' is not a overlapping intervals, so push it into the answer vector as it is.
                ans.push_back(intervals[i]);
            }
        }

        // finally return answer.
        return ans;
    }
};

int main(void)
{
    vector<vector<int>> intervals{
        {8, 10},
        {2, 6},
        {15, 18},
        {1, 3},
    };

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}