#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Recursive Solution, Trying all possible path and find the path with that takes minimum  jumps to reach the last index.

    Time Complexity: O(n * nums[i]), where 'n' is the size of the nums vector.
    Space Complexity: O(n), recursive stack space.
    */
    int minJumps_Recursive(vector<int> &nums, int pos)
    {
        // Base Case.

        // When pos == nums.size() - 1, which means we have reached the last index.
        // So return 0 from here, because we reached the last index, and from here we don't need any jump or we can say, we need 0 jumps.
        if (pos >= nums.size() - 1)
        {
            return 0;
        }

        // we need to find minimum jump, so declare a variable 'minJump' and initialize it with maximum possible jumps.
        int minJump = 10001;

        // Now, from each index, we can atmax take 'nums[pos]' jumps.
        // So, run a loop to explore all possible jumps from current index (nums[pos]).
        for (int i = 1; i <= nums[pos]; i++)
        {
            minJump = min(minJump, 1 + minJumps_Recursive(nums, pos + i));
        }

        // return minimum jump.
        return minJump;
    }

    /* Recursive Dynamic Programming - Memoization Solution, Storing the answer of subproblems.

    Time Complexity: O(n * nums[i]), where 'n' is the size of the nums vector.
    Space Complexity: O(n) + O(n), recursive stack space and space used by 'dp' vector.
    */
    int minJumps_Memoized(vector<int> &nums, vector<int> &dp, int pos)
    {
        // Base Case.

        // When pos == nums.size() - 1, which means we have reached the last index.
        // So return 0 from here, because we reached the last index, and from here we don't need any jump or we can say, we need 0 jumps.
        if (pos >= nums.size() - 1)
        {
            return 0;
        }

        // Before calling recursion, just check whether this subproblem is overlapping subproblem or not. If yes, then the answer of this subproble is already stored in our dp vector.
        if (dp[pos] != 10001)
        {
            return dp[pos];
        }

        // Now, from each index, we can atmax take 'nums[pos]' jumps.
        // So, run a loop to explore all possible jumps from current index (nums[pos]).
        for (int i = 1; i <= nums[pos]; i++)
        {
            // calculate and store the answer.
            dp[pos] = min(dp[pos], 1 + minJumps_Memoized(nums, dp, pos + i));
        }

        // return minimum jump.
        return dp[pos];
    }

    /* Recursive Dynamic Programming - Tabulation Solution, Converting Recursive to Iterative Solution.

    Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    Space Complexity: O(n), space used by 'dp' vector.
    */
    int minJumps_Tabulized(vector<int> &nums)
    {
        // Base Case.
        vector<int> dp(nums.size(), 10001); // Intitalize 'dp' vector with maximum possible jumps, becuase we have to return minimum jumps.

        // When pos == nums.size() - 1, which means we have reached the last index.
        // So return 0 from here, because we reached the last index, and from here we don't need any jump or we can say, we need 0 jumps.
        dp[nums.size() - 1] = 0;

        for (int pos = nums.size() - 2; pos >= 0; pos--)
        {
            // Now, from each index, we can atmax take 'nums[pos]' jumps.
            // So, run a loop to explore all possible jumps from current index (nums[pos]).
            for (int jumpLength = 1; jumpLength <= nums[pos]; jumpLength++)
            {
                // calculate and store the answer.

                // It may possible that pos+jumpLength becomes greater than nums.size().
                if (pos + jumpLength > nums.size() - 1)
                {
                    dp[pos] = min(dp[pos], 1 + dp[nums.size() - 1]);
                }
                else
                {
                    dp[pos] = min(dp[pos], 1 + dp[pos + jumpLength]);
                }
            }
        }

        // return minimum jump.
        return dp[0];
    }

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int minJumps_Optimized(vector<int> &nums)
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
        // so return 0 from here.
        if (nums.size() == 1)
        {
            return 0;
        }

        // size of vector.
        int n = nums.size();

        // needed variables.
        int maxReach = 0;
        int jump = 0;
        int pos = 0;

        // traverse through the vector and find the answer.
        for (int i = 0; i < n - 1; i++)
        {
            // update maxReach with maximum reachable index.
            maxReach = max(maxReach, i + nums[i]);

            if (pos == i)
            {
                pos = maxReach;
                jump++;
            }
        }

        return jump;
    }

public:
    int jump(vector<int> &nums)
    {

        // // Recursive Solution.
        // return minJumps_Recursive(nums, 0);

        // // DP Memoization Solution.
        // vector<int> dp(nums.size(), 10001); // Intitalize 'dp' vector with maximum possible jumps, becuase we have to return minimum jumps.
        // return minJumps_Memoized(nums, dp, 0);

        // // DP Tabulation Solution.
        // return minJumps_Tabulized(nums);

        // Optimized Solution.
        return minJumps_Optimized(nums);
    }
};

int main(void)
{
    vector<int> nums{2, 3, 1, 1, 4};

    // Solution.
    Solution obj;
    cout << obj.jump(nums);
    return 0;
}