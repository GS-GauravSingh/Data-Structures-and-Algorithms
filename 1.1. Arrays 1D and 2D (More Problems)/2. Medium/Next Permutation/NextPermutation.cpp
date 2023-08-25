#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    /* Method to generate all unique permutations. */
    void generateAllPermutations(int idx, vector<int> &nums, vector<vector<int>> &allPermutations)
    {
        // Base case
        if (idx >= nums.size())
        {
            allPermutations.push_back(nums);
            return;
        }

        // Recursive case.
        // Using unordered_set to skip duplicates.
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++)
        {
            // Skipping Duplicates.
            if (st.find(nums[i]) != st.end())
            {
                continue;
            }

            st.insert(nums[i]);

            // place every element to first position one by one.
            swap(nums[idx], nums[i]);

            // recursive call.
            generateAllPermutations(idx + 1, nums, allPermutations);

            // backtracking step.
            swap(nums[idx], nums[i]);
        }
    }

    /* Brute Force Approach: Generate All permutations of 'nums' and then find the next permutation.

    Time Complexity: O(n log(n)) for sorting + O(n*n!) time to generate all permutations + O(n!*n) for finding next permutation, where 'n' is the size of the nums vector.
    Space Complexity: O(n!*n) to store all permutations + O(n) is for vectors and set.
    */

    vector<int> nextPermutation_BruteForce(vector<int> &nums)
    {
        // make a copy of original vector.
        vector<int> temp = nums;

        // sort the 'temp' vector, because sorting will help us to skip duplicates.
        sort(temp.begin(), temp.end());

        // vector to store all prmutations.
        vector<vector<int>> allPermutations;

        // generating all permutations and store it in 'allPermutations' vector.
        generateAllPermutations(0, temp, allPermutations);

        // now after the above fundtion call ends, all permutation of nums are stored in 'allPermutations' vector.
        // sort the 'allPermutations' vector. So that all the permutation are sorted in lexicographical order.
        sort(allPermutations.begin(), allPermutations.end());

        // vector to store next permutations.
        vector<int> nextPer;

        // iterate through the 'allPermutations' vector and find the next permutation.
        int numsIdx = 0;
        for (int i = 0; i < allPermutations.size(); i++)
        {
            // boolean variable to find 'nums' in our 'allPermutations' vector.
            bool found = true;
            int k = 0;

            for (int j = 0; j < allPermutations[0].size(); j++)
            {

                if (allPermutations[i][j] != nums[k])
                {
                    found = false;
                    break;
                }

                k++;
            }

            if (found == true)
            {
                numsIdx = i;
                break;
            }
        }

        int nextPermutationIdx = (numsIdx + 1) % allPermutations.size();
        nextPer = allPermutations[nextPermutationIdx];
        return nextPer;
    }

    /* Better Approach: Using in-built C++ STL 'next_permutation()' method to find next permutation of nums.

    Time Complexity: The time complexity of next_permutation() is O(n), where 'n' is the size of the sequence or the number of elements in the array.
    Space Complexity: The space complexity of next_permutation() is O(1). The method performs in-place rearrangement of the elements of the sequence, modifying the original sequence directly.
    */
    void nextPermutation_BetterApproach(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }

    /* Optimal Approach:

    Algorithm:

    Step 1:- traverse from the back and find index element a[i] i.e., a[i] < a[i+1].
    Step 2:- if no such element is found it means the given array is sorted in descending order. In this case your next permutation is the reverse of the original array. So, reverse the array and return ans.
    Step 3:- If there is an element a[i] exists such that a[i] < a[i+1]. In this case, again traverse form back and find the element which if greater than a[i].
    Step 4:- swap(a[i], element which is greater than a[i]);
    Step 5:- in last step, reverse that array from index, index of(a[i]) to end.


    Time Complexity:- O(n), where 'n' is the size of the nums vector.
    Space Complexity:- O(1).
    */
    void nextPermutation_Optimal(vector<int> &nums)
    {
        // Step 1:- traverse from the back and find index element a[i] i.e., a[i] < a[i+1].
        int n = nums.size();
        int index1 = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index1 = i;
                break;
            }
        }

        // Step 2:- if no such element is found it means the given array is sorted in descending order. In this case your next permutation is the reverse of the original array. So, reverse the array and return ans.
        if (index1 < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {

            // Step 3:- If there is an element a[i] exists such that a[i] < a[i+1]. In this case, again traverse form back and find the element which if greater than a[i].
            int index2 = -1;
            for (int i = n - 1; i > index1; i--)
            {
                if (nums[i] > nums[index1])
                {
                    index2 = i;
                    break;
                }
            }

            // Step 4:- swap(a[i], element which is greater than a[i]);
            swap(nums[index1], nums[index2]);

            // Step 5:- in last step, reverse that array from index, index of(a[i]) to end.
            reverse(nums.begin() + index1 + 1, nums.end());
        }
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return;
        }

        // // Brute Force Approach.
        // vector<int> nextP = nextPermutation_BetterApproach(nums);
        // nums = nextP;

        // // Better Approach.
        // nextPermutation_BetterApproach(nums);

        // Optimal Approach.
        nextPermutation_Optimal(nums);
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3};

    // Solution.
    Solution obj;
    obj.nextPermutation(nums);

    for (int i : nums)
    {
        cout << i << " ";
    }

    return 0;
}