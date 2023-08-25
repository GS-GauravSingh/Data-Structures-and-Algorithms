#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Time Complexity: O(n log(n)) is for sorting the intervals vector + O(n) is for merging overlapping intervals, where 'n' is the number of rows in intervals vector.
    // Space Complexity: O(n*2), space used by answer vector to store intervals.
    vector<vector<int>> mergeIntervalsmergeIntervals_InputIsNotSorted(vector<vector<int>> &intervals)
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

    // Time Complexity: O(n) is for merging overlapping intervals, where 'n' is the number of rows in intervals vector.
    // Space Complexity: O(n*2), space used by answer vector to store intervals.
    vector<vector<int>> mergeIntervals_InputIsSorted(vector<vector<int>> &intervals)
    {

        // size of intervals vector.
        int n = intervals.size();

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

public:
    // Time Complexity: O(n) is for merging overlapping intervals, where 'n' is the number of rows in intervals vector.
    // Space Complexity: O(n*2), space used by answer vector to store intervals.
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        // Base Case
        if (intervals.empty())
        {
            return {newInterval};
        }

        // Creating a copy of original 'intervals' vector because I don't want to modify original vector.
        // vector<vector<int>> temp = intervals;

        // Now, push the new interval into the temp vector.
        // temp.push_back(newInterval);

        /* A small optimization we can can done is: Since the 'intervals' vector is sorted in ascending order and initially there is no overlapping intervals. So, instead of pushing 'newInterval' at the back of the 'temp' vector. What we can do is, we can insert 'newinterval' into its correct position and when the 'newInterval' is inserted into ints correct position, we can perform merging of overlapping intervals and there is no need sort the intervals while merging overlapping intervals, because intervals are already sorted. */

        // Inserting 'newIntervals' into its correct position.

        // creaing a new vector to store all intervals.
        vector<vector<int>> temp2;

        // traverse the intervals vector and insert the newInterval into its correct position.
        for (int i = 0; i < intervals.size(); i++)
        {
            // Intervals are sorted based on the start interval [start interval, end interval].
            if (intervals[i][0] > newInterval[0])
            {
                // Insert new interval.
                temp2.push_back(newInterval);

                // Insert current interval, if you don'y insert this interval, then it would be skipped.
                temp2.push_back(intervals[i]);
            }
            else
            {
                temp2.push_back(intervals[i]);
            }
        }

        // If the insertion is successful, the the size of temp2 vector is equalt to (intervals.size() + newInterval.size()), but is the size of temp2 vector is != (intervals.size() + newInterval.size()), it means the correct position of newInterval is at the end of the intervals vector.
        if (temp2.size() != intervals.size() + newInterval.size())
        {
            temp2.push_back(newInterval);
        }

        // Merge the overlapping intervals.
        vector<vector<int>> ans = mergeIntervals_InputIsSorted(temp2);

        // Finally return answer.
        return ans;
    }
};

int main(void)
{
    vector<vector<int>> intervals{
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18},
    };

    vector<int> newInterval{11, 14};

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);

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