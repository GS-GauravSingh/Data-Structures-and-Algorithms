#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: Generate all quadruplets using 4-loops and find store and return those quadruplets whose sum of element is equal to target.

    Time Complexity: O(n log(n)) + O(n^4), where 'n' is the size of the nums vector. O(n log(n)) is for sorting and O(n^4) is for finding quadruplets.
    Space Complexity: O(1), excluding the space used by ans vector to store quadruplets.
    */
    vector<vector<int>> fourSum_BruteForce(vector<int> &nums, int target)
    {

        // size of the nums vector.
        int n = nums.size();

        // Duplicates may present in the nums vector, so sort the nums vector, this will help us to skip duplicates.
        sort(nums.begin(), nums.end());

        // vector to store quadruplets whose sum of element is equal to target.
        vector<vector<int>> ans;

        // Generate all quadruplets using 4-loops and find store and return those quadruplets whose sum of element is equal to target.
        for (int i = 0; i < n; i++)
        {
            // First Number of quadruplet.
            long long firstNum = nums[i]; // use long long instead of int to avoid integer overflow.

            for (int j = i + 1; j < n; j++)
            {
                // Second Number of quadruplet.
                long long secondNum = nums[j]; // use long long instead of int to avoid integer overflow.

                for (int k = j + 1; k < n; k++)
                {
                    // Third Number of quadruplet.
                    long long thirdNum = nums[k]; // use long long instead of int to avoid integer overflow.

                    for (int l = k + 1; l < n; l++)
                    {
                        // Fourth Number of quadruplet.
                        long long fourthNum = nums[l]; // use long long instead of int to avoid integer overflow.

                        // sum of quadruplets.
                        long long sum = firstNum + secondNum + thirdNum + fourthNum; // use long long instead of int to avoid integer overflow.

                        // Check whether the sum of quadruplet is equal to target or not.
                        // If yes, then store the quadruplet in our answer vector, otherwise continue checking other quadruplet.
                        if (sum == target)
                        {
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                            // Skipping Duplicates.
                            // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                            while (l + 1 < n && nums[l] == nums[l + 1])
                            {
                                l++;
                            }
                        }
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

        // return answer
        return ans;
    }

    /* Optimal Approach: Using sorting, nested loops and two pointer.

    Time Complexity: O(n log(n)) + O(n^3), where 'n' is the size of the nums vector. O(n log(n)) is for sorting and O(n^3) is for finding quadruplets.
    Space Complexity: O(1), excluding the space used by ans vector to store quadruplets.
    */
    vector<vector<int>> fourSum_Optimal(vector<int> &nums, int target)
    {

        // size of the nums vector.
        int n = nums.size();

        // Duplicates may present in the nums vector, so sort the nums vector, this will help us to skip duplicates.
        sort(nums.begin(), nums.end());

        // vector to store quadruplets whose sum of element is equal to target.
        vector<vector<int>> ans;

        // Finding Quadruplets whose sum is equal to the target.
        for (int i = 0; i < n; i++)
        {
            // First Number of quadruplet.
            long long firstNum = nums[i]; // use long long instead of int to avoid integer overflow.

            for (int j = i + 1; j < n; j++)
            {
                // Second Number of quadruplet.
                long long secondNum = nums[j]; // use long long instead of int to avoid integer overflow.

                // Now, use two-pointer approach to find the third and fourth number of quadruplets.
                int start = j + 1;
                int end = n - 1;

                while (start < end)
                {
                    // Third Number of quadruplet.
                    long long thirdNum = nums[start]; // use long long instead of int to avoid integer overflow.

                    // Fourth Number of quadruplet.
                    long long fourthNum = nums[end]; // use long long instead of int to avoid integer overflow.

                    // sum of quadruplets.
                    long long sum = firstNum + secondNum + thirdNum + fourthNum; // use long long instead of int to avoid integer overflow.

                    // Check whether the sum of quadruplet is equal to target or not.
                    // If yes, then store the quadruplet in our answer vector, otherwise continue checking other quadruplet.
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        // Skipping Duplicates.
                        // Considering only first occurence of element and then skip all the occurence of this element, in case of duplicates.
                        while (start < end && nums[start] == nums[start + 1])
                        {
                            start++;
                        }

                        while (start < end && nums[end] == nums[end - 1])
                        {
                            end--;
                        }

                        // Update Pointers.
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

        // return answer
        return ans;
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        // Brute Force Approach.
        // return fourSum_BruteForce(nums, target);

        // Optimal Approach.
        return fourSum_Optimal(nums, target);
    }
};

int main(void)
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.fourSum(nums, target);

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