#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/

class Solution
{
public:
    /* Approach 1:- Using prefix and suffix array. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(n)
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        // prefix array.
        vector<int> prefix(n);
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= nums[i];
            prefix[i] = product;
        }

        // suffix array.
        vector<int> suffix(n);
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            product *= nums[i];
            suffix[i] = product;
        }
        // print(prefix);
        // print(suffix);

        // ans array.
        vector<int> ans(n);
        ans[0] = suffix[1];         // corner case.
        ans[n - 1] = prefix[n - 2]; // corner case.

        for (int i = 1; i < n - 1; i++)
        {
            // for rest of the cases.
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }

        return ans;
    }

    /* Approach 2 (Optimized):- without using extra space. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    vector<int> productExceptSelf_Optimized(vector<int> &nums)
    {

        // Step 1:- store the cumulative multiplication of vector in our ans vector (it's like a prefix array).
        int n = nums.size();
        vector<int> ans(n);
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= nums[i];
            ans[i] = product;
        }

        // Step 2:- traverse from right to left and update output array.

        product = 1;
        for (int i = n - 1; i > 0; i--)
        {
            ans[i] = ans[i - 1] * product;
            product *= nums[i];
        }
        ans[0] = product;

        return ans;
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
    vector<int> arr = {1, 2, 3, 4};

    Solution s;
    // vector<int> ans = s.productExceptSelf(arr);
    vector<int> ans = s.productExceptSelf_Optimized(arr);
    s.print(ans);
}