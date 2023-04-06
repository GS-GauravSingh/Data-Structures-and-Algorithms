/*
Question :-
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.


Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/
#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Method 1:- Using nested loops.*/
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    int findDuplicate_Approach_1(vector<int> &nums)
    {
        int n = nums.size();
        int ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }

    /* Brute Force Method 2:- Use sorting (so the duplicate element come together).*/
    // Time Complexity:- O(n log(n))
    // Space Complexity:- O(1)
    int findDuplicate_Approach_2(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }

        return -1;
    }

    /* Brute Force Method 3:- Use Hashing */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    int findDuplicate_Approach_3(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        for (auto i : mpp)
        {
            if (i.second > 1)
            {
                return i.first;
            }
        }

        return -1;
    }

    /* Optmized Approach:- Marking visited value within the array.
    Since all values of the array are between [1…n] and the array size is n+1, while scanning the array from left to right, we set the nums[n] to its negative value.

    With extra O(1) space, with modifying the input.
    */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int findDuplicate_Optimized_1(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]);

            // if any element is already visited, then return it's index.
            if (nums[idx] < 0)
            {
                return idx;
            }

            // mark visited.
            nums[idx] = -nums[idx];
        }

        return -1;
    }

    /* Optmized Approach:- Using Linked List Cycle Method. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int findDuplicate_Optimized_2(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};

    Solution s;
    cout << s.findDuplicate_Approach_1(arr) << endl;
    cout << s.findDuplicate_Approach_2(arr) << endl;
    cout << s.findDuplicate_Approach_3(arr) << endl;
    cout << s.findDuplicate_Optimized_1(arr) << endl;
    cout << s.findDuplicate_Optimized_2(arr);
}