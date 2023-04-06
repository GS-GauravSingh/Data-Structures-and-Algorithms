/*
Question :-
Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.
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
    int binarySearch(vector<char> &arr, char key)
    {
        // size of array.
        int n = arr.size();

        // low and high pointers.
        int low = 0;
        int high = n - 1;


        // we have to return the next character after x in alphabetical order.
        int ans;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if x is found, then simply return the index of x.
            if (arr[mid] == key)
            {
                return (mid + 1 < n) ? mid + 1 : mid;
            }
            else if (arr[mid] > key)
            {
                // arr[mid] < key.
                ans = mid;

                high = mid - 1;
            }
            else
            {

                low = mid + 1;
            }
        }

        // return ans;
        return ans;
    }
};

int main()
{
    vector<char> arr = {'a','c','f','g'};
    char key = 'b';

    Solution S;
    int idx = S.binarySearch(arr, key);

    cout << "Next Character after " << key << " is present at index " << idx << "." << endl;
}