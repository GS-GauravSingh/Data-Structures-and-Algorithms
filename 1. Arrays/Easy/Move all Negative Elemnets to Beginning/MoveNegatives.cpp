/*
Question :-
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Note: Order of elements is not important here.

Examples :

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
*/

#include <bits/stdc++.h>
using namespace std;

/* --------------------- Solution Class --------------------------- */
class Solution
{
private:
public:
    /* Approach 1:- Using Extra space. TC:- O(n), SC:- O(n) */
    void moveNegative_Approach_1(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            // first push all negative elements.
            if (arr[i] < 0)
            {
                ans.push_back(arr[i]);
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            // then push all non-negative elements.
            if (arr[i] >= 0)
            {
                ans.push_back(arr[i]);
            }
        }

        // update answer
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = ans[i];
        }
    }
    /* Approach 2:- Using 2 pointer. TC:- O(n), SC:- O(1) */
    void moveNegative_Approach_2(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            if (arr[low] < 0)
            {
                low++;
            }
            else if (arr[high] > 0)
            {
                high--;
            }
            else
            {
                swap(arr[low], arr[high]);
            }
        }
    }
};

int main()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    Solution S;
    S.moveNegative_Approach_2(arr);

    for(auto i : arr)
    {
        cout<<i<<" ";
    }
}