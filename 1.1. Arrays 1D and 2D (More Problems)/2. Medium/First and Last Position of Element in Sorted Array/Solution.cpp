#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Binary Search For finding first occurrence of target in nums vector.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int firstOccurrence(vector<int> &nums, int target)
    {
        // size of nums vector.
        int n = nums.size();

        // Low and High pointers.
        int low = 0;
        int high = n - 1;

        // variable to store first occurrence index.
        int firstOccIdx = -1;

        // Apply binary search and find the first occurrence of target.
        while (low <= high)
        {
            // Calculating mid.
            int mid = low + (high - low) / 2;

            // If nums[mid] == target, it means we found the target.
            if (nums[mid] == target)
            {
                // if target is found, store it's index because it may possible that this is the first occurence of target.
                firstOccIdx = mid;

                // Now, move to left half because first occurence is always present at the left half of array.
                high = mid - 1;
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

        // return answer.
        return firstOccIdx;
    }

    /* Binary Search For finding last occurrence of target in nums vector.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int lastOccurrence(vector<int> &nums, int target)
    {
        // size of nums vector.
        int n = nums.size();

        // Low and High pointers.
        int low = 0;
        int high = n - 1;

        // variable to store first occurrence index.
        int lastOccIdx = -1;

        // Apply binary search and find the first occurrence of target.
        while (low <= high)
        {
            // Calculating mid.
            int mid = low + (high - low) / 2;

            // If nums[mid] == target, it means we found the target.
            if (nums[mid] == target)
            {
                // if target is found, store it's index because it may possible that this is the last occurence of target.
                lastOccIdx = mid;

                // Now, move to right half because last occurence is always present at the right half of array.
                low = mid + 1;
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

        // return answer.
        return lastOccIdx;
    }

public:
    /*
    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    vector<int> searchRange(vector<int> &nums, int target)
    {

        // vector to store answer.
        vector<int> ans;
        ans.push_back(firstOccurrence(nums, target));
        ans.push_back(lastOccurrence(nums, target));

        return ans;
    }
};

int main(void)
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;

    // Solution.
    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);
    cout << "First Occurence Index: " << ans[0] << ".\nLast Occurence Index: " << ans[1] << ".";
    return 0;
}