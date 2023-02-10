#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach :- using extra space. */
    // Time Complexity:- O(n), n is size of vectors.
    // Space Complexity:- O(n)
    void moveZerosBruteForce(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans;
        // first push elements which has value 0.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans.push_back(nums[i]);
            }
        }

        // then push non-zero elements.
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
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

    /* Optimized Approach. */
    // Time Complexity:- O(n), n is size of vector.
    // Space Complexity:- O(1)
    void moveZeros(vector<int> &arr)
    {
        int n = arr.size();
        int i = n - 1;
        int j = i - 1;

        while (j >= 0)
        {
            // if both are 0's, decrement j.
            if (arr[i] == 0 && arr[j] == 0)
            {
                j--;
            }
            else if (arr[i] == 0 && arr[j] != 0)
            {
                // if arr[i] == 0 and arr[j] != 0, than swap(arr[i], arr[j]) and decrement both.
                swap(arr[j], arr[i]);
                i--;
                j--;
            }
            else
            {
                // if both are non-zeros elements, than decrement both.
                i--;
                j--;
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
    // s.moveZerosBruteForce(arr);
    // s.print(arr);

    cout << "Optimized Approach Output:-\n";
    s.moveZeros(arr);
    s.print(arr);
}