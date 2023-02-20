#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    void insertionSort(vector<int> &arr, int n)
    {
        for (int i = 1; i < n; i++)
        {
            int current = arr[i];

            int prev = i - 1;
            while (prev >= 0 && arr[prev] > current)
            {
                // shift elements one step ahead.
                arr[prev + 1] = arr[prev];

                // previous sholud go one step back.
                prev--;
            }

            // after the above loop end, the prev pointer will point, 1 index back, to the correct position of the current element.
            // means if the current element has correct position index is 2. SO, perv will points to 1. 
            // So, at index prev+1 place current.
            arr[prev + 1] = current;
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
    S.insertionSort(arr, arr.size());
    S.print(arr);
}