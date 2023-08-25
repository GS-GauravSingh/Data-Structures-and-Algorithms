#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Optimal Approach: Using unordered_map.
    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(n), space used by unordered_map.
    */
    bool containsDuplicate(vector<int> &nums)
    {

        // unordered_map.
        unordered_map<int, int> map;

        // Traverse the nums vector and store the frequency of each element into our map.
        for (auto it : nums)
        {
            map[it]++;
        }

        // Now, Iterate through the map and if any element is having a frequency greater than 1, it means duplicates are present, otherwise not.
        for (auto it : map)
        {
            // if any element is having a frequency greater than 1, it means duplicates are present. So return true.
            if (it.second > 1)
            {
                return true;
            }
        }

        // if above loop does not return anything, it means duplicates does not present. So return false from here.
        return false;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 1};

    // Solution.
    Solution obj;
    cout << obj.containsDuplicate(nums);
    return 0;
}