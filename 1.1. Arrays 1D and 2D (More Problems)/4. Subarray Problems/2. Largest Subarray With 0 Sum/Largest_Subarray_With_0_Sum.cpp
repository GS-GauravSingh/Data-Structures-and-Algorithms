#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Using 3 loops, generate all subarrays and then find the length of the largest subarray having sum 0. */
    // Time Complexity: O(n^3), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int maxLen_BruteForce(vector<int> &arr, int n)
    {
        // variable to store the maximum length.
        int maximumLength = 0;

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

                // Check whether the sum of current subarray is equal to 0 or not. If yes, then update the maximum length, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    maximumLength = max(maximumLength, j - i + 1);
                }
            }
        }

        // return the maximum length.
        return maximumLength;
    }

    /* Better Approach: Instead of using 3 loops we can generate all subarrays using nested loops and then find the length of the largest subarray having sum 0. */
    // Time Complexity: O(n^2), where 'n' is the size of the array.
    // Space Complexity: O(1).
    int maxLen_Better(vector<int> &arr, int n)
    {
        // variable to store the maximum length.
        int maximumLength = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable to calculate sum of particular subarray.
                int subarraySum = 0;

                // sum.
                subarraySum += arr[j];

                // Check whether the sum of current subarray is equal to 0 or not. If yes, then update the maximum length, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    maximumLength = max(maximumLength, j - i + 1);
                }
            }
        }

        // return the maximum length.
        return maximumLength;
    }

    /* Optimized Approach: Using Maths and Hashing. */
    // Time Complexity: O(n), where 'n' is the size of the array.
    // Space Complexity: O(n), space used by unordered_map.
    int maxLen_Optimized(vector<int> &arr, int n)
    {
        // variable to store the maximum length.
        int maximumLength = 0;

        // unordered_map to store prefix/cumulative sum of array correspond to its index.
        unordered_map<int, int> map;

        // variable to calculate prefix sum of array.
        int prefixSum = 0;

        // Traverse the array and find the answer.
        for (int i = 0; i < n; i++)
        {
            // update prefix sum.
            prefixSum += arr[i];

            // Check, whether this prefixSum has already been seen before or not.
            // If this prefixSum has already been seen before, it means there is an subarray whose sum equals to 0.
            if (map.find(prefixSum) != map.end())
            {
                maximumLength = max(maximumLength, i - map[prefixSum]);
            }
            else
            {
                // insert the prfix sum into the map with its index.
                map[prefixSum] = i;
            }

            // Corner Cases.
            // IF the array itself contains 0, in this case a subarray already exists in the array whose sum equals to 0.
            if (arr[i] == 0)
            {
                maximumLength = max(maximumLength, 1 /* length of single element is 1. */);
            }

            if (prefixSum == 0)
            {
                maximumLength = max(maximumLength, i + 1);
            }
        }

        // return maximum length.
        return maximumLength;
    }

public:
    /* Question: Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0. */
    int maxLen(vector<int> &arr, int n)
    {
        // // Brute Force Approach.
        // maxLen_BruteForce(arr, n);

        // // Better  Approach.
        // maxLen_Better(arr, n);

        // Optimized Approach.
        return maxLen_Optimized(arr, n);
    }
};

int main(void)
{
    vector<int> arr{15, -2, 2, -8, 1, 7, 10, 23};

    // Solution.
    Solution obj;

    cout << "Length of largest Subarray with sum 0: " << obj.maxLen(arr, arr.size());
    return 0;
}