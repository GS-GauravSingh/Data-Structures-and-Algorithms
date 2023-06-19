#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    static bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.second.second < b.second.second;
    }

public:
    /* Question: This proble is just an extension of previous problem "N Meeting in one room". In the previous question, we have to return the count of maximum meetings, but in this question, we need to print all meetings.

    Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting. */

    // Time Complexity: O(n log(n)), where 'n' is the size of the array.
    // Space Complexity: O(n), size of 'meetings' vector.
    vector<int> maxMeetings(int start[], int end[], int n)
    {
        // Sort both the array in terms of there ending time.
        vector<pair<int, pair<int, int>>> meetings;

        // insert (startTime, endTime) of all meetings in the above vector.
        for (int i = 0; i < n; i++)
        {
            int startTime = start[i];
            int endTime = end[i];
            int meetingNumber = i + 1;

            meetings.push_back({meetingNumber, {startTime, endTime}});
        }

        // Now, sort the 'meetings' vector according to the ending time of meetings.
        sort(meetings.begin(), meetings.end(), compare);

        vector<int> ans;
        ans.push_back(meetings[0].first);
        int prevEnd = meetings[0].second.second;
        for (int i = 1; i < n; i++)
        {
            if (meetings[i].second.first > prevEnd)
            {
                ans.push_back(meetings[i].first);
                prevEnd = meetings[i].second.second;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(void)
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    // Solution.
    Solution S;
    vector<int> ans = S.maxMeetings(start, end, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}