#include <bits/stdc++.h>
using namespace std;

/* ------------------ Solution Class ---------------------------- */
class Solution
{
private:
public:

    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    void prefixSum(vector<int> &arr)
    {
        /*
        Prefix sum is a cumulative sum of array elements.
        Example :
        arr = {1,2,3,4}
        Prefix Sum array = {1, 1+2, 1+2+3, 1+2+3+4 } => {1, 3, 6, 10}
        */

        vector<int> prefixSumArr;

        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            prefixSumArr.push_back(sum);
        }

        // printing.
        cout<<"Original array => ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<"\nPrefix sum array => ";
        for (int i = 0; i < prefixSumArr.size(); i++)
        {
            cout<<prefixSumArr[i]<<" ";
        }
        
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Solution S;
    S.prefixSum(arr);
}