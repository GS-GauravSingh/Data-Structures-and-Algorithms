#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    long long int solve(vector<int> &nums)
    {
        // size of nums vector.
        long long int n = nums.size();

        // pointers.
        long long int prevOne = 0;
        long long int prevTwo = 0;

        for (int idx = 0; idx < n; idx++)
        {
            // Picking the ith element, Now when we are picking the ith element, then the sum has to increase by nums[i] and when we are picking the ith element, we have to skip the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are picking the ith element then the next element we are going to pick is i+2th element.
            long long int pickSum = nums[idx] + ((idx - 2 < 0) ? 0 : prevTwo);

            // Not Picking the ith element, Now when we are skipping the ith element, then the sum will not increase and when we are skipping the ith element, we can pick the i+1th element because we have to create subsequence in such a way that no two elements are adjacent.
            // So, when we are skipping the ith element then the next element we are going to pick is i+1th element.
            long long int notPickSum = ((idx - 1 < 0) ? 0 : prevOne);

            // store the maximum sum.
            long long int curr = max(pickSum, notPickSum);

            // update the pointers.
            prevTwo = prevOne;
            prevOne = curr;
        }

        // return the maximum sum.
        return prevOne;
    }

public:
    /* Question: A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get notified.

    Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money that the thief can rob without alerting the police. */

    /* Note: This question can be solved using the approach discussed in the Maximum Sum of non-adjacent elements. */
    long long int houseRobber(vector<int> &valueInHouse)
    {
        // Base Case
        if (valueInHouse.size() == 1)
        {
            return valueInHouse[0];
        }

        // size of 'valueInHouse' vector.
        int n = valueInHouse.size();

        // Divide the array 'valueInHouse' into two parts.

        // First part contains all the elements present in 'valueInHouse' array except for the last (valueInHouse[n-1]) element.
        vector<int> arr1;

        // Second part contains all the elements present in 'valueInHouse' array except for the first (valueInHouse[0]) element.
        vector<int> arr2;

        // store the elements in both the arrays.
        for (int i = 0; i < n; i++)
        {
            // First part contains all the elements present in 'valueInHouse' array except for the last (valueInHouse[n-1]) element.
            if (i != n - 1)
            {
                arr1.push_back(valueInHouse[i]);
            }

            // Second part contains all the elements present in 'valueInHouse' array except for the first (valueInHouse[0]) element.
            if (i != 0)
            {
                arr2.push_back(valueInHouse[i]);
            }
        }

        // store the answer for arr1.
        long long int ans1 = solve(arr1);

        // store the answer for arr2.
        long long int ans2 = solve(arr2);

        // return the maximum answer.
        return max(ans1, ans2);
    }
};

int main(void)
{
    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();

    // Solution.
    Solution S;
    cout << "Maximum amount of money the robber can rob tonight is : " << S.houseRobber(arr) << "$.";
    return 0;
}