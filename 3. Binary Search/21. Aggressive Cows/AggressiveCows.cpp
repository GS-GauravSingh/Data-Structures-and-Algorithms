#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach  :- Using Binary Search */
    // Time Complexity :- O(n * log(n))
    // Space Complexity :- O(1)
    bool isPossible(vector<int> &arr, int k, int mid)
    {
        int cowCount = 1;
        int lastPos = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] - lastPos >= mid)
            {
                cowCount++;
                if (cowCount == k)
                {
                    return true;
                }
                lastPos = arr[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int maxi = -1;
        for (int i = 0; i < stalls.size(); i++)
        {
            maxi = max(maxi, stalls[i]);
        }
        int e = maxi;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(stalls, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> stalls = {4, 2, 1, 3, 6};
    int cows = 2;

    Solution S;
    cout << S.aggressiveCows(stalls, cows);
}