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

            // left half
            // if arr[low] <= arr[mid], it means, left half is sorted.
            if (arr[low] <= arr[mid])
            {
                // arr[low] to arr[mid] is left half and if this conditions is true, it means left half is sorted.
                // and when arr[mid + 1] < arr[mid], it means all element from arr[0] to arr[mid] are rotated.
                if (arr[mid + 1] < arr[mid])
                {
                    k = mid + 1; // +1 is for 1-based indexing.
                    break;
                }
                else
                {
                    // else if arr[mid + 1] > arr[mid], move to right half.
                    // Basically, we are looking for a breakpoint in left half, where arr[mid + 1] < arr[mid].
                    low = mid + 1;
                }
            }
            // right half.
            // if arr[mid] <= arr[high], it means, right half is sorted.
            else if (arr[mid] <= arr[high])
            {
                // arr[mid] to arr[high] is right half and if this conditions is true, it means right half is sorted.
                // and if arr[mid] < arr[mid - 1], it means all element from arr[0] to arr[mid - 1] are rotated.
                if (arr[mid] < arr[mid - 1])
                {
                    k = mid;
                    break;
                }
                else
                {
                    // else if arr[mid] > arr[mid - 1], move to left half.
                    high = mid - 1;
                }
            }
        }

        // if k == n, it means array is sorted in increasing order.
        if(k == n)
        {
            return 0;
        }

        return k;
    }

public:
    /* Using Modified Binary Search. See the code above. */
    int countRotations(vector<int> &arr)
    {
        return binarySearch(arr);
    }

    /* Another apporach is, You can find the index of minimum element. */
};

int main()
{
    vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};

    Solution S;
    cout << "Array is Rotated by " << S.countRotations(arr) << "." << endl;
}
