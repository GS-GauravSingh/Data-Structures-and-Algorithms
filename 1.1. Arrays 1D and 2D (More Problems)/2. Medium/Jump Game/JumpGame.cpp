#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Dry-Run:
    Observation: If the array contains all non-zeros elements, then we can absolutely reached to the last index.

    Example 1: nums = {2, 3, 1, 1, 4}.


    nums = {2, 3, 1, 1, 4}.
    index   0  1  2  3  4

    >> i = 0,
    nums[0] = 2, so from here (from index 0), we can maximum take 2 jumps and if we make 2 jumps from here, we can reach the index "i+nums[i]" i.e., "0 + nums[0]" i.e., 2. So, from here the maximum we can reach is index 2 and index 2 is not a last index.

    So, from index 0, our maximum reachability is index 2 and we have to store this maximum reachability into a separate variable, lets call it maxReach.

    From index 0, our maxReach = 2 and maxReach should be updated to represent the maximum possible index that can be reached.

    >> i = 1,
    nums[1] = 3, so from here (from index 1), we can maximum take 3 jumps and if we make 3 jumps from here, we can reach the index "i+nums[i]" i.e., "1 + nums[1]" i.e., 4. So, from here the maximum we can reach is index 4 and index 4 is the last index.

    So, from index 1, our maximum reachability is index 4. So we can return true from here because we reached the last Index.


    Example 2: nums = {3, 2, 1, 0, 4}.

    nums = {3, 2, 1, 0, 4}
    index   0  1  2  3  4

    >> i = 0,
    nums[0] = 3, so from here (from index 0), we can maximum take 3 jumps and if we make 3 jumps from here, we can reach the index "i+nums[i]" i.e., "0 + nums[0]" i.e., 3. So, from here the maximum we can reach is index 3 and index 3 is not a last index.

    So, from index 0, our maximum reachability is index 3 and we have to store this maximum reachability into a separate variable, lets call it maxReach.

    From index 0, our maxReach = 3.

    >> i = 1,
    nums[1] = 2, so from here (from index 1), we can maximum take 2 jumps and if we make 2 jumps from here, we can reach the index "i+nums[i]" i.e., "1 + nums[1]" i.e., 3. So, from here the maximum we can reach is index 3 and index 3 is not a last index.

    So, from index 1, our maximum reachability is index 3.

    From index 1, our maxReach = 3.

    >> i = 2,
    nums[2] = 1, so from here (from index 2), we can maximum take 1 jump and if we make 1 jump from here, we can reach the index "i+nums[i]" i.e., "2 + nums[2]" i.e., 3. So, from here the maximum we can reach is index 3 and index 3 is not a last index.

    So, from index 2, our maximum reachability is index again 3.

    From index 2, our maxReach = 3.

    >> i = 3,
    nums[3] = 0, so from here (from index 3), we can maximum take 0 jump and it means from here we cannot move ahead.

    So, from index 3, we cannot move ahead.

    From index 3, our maxReach = 3.

    >> i = 4,
    nums[4] = 4,

    Notice that, our maximum reachability is index 3 (maxReach = 3) and the value of  'i = 4' is greater than maxReach, it means from the previous element of nums we can maximum reach upto index 3.

    So, when maxReach < i, it means we cannot reach the last index. So return false from here.
    */

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    bool canJump(vector<int> &nums)
    {
        // Base Case

        // Now, you are standing at index 0 and index 0 itself contains 0, it means you cannot make any jump from here.
        // So, if you cannot make any jump, how can you reach the last index.
        // that's why return false from here.
        if (nums[0] == 0 && nums.size() > 1)
        {
            return false;
        }

        // If the array contains only single element, it means you are already standing at the last index.
        // so return true from here.
        if (nums.size() == 1)
        {
            return true;
        }

        // size of vector.
        int n = nums.size();

        // needed variables.
        int maxReach = nums[0];

        // traverse through the vector and find the answer.
        for (int i = 1; i < n; i++)
        {
            // if maxReach having value < i,
            // means we cannot reach the end, return false.
            if (maxReach < i)
            {
                return false;
            }

            // if maxReach having value >= n-1,
            // means we reached the last index, retun true.
            if (maxReach >= n - 1)
            {
                return true;
            }

            // update maxReach with maximum reachable index.
            maxReach = max(maxReach, i + nums[i]);
        }

        return false;
    }
};

int main(void)
{
    vector<int> nums{2, 3, 1, 1, 4};

    // Solutioon.
    Solution obj;
    cout << obj.canJump(nums);

    return 0;
}