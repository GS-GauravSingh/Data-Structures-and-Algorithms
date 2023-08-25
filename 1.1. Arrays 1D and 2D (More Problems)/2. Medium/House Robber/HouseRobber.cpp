#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Recursive Solution to find the maximum amount of money you can rob tonight without alerting the police. */
    // Time Complexity: O(2^n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), recursive stack space.
    int robRecursive(int idx, vector<int> &nums)
    {
        // Base Case
        // When "idx >= nums. size()", it means we have traversed all the elements of the nums array. Now, there are no houses left where we can rob.
        // So, return 0 from here.
        if (idx >= nums.size())
        {
            return 0;
        }

        // Recursive Case.

        // Now, for the house at each index, we have two choices either we can rob this house or we can skip this house (do not rob this house).

        // Rob current house.
        // Now, when the robber is robbing this current house, the profit that the robber is having is the money present in this house and after robbing this house, robber cannot move to the adjacent house because adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

        // So, the robber will move to the house adjacent to the next house.
        int robCurrent = nums[idx] + robRecursive(idx + 2, nums);

        // Skipping current house.
        // Now, when the robber is robbing this current house, the profit that the robber is having is 0 and after skipping this house, robber can move to the adjacent house.
        int skipCurrent = 0 + robRecursive(idx + 1, nums);

        // Now, return the maximum amount of money that the robber can rob from the above two choices.
        return max(robCurrent, skipCurrent);
    }

    /* Optimizing above Recursive Solution using Dynamic Programming - Memoization Technique. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space and space used by 'dp' vector.
    int robMemoized(int idx, vector<int> &nums, vector<int> &dp)
    {
        // Base Case
        // When "idx >= nums. size()", it means we have traversed all the elements of the nums array. Now, there are no houses left where we can rob.
        // So, return 0 from here.
        if (idx >= nums.size())
        {
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx] != -1)
        {
            // If dp[n] == -1, it means this is not an overlapping subproblem.
            // but If dp[n] != -1, it means this is an overlapping subproblem and the dp[n] contains the answer of this subproblem.
            return dp[idx];
        }

        // Now, for the house at each index, we have two choices either we can rob this house or we can skip this house (do not rob this house).

        // Rob current house.
        // Now, when the robber is robbing this current house, the profit that the robber is having is the money present in this house and after robbing this house, robber cannot move to the adjacent house because adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

        // So, the robber will move to the house adjacent to the next house.
        int robCurrent = nums[idx] + robMemoized(idx + 2, nums, dp);

        // Skipping current house.
        // Now, when the robber is robbing this current house, the profit that the robber is having is 0 and after skipping this house, robber can move to the adjacent house.
        int skipCurrent = 0 + robMemoized(idx + 1, nums, dp);

        // Store the answer of this subproblem in 'dp' vector.
        // Now, return the maximum amount of money that the robber can rob from the above two choices.
        return dp[idx] = max(robCurrent, skipCurrent);
    }

    /* Optimizing above DP Memoization Solution using Dynamic Programming - Tabulation Technique. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), space used by 'dp' vector.
    int robTabulized(vector<int> &nums)
    {
        // 'dp' vector.
        vector<int> dp(nums.size(), 0);

        // Traverse the 'dp' vector.
        for (int idx = nums.size() - 1; idx >= 0; idx--)
        {
            // Now, for the house at each index, we have two choices either we can rob this house or we can skip this house (do not rob this house).

            // Rob current house.
            // Now, when the robber is robbing this current house, the profit that the robber is having is the money present in this house and after robbing this house, robber cannot move to the adjacent house because adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

            // So, the robber will move to the house adjacent to the next house.
            int robCurrent = nums[idx] + ((idx + 2 >= nums.size()) ? 0 : dp[idx + 2]);

            // Skipping current house.
            // Now, when the robber is robbing this current house, the profit that the robber is having is 0 and after skipping this house, robber can move to the adjacent house.
            int skipCurrent = 0 + ((idx + 1 >= nums.size()) ? 0 : dp[idx + 1]);

            // Store the answer of this subproblem in 'dp' vector.
            dp[idx] = max(robCurrent, skipCurrent);
        }

        // return final answer.
        return dp[0];
    }

    // /* Space Optimizing the above DP Tabulation code. */
    // If you closely look at the relationship, for finding the answer of current index, we only need answers for previous 2 indices i.e., dp[idx + 1], dp[idx + 2].
    // So, we can use Variable instead of 'dp' array/vector.
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int robSpaceOptimized(vector<int> &nums)
    {
        // 'oneIdxPrev' and 'twoIdxPrev' variables.
        int oneIdxPrev = 0, twoIdxPrev = 0;

        // Traverse.
        for (int idx = nums.size() - 1; idx >= 0; idx--)
        {
            // Now, for the house at each index, we have two choices either we can rob this house or we can skip this house (do not rob this house).

            // Rob current house.
            // Now, when the robber is robbing this current house, the profit that the robber is having is the money present in this house and after robbing this house, robber cannot move to the adjacent house because adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

            // So, the robber will move to the house adjacent to the next house.
            int robCurrent = nums[idx] + ((idx + 2 >= nums.size()) ? 0 : twoIdxPrev);

            // Skipping current house.
            // Now, when the robber is robbing this current house, the profit that the robber is having is 0 and after skipping this house, robber can move to the adjacent house.
            int skipCurrent = 0 + ((idx + 1 >= nums.size()) ? 0 : oneIdxPrev);

            // Store the answer for current index.
            int curr = max(robCurrent, skipCurrent);

            // Update both the pointers.
            twoIdxPrev = oneIdxPrev;
            oneIdxPrev = curr;
        }

        // return final answer.
        return oneIdxPrev;
    }

public:
    int rob(vector<int> &nums)
    {

        // // Recursive Solution.
        // return robRecursive(0, nums);

        // // Dynamic Programming - Memoization Solution.
        // vector<int> dp(nums.size(), -1);
        // return robMemoized(0, nums, dp);

        // // Dynamic Programming - Tabulation Solution.
        // return robTabulized(nums);

        // Space Optimization S0lution.
        return robSpaceOptimized(nums);
    }
};

int main(void)
{
    vector<int> nums{2, 7, 9, 3, 1};

    // Solution.
    Solution obj;
    cout << "Robber Maximum Profit: " << obj.rob(nums) << ".";
    return 0;
}