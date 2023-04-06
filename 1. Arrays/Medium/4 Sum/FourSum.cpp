/*
Question :-
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach :- Using sorting, loops,and 2 pointer. */
    // Time Complexity :- O()
    // Space Complexity :- O()
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        // size of array.
        int n = nums.size();

        // sort the array.
        sort(nums.begin(), nums.end());

        // vector to store answer.
        vector<vector<int>> ans;

        // iterate through the array and find the answer.
        for (int i = 0; i < n; i++)
        {
            // first Number.
            long long firstNumber = nums[i];

            for (int j = i + 1; j < n; j++)
            {
                // second Number .
                long long secondNumber = nums[j];

                // find thrid and fourth number using 2 pointer approach.
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    // third number.
                    long long thirdNumber = nums[start];

                    // fourth number.
                    long long fourthNumber = nums[end];

                    // sum
                    long long sum = firstNumber + secondNumber + thirdNumber + fourthNumber;

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        // remove duplicate elements.
                        while (start < end && nums[start] == nums[start + 1])
                        {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end - 1])
                        {
                            end--;
                        }

                        // move pointer's.
                        start++;
                        end--;
                    }
                    else if (sum > target)
                    {
                        end--;
                    }
                    else
                    {
                        // sum < target
                        start++;
                    }
                }
                // remove duplicate elements.
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
            }
            // remove duplicate elements.
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
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;

    Solution S;
    vector<vector<int>> ans =   S.fourSum(nums, target);
    S.print2D(ans);

}