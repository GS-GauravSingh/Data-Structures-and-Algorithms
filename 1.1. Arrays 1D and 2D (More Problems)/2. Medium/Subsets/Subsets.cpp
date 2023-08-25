#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Recursive Method to generate all subsets of 'nums' array. */
    // Time Complexity: O(2^n * n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), recursive stack space.
    void generateAllSubsets(int i, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &powerSet)
    {
        // Base Case

        // When i >= nums.size(), it means we have traverse all the elements of nums vector and 'subSet' vector is storing one possible subset of nums vector. So, store this subset into our powerset vector and return from here.
        if (i >= nums.size())
        {
            powerSet.push_back(subSet);
            return;
        }

        // Recursive Case.

        // Picking the 'ith' indexed element.
        subSet.push_back(nums[i]);
        generateAllSubsets(i + 1, nums, subSet, powerSet);

        // Backtracking Step.
        subSet.pop_back();

        // Not Picking the 'ith' indexed element.
        generateAllSubsets(i + 1, nums, subSet, powerSet);
    }

public:
    // Time Complexity: O(2^n * n) for generating all subsets, where 'n' is the size of the nums vector.
    // Space Complexity: O(n) recursive stack space while generating all subsets + O(2^n * n) space used for storing all subsets 'powerSet' + O(n) space used for creating subsets 'subSet'.
    vector<vector<int>> subsets(vector<int> &nums)
    {

        // vector to store all subsets.
        vector<vector<int>> powerSet;

        // vector for creating subsets.
        vector<int> subSet;

        // Generating all subsets.
        generateAllSubsets(0, nums, subSet, powerSet);

        // Finally return answer.
        return powerSet;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3};

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.subsets(nums);

    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}