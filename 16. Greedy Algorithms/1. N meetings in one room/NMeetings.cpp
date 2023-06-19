#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    static bool compare(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

public:
    /* Question: There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
    What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

    Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting. */

    // Time Complexity: O(n log(n)), where 'n' is the size of the array.
    // Space Complexity: O(n), size of 'meetings' vector.
    int maxMeetings(int start[], int end[], int n)
    {
        // Sort both the array in terms of there ending time.
        vector<pair<int, int>> meetings;

        // insert (startTime, endTime) of all meetings in the above vector.
        for (int i = 0; i < n; i++)
        {
            int startTime = start[i];
            int endTime = end[i];

            meetings.push_back({startTime, endTime});
        }

        // Now, sort the 'meetings' vector according to the ending time of meetings.
        sort(meetings.begin(), meetings.end(), compare);

        int cnt = 1;
        int prevEnd = meetings[0].second;
        for (int i = 1; i < n; i++)
        {
            if (meetings[i].first > prevEnd)
            {
                cnt++;
                prevEnd = meetings[i].second;
            }
        }

        return cnt;
    }
};

int main(void)
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    // Solution.
    Solution S;
    cout << S.maxMeetings(start, end, n);

    return 0;
}