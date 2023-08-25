#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using Boyer Moore’s Voting Algorithm. */
    // Time Complexity :- O(n), where 'n' is the size of the nums vector.
    // Space Complexity :- O(1).
    int majorityElement(vector<int> &nums)
    {

        // Initialize 'freq' with 0.
        int freq = 0;

        // variable to store majority element.
        int majorityEle = 0;

        // Traverse the array.
        for (int i = 0; i < nums.size(); i++)
        {
            // IF 'freq == 0', in this case,
            // Step 1: Consider this current element 'nums[i]' as majority element.
            // Setp 2: Increment the frequence by 1.
            if (freq == 0)
            {
                majorityEle = nums[i];
                freq++;
            }

            // Simply check, if the the current element i.e., nums[i], if nums[i] == majorityEle, then increment the 'freq'.
            else if (nums[i] == majorityEle)
            {
                freq++;
            }

            // but, if the current element i.e., nums[i], if nums[i] != majorityEle, then decrement the 'freq'.
            else
            {
                freq--;
            }
        }

        // return majority element.
        return majorityEle;
    }
};

int main(void)
{
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};

    // Solution.
    Solution obj;
    cout << "Majority Element: " << obj.majorityElement(nums) << ".";
    return 0;
}