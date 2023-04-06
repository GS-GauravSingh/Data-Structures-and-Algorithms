/*
Problem statement:
Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

Example:

Input:
1 4 8 3 2

Output:
8
*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int maxElement(vector<int> &arr)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // maximum element.
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return arr[mid];
            }
            else if (arr[mid] < arr[mid - 1])
            {
                high = mid - 1;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {1, 3, 8, 12, 4, 2};

    Solution S;

    cout << "Maximum Element is " << S.maxElement(arr);
}