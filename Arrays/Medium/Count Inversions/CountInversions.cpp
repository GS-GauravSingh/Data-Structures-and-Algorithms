/*
Question :-
Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0

Explanation: we have a sorted array and the sorted array
has 0 inversions as for i < j you will never find a pair
such that A[j] < A[i]. More clear example: 2 has index 1
and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
inversion.

Example 2:
Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7

Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and
(1,4) as both are not satisfy our condition.

*/
#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- Using nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int countInv_Approach_1(vector<int> arr)
    {
        // size of array.
        int n = arr.size();

        // variable to store answer.
        int cntInv = 0;

        // traversing through the array and find answer.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // condition for inversison, a[i] > a[j].
                if (arr[i] > arr[j])
                {
                    cntInv++;
                }
            }
        }

        return cntInv;
    }

    /* Approach 2 :- Using Merge Sort */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)

    /* Merge Method. */
    int merge(vector<int> &arr, int left, int right)
    {
        // size of array.
        int n = arr.size();

        // variable to store count of inversions.
        int cntInv = 0;

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

                cntInv += (mid - leftHalfStart) + 1;
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

        // return inversion count.
        return cntInv;
    }

    /* Merge Sort Method. */
    int mergeSort(vector<int> &arr, int left, int right)
    {
        // variable to store count of inversions.
        int cntInv = 0;

        if (left < right)
        {
            // mid
            int mid = (left + right) / 2;

            // left half [left, mid].
            cntInv += mergeSort(arr, left, mid);

            // right half [mid + 1, right].
            cntInv += mergeSort(arr, mid + 1, right);

            // merge 2 sorted arrays.
            cntInv += merge(arr, left, right);
        }

        // return inversion count.
        return cntInv;
    }

    int countInv_Approach_2(vector<int> &arr)
    {
        // size of array.
        int n = arr.size();

        // variable to store answer.
        int cntInv = 0;
        // for (int i : arr)
        // {
        //     cout << i << " ";
        // }

        cntInv = mergeSort(arr, 0, n - 1);

        return cntInv;
    }
};

int main()
{
    Solution S;

    vector<int> arr = {5, 3, 2, 1, 4};
    // cout << "Total number of Inversion's is = " << S.countInv_Approach_1(arr) << endl;
    cout << "Total number of Inversion's is = " << S.countInv_Approach_2(arr) << endl;

}