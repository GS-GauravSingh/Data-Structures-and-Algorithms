/*
Question :-
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:
Input: nums = [1,1,1], k = 2
Output: 2


Example 2:
Input: nums = [1,2,3], k = 3
Output: 2


Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- generating all subarrays.  */
    // Time Complexity :- O(n^3)
    // Space Complexity :- O(1)
    int subarraySum_Approach_1(vector<int> &nums, int k)
    {

        // size of array.
        int n = nums.size();

        // variable to count total number of subarrays having sum = k.
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the sum of each subarray.
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                // if sum == k, increment count;
                if (sum == k)
                {
                    count++;
                }
            }
        }

        return count;
    }

    /* Approach 2 :- Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops).  */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int subarraySum_Approach_2(vector<int> &nums, int k)
    {

        // size of array.
        int n = nums.size();

        // variable to count total number of subarrays having sum = k.
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the sum of each subarray.
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];

                // if sum == k, increment count;
                if (sum == k)
                {
                    count++;
                }
            }
        }

        return count;
    }

    /* Approach 3 :- using prefix sum and map. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    int subarraySum_Approach_3(vector<int> &nums, int k)
    {

        // size of the vector
        int n = nums.size();

        // prefix array
        vector<int> prefix(n);

        // making our prefix array
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }

        // declare an unordered map
        unordered_map<int, int> mp;

        // to store the number of sybarrays whose sum equals to k.
        int count = 0;

        // traverse from the prefix array
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == k) // if it already becomes equal to k, then increment count
                count++;

            // now, check if (prefix[i] - k) is present in map or not
            if (mp.find(prefix[i] - k) != mp.end())
            {
                // if yes, then update our answer with it's frequency.
                count += mp[prefix[i] - k];
            }

            // store prefix sum in map with it's frequency.
            mp[prefix[i]]++;
        }

        // return our answer
        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution S;
    cout << S.subarraySum_Approach_1(nums, k) << endl;
    cout << S.subarraySum_Approach_2(nums, k) << endl;
    cout << S.subarraySum_Approach_3(nums, k);
}