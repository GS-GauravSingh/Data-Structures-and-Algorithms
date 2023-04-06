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
    bool subarrayWithZeroSum_Approach_1(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

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

                // if the sum of subarray is 0, then return true.
                if (sum == 0)
                {
                    return true;
                }
            }
        }

        // return false, if we don't find any subarray with sum 0.
        return false;
    }

    /* Approach 2 :- Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops).  */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    bool subarrayWithZeroSum_Approach_2(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the sum of each subarray.
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];

                // if the sum of subarray is 0, then return true.
                if (sum == 0)
                {
                    return true;
                }
            }
        }

        // return false, if we don't find any subarray with sum 0.
        return false;
    }

    /* Approach 3 :- The idea is to iterate through the array and for every element arr[i], calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero-sum array.  */

    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    bool subarrayWithZeroSum_Approach_3(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // map to store cumulative sum of array.
        unordered_map<int, int> seen;

        // variable for calculating the prefix sum..
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate prefix sum.
            sum += nums[i];

            // check, if current sum has been seen before or not.
            if (seen.find(sum) != seen.end())
            {
                // means this sum has been seen before, it means there is a subarray having sum = 0.
                return true;
            }

            // if the array itself contains an element 0 and it may possible that the sum is = 0.
            // in both the cases return true.
            if (nums[i] == 0 || sum == 0)
            {
                return true;
            }

            // store prefix sum into map.
            seen[sum]++;
        }

        // return false, if we don't find any subarray with sum 0.
        return false;
    }
};

int main()
{
    vector<int> nums = {4, 2, -3, 1, 6};

    Solution S;
    cout << S.subarrayWithZeroSum_Approach_1(nums) << endl;
    cout << S.subarrayWithZeroSum_Approach_2(nums) << endl;
    cout << S.subarrayWithZeroSum_Approach_3(nums);
}