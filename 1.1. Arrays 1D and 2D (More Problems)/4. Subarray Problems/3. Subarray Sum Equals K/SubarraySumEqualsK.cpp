#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Using 3 loops, generate all subarrays and then find the total number of subarrays whose sum is equals to k. */
    // Time Complexity: O(n^3), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int subarraySum_BruteForce(vector<int> &arr, int k)
    {
        // size of vector.
        int n = arr.size();

        // variable to store the count of subarrays whose sum is equal to k.
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable to calculate sum of particular subarray.
                int subarraySum = 0;

                for (int k = i; k <= j; k++)
                {
                    // sum.
                    subarraySum += arr[k];
                }

                // Check whether the sum of current subarray is equal to k or not. If yes, then count this subarray, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    cnt++;
                }
            }
        }

        // return the count.
        return cnt;
    }

    /* Better Approach: Instead of using 3 loops we can generate all subarrays using nested loops and then find the total number of subarrays whose sum is equals to k. */
    // Time Complexity: O(n^2), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int subarraySum_Better(vector<int> &arr, int k)
    {
        // size of vector.
        int n = arr.size();

        // variable to store the count of subarrays whose sum is equal to k.
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable to calculate sum of particular subarray.
                int subarraySum = 0;

                // sum.
                subarraySum += arr[j];

                // Check whether the sum of current subarray is equal to k or not. If yes, then count this subarray, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    cnt++;
                }
            }
        }

        // return the count.
        return cnt;
    }

    /* Optimized Approach: Using Maths and Hashing. */
    // Time Complexity: O(n), where 'n' is the size of the array.
    // Space Complexity: O(n), space used by unordered_map.
    int subarraySum_Optimized(vector<int> &arr, int k)
    {
        // size of vector.
        int n = arr.size();

        // variable to store the count of subarrays whose sum is equal to k.
        int cnt = 0;

        // declare an unordered map
        unordered_map<int, int> mp;

        // variable to calculate prefix Sum.
        int prefixSum = 0;

        // traverse from the prefix array
        for (int i = 0; i < n; i++)
        {
            // prefix sum.
            prefixSum += arr[i];

            // if prefixSum already becomes equal to k, then increment the count.
            if (prefixSum == k)
                cnt++;

            // now, check if (prefix[i] - k) is present in map or not
            if (mp.find(prefixSum - k) != mp.end())
            {
                // if yes, then update our answer with it's frequency.
                cnt += mp[prefixSum - k];
            }

            // store prefix sum in map with it's frequency.
            mp[prefixSum]++;
        }

        // return our answer
        return cnt;
    }

public:
    /* Question: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k. */
    int subarraySum(vector<int> &nums, int k)
    {
        // // Brute Force Approach.
        // subarraySum_BruteForce(nums, k);

        // // Better  Approach.
        // subarraySum_Better(nums, k);

        // Optimized Approach.
        return subarraySum_Optimized(nums, k);
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3};
    int k = 3;

    // Solution.
    Solution obj;
    cout << "Count: " << obj.subarraySum(nums, k) << ".";
    return 0;
}