/*
Given a sorted array, find the element in the array which has minimum difference with the given number.
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
    int binarySearch(vector<int> &arr, int key)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        int diff = INT_MAX;
        int ans = 0;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                return mid;
            }
            else
            {
                if (abs(arr[mid] - key) < diff)
                {
                    diff = abs(arr[mid] - key);
                    ans = arr[mid];
                }
            }

            if (arr[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 3, 8, 10, 15};
    int key = 12;

    Solution S;
    cout << S.binarySearch(arr, key);
}