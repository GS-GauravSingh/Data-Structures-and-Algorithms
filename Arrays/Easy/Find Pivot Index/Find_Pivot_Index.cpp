/*
Question :-
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.



Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11



Constraints:

1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000

*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------- Solution Class ---------------------------- */
class Solution
{
public:
    /* Approach 1 :- using prefix and suffix array. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    int pivotIndex_Approach_1(vector<int> &nums)
    {

        // size of vector.
        int n = nums.size();

        // prefix array
        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }

        // suffix array
        sum = 0;
        vector<int> suffix(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            sum += nums[i];
            suffix[i] = sum;
        }

        // corner cases.
        if (suffix[1] == 0)
        {
            return 0;
        }
        if (prefix[n - 2] == 0)
        {
            return n - 1;
        }

        // finding index of pivot elemnet.
        for (int i = 1; i < n - 1; i++)
        {
            if (prefix[i - 1] == suffix[i + 1])
            {
                return i;
            }
        }
        return -1;
    }

    /* Approach 2 :- optimizing above approach. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int pivotIndex_Approach_2(vector<int> &nums)
    {

        // size of vector.
        int n = nums.size();

        // Base Case
        if (n == 1)
        {
            return 0;
        }

        // calculate the sum of entire array.
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
        }

        // intialize 2 pointers, leftSum = 0, and rightSum = prefixSum.
        int leftSum = 0;
        int rightSum = prefixSum;

        for (int i = 0; i < n; i++)
        {
            // remove the current element.
            rightSum = rightSum - nums[i];

            // check if leftSum == right sum or not.
            if (leftSum == rightSum)
            {
                // if both are equal, return index pivot element.
                return i;
            }

            // add current element to leftSum.
            leftSum = leftSum + nums[i];
        }

        return -1;
    }
};

int main()
{
    Solution s;

    vector<int> arr = {1, 7, 3, 6, 5, 6};

    cout << "Pivot element index is : " << s.pivotIndex_Approach_1(arr) << endl;
    cout << "Pivot element index is : " << s.pivotIndex_Approach_2(arr) << endl;
}