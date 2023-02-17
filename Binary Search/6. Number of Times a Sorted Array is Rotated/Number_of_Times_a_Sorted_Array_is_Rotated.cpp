/*
Question :-
Given an array arr[] of size N having distinct numbers sorted in increasing order and the array has been right rotated (i.e, the last element will be cyclically shifted to the starting position of the array) k number of times, the task is to find the value of k.

Examples:
Input: arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation: Initial array must be {2, 3, 6, 12, 15, 18}.
We get the given array after rotating the initial array twice.

Input: arr[] = {7, 9, 11, 12, 5}
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Modified Binary Search Algorithm */
    /* Approach, value of k = index of minimum element. */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int binarySearch(vector<int> &arr)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store rotation count.
        int k = 0;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // element just before mid.
            int prev = (mid - 1 + n) % n;

            // element just after mid.
            int next = (mid + 1) % n;

            // minimum element, arr[mid - 1] > arr[mid] < arr[mid + 1]
            if (arr[mid] <= arr[prev] && arr[mid] <= arr[mid ])
            {
                return mid;
            }

            else if (arr[0] <= arr[mid])
            {
                low = mid + 1;
            }
            else if(arr[mid] <= arr[high])
            {
                // arr[low] >= arr[mid]
                high = mid - 1;
            }
        }

        return k;
    }

public:
    /* Using Modified Binary Search. See the code above. */
    int countRotations(vector<int> &arr)
    {
        return binarySearch(arr);
    }
};

int main()
{
    vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};

    Solution S;
    cout << "Array is Rotated by " << S.countRotations(arr) << "." << endl;
}
