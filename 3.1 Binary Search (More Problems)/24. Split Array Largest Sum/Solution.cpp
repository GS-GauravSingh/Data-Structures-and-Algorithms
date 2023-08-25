#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool canSplitOrNot(vector<int> &nums, int k, int limit)
    {
        int split = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= limit)
            {
                sum += nums[i];
            }
            else
            {
                split++;
                if (split > k || nums[i] > limit)
                {
                    return false;
                }
                sum = nums[i];
            }
        }

        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        // Similar Question: Book Allocation Problem.

        // size of vector.
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int low = 0;
        int high = 0;
        for (int i : nums)
            high += i;

        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canSplitOrNot(nums, k, mid))
            {
                ans = mid;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 4, 5};
    int k = 2;

    // Solution.
    Solution obj;
    cout << obj.splitArray(nums, k);
    return 0;
}