#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using two-pointers, Instead of shifting all 0's to the right, we can shift all the non-zero's element to the left.

    Dry-Run: Example: nums = {0, 1, 0, 3, 12};

    // Initial Configuration.
    nums =      {0,    1,    0,    3,    12}
    pointers:   prev  curr

    // Loop Starts.

    ## 0th iteration.
    >> nums[prev] == 0 && nums[curr] != 0, in this case we simply swap both the element and increment both the pointers.

    // operations.
    swap(nums[prev], nums[curr]);
    prev++;
    curr++;

    // result
    nums =      {1,    0,    0,    3,    12}
    pointers:         prev  curr

    ## 1st iteration.
    >> nums[prev] == 0 && nums[curr] == 0, when both pointers points to 0, in this case we simply increment curr pointer.

    // operations.
    curr++;

    // result
    nums =      {1,    0,    0,    3,    12}
    pointers:         prev        curr

    ## 2nd iteration.
    >>  nums[prev] == 0 && nums[curr] != 0, in this case we simply swap both the element and increment both the pointers.

    // operations.
    swap(nums[prev], nums[curr]);
    prev++;
    curr++;

    // result
    nums =      {1,    3,    0,    0,    12}
    pointers:               prev        curr

    ## 3rd iteration.
    >>  nums[prev] == 0 && nums[curr] != 0, in this case we simply swap both the element and increment both the pointers.

    // operations.
    swap(nums[prev], nums[curr]);
    prev++;
    curr++;

    // result
    nums =      {1,    3,    12,    0,    0}
    pointers:                      prev       curr

    Now, curr pointer is > size of array, so the loop will terminate at this point and our answer is ready. We successfully shif all the non-zero element to the left.


    Time Complexity: O(n), where 'n' is the size of nums vector.
    Space Complexity: O(1).
    */
    void moveZeroes(vector<int> &nums)
    {

        // Size of the nume vector.
        int n = nums.size();

        // initialize 2 pointer prev and curr with 0.
        int prev = 0, curr = 0;

        // Iterate the nums vector using 'curr' pointer.
        while (curr < n)
        {
            // when both pointers points to 0, in this case we simply increment 'curr' pointer.
            if (nums[prev] == 0 && nums[curr] == 0)
            {
                curr++;
            }

            // nums[prev] == 0 && nums[curr] != 0, in this case we simply swap both the element and increment both the pointers.
            else if (nums[prev] == 0 && nums[curr] != 0)
            {
                swap(nums[prev], nums[curr]);
                prev++;
                curr++;
            }

            // if both are non-zero element, in this case, simple increment both the pointers.
            else
            {
                prev++;
                curr++;
            }
        }
    }
};

int main(void)
{
    vector<int> nums{0, 1, 0, 3, 12};

    // Solution.
    Solution obj;
    obj.moveZeroes(nums);

    for (auto i : nums)
        cout << i << " ";
    return 0;
}