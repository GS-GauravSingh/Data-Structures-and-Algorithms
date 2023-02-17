/*
Question :-
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4


Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach :- Using Binary Search. */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(1)
    int search(vector<int> &nums, int target)
    {
        // size of array.
        int n = nums.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if nums[mid] == target, return mid.
            if (target == nums[mid])
            {
                return mid;
            }

            // checking if left half is sorted or not.
            else if (nums[low] <= nums[mid])
            {
                // if nums[low] <= nums[mid], it means left half is sorted.

                // Now, check if the target is in the range of nums[low] to nums[mid].
                if (target >= nums[low] && target <= nums[mid])
                {
                    // if yes, then continue searching for target on left half.
                    high = mid - 1;
                }
                else
                {
                    // if no, then move to right half.
                    low = mid + 1;
                }
            }

            // checking if right half is sorted or not.
            else if (nums[mid] <= nums[high])
            {
                // if nums[mid] <= nums[high], it means right half is sorted.

                // Now, check if the target is in the range of nums[mid] to nums[high].
                if (target >= nums[mid] && target <= nums[high])
                {
                    // if yes, then continue searching for target on right half.
                    low = mid + 1;
                }
                else
                {
                    // if no, then move to left half.
                    high = mid - 1;
                }
            }
        }

        // return -1 is key not found.
        return -1;
    }
};

int main()
{
    vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
    int target = 5;

    Solution S;
    int idx = S.search(arr, target);

    if (idx != -1)
    {
        cout << target << " is present at index " << idx << "." << endl;
    }
    else
    {
        cout << target << " not found." << endl;
    }
}