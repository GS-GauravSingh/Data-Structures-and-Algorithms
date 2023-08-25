#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Binary Search Algorithm for finding index of Pivot element in rotated soeted array.

    Example: arr = {4,5,6,1,2,3}, here 1 is pivot element. Pivot = minimum element of array.

    Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int findPivotIdx(vector<int> &nums)
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
    /* Question: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.  */
    int findKRotation(vector<int> &arr)
    {
        /*
        Example: array: {4, 5, 6, 1, 2, 3}

        Find the index of pivot element, Pivot Element is the minimum element of the array and in this case 1 is our pivot element.
        Index of Pivot is: 3.

        Now, I can say than array is rotated 'pivotIdx' times i.e., 3 times.

        */

        // Setp 1: Find the index of Pivot Element. Pivot Element is the minimum element of the array.
        int pivotIdx = findPivotIdx(arr);

        // Arrays is rotated 'pivotIdx' times.

        // if pivot index is 0, it means arrays is sorted in ascending order (no rotation).
        if (pivotIdx == -1)
        {
            return 0;
        }

        return pivotIdx;
    }
};

int main(void)
{
    vector<int> nums{4, 5, 6, 1, 2, 3};

    // Solution.
    Solution obj;
    cout << "Array is rotated " << obj.findKRotation(nums) << " times.";

    return 0;
}