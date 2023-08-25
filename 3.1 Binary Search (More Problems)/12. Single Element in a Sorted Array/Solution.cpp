#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    Return the single element that appears only once. */

    // Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    // Space COmplexity: O(1).
    int singleNonDuplicate(vector<int> &nums)
    {
        /*

        Explanation:

        Consider an array:
        Arr =   {1, 1, 2, 2, 3, 4, 4, 5, 5}, n = 9.
        Index:   0  1  2  3  4  5  6  7  8

        Observation 1st: Since the array is sorted in ascending order, all duplicate (elements that are appear twice) elements are appear in pairs.

        Observation 2nd: If we consider an pair, let's say (1, 1), the first occurence of 1 is present at index 0 (EVEN Index) and the second occurence of 1 is present at index 1 (ODD Index).

        Observation 3rd: Suppose I am standing at index 'i' and 'i' is even index, then I can say that, the second occurence of current element is present at index 'i+1' (Odd index). Similarly, if I am standing at index 'i' and 'i' is odd index, then I can say that, the second occurence of current element is present at index 'i-1' (Even index).

        Now, I am writing all the pairs:
        Arr =   {1, 1, 2, 2, 3, 4, 4, 5, 5}, n = 9.
        Index:   0  1  2  3  4  5  6  7  8

        Array:  (1,   1),    (2,  2),     3,    (4,   4),    (5,  5)
        Index:  0    1        2   3       4      5    6       7   8
        Pair:  (even,odd)   (even,odd)   even   (odd, even)  (odd,even)

        Now, if you carefully observe,

        When the single element does not appear then the pairs are in the form of (even, odd) and the moment when the single element appears then the pairs are in the form of (odd, even).

        Now, I can say that, If my pair look like this (even, odd) then I am in the left side/half of single element and if my pair look like this (odd, even) then I am in the right side/half of single element
        */

        // size of vector.
        int n = nums.size();

        // Corner Case

        // Only single element present in the array.
        if (n == 1)
        {
            return nums[0];
        }

        // If nums[0] != nums[1]: This means the very first element of the array is the single element. So, we will return nums[0].
        if (nums[0] != nums[1])
        {
            return nums[0];
        }

        // If nums[n-1] != nums[n-2]: This means the last element of the array is the single element. So, we will return nums[n-1].
        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }

        // Needed variables for Binary Search.
        int low = 1, high = n - 2;

        // Binary Search.
        while (low <= high)
        {
            // Mid
            int mid = low + (high - low) / 2;

            // Single Element Condition. If this nums[mid] is a single element, then nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1].
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }

            // We are in left half.
            else if (
                ((mid % 2 == 1 /* Mid is at ODD Index. */) && nums[mid - 1] == nums[mid]) ||
                ((mid % 2 == 0 /* Mid is at EVEN Index. */) && nums[mid + 1] == nums[mid]))
            {
                low = mid + 1;
            }

            // We are in the right half.
            else
            {
                high = mid - 1;
            }
        }

        return -1; // to avoid error.
    }
};

int main(void)
{
    vector<int> nums{1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7};

    // Solution.
    Solution obj;
    cout << "Single Element: " << obj.singleNonDuplicate(nums) << ".";
    return 0;
}