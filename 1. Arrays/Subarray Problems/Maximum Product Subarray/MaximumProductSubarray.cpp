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
    int maxProduct_Approach_1(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum product subarray..
        int maxP = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // variable for calculating the product of each subarray.
                int product = 1;
                for (int k = i; k <= j; k++)
                {
                    product *= nums[k];
                }

                // maximum product subarray.
                maxP = max(maxP, product);
            }
        }

        return maxP;
    }

    /* Approach 2 :- Instead of using 3 loops, we can generate all subarrays using nested loops (2 loops).  */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int maxProduct_Approach_2(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum product subarray..
        int maxP = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            // variable for calculating the product of each subarray.
            int product = 1;
            for (int j = i; j < n; j++)
            {

                product *= nums[j];

                // maximum product subarray.
                maxP = max(maxP, product);
            }
        }

        return maxP;
    }

    /* Approach 3 :- using kadanes algorithm with slight variation. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int maxProduct_Approach_3(vector<int> &nums)
    {

        // size of array.
        int n = nums.size();

        // variable for storing maximum product subarray..
        int maxP = nums[0];

        int maxValue = nums[0];
        int minValue = nums[0];

        for (int i = 1; i < n; i++)
        {
            // When multiplied by -ve number,
            // maxVal becomes minVal
            // and minVal becomes maxVal.
            if (nums[i] < 0)
            {
                swap(maxValue, minValue);
            }

            // maxVal and minVal stores the
            // product of subarray ending at arr[i].
            maxValue = max(nums[i], maxValue * nums[i]);
            minValue = min(nums[i], minValue * nums[i]);

            // Max Product of array.
            maxP = max(maxP, maxValue);
        }

        return maxP;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};

    Solution S;
    cout << S.maxProduct_Approach_1(nums) << endl;
    cout << S.maxProduct_Approach_2(nums) << endl;
    cout << S.maxProduct_Approach_3(nums);
}