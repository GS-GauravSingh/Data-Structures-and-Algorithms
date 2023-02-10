/*
Question :-
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


Example 1:
Input: nums = [1,2,3,1]
Output: true


Example 2:
Input: nums = [1,2,3,4]
Output: false


Constraints:

1 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------- Solution Class ------------------------------- */
class Solution
{
public:
    /*
    Approach 1:- Using nested loops.

    Time Complexity :- O(n^2)
    Space Complexity :- O(1)
    */
    bool containsDuplicate_Approach_1(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }

        return false;
    }

    /*
    Approach 2 :- Using Sorting.

    Time Complexity :- O(n log(n))
    Space Complexity :- O(1)
    */
    bool containsDuplicate_Approach_2(vector<int> &nums)
    {
        // sort the vector.
        sort(nums.begin(), nums.end());

        // traverse through the array and chek duplicates.
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }

        return false;
    }

    /*
    Approach 3 :- Using hashing.

    Time Complexity :- O(n)
    Space Complexity :- O(n)
    */
    bool containsDuplicate_Approach_3(vector<int> &nums)
    {
        // unordered map
        unordered_map<int, int> frequency;

        // store the frequency of each element into map.
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i];
            frequency[element]++;
        }

        // traverse through the map, and any element having frequency > 1, means duplicates is present.
        for (auto i : frequency)
        {
            if (i.second > 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    Solution S;

    if (S.containsDuplicate_Approach_3(nums))
    {
        cout << "Duplicates Present.";
    }
    else
    {
        cout << "Duplicates not Present.";
    }
}