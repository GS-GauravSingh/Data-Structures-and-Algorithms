#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    bool solve(int idx, int n, int bucketSum, int bucketNum, int reqSum, int k, vector<int> &nums, vector<int> &alreadyPicked)
    {

        // Base Case.

        if (bucketNum == k + 1)
        {
            return true;
        }

        if (bucketSum == reqSum)
        {
            return solve(0, n, 0, bucketNum + 1, reqSum, k, nums, alreadyPicked);
        }

        if (bucketSum > reqSum)
        {
            return false;
        }

        if (idx >= n)
        {
            return false;
        }

        // Recursive Case.
        if (alreadyPicked[idx] == 1)
        {
            // means, this element is already picked in the past.
            // move to next element, and bucket number will remain same.
            return solve(idx + 1, n, bucketSum, bucketNum, reqSum, k, nums, alreadyPicked);
        }
        else
        {
            // means, this element is not picked.
            // Now, we have to choices, first is to pick this element and second is not pick this element.

            // Picking the ith element.
            bucketSum += nums[idx];
            alreadyPicked[idx] = 1;
            bool ans1 = solve(idx + 1, n, bucketSum, bucketNum, reqSum, k, nums, alreadyPicked);

            // backtracking step.
            bucketSum -= nums[idx];
            alreadyPicked[idx] = 0;

            // Not picking the ith element.
            bool ans2 = solve(idx + 1, n, bucketSum, bucketNum, reqSum, k, nums, alreadyPicked);

            return ans1 | ans2;
        }
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int n, int K)
    {
        vector<int> alreadyPicked(n, 0);
        int reqSum = 0;

        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }

        if (sum % K == 0)
        {
            reqSum = sum / K;
        }
        else
        {
            return false;
        }

        return solve(0, nums.size(), 0, 1, reqSum, K, nums, alreadyPicked);
    }
};

int main()
{
    vector<int> arr = {4, 3, 1, 3, 4, 3, 1, 2};

    Solution S;
    cout << S.canPartitionKSubsets(arr, arr.size(), 3);
}