#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Generate all triplets using 3 loops and store those triplets whose sum is equal to 0.

    Time Complexity: O(n log(n)) + O(n^3), where 'n' is the size of the nums vector. O(n log(n)) is for sorting the nums vector and  O(n^3) is for finding triplets.
    Space Complexity: O(1), excluding the space used by vector to store triplets.
    */
    vector<vector<int>> threeSum_BruteForce(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // sort the given array, this will help us to skip the duplicates.
        sort(nums.begin(), nums.end());

        // vector to store answer.
        vector<vector<int>> ans;

        // Generate all triplets using 3 loops and store those triplets whose sum is equal to 0.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // Check whether the sum of triplets is equal to 0 or not.
                    // If yes, then store the triples in our answer vector, otherwise continue checking other triplets.
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }

                    // Skipping Duplicates.
                    // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                    while (k + 1 < n && nums[k] == nums[k + 1])
                    {
                        k++;
                    }
                }

                // Skipping Duplicates.
                // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }

            // Skipping Duplicates.
            // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        // return answer.
        return ans;
    }

    /* Optimal Approach: Using Sorting and 2 pointers.

    Time Complexity: O(n log(n)) + O(n^2), where 'n' is the size of the nums vector. O(n log(n)) is for sorting the nums vector and  O(n^2) is for finding triplets.
    Space Complexity: O(1), excluding the space used by vector to store triplets.
    */
    vector<vector<int>> threeSum_Optimal(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // sort the given array, this will help us to skip the duplicates.
        sort(nums.begin(), nums.end());

        // vector to store answer.
        vector<vector<int>> ans;

        // Traverse through the vector and find the triplets.
        for (int i = 0; i < n; i++)
        {
            // Now, our task is to find three numbers (triplets), whose sum is equal to 0.

            // Getting the first number of the the triplet.
            int firstNum = nums[i];

            // set the target to -ve of first number.
            int target = -firstNum;

            // Now, find 2 numbers whose summation is equal to target.
            // when you find 2 numbers whose summation is equal to target.
            // after adding the firstNumber in the summation, the answer will be 0.
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                // second number
                int secondNum = nums[start];

                // third number.
                int thirdNum = nums[end];

                // sum of second and third number.
                int sum = secondNum + thirdNum;

                // Check whether the sum of triplets is equal to 0 or not.
                // If yes, then store the triples in our answer vector, otherwise continue checking other triplets.
                if (sum == target)
                {
                    ans.push_back({firstNum, secondNum, thirdNum});

                    // Skipping Duplicates.
                    // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                    while (start < end && nums[start] == nums[start + 1])
                    {
                        start++;
                    }

                    // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                    while (start < end && nums[end] == nums[end - 1])
                    {
                        end--;
                    }

                    // Update both pointers.
                    start++;
                    end--;
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

            // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        // return answer.
        return ans;
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        // // Brute Force Approach.
        // return threeSum_BruteForce(nums);

        // Optimal Approach.
        return threeSum_Optimal(nums);
    }
};

int main(void)
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << ", ";
        }
        cout << endl;
    }
    return 0;
}