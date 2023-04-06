#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    int binarySearch(vector<int> &arr, int key)
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

public:
    /* Approach 1 :- Using sorting. */
    // Time Complexity :- O(n log(n)) + O(log(n)), O(n log(n)) for sorting and  O(log(n)) for binary search.
    // Space Complexity :- O(1)
    int searchOnReverseArray_Approach_1(vector<int> &arr, int key)
    {
        // sort the array.
        sort(arr.begin(), arr.end());

        // apply binary search on sorted array.
        int idx = binarySearch(arr, key);

        // retun index of key.
        return idx;
    }

    /* Approach 2 :- Using extra space */
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(n)
    int searchOnReverseArray_Approach_2(vector<int> &arr, int key)
    {

        // vector to store element in increasing order.
        vector<int> aux;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            aux.push_back(arr[i]);
        }

        // apply binary search on sorted array (aux).
        int idx = binarySearch(aux, key);

        // retun index of key.
        return idx;
    }

    /* Approach 3 :- Modify Binary Search. */
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(1)
    int searchOnReverseArray_Approach_3(vector<int> &arr, int key)
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
};

int main()
{
    vector<int> arr = {20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    int key = 20;

    Solution S;
    cout << "Index of " << key << " is " << S.searchOnReverseArray_Approach_3(arr, key) << endl;
}