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
        Suffix sum is a cumulative sum of array elements in reverse order.
        Example :
        arr = {1,2,3,4}
        Suffix Sum array = {4+3+2+1, 4+3+2, 4+3, 4 } => {1, 3, 6, 10}
        */

        vector<int> suffixSumArr(arr.size(), 0);
        int k = arr.size() - 1;

        int sum = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            sum += arr[i];
            suffixSumArr[k--] = sum;
        }

        // printing.
        cout<<"Original array => ";
        for (int i = 0; i < arr.size(); i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<"\nSuffix sum array => ";
        for (int i = 0; i < suffixSumArr.size(); i++)
        {
            cout<<suffixSumArr[i]<<" ";
        }
        
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Solution S;
    S.prefixSum(arr);
}