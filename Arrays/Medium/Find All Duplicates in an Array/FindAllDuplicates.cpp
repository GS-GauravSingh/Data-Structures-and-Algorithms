/*
Question:-
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.


Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []


Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- Using Nested Loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    vector<int> findDuplicates_Approach_1(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }

    /* Approach 2 :- Using sorting. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    vector<int> findDuplicates_Approach_2(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // sort the given array.
        sort(nums.begin(), nums.end());

        for (int j = 0; j < n - 1; j++)
        {
            if (nums[j] == nums[j + 1])
            {
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }

    /* Approach 3 :- Using hashing. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    vector<int> findDuplicates_Approach_3(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // unordered map
        unordered_map<int, int> frequency;

        // storing the frequency of each element in map.
        for (int i = 0; i < n; i++)
        {
            int elemenet = nums[i];
            frequency[elemenet]++;
        }
        
        // duplicate element is the element having frequency greater that 1.
        for(auto i : frequency)
        {
            if(i.second > 1)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }


    /*
    Approach 4 :- One Pass

    Algorithm :-
    1. traverse through the array.
    2. Treat array elements an indexes and mark element at nums[index] as negative.
        int index = nums[i];
        num[index] = -nums[index];
    3. Now check if the value a the index is +ve or not. If positive it's a duplicate element. Because if this element appear only once then it's sign is negative.


    Dry Run :-

    Example :- {4, 2, 4, 3, 1}
    
    1st Pass:
    Element = nums[0] = 4.
    index = nums[4 - 1] = nums[3], -1 is for 0-based indexing.
    Array: {4, 2, 4, -3, 1}
    nums[3] = -3, which is negative.
    
    2nd Pass:
    Element = nums[1] = 2.
    index = nums[2 - 1] = nums[1], -1 is for 0-based indexing.
    Array: {4, -2, 4, -3, 1}
    nums[1] = -2, which is negative.
    
    3rd Pass:
    Element = nums[2] = 4.
    index = nums[4 - 1] = nums[3], -1 is for 0-based indexing.
    Array: {4, -2, 4, +3, 1}
    nums[3] = +3, duplicate found.
    
    4th Pass:
    Element = nums[3] = 3.
    index = nums[3 - 1] = nums[2], -1 is for 0-based indexing.
    Array: {4, -2, -4, 3, 1}
    nums[2] = -2, which is negative.
    
    5th Pass:
    Element = nums[4] = 1.
    index = nums[1 - 1] = nums[0], -1 is for 0-based indexing.
    Array: {-4, -2, -4, 3, 1}
    nums[0] = -4, which is negative.

    */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    vector<int> findDuplicates_Approach_4(vector<int> &nums)
    {
        // size of array.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            // index.
            int index = abs(nums[i]) - 1; // 0-based indexing.

            // negate the element
            nums[index] = -nums[index];

            // if this element is positive means double negation had happened which 
            // means we editied this element twice.
            if(nums[index] > 0)
            {
                ans.push_back(index+1);
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
        cout<<endl;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans1 = S.findDuplicates_Approach_1(nums);
    vector<int> ans2 = S.findDuplicates_Approach_2(nums);
    vector<int> ans3 = S.findDuplicates_Approach_3(nums);
    vector<int> ans4 = S.findDuplicates_Approach_4(nums);
    S.print(ans1);
    S.print(ans2);
    S.print(ans3);
    S.print(ans4);
}