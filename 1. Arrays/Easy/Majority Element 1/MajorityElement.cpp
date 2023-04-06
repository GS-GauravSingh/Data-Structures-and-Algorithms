/*
Question :-
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Solution Class ------------------------------ */
class Solution
{
private:
public:
    /* Approach 1 :- Using map. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    int majorityElement_Approach_1(vector<int> &nums)
    {
        // size of vector.
        int n = nums.size();

        // map
        unordered_map<int, int> mpp;

        // counting frequency of each element.
        for (int i = 0; i < n; i++)
        {
            int element = nums[i];
            mpp[element]++;
        }

        // majority element is the element that appear more than n/2 times.
        int appear = n / 2;
        for (auto i : mpp)
        {
            if (i.second > appear)
            {
                return i.first;
            }
        }
        return -1;
    }

    /* Approach 2 :- Boyer Moore Voting Algorithm. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int majorityElement_Approach_2(vector<int> &nums)
    {
        // size of vector.
        int n = nums.size();

        int candidate = -1;
        int votes = 0;
        for (int i = 0; i < n; i++)
        {
            if (votes == 0)
            {
                candidate = nums[i];
                votes++;
            }
            else if (nums[i] == candidate)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }

        return candidate;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element is : " << S.majorityElement_Approach_1(nums) << endl;
    cout << "Majority Element is : " << S.majorityElement_Approach_2(nums);
}