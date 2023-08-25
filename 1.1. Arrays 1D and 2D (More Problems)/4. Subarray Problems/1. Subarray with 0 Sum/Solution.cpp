#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Using 3 loops, generate all subarrays and then find if there is a subarray (of size at-least one) with 0 sum present or not. */
    // Time Complexity: O(n^3), where 'n' is the size of the array.
    // Space Complexity: O(1).
    bool subArrayExists_BruteForce(int arr[], int n)
    {
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

                // Check whether the sum of current subarray is equalt to 0 or not. If yes, then return true, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    return true;
                }
            }
        }

        // return false if there is no subarray that has sum equal to 0.
        return false;
    }

    /* Better Approach: Instead of using 3 loops we can generate all subarrays using nested loops and then find if there is a subarray (of size at-least one) with 0 sum present or not. */
    // Time Complexity: O(n^2), where 'n' is the size of the array.
    // Space Complexity: O(1).
    bool subArrayExists_Better(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            // variable to calculate sum of particular subarray.
            int subarraySum = 0;

            for (int j = i; j < n; j++)
            {
                // sum.
                subarraySum += arr[j];

                // Check whether the sum of current subarray is equalt to 0 or not. If yes, then return true, otherwise continue checking for other subarrays.
                if (subarraySum == 0)
                {
                    return true;
                }
            }
        }

        // return false if there is no subarray that has sum equal to 0.
        return false;
    }

    /* Optimized Approach: Using Maths and Hashing. */
    // Time Complexity: O(n), where 'n' is the size of the array.
    // Space Complexity: O(n), space used by unordered_set.
    bool subArrayExists_Optimized(int arr[], int n)
    {
        // unordered_set to store prefix/cumulative sum of array.
        unordered_set<int> set;

        // variable to calculate prefix sum of array.
        int prefixSum = 0;

        // Traverse the array and find the answer.
        for (int i = 0; i < n; i++)
        {
            // update prefix sum.
            prefixSum += arr[i];

            // Check, whether this prefixSum has already been seen before or not.
            // If this prefixSum has already been seen before, it means there is an subarray whose sum equals to 0.
            if (set.find(prefixSum) != set.end())
            {
                return true;
            }

            // IF the array itself contains 0, in this case a subarray already exists in the array whose sum equals to 0.
            if (arr[i] == 0 || prefixSum == 0)
            {
                return true;
            }

            // insert the prfix sum into the set.
            set.insert(prefixSum);
        }

        // return false if there is no subarray that has sum equal to 0.
        return false;
    }

public:
    
    /* Question: Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum. */
    bool subArrayExists(int arr[], int n)
    {
        // // Brute Force Approach.
        // subArrayExists_BruteForce(arr, n);

        // // Better  Approach.
        // subArrayExists_Better(arr, n);

        // Optimized Approach.
        return subArrayExists_Optimized(arr, n);
    }
};

int main(void)
{
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(int);

    // Solution.
    Solution obj;
    if (obj.subArrayExists(arr, n))
        cout << "Yes.\n";
    else
        cout << "No.";
    return 0;
}