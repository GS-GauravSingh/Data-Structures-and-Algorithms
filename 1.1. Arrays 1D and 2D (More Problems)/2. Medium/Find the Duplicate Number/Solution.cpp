#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Method 1:- Using nested loops. */
    // Time Complexity:- O(n^2), where 'n' is the size of the nums vector.
    // Space Complexity:- O(1).
    int findDuplicate_Approach_1(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }

    /*
    Brute Force Method 2: Use sorting (so the duplicate element come together).
    */
    // Time Complexity:- O(n log(n)), where 'n' is the size of the nums vector.
    // Space Complexity:- O(1).
    int findDuplicate_Approach_2(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // sort the given array.
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }

        return -1;
    }

    /* Brute Force Method 3:- Use Hashing */
    // Time Complexity:- O(n), where 'n' is the size of the nums vector.
    // Space Complexity:- O(n), space used by unordered_amp.
    int findDuplicate_Approach_3(vector<int> &nums)
    {
        // Unordered_map.
        unordered_map<int, int> map;

        // store the frequency of each element into map.
        for (int i = 0; i < nums.size(); i++)
        {

            int element = nums[i];
            map[element]++;
        }

        // Traverse the map and the element having frequency greater than 1, that number is repeted number..
        for (auto it : map)
        {

            if (it.second > 1)
            {
                return it.first;
            }
        }

        return -1;
    }

    /*
     * Optmized Approach:- Marking visited value within the array.
     * Since all values of the array are between [1…n] and the array size is n+1,
     * while scanning the array from left to right, we set the nums[n] to its
     * negative value.
     *
     * With extra O(1) space, with modifying the input.
     */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    int findDuplicate_Optimized(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            int idx = abs(nums[i]);

            // already visited.
            if (nums[idx] < 0)
            {
                return idx;
            }

            // mark visited.
            nums[idx] = -nums[idx];
        }

        return -1;
    }

public:
    int findDuplicate(vector<int> &nums)
    {
        return findDuplicate_Optimized(nums);
    }
};

int main(void)
{
    vector<int> nums{1, 3, 4, 2, 2};

    // Solution.
    Solution obj;
    cout << obj.findDuplicate(nums);
    return 0;
}