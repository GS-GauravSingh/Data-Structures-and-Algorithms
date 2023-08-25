#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n*log(n)) for sorting 'intervals' vector + O(n) for finding answer, where 'n' is the size of the 'intervals' vector.
    // Space Complexity: O(1).
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        // Sort the given vector.
        sort(intervals.begin(), intervals.end());

        // Variable to track the end point of previous interval.
        int prevEnd = intervals[0][1];

        // variable to store the number of intervals we removed.
        int cnt = 0;

        // Traverse the intervals and find the answer.
        for (int i = 1; i < intervals.size(); i++)
        {
            // Overlapping Condition.
            if (prevEnd > intervals[i][0])
            {
                /*
                When 'prevEnd > intervals[i][0]', it means there is an overlap between the previous interval and current interval. Now, you need to decide which interval you need to remove.

                Example: Consider these 3 intervals : [1, 2], [1, 3], [2, 3]

                And initially and pointer:      [1,   2],    [1, 3],  [2, 3]
                                                   prevEnd    current

                Now these 2 intervals ([1, 2] and [1, 3]) are overlapping intervals.

                Case 1: Remove interval [1, 2],
                    Now, if I remove this interval [1, 2], in this example we can clearly see that after removing interval [1, 2], we need to remove 1 more interval to make the intervals non-overlapping. So, if we remove the interval with a smaller endpoint, it may be possible that the interval with a larger endpoint is merged with another interval.

                    So, after removing interval [1, 2]: these intervals are still overlapping : [1, 3], [2, 3].

                Case 2: Remove interval [1, 3],
                    But if we remove the interval with smaller endpoint, then there is a chance that this interval may not merge with the other interval.
                    So, after removing interval [1, 3]: these intervals are not overlapping : [1, 2], [2, 3].
                */

                // Increment the count, because from previous interval and current interval, we are removing the interval having larger endpoint.
                cnt++;

                // Now, Update the prevEnd with the smaller ending point.
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
            {

                // This menas that, there is no overlap between the previous interval and current interval.
                // So, update the prevEnd with the endpoint of current interval.
                prevEnd = intervals[i][1];
            }
        }

        // return answer.
        return cnt;
    }
};

int main(void)
{
    vector<vector<int>> intervals{
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3},
    };

    // Solution.
    Solution obj;
    cout << obj.eraseOverlapIntervals(intervals);
    return 0;
}