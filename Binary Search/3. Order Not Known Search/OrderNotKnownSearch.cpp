/*
Question :-
Given an integer array, which is sorted in Increasing or decreasing order. Your task is to search for key in this array.
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
    int binarySearch_AscendingOrder(vector<int> &arr, int key)
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
    int binarySearch_DescendingOrder(vector<int> &arr, int key)
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
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(1)
    int search(vector<int> &arr, int target)
    {
        // size of array.
        int n = arr.size();

        // if size of arrays is 1.
        if (n == 1)
        {
            if (arr[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        // if arr[0] < arr[1], means array is sorted in ascending order.
        if (arr[0] < arr[1])
        {
            return binarySearch_AscendingOrder(arr, target);
        }
        else
        {
            // if arr[0] > arr[1], means array is sorted in descending order.
            return binarySearch_DescendingOrder(arr, target);
        }
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // ascending order
    vector<int> arr2 = {9, 8, 7, 6, 5, 4, 3, 2, 1}; // descending order
    int key = 7;

    Solution S;

    int idx1 = S.search(arr1, key);
    int idx2 = S.search(arr1, key);

    if (idx1 != -1)
    {
        cout << "Key Found at Index " << idx1 << "." << endl;
    }
    else
    {
        // key not found.
        cout << "Key not Found." << endl;
    }
}