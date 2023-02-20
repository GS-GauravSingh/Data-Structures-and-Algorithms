#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Bubble sort is a simplest sorting algorithm, that works by repeatedly swapping the adjacent elements if they are in wrong order. In each iteration of bubble sort, we place the largest element to the end. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    void bubbleSort(vector<int> &arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            // Repeatedly swapping the adjacent elements if they are in wrong order.
            // In each iteration of bubble sort, we place the largest element in its correct position. So, there is no need to check that elemenmt again.
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    print(arr);
                    cout << "Swapping (" << arr[j] << "," << arr[j + 1] << ")" << endl;
                    swap(arr[j], arr[j + 1]);
                    // print(arr);
                }
            }
            cout << arr[n - i - 1] << " Place at it's correct position\n";
        }
    }

    // Time Complexity :- wors case O(n^2), best case O(n).
    // Space Complexity :- O(1)
    void bubbleSortAdaptive(vector<int> &arr, int n)
    {
        // flag to chek if input is sorted ot not.
        bool isSorted = true;

        for (int i = 0; i < n; i++)
        {
            // Repeatedly swapping the adjacent elements if they are in wrong order.
            // In each iteration of bubble sort, we place the largest element in its correct position. So, there is no need to check that elemenmt again.
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // if the programs does not enter into this if block, it means the array is sorted.
                    // and in linear time, it can identify that the array is sorted.
                    // That's why, this variation of bubble sort is adaptive.
                    isSorted = false;
                    swap(arr[j], arr[j + 1]);
                }
            }

            if (isSorted == true)
            {
                // it means, array is sorted.
                cout << "Input is Sorted.";
                break;
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
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {4, 3, 2, 1};

    Solution S;
    S.bubbleSort(arr, arr.size());
    S.bubbleSortAdaptive(arr, arr.size());
    // S.print(arr);
}