#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Using Linear Search.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int linearSearch(vector<int> &nums, int target)
    {
        // Size of nums vector.
        int n = nums.size();

        // Using Linear Search.
        for (int i = 0; i < n; i++)
        {
            // If target is already present, then return the index of it.
            if (nums[i] == target)
            {
                // In case, target is already present, then we have to just return the index of target.
                return i;
            }

            // Else, if target is not present, in this case we have to reutrn the correct position of target.
            else
            {

                // If nums[n-1] (the last element of the array) is less than the target, it means the target should be inserted at the end of the array, so it returns n as the index to insert the target.
                if (nums[n - 1] < target)
                {
                    return n;
                }

                // Now, if the above condition false, in that casm we just have to find that element that is just greater than target.
                // If nums[i] is greater than the target, it means the target should be inserted at index i, so we have to return 'i' as the index to insert the target.
                if (nums[i] > target)
                {
                    return i;
                }
            }
        }

        // just returning -1, because return type is 'int'.
        return -1;
    }

    /* Using Binary Search.

    Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int binarySearch(vector<int> &nums, int target)
    {
        // Size of nums vector.
        int n = nums.size();

        // Using Binary Search.
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            // Calculating mid.
            int mid = low + (high - low) / 2;

            // Target Found.
            // In case, target is already present, then we have to just return the index of target.
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }

public:
    int searchInsert(vector<int> &nums, int target)
    {
        // // Brute Force Solution.
        // return linearSearch(nums, target);

        // Optimized Solution.
        return binarySearch(nums, target);
    }
};

int main(void)
{
    vector<int> nums{1, 3, 5, 6};
    int target = 7;

    // Solution.
    Solution obj;
    cout << "Insert Position Index: " << obj.searchInsert(nums, target) << ".";
    return 0;
}