#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Time Complexity to generate all subsets: O(2^n), where 'n' is the size of the nums vector.
    // Space Complexity: O(target), recursive stack space.
    void generateCombinations(int i, int n, int target, vector<int> &nums, vector<int> &subSet, vector<vector<int>> &powerSet)
    {
        // Base Cases

        // If target < 0, then no need to move forward in this direction because in this direction we will not find any of those combinations whose sum of elements is equal to the target.
        if (target < 0)
        {
            return;
        }

        // If target = 0, it means we have a subset/combination whose sum of elements is equal to target.
        // so store this subset into answer and return from here.
        if (target == 0)
        {
            powerSet.push_back(subSet);
            return;
        }

        // If i >= n, it means we traverse all the element of nums, so simply return from here.
        if (i >= n)
        {
            return;
        }

        // Recursive case.

        // Picking the ith element.
        subSet.push_back(nums[i]);
        target = target - nums[i];

        // We can choose same number multiple time so don't increment 'i'.
        generateCombinations(i, n, target, nums, subSet, powerSet);

        // Backtracking Step.
        subSet.pop_back();
        target = target + nums[i];

        // Now picking the ith element.
        generateCombinations(i + 1, n, target, nums, subSet, powerSet);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        int n = candidates.size();

        vector<int> subSet;
        vector<vector<int>> powerSet;
        generateCombinations(0, n, target, candidates, subSet, powerSet);
        return powerSet;
    }
};

int main(void)
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(candidates, target);

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