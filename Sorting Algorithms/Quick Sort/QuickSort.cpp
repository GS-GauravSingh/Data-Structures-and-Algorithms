#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Partition Method. */
    int partition(vector<int> &arr, int start, int end)
    {
        // chossing the ending element as pivot.
        int pivot = arr[end];

        // now, we have to place pivot in such a way that, all element which is less than pivot are present at the left of the pivot, and all element which is greater than pivot are present at the right of the pivot.
        int low = start - 1;
        for (int i = start; i <= end; i++)
        {
            if (arr[i] < pivot)
            {
                low++;
                swap(arr[i], arr[low]);
            }
        }

        swap(arr[low + 1], arr[end]);
        return low + 1;
    }

public:
    // Time Complexity :- average case O(n log(n)), worst case O(n^2).
    // Space Complexity :- O(log (n)), recursive stack space.
    void quickSort(vector<int> &arr, int start, int end)
    {
        // Base Case
        if (start >= end)
        {
            return;
        }

        // Recursive Case.
        int pivotIdx = partition(arr, start, end);

        quickSort(arr, start, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
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
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};

    Solution S;
    S.quickSort(arr, 0, arr.size() - 1);
    S.print(arr);
}