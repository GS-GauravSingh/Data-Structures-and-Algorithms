#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Appriach: Generate all subarrys of size 'k' and then find the subarray with maximum sum. */
    // Time Compelxity: O((N - K + 1) * K), where 'N' is the size of the subarray and 'K' si the window size.
    // Space Complexity: O(1).
    long maximumSumSubarray_BruteForce(vector<int> &arr, int K, int N)
    {

        // variable to store maximum sum of subarray of size 'k'.
        long maxSum = 0;

        // Now, there can be total (N - K + 1) subarrays of size 'k'.
        for (int i = 0; i < (N - K + 1); i++)
        {
            // variable to calculate sum of each subarray of sze 'k'.
            long sum = 0;

            // Traverse through the current window of size 'k'.
            for (int j = 0; j < K; j++)
            {
                sum += arr[i + j];
            }

            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }

    /* Optimized Appriach: Using Sliding Window Algorithm. */
    // Time Compelxity: O(n), where 'n' is the size of the subarray.
    // Space Complexity: O(1).
    long maximumSumSubarray_Opimized(vector<int> &arr, int K, int N)
    {
        // variable to store maximum sum of subarray of size 'k'.
        long maxSum = 0;

        // variable to calculate sum of each subarray of sze 'k'.
        long sum = 0;

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        int end = 0;

        // We have to run a loop while end < N.
        while (end < N)
        {
            // calculate the sum, because we have to calculate the sum anyway.
            sum += arr[end];

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // If 'windowSize' is less then 'k'.
            if (windowSize < K)
            {
                end++;
            }

            // when "windowSize == K", it means we hit the window size i.e., k.
            else if (windowSize == K)
            {
                // When "windowSize == k", it means now, our current window is of size 'k'. So, store the maximum sum in this window.
                maxSum = max(maxSum, sum);

                // And then shift this window ahead, but before shifting this window ahead, we have to remove the starting element of this window from our sum.
                sum = sum - arr[start];

                // Shift this window ahead.
                start++;
                end++;
            }
        }

        // return the maximum sum.
        return maxSum;
    }

public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        // Brute Force Approach.
        return maximumSumSubarray_BruteForce(Arr, K, N);

        // Optimized Approach.
        // return maximumSumSubarray_Opimized(Arr, K, N);
    }
};

int main(void)
{
    vector<int> arr{100, 200, 300, 400};
    int K = 2;

    // Solution.
    Solution obj;
    cout << "Maximum Sum: " << obj.maximumSumSubarray(K, arr, arr.size()) << ".";
    return 0;
}
