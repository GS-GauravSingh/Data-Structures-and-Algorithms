/*
Question :-
Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

Examples :
Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2
Explanation: Output is index of 40 in given array i.e. 2

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
Output: -1
Explanation: -1 is returned to indicate the element is not present
*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach :- Using Binary Serach */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(1)
    int search(vector<int> &arr, int target)
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

            // every element at ith index can be present at 3 indices, i.e., i, i+1, i-1.
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (mid - 1 >= 0 && arr[mid - 1] == target)
            {
                return mid - 1;
            }
            else if (mid + 1 < n && arr[mid + 1] == target)
            {
                return mid + 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 2;
            }
            else
            {
                // arr[mid] < key.
                low = mid + 2;
            }
        }

        // return -1 is key not found.
        return -1;
    }
};

int main()
{
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 40;

    Solution S;
    int idx = S.search(arr, target);

    if (idx != -1)
    {
        cout << target << " is present at index " << idx << "." << endl;
    }
    else
    {
        cout << target << " not found." << endl;
    }
}