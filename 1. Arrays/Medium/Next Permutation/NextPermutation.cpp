#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Method to print 2D vector. */
    void print2DVec(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    /* Method to print vector */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Approach 1:- you can use in-built function named as next_permutation(), to return the next permutation.
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    void nextPermutation_Approach1(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }

    // Approach 2:- generate all possible permutations and return the next permutation.
    // Time Complexity:- O(n!*n)
    // Space Complexity:- O(n!*n)
    void generateAllPermutations(int idx, vector<int> &nums, vector<vector<int>> &allPermutations)
    {
        // Base Case
        if (idx >= nums.size())
        {
            allPermutations.push_back(nums);
            return;
        }

        // Recursive Case
        for (int i = idx; i < nums.size(); i++)
        {
            // place every element to first position one by one.
            swap(nums[i], nums[idx]);

            // recursive call.
            generateAllPermutations(idx + 1, nums, allPermutations);

            // backtracking step.
            swap(nums[i], nums[idx]);
        }
    }

    void nextPermutation_Approach2(vector<int> &nums)
    {
        // before generating all permutation, remember we need to return next_permutation in lexicographical order.
        // So, sort the given vector before generating all permutations.
        sort(nums.begin(), nums.end());

        // generating all permutations and store it in a vector.
        vector<vector<int>> allPermutations;
        generateAllPermutations(0, nums, allPermutations);

        // now at this point all permutation are stored in allPermutation vector.

        // iterate through the vector and find the next permutation.
        bool nextPermutationIdx = -1;
        for (int i = 0; i < allPermutations.size(); i++)
        {
            bool found = false;
            int k = 0;
            for (int j = 0; j < allPermutations[0].size(); j++)
            {
                if (nums[j] == nums[k])
                {
                    found = true;
                    k++;
                }
                else
                {
                    found = false;
                }
            }

            if (found == true)
            {
                nextPermutationIdx = (i + 1) % nums.size();
                break;
            }
        }

        // copying next permutation to original vector.
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = allPermutations[nextPermutationIdx][j++];
        }

        print2DVec(allPermutations);
    }

    /*
    Approach 3:- Algorithm,

    Step 1:- traverse from the back and find index element a[i] i.e., a[i] < a[i+1].
    Step 2:- if no such element is found it means the given array is sorted in descending order. In this case your next permutation is the reverse of the original array. So, reverse the array and return ans.
    Step 3:- If there is an element a[i] exists such that a[i] < a[i+1]. In this case, again traverse form back and find the element which if greater than a[i].
    Step 4:- swap(a[i], element which is greater than a[i]);
    Step 5:- in last step, reverse that array from index, index of(a[i]) to end.


    Time Complexity:- O(n)
    Space Complexity:- O(1)
    */
    // Approach 3 :- Code.
    void nextPermutation_Approach3(vector<int> &nums)
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
};
/*-------------------------- Solution Class Ends Here. ------------------------- */
int main()
{
    vector<int> arr = {2,3,1};

    Solution s;
    s.nextPermutation_Approach2(arr);

    s.printVec(arr);
}