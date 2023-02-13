#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(n log (n))
// Space Complexity:- O(1)
int getMinDiff(int arr[], int n, int k)
{
    // sort the array.
    sort(arr, arr + n);

    // store initial answer.
    int smallestTower = arr[0];
    int largestTower = arr[n - 1];
    int diff = largestTower - smallestTower;

    // variable to store maximum and minimum height.
    int minHeight = 0;
    int maxHeight = 0;

    for (int i = 1; i < n; i++)
    {
        // edge case (given in question).
        if (arr[i] - k < 0)
        {
            continue;
        }

        // check if the towers form index 0 to n-2, after increment their height by k.
        // In towers ki height k se bhadane ke baad, largest tower ki height se badi ho rhi hai ya nhi.
        maxHeight = max(arr[i - 1] + k, largestTower - k);

        // In towers (0th - n-2th) ki height k se ghatane ke baad, smallest tower ki height se kam ho rhi hai ya nhi.
        minHeight = min(arr[i] - k, smallestTower + k);

        diff = min(diff, (maxHeight - minHeight));

    }
    return diff;
}

int main()
{
    int heights[] = {3, 9, 12, 16, 20};
    int n = 5;
    int k = 3;

    cout << getMinDiff(heights, n, k);
}