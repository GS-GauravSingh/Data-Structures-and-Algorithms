#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using Auxiliary array. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), space used bu auxiliary vector.
    void rotate_BruteForce(vector<int> &nums, int k)
    {
        // Size of nums vector.
        int n = nums.size();

        // Auxiliary Vector.
        vector<int> aux(n, 0);

        // Insert each element of nums vector into its correct index in aux vector.
        /*
        Dry-Run:

        Example: nums = [1,2,3,4,5,6,7], k = 3 and n = 7.

        Initially, aux[] vector is of size 'n', aux = {0, 0, 0, 0, 0, 0, 0};

        >> i = 0 and nums[i] = 1,
        correctIdx = (i + k) % n => (0+3) % 7 => 3 % 7 = 3.
        aux = {0, 0, 0, 1, 0, 0, 0};

        >> i = 1 and nums[i] = 2,
        correctIdx = (i + k) % n => (1+3) % 7 => 4 % 7 = 4.
        aux = {0, 0, 0, 1, 2, 0, 0};

        >> i = 2 and nums[i] = 3,
        correctIdx = (i + k) % n => (2+3) % 7 => 5 % 7 = 5.
        aux = {0, 0, 0, 1, 2, 3, 0};

        >> i = 3 and nums[i] = 4,
        correctIdx = (i + k) % n => (3+3) % 7 => 6 % 7 = 6.
        aux = {0, 0, 0, 1, 2, 3, 4};

        >> i = 4 and nums[i] = 5,
        correctIdx = (i + k) % n => (4+3) % 7 => 7 % 7 = 0.
        aux = {5, 0, 0, 1, 2, 3, 4};

        >> i = 5 and nums[i] = 6,
        correctIdx = (i + k) % n => (5+3) % 7 => 8 % 7 = 1.
        aux = {5, 6, 0, 1, 2, 3, 4};

        >> i = 6 and nums[i] = 7,
        correctIdx = (i + k) % n => (6+3) % 7 => 9 % 7 = 2.
        aux = {5, 6, 7, 1, 2, 3, 4};

        */
        for (int i = 0; i < nums.size(); i++)
        {
            int correctIdx = (i + k) % n;
            aux[correctIdx] = nums[i];
        }

        // Update original vector.
        nums = aux;
    }

    /* Optimized Approach: Using reverse(). */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    void rotate_Optimized(vector<int> &nums, int k)
    {
        // Size of nums vector.
        int n = nums.size();

        // Do, Mod of k with n, because it may possible that the value of k is > n.
        k = k % n;

        // Example: nums = [1,2,3,4,5,6,7], k = 3 and n = 7.
        // Step 1: Reverse entire nums array.
        // After reversing: nums = [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements.
        // Before reversing: nums = [7,6,5,4,3,2,1].
        // After reversing: nums = [5, 6, 7, 4,3,2,1]
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse last n-k elements.
        // Before reversing: nums = [5, 6, 7, 4,3,2,1].
        // After reversing: nums = [5, 6, 7, 1, 2, 3, 4]
        reverse(nums.begin() + k, nums.end());
    }

public:
    void rotate(vector<int> &nums, int k)
    {

        // Base Case
        if (k == 0)
        {
            return;
        }

        // // Brute Force Solution.
        // rotate_BruteForce(nums, k);

        // Optimized Solution.
        rotate_Optimized(nums, k);
    }

    /* Method to print vector. */
    void printVec(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Solution.
    Solution obj;

    cout << "Before: ";
    obj.printVec(nums);

    cout << "After: ";
    obj.rotate(nums, k);
    obj.printVec(nums);
    return 0;
}