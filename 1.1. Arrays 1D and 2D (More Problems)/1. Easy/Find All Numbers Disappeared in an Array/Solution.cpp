#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    vector<int> findDisappearedNumbers(vector<int> &nums)
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
            nums[index] = (nums[index] > 0) ? -nums[index] : nums[index];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    // Solution.
    Solution obj;
    vector<int> ans = obj.findDisappearedNumbers(nums);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}