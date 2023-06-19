#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: A divisible subset is the one in which if we pick two elements i and j from the subset, then either arr[i]%arr[j] == 0 or arr[j] % arr[i] == 0.

    For example, [16,8,4] is a divisible subset.
    Explanation: Divisible Pairs : {16, 8}, {16, 4}, {4, 8}, either arr[i]%arr[j] == 0 or arr[j] % arr[i] == 0, all pairs are divisible.
    */

   // Time Complexity: O(N*N).
    // Space Complexity: O(N).
    vector<int> divisibleSet(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<int> dp(n, 1);
        vector<int> hash(n);

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (arr[i] % arr[prevIdx] == 0 && 1 + dp[prevIdx] > dp[i])
                {
                    dp[i] = 1 + dp[prevIdx];
                    hash[i] = prevIdx;
                }
            }
        }

        int ans = -1;
        int lastIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                lastIdx = i;
            }
        }

        // Storing LIS.
        vector<int> temp;
        temp.push_back(arr[lastIdx]);

        while (hash[lastIdx] != lastIdx)
        {
            lastIdx = hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};

int main(void)
{
    vector<int> arr = {1, 16, 7, 8, 4};

    // Solution.
    Solution S;
    vector<int> ans = S.divisibleSet(arr);

    cout << " The longest divisible subset elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}