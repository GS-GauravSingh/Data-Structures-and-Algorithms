#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int removeDuplicates(vector<int> &nums)
    {

        // Size of nums vector.
        int n = nums.size();

        // Base Case
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Now, first 2 elements are fixed, So start from index 2.
        int i = 2;

        for (int j = 2; j < n; j++)
        {
            if (nums[j] != nums[i - 2])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main(void)
{
    vector<int> nums{1, 1, 1, 2, 2, 3};

    // Solution.
    Solution obj;
    int len = obj.removeDuplicates(nums);

    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}