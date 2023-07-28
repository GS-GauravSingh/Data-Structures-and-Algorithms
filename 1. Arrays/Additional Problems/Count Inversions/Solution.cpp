#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Let’s understand the Question more deeply. We are required to give the total number of inversions and the inversions are: For i & j < size of an array if i < j then you have to find pair (a[i], a[j]) such that a[i] > a[j].

    For example, for the given array: [5,3,2,1,4], (5, 3) will be a valid pair as 5 > 3 and index 0 < index 1. But (1, 4) cannot be valid pair. */

    /* Brute Force Approach:  The naive approach is pretty straightforward. We will use nested loops to solve this problem. We know index i must be smaller than index j. So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition a[i] > a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i]. */

    // Time Complexity: O(N^2), where 'N' is the size of the array 'arr'.
    // Space Complexity: O(1).
    long long inversionCount_BruteForce(long long arr[], long long N)
    {
        // variavle to store inversion count.
        int inv_cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (arr[i] > arr[j])
                {
                    inv_cnt++;
                }
            }
        }

        return inv_cnt;
    }

    /* Optimized Approach: Using Merge Sort. */

    /* Merge method of Merge Sort Algorithm. */
    // Time Complexity: O(n), where 'n' is the size of the array.
    // Space Complexity: O(n), space used by auxiliary vector.
    long long merge(long long arr[], long long low, long long high)
    {
        // Calculating Mid.
        long long mid = low + (high - low) / 2;

        // vector to store elements in sorted order.
        vector<long long> temp;

        // variable to store inversion count.
        long long inv_cnt = 0;

        // Our left half is from [low, mid] and right half is from [mid + 1, high].
        int left = low;
        int right = mid + 1;

        // In 'temp' vector, compare and Store the elements in sorted order.
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                // store element.
                temp.push_back(arr[left]);

                // update left pointer.
                left++;
            }
            else
            {
                // arr[left] > arr[right].

                // store element.
                temp.push_back(arr[right]);

                // store inversion count.
                inv_cnt += (mid - left + 1);

                // update right pointer.
                right++;
            }
        }

        // Process remaining elements of left half if exists.
        while (left <= mid)
        {
            // store element.
            temp.push_back(arr[left]);

            // update left pointer.
            left++;
        }

        // Process remaining elements of right half if exists.
        while (right <= high)
        {
            // store element.
            temp.push_back(arr[right]);

            // update right pointer.
            right++;
        }

        // Copy back all the element from temp array to original array.
        // 'temp' array contains the elements in sorted order.

        int k = 0; // Pointer to traverse the 'temp' vector.

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[k++];
        }

        // return inversion count.
        return inv_cnt;
    }

    /* Merge Sort Algorithm. */
    // Time Complexity: O(n*log(n)), where 'n' is the size of the array.
    // Space Complexity: O(n) + O(log (n)), space used by auxiliary vector in merge method and recursive stack space.
    long long mergeSort(long long arr[], long long low, long long high)
    {
        // variable to store inversion count.
        long long inv_cnt = 0;

        // Base case
        if (low >= high)
        {
            return inv_cnt;
        }

        // Recursive Case.

        // Calculating Mid.
        long long mid = low + (high - low) / 2;

        // Left Half.
        inv_cnt += mergeSort(arr, low, mid);

        // Right Half.
        inv_cnt += mergeSort(arr, mid + 1, high);

        // Merge.
        inv_cnt += merge(arr, low, high);

        // return inversion count.
        return inv_cnt;
    }

    long long inversionCount_Optimized(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N - 1);
    }

public:
    /* Question: Given an array of integers. Find the Inversion Count in the array.

    What is an Inversion Count?
    For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
    Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

    Example 1:
    Input: N = 5, arr[] = {2, 4, 1, 3, 5}
    Output: 3
    Explanation: The sequence 2, 4, 1, 3, 5
    has three inversions (2, 1), (4, 1), (4, 3).
    */
    long long int inversionCount(long long arr[], long long N)
    {
        // // Brute Force Approach.
        // return inversionCount_BruteForce(arr, N);

        // Optimized Approach.
        return inversionCount_Optimized(arr, N);
    }
};

int main(void)
{
    long long arr[] = {2, 4, 1, 3, 5};
    long long n = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;
    cout << "Inversion Count: " << S.inversionCount(arr, n) << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}