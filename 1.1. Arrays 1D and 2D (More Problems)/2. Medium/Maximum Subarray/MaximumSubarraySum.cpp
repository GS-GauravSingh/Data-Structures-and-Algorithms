#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Approach 1: Generate all subarrays and then find the subarray with the maximum sum.

    Time Complexity: O(n^3), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int maxSubArray_BruteForce_1(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // variable to store maximum sum.
        int maxSum = INT_MIN;

        // Generating all subarrays.
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable to calculate sum of particular subarray.
                int sum = 0;

                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                // store maximum sum.
                maxSum = max(maxSum, sum);
            }
        }

        // return answer.
        return maxSum;
    }

    /* Approach 2: Instead of using 3 loops, we can Generate all subarrays using nested loops and then find the subarray with the maximum sum.

    Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int maxSubArray_BruteForce_2(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // variable to store maximum sum.
        int maxSum = INT_MIN;

        // Generating all subarrays.
        for (int i = 0; i < n; i++)
        {
            // variable to calculate sum of particular subarray.
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                // store maximum sum.
                maxSum = max(maxSum, sum);
            }
        }

        // return answer.
        return maxSum;
    }

    /* Approach 3: Using Perfix Array.

    Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    Space Complexity: O(n), space used by prefix array.
    */
    int maxSubArray_BruteForce_3(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // variable to store maximum sum.
        int maxSum = INT_MIN;

        // Prefix.
        vector<int> prefix;

        // storing prefix sum of nums array into prefix array.
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix.push_back(sum);
        }

        // Generating all subarrays.
        for (int i = 0; i < n; i++)
        {
            // variable to calculate sum of particular subarray.
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                // sum of each subarray.
                sum = (i > 0) ? (prefix[j] - prefix[i - 1]) : prefix[j];

                // store maximum sum.
                maxSum = max(maxSum, sum);
            }
        }

        // return answer.
        return maxSum;
    }

    /* Optimal Approach: Using Kadane's Algorithm.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int kadanesAlgorithm(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return nums[0];
        }

        // size of vector.
        int n = nums.size();

        // Needed variables.
        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < n; i++)
        {
            currSum += nums[i];

            if (currSum < nums[i])
            {
                currSum = nums[i];
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

public:
    int maxSubArray(vector<int> &nums)
    {

        // // Brute Force Approach 1.
        // return maxSubArray_BruteForce_1(nums);

        // // Brute Force Approach 2.
        // return maxSubArray_BruteForce_2(nums);

        // // Brute Force Approach 3.
        // return maxSubArray_BruteForce_3(nums);

        // Optimal Solution.
        return kadanesAlgorithm(nums);
    }
};

int main(void)
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Solution.
    Solution obj;
    cout << "Maximum Subarray Sum: " << obj.maxSubArray(nums) << ".";
    return 0;
}