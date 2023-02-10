/*
Question :-
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 3⌋ times. You may assume that the majority element always exists in the array.



Example 1:
Input: nums = [3,2,3]
Output: 3



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
    vector<int> majorityElement_Approach_1(vector<int> &nums)
    {
        // size of vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // map
        unordered_map<int, int> mpp;

        // counting frequency of each element.
        for (int i = 0; i < n; i++)
        {
            int element = nums[i];
            mpp[element]++;
        }

        // majority element is the element that appear more than n/3 times.
        int appear = n / 3;
        for (auto i : mpp)
        {
            if (i.second > appear)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }

    /* Approach 2 :- Boyer Moore Voting Algorithm. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    vector<int> majorityElement_Approach_2(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answers.
        vector<int> ans;

        // at max, we can have only 2 majority elements.
        // and minimum, we can have 0 majority elements.
        int num1 = -1, num2 = -1, votes_1 = 0, votes_2 = 0;

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == num1)
            {
                votes_1++;
            }
            else if (nums[i] == num2)
            {
                votes_2++;
            }
            else if (votes_1 == 0)
            {
                num1 = nums[i];
                votes_1++;
            }
            else if (votes_2 == 0)
            {
                num2 = nums[i];
                votes_2++;
            }
            else
            {
                votes_1--;
                votes_2--;
            }
        }

        // verify if num1 and num2 appear more than n/3 times or not.
        votes_1 = 0;
        votes_2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
            {
                votes_1++;
            }
            else if (nums[i] == num2)
            {
                votes_2++;
            }
        }

        int appear = n / 3;
        if (votes_1 > appear)
        {
            ans.push_back(num1);
        }
        if (votes_2 > appear)
        {
            ans.push_back(num2);
        }

        return ans;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    vector<int> ans1 = S.majorityElement_Approach_1(nums);
    vector<int> ans2 = S.majorityElement_Approach_2(nums);

    for(auto i : ans1)
    {
        cout<<i<<" ";
    }
}