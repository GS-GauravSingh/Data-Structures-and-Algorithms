#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach :- using extra space. */
    // Time Complexity:- O(n), n is size of vectors.
    // Space Complexity:- O(n)
    void moveZeroesBruteForce(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans;
        // first push non-zero elements.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // then push elements which has value 0.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // update original vector.
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }

    /* Optimized Approach :- using 2 pointer's. */
    // Time Complexity:- O(n), n is size of vector.
    // Space Complexity:- O(1)
    void moveZeroes(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 0 || nums.size() == 1)
        {
            return;
        }

        // 2 pointers
        int i = 0;
        int j = i + 1;

        while (j < nums.size())
        {
            if (nums[i] == 0 && nums[j] == 0)
            {
                // if both are 0, then increment j.
                j++;
            }
            else if (nums[i] == 0 && nums[j] != 0)
            {
                // if nums[i] == 0 && nums[j] != 0, then swap(nums[i], nums[j]).
                // and increment both i and j.
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                // if both are non-zero elements,
                // then increment both i and j.
                i++;
                j++;
            }
        }
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{
    vector<int> arr = {0, 1, 0, 3, 12};

    Solution s;
    // cout<<"Brute Force Approach Output:-\n";
    // s.moveZeroesBruteForce(arr);
    // s.print(arr);

    cout << "Optimized Approach Output:-\n";
    s.moveZeroes(arr);
    s.print(arr);
}