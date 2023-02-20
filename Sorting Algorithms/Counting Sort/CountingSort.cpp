#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    void countingSort(vector<int> &arr, int n)
    {
        // Step 1 :- find the maximum element in the array.
        int maxx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxx = max(maxx, arr[i]);
        }

        // Step 2 :- Declare an array of size same as the maximum element + 1 and Initializes all element of auxiliary array with zero.
        vector<int> aux(maxx + 1, 0);

        // Step 3 :- Store the frequency of each element in auxiliary array.
        for (int i = 0; i < n; i++)
        {
            int element = arr[i];
            aux[element]++;
        }

        // Step 4 :- In auxiliary, treat indices as element and element's as the frequency of that element(i th index) and update the original array.
        int j = 0;
        for (int i = 0; i <= maxx + 1; i++)
        {
            int element = i;
            int &freq = aux[i];

            if (freq > 0)
            {
                arr[j] = element;
                freq--;
                j++;
            }
        }
    }

    /* Method to print 1D vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
    }
};

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Solution S;
    S.countingSort(arr, arr.size());
    S.print(arr);
}