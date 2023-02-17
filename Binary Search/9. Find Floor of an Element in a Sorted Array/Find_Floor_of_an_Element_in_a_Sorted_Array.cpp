/*
Question :-
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.

Example:

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in arr[] smaller than 5.
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
    int binarySearch(vector<int> &arr, int x)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // if x is present in the array, then simply return the index of x.
        // But if it is not present, we have to return the value which is smaller that or equal to x.

        // variable to store value which is smaller that or equal to x.
        int ans = -1;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if x is found, then simply return the index of x.
            if (arr[mid] == x)
            {
                return mid;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < key.
                // But if it is not present, we have to return the value which is smaller that or equal to x.

                // store the index of  smaller value.
                ans = mid;
                low = mid + 1;
            }
        }

        // return ans;
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 8, 10, 12, 19};
    int x = 5;

    Solution S;
    int idx = S.binarySearch(arr, x);

    cout << "Floor value of " << x << " is present at index " << idx << "." << endl;
}