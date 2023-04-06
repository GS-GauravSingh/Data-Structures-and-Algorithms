/*
Question :-
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not matter.


Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach :- Using sorting and 2 pointer. */
    // Time Complexity :- O(n log(n)) + O(n^2), n log(n) for sorting, and O(n^2) for iterating through the vector.
    // Space Complexity :- O(1)
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answer.
        vector<vector<int>> ans;

        // sort the given vector.
        sort(nums.begin(), nums.end());

        // traverse through the vector and find the triplets.
        for (int i = 0; i < n; i++)
        {
            // We have to find three numbers, whose sum is equal to 0.

            // we got the first number.
            int firstNumber = nums[i];

            // set the target to -ve of first number.
            int target = -firstNumber;

            // Now, find 2 numbers whose summation is equal to target.
            // when you find 2 numbers whose summation is equal to target.
            // after adding the firstNumber in the summation, the answer will be 0.

            // 2 pointer
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                // second number.
                int secondNumber = nums[start];

                // third number.
                int thirdNumber = nums[end];

                // sum
                int sum = secondNumber + thirdNumber;

                if (sum == target)
                {
                    ans.push_back({firstNumber, secondNumber, thirdNumber});

                    // skipping the duplicates.
                    while (start < end && nums[start + 1] == nums[start])
                    {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end - 1])
                    {
                        end--;
                    }

                    // update the pointers.
                    start++;
                    end--;
                }
                else if (sum > target)
                {
                    end--;
                }
                else
                {
                    // sum < target.
                    start++;
                }
            }
            // skip the duplicate elements.
            while (i + 1 < n && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return ans;
    }

    /* Method to print 1D vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
    }

    /* Method to print 2D vector. */
    void print2D(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution S;
    vector<vector<int>> ans = S.threeSum(nums);
    S.print2D(ans);
}