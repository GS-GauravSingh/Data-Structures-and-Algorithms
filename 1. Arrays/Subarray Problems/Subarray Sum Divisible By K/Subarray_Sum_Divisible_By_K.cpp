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
    int subarraysDivByK_Approach_1(vector<int> &nums, int k)
    {

        // size of array.
        int n = nums.size();

        // variable to count total number of subarrays having sum % k == 0.
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

                // if sum % k == 0, increment count;
                if ((sum % k) == 0)
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
    int subarraysDivByK_Approach_2(vector<int> &nums, int k)
    {

        // size of array.
        int n = nums.size();

        // variable to count total number of subarrays having sum % k == 0.
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the sum of each subarray.
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];

                // if sum % k == 0, increment count;
                if ((sum % k) == 0)
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
    int subarraysDivByK_Optimized(vector<int> &nums, int k)
    {

        // size of the vector
        int n = nums.size();

        // variable to count total number of subarrays having sum % k == 0.
        int count = 0;

        // map to store cumulative sum of array.
        unordered_map<int, int> mpp;
        mpp[0] = 1; // initially our cumulative sum is 0.

        // to calculate prefix sum.
        int prefixSum = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            int remainder = prefixSum % k;
            if (remainder < 0)
            {
                remainder += k;
            }

            if (mpp.find(remainder) != mpp.end())
            {
                count += mpp[remainder];
            }

            mpp[remainder]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution S;

    cout << S.subarraysDivByK_Approach_1(nums, k) << endl;
    cout << S.subarraysDivByK_Approach_2(nums, k) << endl;
    cout << S.subarraysDivByK_Optimized(nums, k) << endl;
}