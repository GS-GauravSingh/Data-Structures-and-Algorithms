#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    // Time Complexity: O(N*logN)
    // Space Complexity: O(N)
    int longestIncreasingSubsequence(int arr[], int n)
    {

        vector<int> temp;
        temp.push_back(arr[0]);

        int len = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                // arr[i] > the last element of temp array

                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                // replacement step
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }

        return len;
    }
};

int main(void)
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;
    cout << "The length of the longest increasing subsequence is "
         << S.longestIncreasingSubsequence(arr, n);
    return 0;
}
