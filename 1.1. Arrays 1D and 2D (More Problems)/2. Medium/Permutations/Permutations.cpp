#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Method to generate all permutations.

    Time Complexity: O(n*n!) time to generate all permutations, where 'n' is the size of the nums vector.
    Space Complexity: O(n), recursive stack space.
    */
    void generateAllPermutations(int idx, vector<int> &nums, vector<vector<int>> &allPermutations)
    {
        // Base case
        if (idx >= nums.size())
        {
            allPermutations.push_back(nums);
            return;
        }

        // Recursive case.
        for (int i = idx; i < nums.size(); i++)
        {
            // place every element to first position one by one.
            swap(nums[idx], nums[i]);

            // recursive call.
            generateAllPermutations(idx + 1, nums, allPermutations);

            // backtracking step.
            swap(nums[idx], nums[i]);
        }
    }

public:
    /*
    Time Complexity: O(n*n!) time to generate all permutations, where 'n' is the size of the nums vector.
    Space Complexity: O(n!*n) to store all permutations.
    */
    vector<vector<int>> permute(vector<int> &nums)
    {

        // vector to store all prmutations.
        vector<vector<int>> allPermutations;

        // generating all permutations and store it in 'allPermutations' vector.
        generateAllPermutations(0, nums, allPermutations);

        // al permutations of nums are stored in allPermutations vector.
        return allPermutations;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3};

    // Solution.
    Solution obj;
    vector<vector<int>> ans = obj.permute(nums);

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