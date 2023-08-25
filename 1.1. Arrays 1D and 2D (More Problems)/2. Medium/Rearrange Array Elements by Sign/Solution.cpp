#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Brute Force Approach: Using Auxiliary arrays. */
    // Time Complexity: O(n) + O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n/2) + O(n/2) + O(n), space used by auxiliary vectors.
    vector<int> rearrangeArray_BruteForce(vector<int> &nums)
    {
        // SIze of nums vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // Create 2 arrays to store positive and negative elements.
        vector<int> neg, pos;

        // Traverse the nums vector and store positive and negative elements seperately in their own vector.
        for (int i = 0; i < nums.size(); i++)
        {
            // Negative Element.
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            // Positive Element.
            else
            {
                pos.push_back(nums[i]);
            }
        }

        // In constraint of question it is given that the length of nums is even. So to rearrange elements in given order, there will be equal number of positive and negative element.

        // So both the above vector have equal number of elements i.e, n/2.
        for (int i = 0; i < n / 2; i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }

    /* Optimized Approach. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), space used by answer vectors.
    vector<int> rearrangeArray_Optimized(vector<int> &nums)
    {
        // SIze of nums vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans(n);

        // We know that the resultant array must start from a positive element.
        // Order oe elements: +ve, -ve, +ve, -ve ..... so on.
        // If you observe carefully, Positive element are at even indices and Negative elements are at odd indices.
        int posIdx = 0;
        int negIdx = 1;

        // Start traversing the array and fill positive elements at even indexes and negative elements at odd indexes.
        for (int i = 0; i < n; i++)
        {
            // Negative Element at odd indexes.
            if (nums[i] < 0)
            {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }

            // Positive Element at even indexes.
            else
            {
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
        }

        return ans;
    }

public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        // // Brute Force Approach.
        // return rearrangeArray_BruteForce(nums);

        // Optimized Approach.
        return rearrangeArray_Optimized(nums);
    }
};

int main(void)
{
    vector<int> nums{3, 1, -2, -5, 2, -4};

    // Solution.
    Solution obj;
    vector<int> ans = obj.rearrangeArray(nums);

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}