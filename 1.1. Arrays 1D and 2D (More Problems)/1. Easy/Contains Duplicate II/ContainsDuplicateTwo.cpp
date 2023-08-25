#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using unordered_map.
    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(n), space used by unordered_map.
    */
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // unordered_map.
        unordered_map<int, int> map;

        // Traverse the nums vector and
        for (int i = 0; i < nums.size(); i++)
        {
            // If the current element has already been seen before, it means this 'nums[i]' (current element) is a duplicate element.
            // Now, you have to fund the indexes,
            // The index of the previous occurrence of this element is stored inside the map, and 'i' is the index of the current element.
            // Now, simply check for the condition.
            if (map.find(nums[i]) != map.end())
            {
                // get the index of previous occurence of this duplicate element.
                int j = map[nums[i]];

                // Check for condition.
                if (abs(i - j) <= k)
                {
                    return true;
                }
            }

            // Now, if the condition does not execute, it menas we have not seen this number before, so insert this number with its index into the map.
            // But, if the above condition evaluates to true, but this condition (abs(i - j) <= k) evaluates to false, in this case, we also update the index of this number.
            map[nums[i]] = i;
        }

        // if the above loop does not return anything, it means their is not pair exists which statisfy the given condition.
        // So return false.
        return false;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 1};
    int k = 3;

    // Solution.
    Solution obj;
    cout << obj.containsNearbyDuplicate(nums, k);
    return 0;
}