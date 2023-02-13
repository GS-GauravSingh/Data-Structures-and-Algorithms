/*
Question :-
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.


Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


Constraints:

0 <= nums.length <= 10^5
-109 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /*
    Approach 1 :- using sorting.

    Intution:-
    1. The very first thing we can think of is we simply arrange the array in ascending order.
    2. After arranging the array in sorted order, we just find the length of the longest consecutive sequence.

    Time Complexity :- O(n log(n)), n is the size of the array.
    Space Complexity :- O(1).
    */
    int longestConsecutive_BruteForce(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // Base Case
        if (n == 0)
        {
            // if length of array is zero, then from here simply return 0.
            return 0;
        }
        if (n == 1)
        {
            // if length of array is 1, then the longest consecutive sequence is of length 1.
            return 1;
        }

        // sort the given array.
        sort(nums.begin(), nums.end());

        // put currLen = 1 and maxLen = 0.
        int currLen = 1, maxLen = 0;

        for (int i = 1; i < n; i++)
        {
            // skip the duplicate elements.
            if (nums[i] == nums[i - 1])
            {
                continue;
            }

            // if difference of nums[i] - nums[i-1] = 1, then this is a consecutive sequence,
            // increment the currLen.
            // ex:-  1,2 , diff = 2-1 = 1.
            else if (nums[i] - nums[i - 1] == 1)
            {
                currLen++;
            }
            else
            {
                // if difference is not 1, reinitilized length with 1.
                currLen = 1;
            }

            // calculate max length.
            maxLen = max(maxLen, currLen);
        }

        // update maxLen one more time, because if all duplicates are present,
        // then the answer is 1.
        maxLen = max(maxLen, currLen);
        return maxLen;
    }

    /* optimized apporach :- using hashing. */
    // Time Complexity :- O(n), n is the size of the array.
    // Space Complexity :- O(n).
    int longestConsecutive(vector<int> &nums)
    {
        // size of vector.
        int n = nums.size();

        // Base Case
        if (n == 0)
        {
            // if length of array is zero, then from here simply return 0.
            return 0;
        }

        if (nums.size() == 1)
        {
            return 1;
        }

        // insert all element into set.
        unordered_set<int> s;
        for (auto val : nums)
        {
            s.insert(val);
        }

        //  variable to store the length of longest consecutive sequence.
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            // current element is nums[i]. Now try to find the predecessor of current element,
            // if predecessor is present it means this current element is a part of a consecutive sequence.
            // So, ignore this element.

            // Example:- current element  = 2, predecessor is 2-1 i.e., 1.
            int currElement = nums[i];
            int predecessor = currElement - 1;

            // But if predecessor is not present, it means this current element can start it's own consecutive sequence.
            // Now, find it's successor and computer the length.
            int currLen = 0;

            if (s.find(predecessor) == s.end())
            {
                while (s.find(currElement) != s.end())
                {
                    currElement++;
                    currLen++;
                }
            }

            // update max length
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    Solution S;
    cout << "Length of Longest Consecutive Sequence is " << S.longestConsecutive(nums);
}