#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to find kth smallest element in unsorted array. */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our max heap does not contain more than k element.
    int kthSmallest(long long arr[], int n, int k)
    {
        // Max Heap.
        priority_queue<int> pq;

        // Traversing the array.
        for (int i = 0; i < n; i++)
        {
            // Step 1: push arr[i] into Max Heap.
            pq.push(arr[i]);

            // Step 2: Check the size of Max Heap.
            // If size of Max Heap is > K, in this case pop the top element of Max Heap.
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: After the above loop ends, our kth smallest element is present at the top of the Max Heap.
        return pq.top();
    }

public:
    /* Method to find sum of elements between k1 smallest and k2 smallest elements. */
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        // Step 1: Find the K1 smallest and k2 smallest element.
        int k1SmallestElement = kthSmallest(A, N, K1);
        int k2SmallestElement = kthSmallest(A, N, K2);

        // Step 2: calculat the sum.
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > k1SmallestElement && A[i] < k2SmallestElement)
            {
                sum += A[i];
            }
        }

        return sum;
    }
};

int main(void)
{
    long long A[] = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;
    int n = sizeof(A) / sizeof(long long);

    // Solution.
    Solution S;
    cout << S.sumBetweenTwoKth(A, n, k1, k2);
}