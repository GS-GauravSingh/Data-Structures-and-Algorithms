#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Merge Method. */
    void merge(vector<int> &arr, int left, int right)
    {
        // size of array.
        int n = arr.size();

        // vector, used to merge both array in sorted manner.
        vector<int> temp;

        // left half => [left, mid].
        int leftHalfStart = left;
        int mid = (left + right) / 2;

        // right half => [mid + 1, right].
        int rightHalfStart = mid + 1;

        // merge both halfs.
        while ((leftHalfStart <= mid) && (rightHalfStart <= right))
        {
            if (arr[leftHalfStart] <= arr[rightHalfStart])
            {
                temp.push_back(arr[leftHalfStart]);

                // move pointer.
                leftHalfStart++;
            }
            else
            {
                // arr[leftHalfStart] > arr[rightHalfStart]
                temp.push_back(arr[rightHalfStart]);

                // move pointer.
                rightHalfStart++;

            }
        }

        // remaining element in left half.
        while (leftHalfStart <= mid)
        {
            temp.push_back(arr[leftHalfStart++]);
        }
        // remaining element in right half.
        while (rightHalfStart <= right)
        {
            temp.push_back(arr[rightHalfStart++]);
        }

        // copy back all the element from temp array to original array.
        // temp array contains the elements in sorted order.
        int k = 0;
        for (int i = left; i <= right; i++)
        {
            arr[i] = temp[k++];
        }

    }

public:
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(n) + O(log (n)), auxiliary vector and recursive stack space.
    void mergeSort(vector<int> &arr, int start, int end)
    {
        // Base Case
        if (start >= end)
        {
            return;
        }

        // Recursive Case.

        // divide the array from mid and sort the left and right half recursively.
        int mid = start + (end - start) / 2;

        // left half is from [start, mid].
        mergeSort(arr, start, mid);

        // right half is from [mid + 1, end].
        mergeSort(arr, mid + 1, end);

        // merge both left and right half.
        merge(arr, start, end);
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
    S.mergeSort(arr, 0, arr.size() - 1);
    S.print(arr);
}