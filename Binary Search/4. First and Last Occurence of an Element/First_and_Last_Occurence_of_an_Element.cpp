#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Binary Search Algorithm for find first occurence of an element. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    int binarySearch_firstOccurence(vector<int> &arr, int target)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store first occurence of traget.
        int firstOcc = -1;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                // if target is found, store it's index because it may possible that this is the first occurence of traget.
                firstOcc = mid;

                // first occurence is always present at the left half of array..
                high = mid - 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < target.
                low = mid + 1;
            }
        }

        // return first occurence.
        return firstOcc;
    }

    /* Binary Search Algorithm for find last occurence of an element. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    int binarySearch_lastOccurence(vector<int> &arr, int target)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store last occurence of traget.
        int lastOcc = -1;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                // if target is found, store it's index because it may possible that this is the last occurence of traget.
                lastOcc = mid;

                // if this is not the last occurence of traget, then last occurence is always present at the right half of array.
                low = mid + 1;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < target.
                low = mid + 1;
            }
        }

        // return last occurence.
        return lastOcc;
    }
};

int main()
{
    vector<int> arr = {2, 4, 10, 10, 10, 18, 20};
    int target = 10;

    Solution S;

    cout << "First Occurence of " << target << " is present at index " << S.binarySearch_firstOccurence(arr, target) << endl;
    cout << "Last Occurence of " << target << " is present at index " << S.binarySearch_lastOccurence(arr, target) << endl;
}