#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Tabulation algorithm to find the length of the longest increasing subsequence. */
    // Time Complexity: O(n*n), where 'n' is the size of the vector.
    // Space Complexity: O(n), size of both vectors.
    void solveOptimized(int n, int *arr)
    {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }
        

        for (int i = 0; i < n; i++)
        {
            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (arr[prevIdx] < arr[i])
                {
                    dp[i] = max(dp[i], 1 + dp[prevIdx]);
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

        for (auto it : temp)
        {
            cout << it << " ";
        }
    }

public:
    void printLongestIncreasingSubsequence(int arr[], int n)
    {
        solveOptimized(n, arr);
    }
};

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;
    S.printLongestIncreasingSubsequence(arr, n);
    return 0;
}