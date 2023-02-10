#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Brute Force Approach:- Using nested loops. */
    // Time Complexity:- O(n^2), n is the size of vector.
    // Space Complexity:- O(1)
    vector<int> twoSum_BruteForce(vector<int> &nums, int target)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size()-1; i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                int sum = nums[i]+nums[j];
                if(sum == target){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                }
            }
            
        }
        return ans;
        
    }
    
    /* Optimized Approach:- Using unordered_map. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int value = target-nums[i];
            auto it = mpp.find(value);
            
            if(it != mpp.end()){
                ans.push_back(nums[i]);
                ans.push_back(it->first);
            }
            mpp[nums[i]] = i;
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
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> ans1 = s.twoSum_BruteForce(arr, target);
    vector<int> ans2 = s.twoSum(arr, target);
    s.print(ans1);
    s.print(ans2);
}