#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: Given and array 'nums' of integers sorted in incresing order and an integer 'x'. Your task is to return thee index of Upper bound of x.

    What is Upper Bound?
    So, in lower bound what happens is,
    1. If 'x' itself is present in the array, then 'x' itself is the lower bound of 'x'.
    2. But, if 'x' is not present in the array, then the value which is just greater then 'x' is your lower bound of x.
    3. And in case of multilpe occurence of x is present, then in this case the index of first occurence of 'x' is your lower bound.

    But, In Upper Bound,
    1. Whether 'x' is present or not, the upper bound of 'x' is the value that is just greater than 'x'.

    Note: If 'x' is greater or equal to then the maximum value of array, then the upper bound is equal to the size of the array.

    Return the index of upper bound.

    */
    int upperBound(vector<int> &nums, int n, int x)
    {
        // Base Case
        // When the value of 'x' is greater or equal to the maximum element of the array.
        if (x >= nums[n - 1])
        {
            // The upper bound of 'x' is the index of the first element that is strictly greater than 'x'.
            // Since there are no elements greater than 'x' in the array, the upper bound would be positioned at the end of the array, which is represented by the size of the array.
            return n;
        }

        // Needed variables for Binary Search.
        int low = 0;
        int high = n - 1;

        // variable to store the index of upper bound.
        int up = 0;

        // Apply Binary Search and find the the index of upper bound of 'x' in nums array.
        while (low <= high)
        {
            // Index of middle element.
            int mid = low + (high - low) / 2;

            // If nums[mid] > x, it means all the element after mid are also greater than 'x' (because input array is sorted).
            // The upper bound of 'x' is the index of the first element that is strictly greater than 'x'.
            if (nums[mid] > x)
            {
                // This value is greater then 'x', it can be a possible answer, store the index.
                up = mid;

                // and then move to left half.
                high = mid - 1;
            }

            // Now, if nums[mid] < x, it means all the element before mid are also smaller than x (because input array is sorted).
            else
            {
                // So, set low = mid + 1.
                low = mid + 1;
            }
        }

        // return the index of upper bound of x.
        return up;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6};

    // Solution.
    Solution obj;

    int x = 3;
    cout << "Index of Upper Bound: " << obj.upperBound(nums, nums.size(), x) << ".";

    return 0;
}