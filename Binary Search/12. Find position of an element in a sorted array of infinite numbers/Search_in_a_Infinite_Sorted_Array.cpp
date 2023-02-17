/*
Suppose you have a sorted array of infinite numbers, how would you search an element in the array?
Source: Amazon Interview Experience.
Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.
If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.
Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
->if it is greater than high index element then copy high index in low index and double the high index.
->if it is smaller, then apply binary search on high and low indices found.
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
    int binarySearch(vector<int> &arr, int l,int h, int key)
    {
        // size of array.
        int n = arr.size();

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

public:
    // function takes an infinite size array and a key to be
    //  searched and returns its position if found else -1.
    // We don't know size of arr[] and we can assume size to be
    // infinite in this function.
    // NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
    // THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
    int findPos(vector<int> &arr, int key)
    {
        int low = 0;
        int high = 1;

        while (key > arr[high])
        {
            low = high;
            high = high * 2;
        }

        return binarySearch(arr, low, high, key);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 14, 16, 18, 19, 20, 25, 28, 30, 35, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50};
    int target = 47;

    Solution S;
    int idx = S.findPos(arr, target);

    if (idx != -1)
    {
        cout << target << " is present at index " << idx << "." << endl;
    }
    else
    {
        cout << target << " not found." << endl;
    }
}