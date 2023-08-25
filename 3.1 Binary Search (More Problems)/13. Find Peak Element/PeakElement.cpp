#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* 
    Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int findPeakElement(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // COrner case
        if (n == 1)
        {
            return 0;
        }
        else
        {
            // n > 1.

            // IF nums[0] > nums[1], it means nums[0] is a peak element.
            // This is because the first element (nums[0]) is compared only to its right neighbor (nums[1]), and due to the assumption that nums[-1] is considered as -∞, any element greater than its right neighbor would be considered a peak element.
            if (nums[0] > nums[1])
            {
                return 0;
            }

            // IF nums[n - 1] > nums[n - 2], it means nums[n - 1] is a peak element.
            // This is because the last element (nums[n - 1]) is compared only to its left neighbor (nums[n - 2]), and due to the assumption that nums[n] is considered as -∞, any element greater than its left neighbor would be considered a peak element.
            if (nums[n - 1] > nums[n - 2])
            {
                return n - 1;
            }
        }

        // low and high Pointers.
        int low = 1;
        int high = n - 2;

        // Traverse the array and find the the index of peak element in nums vector.
        while (low <= high)
        {
            // Index of middle element.
            int mid = low + (high - low) / 2;

            // A peak element is an element that is strictly greater than both of its neighbors (left and right).
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            // Mid lies in Upward Slope. Move to right.
            else if (nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }

            // Mid lies in Downward Slope. Move to left.
            else if (nums[mid] > nums[mid + 1] /* or nums[mid] < nums[mid - 1], both condition are correct. */)
            {
                high = mid - 1;
            }
        }

        // return -1 to avoid error.
        return -1;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 4, 5, 4, 3, 2, 1};

    // SOlution.
    Solution obj;
    cout << "Peak Element Index is: " << obj.findPeakElement(nums) << ".";
    return 0;
}