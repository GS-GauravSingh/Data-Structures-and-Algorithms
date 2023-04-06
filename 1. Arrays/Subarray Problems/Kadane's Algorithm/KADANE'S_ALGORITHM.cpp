#include <bits/stdc++.h>
using namespace std;

/* Kadane's Algorithm is used to find the maximum subarray sum in linear time complexity and constant space complexity. */
// Time Complexity :- o(n)
// Space Complexity :- o(1)

// Note:-  if a testcase contains all negative elements then this code is not work as expected. Use the below code this will work on all the testcases.
int KadanesAlgorithm_01(vector<int> &arr)
{
    // size of vector.
    int n = arr.size();

    int maxSum = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum < 0)
        {
            currSum = 0;
        }

        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int KadanesAlgorithm_02(vector<int> &arr)
{
    // size of vector.
    int n = arr.size();

    int maxSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currSum += arr[i];

        if (currSum < arr[i])
        {
            currSum = arr[i];
        }

        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Maximum Subarray sum (Kadane's Algo.) = " << KadanesAlgorithm_01(arr) << endl;
    cout << "Maximum Subarray sum (Kadane's Algo (variation)) = " << KadanesAlgorithm_02(arr) << endl;
}