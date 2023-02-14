#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Brute Force Code :- generate all subarrays. */
    // Time Complexity:- O(n^3)
    // Space Complexity:- O(1)
    int maxLen_BruteForce_1(vector<int> &arr, int n)
    {
        // variable for storing maximum length of subarray having sum equals to 0.
        int maximumLength = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the sum of each subarray.
                int sum = 0;

                for (int k = i; k <= j; k++)
                {
                    sum += arr[k];
                    // cout << arr[k] << " ";
                }
                // computing maximum length.
                if (sum == 0)
                {
                    maximumLength = max(maximumLength, j - i + 1);
                }
                // cout << " sum : " << sum << " and Length : " << (j - i + 1) << endl;
            }
        }

        return maximumLength;
    }

    /* Optimizing Brute Force Approach :- instead of using 3 loops, we can also generate all subarrays with nested loops (2 loops). */
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    int maxLen_BruteForce_2(vector<int> &arr, int n)
    {
        // variable for storing maximum length of subarray having sum equals to 0.
        int maximumLength = 0;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the sum of each subarray.
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                // computing maximum length.
                if (sum == 0)
                {
                    maximumLength = max(maximumLength, j - i + 1);
                }
            }
        }

        return maximumLength;
    }

    /* Optimized Code :- using hashing. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    int maxLen_Optimized(vector<int> &arr, int n)
    {
        // map to store prefix sum of array.
        unordered_map<int, int> preSum;

        // variable for calculation prefix sum.
        int sum = 0;

        // variable for storing maximum length of subarray having sum equals to 0.
        int maximumLength = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == 0)
            {
                maximumLength = i + 1; 
            }
            else
            {
                if (preSum.find(sum) != preSum.end())
                {
                    maximumLength = max(maximumLength, i - preSum[sum]);
                }
                else
                {
                    preSum[sum] = i;
                }
            }
        }

        return maximumLength;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << s.maxLen_Optimized(arr, arr.size());
}