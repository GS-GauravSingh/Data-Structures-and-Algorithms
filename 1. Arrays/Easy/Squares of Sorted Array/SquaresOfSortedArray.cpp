#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach. */
    // Time Complexity:- O(n log(n)), n is the size of vector.
    // Space Complexity:- O(1)
    vector<int> sortedSquares_BruteForce(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    /* Optimized Approach. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    vector<int> sortedSquares(vector<int> nums)
    {
        // Step 1:- Since we need to put squares in result array, we can consider that all numbers are positive.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
            }
        }

        // Step 2:- use 2 pointer apporach.
        int n = nums.size();
        int start = 0, end = nums.size() - 1;

        vector<int> ans(n);
        int k = n-1;

        while (k >= 0)
        {
            if(nums[start] > nums[end]){
                ans[k--] = nums[start]*nums[start];
                start++;
            }
            else{
                ans[k--] = nums[end]*nums[end];
                end--;

            }
        }
        
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
    vector<int> arr = {-4, -1, 0, 3, 10};

    Solution s;
    // vector<int> ans1 = s.sortedSquares_BruteForce(arr);
    vector<int> ans2 = s.sortedSquares(arr);
    // s.print(ans1);
    s.print(ans2);
}