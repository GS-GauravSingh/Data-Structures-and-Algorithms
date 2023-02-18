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
    /* Binary Search Algorithm for arrays which is sorted in ascending order. */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int binarySearch_AscendingOrder(vector<int> &arr, int l, int h, int key)
    {
        // low and high pointers.
        int low = l;
        int high = h;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                return mid;
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
        return -1;
    }

    /*  Binary Search Algorithm for array which is sorted in decreasing order. */
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(1)
    int binarySearch_DescendingOrder(vector<int> &arr, int l, int h, int key)
    {

        // low and high pointers.
        int low = l;
        int high = h;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                // since the array is sorted in decreasing order, and if the middle element is greater than key.
                // So, smaller element are present at right half.
                low = mid + 1;
            }
            else
            {
                // arr[mid] < key.

                // since the array is sorted in decreasing order, and if the middle element is less than key.
                // So, larger element are present at left half.
                high = mid - 1;
            }
        }

        // return -1 is key not found.
        return -1;
    }

public:
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int findElement(vector<int> &arr, int target)
    {

        // Step 1:- Find the index of maximum element.

        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        int maxElementIdx = 0;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // maximum element.
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                maxElementIdx = mid;
                break;
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

        /*
        At this point, We got the index of maximum element in Biotonic array.

        As, we know that this is a Biotonic Array. So, from the maximum element, we can divide the array
        into to half,

        1. from index 0 to index of maximum element
        2. from index of maximum element + 1 to end of the array.

        and if you notice, first half is sorted in increasing order and second half is sorted in decreasing order
        Now, simply apply Binary search.
        */

        int idx1 = binarySearch_AscendingOrder(arr, 0, maxElementIdx, target);
        if (idx1 != -1)
        {
            return idx1;
        }

        int idx2 = binarySearch_DescendingOrder(arr, maxElementIdx + 1, arr.size() - 1, target);
        return idx2;
    }
};

int main()
{
    vector<int> arr = {1, 3, 8, 9, 10, 11, 2};
    int target = 11;

    Solution S;

    cout << target << " is present at index " << S.findElement(arr, target);
}