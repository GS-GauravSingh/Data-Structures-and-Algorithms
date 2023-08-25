#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    /*
    Time Complexity: O(n), where 'n' is the size of the 'nums' vector.
    Space Complexity: O(1).
    */
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return nums[0];
        }

        // size of vector.
        int n = nums.size();

        // Needed variables.
        int maxLen = 0;
        int currLen = 0;

        for (int i = 0; i < n; i++)
        {
            currLen += nums[i];

            // Break Point.
            if (nums[i] == 0)
            {
                currLen = 0;
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};

int main(void)
{
    vector<int> nums{1, 1, 0, 1, 1, 1};

    // Solution.
    Solution obj;
    cout << obj.findMaxConsecutiveOnes(nums);
    return 0;
}