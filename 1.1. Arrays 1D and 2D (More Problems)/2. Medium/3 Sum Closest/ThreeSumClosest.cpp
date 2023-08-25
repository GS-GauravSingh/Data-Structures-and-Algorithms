#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Generate all triplets using 3 loops and return the sum of those triplets whose sum is equal to target and if the sum of triplet is not equal to target, then in this case, we have to find the triplets whose sum is closest to target. .

    Time Complexity: O(n^3), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int threeSumClosest_BruteForce(vector<int> &nums, int target)
    {
        // Size of nums vector.
        int n = nums.size();

        // 'diff' is used to find the triplets whose sum is closest to target.
        int diff = INT_MAX;

        // variable to store answer.
        int ans = 0;

        // Generate all triplets using 3 loops and return the sum of those triplets whose sum is equal to the target.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // sum of triplets.
                    int sum = nums[i] + nums[j] + nums[k];

                    // Check whether the sum of triplets is equal to target or not.
                    // If yes, then return the sum (or you can return target also because sum is equal to target), otherwise continue checking other triplets.
                    if (sum == target)
                    {
                        return sum;
                    }

                    // if the sum of triplet is not equal to target, then in this case, we have to find the triplets whose sum is closest to target.
                    else if (abs(sum - target) < diff)
                    {
                        diff = abs(sum - target);
                        ans = sum;
                    }
                }
            }
        }

        // return answer.
        return ans;
    }

    /* Optimal Approach: Using Sorting and 2 pointers.

    Time Complexity: O(n log(n)) + O(n^2), where 'n' is the size of the nums vector.
    Space Complexity: O(1).
    */
    int threeSumClosest_Optimal(vector<int> &nums, int target)
    {
        // Size of nums vector.
        int n = nums.size();

        // sort the given vector.
        sort(nums.begin(), nums.end());

        // 'diff' is used to find the triplets whose sum is closest to target.
        int diff = INT_MAX;

        // variable to store answer.
        int ans = 0;

        // Traverse through the vector and find the triplets.
        for (int i = 0; i < n; i++)
        {
            // Now, our task is to find three numbers (triplets), whose sum is equal to target.

            // Getting the first number of the the triplet.
            int firstNum = nums[i];

            // Now, use two-pointer approach to find second and third number of the triplets.
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                // second number
                int secondNum = nums[start];

                // third number.
                int thirdNum = nums[end];

                // sum of triplets.
                int sum = firstNum + secondNum + thirdNum;

                // Check whether the sum of triplets is equal to target or not.
                // If yes, then return the sum (or you can return target also because sum is equal to target), otherwise continue checking other triplets.
                if (sum == target)
                {
                    return sum;
                }
                // if the sum of triplet is not equal to target, then in this case, we have to find the triplets whose sum is closest to target.
                else if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ans = sum;
                }
                else if (sum < target)
                {
                    start++;
                }
                else
                {

                    // sum > target.
                    end--;
                }
            }
        }

        // return answer.
        return ans;
    }

public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // // Brute Force Approach.
        // return threeSumClosest_BruteForce(nums, target);

        // Optimal Approach.
        return threeSumClosest_Optimal(nums, target);
    }
};

int main(void)
{
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;

    // Solution.
    Solution obj;
    cout << obj.threeSumClosest(nums, target);

    return 0;
}