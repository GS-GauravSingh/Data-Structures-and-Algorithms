#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Binary Search Algorithm.

    Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    bool binarySearch(vector<int> &nums, int start, int end, int target)
    {
        // size of nums vector.
        int n = nums.size();

        // low and high Pointers.
        int low = start;
        int high = end;

        // Traverse the array and find the the index of target in nums vector.
        while (low <= high)
        {
            // Index of middle element.
            int mid = low + (high - low) / 2;

            // If nums[mid] == target, it means target found, so return true.
            if (nums[mid] == target)
            {
                return true;
            }

            // Now, if nums[mid] < target, it means all the element before mid are also smaller than target (because input array is sorted).
            // So, set low = mid + 1.
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }

            // Now, if nums[mid] > target, it means all the element after mid are also greater than target (because input array is sorted).
            // So, set high = mid - 1.
            else
            {
                high = mid - 1;
            }
        }

        // return false in case of target does not present in the nums vector.
        return false;
    }

    /* Binary Search Algorithm for finding index of Pivot element in rotated soeted array.

    Example: arr = {4,5,6,1,2,3}, here 1 is pivot element. Pivot = minimum element of array.

    Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int binarySearch_FindPivotIdx_Approach_1(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // low and high Pointers.
        int low = 0;
        int high = n - 1;

        // Traverse the array and find the the index of target in nums vector.
        while (low <= high)
        {

            // These 2 Condition are extra in this question because of duplicates, rest of the code remains the same as in previous version of this question.
            // Skipping Duplicates from left.
            while (low < high && nums[low] == nums[low + 1])
            {
                low++;
            }

            // Skipping Duplicates from right.
            while (low < high && nums[high] == nums[high - 1])
            {
                high--;
            }

            // Index of middle element.
            int mid = low + (high - low) / 2;

            // Checking, whether left half is sorted or not.
            // if the below condition evaluates to true, it means left half is sorted.
            if (nums[0] <= nums[mid])
            {
                // Now, just check the element at index mid+1, if the element at index mid+1 is smaller that the mid element, it means mid+1 is the index of pivot element.
                if (mid + 1 < n /* check for out of bound */ && nums[mid] > nums[mid + 1])
                {
                    return mid + 1;
                }
                else
                {
                    // IF the above condition does not evaluates to true, then move the low pointer to mid+1.
                    low = mid + 1;
                }
            }

            // Checking, whether right half is sorted or not.
            // if the below condition evaluates to true, it means right half is sorted.
            else if (nums[mid] <= nums[n - 1])
            {
                // Now, just check the element at index mid-1, if the element at index mid-1 is greater that the mid element, it means mid is the index of pivot element.
                if (mid - 1 >= 0 /* check for out of bound */ && nums[mid - 1] > nums[mid])
                {
                    return mid;
                }
                else
                {
                    // IF the above condition does not evaluates to true, then move the high pointer to mid-1.
                    high = mid - 1;
                }
            }
        }

        // return -1 in case the array is sorted so there is not pivot element.
        return -1;
    }

public:
    bool search(vector<int> &nums, int target)
    {
        // If nums vector contains only single element.
        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return true;
            }
            return false;
        }

        // Size of nums vector.
        int n = nums.size();

        // Step 1: Find the index of Pivot Element in nums vector.
        int pivotIdx = binarySearch_FindPivotIdx_Approach_1(nums);

        // Now, in case if array is sorted, so in this case pivot element does not exist and the above fundtion will reutrn -1.
        // So, if pivotIdx == -1, it means array is sorted, so directly apply binary search on entire array.
        if (pivotIdx == -1)
        {
            return binarySearch(nums, 0, n - 1, target);
        }

        // Step 2: Divide the array into tow half, 1st half is from 0 to pivotidx - 1 and 2nd half is from pivotIdx to n. Both the halfs are sorted in increasing order. Now, apply Binary Search on both the halfs ahf find the index of target.
        bool targetPresentOrNot = binarySearch(nums, 0, pivotIdx, target);
        if (targetPresentOrNot != false)
        {
            return targetPresentOrNot;
        }
        return binarySearch(nums, pivotIdx, n - 1, target);
    }
};

int main(void)
{
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 3;

    // Solution.
    Solution obj;
    cout << (obj.search(nums, target) == true ? "Present." : "Not Present.");
    return 0;
}