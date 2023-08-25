#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: Given and array 'nums' of integers sorted in incresing order and an integer 'x'. Your task is to return thee index of lower bound of x.

    What is Lower Bound?
    Suppose, you have to find the lower bound of x.
    1. If 'x' itself is present in the array, then 'x' itself is the lower bound of 'x'.
    2. But, if 'x' is not present in the array, then the value which is just greater then 'x' is your lower bound of x.

    Note: If 'x' is greater then the maximum value of array, then the lower bound is equals to the size of the array.

    Example: Array = {3, 5, 8, 13, 15, 17, 17, 19, 20, 20, 21}, n = 11.
    Index:            0  1  2  3   4   5   6   7   8   9   10

    Let's say we have to find the lower of 'x'.

    Case 1: x = 5 (X present).
    x itself is present in the array, so, 'x' itself is the lower bound of 'x'. Index of x is 2.
    So, Index of lower bound of x is 2.

    Case 2: x = 17 (X present multiple times).
    Now, in this case, 17 is repeating twice in the array. So, if a particular element has multiple occurences, then in this case the index of first occurence of 'x' is your lower bound.

    x itself is present in the array, so, 'x' itself is the lower bound of 'x'. Index of first occurence x is 5.
    So, Index of lower bound of x is 5.

    Case 3: x = 18 (X is not present).
    Now, when 'x' is not present in the array, then the value which is just greater then 'x' is your lower bound of x.
    value which is just greater then 'x' is 19. So 19 is lower bound of x.
    So, Index of lower bound of x is 7.

    Case 4: x = 25 (X is greater then the array maximum element).
    Lower bound is defined as the smallest element that is greater than or equal to 'x'. Since there are no elements greater than 'x' in the array, the lower bound would be positioned at the end of the array, which is represented by the size of the array.


    Return the index of lower bound.

    */
    int lowerBound(vector<int> &nums, int n, int x)
    {
        // Base Case
        // When the value of 'x' is greater then the maximum element of the array.
        if (x > nums[n - 1])
        {
            // Lower bound is defined as the smallest element that is greater than or equal to 'x'.
            // Since there are no elements greater than 'x' in the array, the lower bound would be positioned at the end of the array, which is represented by the size of the array.
            return n;
        }

        // Needed variables for Binary Search.
        int low = 0;
        int high = n - 1;

        // variable to store the index of lower bound.
        int lb = 0;

        // Apply Binary Search and find the the index of lower bound of 'x' in nums array.
        while (low <= high)
        {
            // Index of middle element.
            int mid = low + (high - low) / 2;

            // If nums[mid] == x, it means 'x' is present in the array and when 'x' itself is present in the array, then 'x' itself is the lower bound of 'x'.
            if (nums[mid] == x)
            {
                // But, in case of multiple occurences of 'x', then in this case the index of first occurence of 'x' is your lower bound.
                // So, store the index of this 'x' and continue searching in left half because first occurence of 'x' (if present) is always present in left half.
                lb = mid;
                high = mid - 1;
            }

            // If nums[mid] > x, it means all the element after mid are also greater than 'x' (because input array is sorted).
            // Now, if 'x' is not present in the array, then the value which is just greater then 'x' is your lower bound of x.
            else if (nums[mid] > x)
            {
                // This value is greater then 'x', it can be a possible answer, store the index.
                lb = mid;

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

        // return the index of lower bound of x.
        return lb;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 6};

    // Solution.
    Solution obj;

    int x = 3;
    cout << "Index of Lower Bound: " << obj.lowerBound(nums, nums.size(), x) << ".";
    
    return 0;
}