/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example :

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach  :- Using  Binary Search. */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(1)
    int peakElement(vector<int> &arr)
    {
        // corner case
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }
        if (n > 1)
        {
            if (arr[0] > arr[1])
            {
                return 0;
            }
            if (arr[n - 1] > arr[n - 2])
            {
                return n - 1;
            }
        }

        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // peak element condition.
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return arr[mid];
            }
            // move pointers.
            else if (arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else if (arr[mid] < arr[mid - 1])
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {5, 10, 20, 15};

    Solution S;
    cout << "Peak Element is " << S.peakElement(arr);
}