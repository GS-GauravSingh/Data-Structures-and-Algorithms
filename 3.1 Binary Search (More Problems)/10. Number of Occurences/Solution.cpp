#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
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
    /* Question: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array. */
    int findOccurences(vector<int> &nums, int n, int x)
    {
        /*
        Approach:
        Example: {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4}, x = 2.

        Find the index of first and last occurence of x, and our answer will be lastOccIdx - firstOccIdx + 1.

        For above example:
        Index of First Occurence of 2 is 2.
        Index of Last Occurence of 2 is 5.

        Total Occurence of x = lastOccIdx - firstOccIdx + 1
        Total Occurence of 2 = 5 - 2 + 1 => 4.
        */

        int firstOccIdx = firstOccurrence(nums, x);
        int lastOccIdx = lastOccurrence(nums, x);

        // When 'x' is not present in the array, then both the above method i.e., firstOccurence and lastOccurence will reutrn -1. In this case we have to return 0, where 0 represent there is not occurence of 'x' present in the array.
        if (firstOccIdx == -1)
        {
            return 0;
        }

        // Total Occurence of x = lastOccIdx - firstOccIdx + 1
        int totalOccurences = lastOccIdx - firstOccIdx + 1;

        return totalOccurences;
    }
};

int main(void)
{
    vector<int> nums{1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4};
    int x = 2;

    // Solution.
    Solution obj;
    cout << "There are total " << obj.findOccurences(nums, nums.size(), x) << " Occurences of " << x << " present in the array.";
    return 0;
}