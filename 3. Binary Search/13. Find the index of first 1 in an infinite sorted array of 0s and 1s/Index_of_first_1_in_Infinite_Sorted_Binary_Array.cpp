/*
Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

Example:

Input : arr[] = {0, 0, 1, 1, 1, 1}
Output : 2
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int binarySearch(vector<int> &arr, int l, int h, int key)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = l;
        int high = h;

        // variable to store first occurence of 1.
        int idx = 0;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                idx = mid;
                high = mid - 1;
            }
            else if (arr[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        // return -1 is key not found.
        return idx;
    }

public:
    int findHighIdx(vector<int> &arr)
    {
        int low = 0;
        int high = 1;

        while (arr[high] == 0)
        {
            low = high;
            high = high * 2;
        }

        return binarySearch(arr, low, high, 1);
    }
};

int main()
{
    vector<int> arr = {0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1};

    Solution S;

    cout << "First Occurence of 1 is present at index " << S.findHighIdx(arr);
}