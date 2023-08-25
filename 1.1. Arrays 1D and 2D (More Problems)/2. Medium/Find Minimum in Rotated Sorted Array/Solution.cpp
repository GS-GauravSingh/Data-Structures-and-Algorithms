#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Binary Search Algorithm for finding index of Pivot element in rotated soeted array.

        Example: arr = {4,5,6,1,2,3}, here 1 is pivot element. Pivot = minimum element of array.

        Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
        Space Complexity: O(1).
        */
    int binarySearch_FindPivotIdx(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // low and high Pointers.
        int low = 0;
        int high = n - 1;

        // Traverse the array and find the the index of target in nums vector.
        while (low <= high)
        {
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
    int findMin(vector<int> &nums)
    {

        // Find the Index of Pivot Element.
        int pivotIdx = binarySearch_FindPivotIdx(nums);

        // Now, Pivot is the minimum element of array and from pivot we can divide the array into 2 halfs, first is from [0 to pivotIdx - 1] and second is from [pivotIdx to end].
        // Both the halfs are sorted, so our answer is min(nums[0], nums[pivotIdx]).
        if (pivotIdx != -1)
        {
            return min(nums[0], nums[pivotIdx]);
        }

        // If pivotIdx == -1, it means the arrays is sorted (not rotated).
        return nums[0];
    }
};

int main(void)
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    // Solution.
    Solution obj;
    cout << obj.findMin(nums);
    return 0;
}