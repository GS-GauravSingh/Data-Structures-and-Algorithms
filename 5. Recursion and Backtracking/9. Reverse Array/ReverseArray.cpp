#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- Using 2 pointers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    void reverseIterative(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {
            swap(arr[start++], arr[end--]);
        }
    }

    /* Approach 1 recursive code. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    void reverseRecursive(vector<int> &arr, int start, int end)
    {
        // Base Condition.
        if (start >= end)
        {
            return;
        }

        // Recursive Case.
        swap(arr[start], arr[end]);
        reverseRecursive(arr, start + 1, end - 1);
    }

    /* Method to print 1D vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Solution S;
    S.reverseIterative(arr);
    S.print(arr);
    S.reverseRecursive(arr, 0, arr.size() - 1);
    S.print(arr);
}