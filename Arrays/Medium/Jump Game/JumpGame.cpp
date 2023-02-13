/*
Question :-
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    bool canJump(vector<int> &nums)
    {

        // Corner Case
        // if the first element of array is 0 and size of array is greater than 1, it means you cannot reach thye last index.
        // because from index 0, the minimum jumps you can take is 0 i.e., no jump.
        if (nums[0] == 0 && nums.size() > 1)
        {
            return false;
        }

        // if the array only contains a single element, it means you are at the last index.
        if (nums.size() == 1)
        {
            return true;
        }

        // size of vector.
        int n = nums.size();

        // needed variables.
        int maxReach = nums[0];

        // traverse through the vector and find the answer.
        for (int i = 1; i < n; i++)
        {
            // if maxReach having value < i,
            // means we cannot reach the end, return false.
            if (maxReach < i)
            {
                return false;
            }

            // if maxReach having value >= n-1,
            // means we reached the last index, retun true.
            if (maxReach >= n - 1)
            {
                return true;
            }

            // update maxReach with maximum reachable index.
            maxReach = max(maxReach, i + nums[i]);
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    Solution S;
    if (S.canJump(nums))
    {
        cout << "You reach the end of the array.";
    }
    else
    {
        cout << "You cannot reach the end of the array.";
    }
}