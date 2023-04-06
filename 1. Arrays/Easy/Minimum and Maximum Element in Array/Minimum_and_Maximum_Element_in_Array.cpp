#include <bits/stdc++.h>
using namespace std;

/* ------------------- Solution Class ---------------------- */
class Solution
{
private:
public:
    /* Function to find minimum Element of the Array. Tc:- O(n), SC:- O(1).  */
    int findMinimum(vector<int> &arr)
    {
        int minn = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            minn = min(arr[i], minn);
        }
        return minn;
    }

    /* Function to find maximum Element of the Array. Tc:- O(n), SC:- O(1).  */
    int findMaximum(vector<int> &arr)
    {
        int maxx = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            maxx = max(arr[i], maxx);
        }
        return maxx;
    }
};

int main()
{
    Solution S;
    vector<int> arr = {10, 20, 3, 2, 6, 59, 87, 1};

    cout << "Maximum Element is : " << S.findMaximum(arr) << endl;
    cout << "Minimum Element is : " << S.findMinimum(arr) << endl;
}