/*
Question :-
Given an integer array nums, find the subarray with the largest sum, and return its sum.


Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.


Constraints:

1 <= nums.length <= 10^5
-104 <= nums[i] <= 10^4


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
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
    int maxSubArray_Approach_1(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum subarray sum.
        int maxSubArraySum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the sum of each subarray.
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                    cout << nums[k] << " ";
                }
                cout << " Sum = " << sum;
                cout << endl;

                // maximum subarray sum.
                maxSubArraySum = max(maxSubArraySum, sum);
            }
        }

        return maxSubArraySum;
    }

    /* Approach 2 :- Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops).  */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int maxSubArray_Approach_2(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum subarray sum.
        int maxSubArraySum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the sum of each subarray.
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];

                // maximum subarray sum.
                maxSubArraySum = max(maxSubArraySum, sum);
            }
        }

        return maxSubArraySum;
    }

    /* Approach 3 :- Using Prefix Array.  */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(n)
    int maxSubArray_Approach_3(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum subarray sum.
        int maxSubArraySum = INT_MIN;

        // prefix sum array.
        vector<int> prefix;
        int preSum = 0;
        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            prefix.push_back(preSum);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = (i > 0) ? (prefix[j] - prefix[i - 1]) : prefix[j];
                // maximum subarray sum.
                maxSubArraySum = max(maxSubArraySum, sum);
            }
        }

        return maxSubArraySum;
    }

    /* Optimized Approach :- Kadane's Algorithm. */
    // Time Complexity :- o(n)
    // Space Complexity :- o(1)

    // Note:-  if a testcase contains all negative elements then this code is not work as expected. Use the below code this will work on all the testcases.
    int KadanesAlgorithm_01(vector<int> &arr)
    {
        // size of vector.
        int n = arr.size();

        int maxSum = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++)
        {
            currSum += arr[i];

            if (currSum < 0)
            {
                currSum = 0;
            }

            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int KadanesAlgorithm_02(vector<int> &arr)
    {
        // size of vector.
        int n = arr.size();

        int maxSum = arr[0];
        int currSum = arr[0];

        for (int i = 1; i < n; i++)
        {
            currSum += arr[i];

            if (currSum < arr[i])
            {
                currSum = arr[i];
            }

            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution S;
    cout << "Maximum Subarray sum (Approach 1) = " << S.maxSubArray_Approach_1(nums) << endl;
    cout << "Maximum Subarray sum (Approach 2) = " << S.maxSubArray_Approach_2(nums) << endl;
    cout << "Maximum Subarray sum (Approach 3) = " << S.maxSubArray_Approach_3(nums) << endl;
    cout << "Maximum Subarray sum (Kadane's Algo.) = " << S.KadanesAlgorithm_01(nums) << endl;
    cout << "Maximum Subarray sum (Kadane's Algo. (variation)) = " << S.KadanesAlgorithm_02(nums) << endl;
}