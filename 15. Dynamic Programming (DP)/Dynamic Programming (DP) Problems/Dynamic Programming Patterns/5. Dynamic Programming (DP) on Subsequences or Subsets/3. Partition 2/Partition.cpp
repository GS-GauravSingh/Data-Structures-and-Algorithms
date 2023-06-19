#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    // Time Complexity: O(n*k), where 'n' is the size of the vector 'arr'.
    // Space Complexity: O(k), size of 'prevRow' and 'currRow' array/vector.
    bool solveSpaceOptimized(vector<int> &arr)
    {
        // size of vector 'arr'/.
        int n = arr.size();

        // Find the total sum of elements.
        int tSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            tSum += arr[i];
        }

        // 'prevRow' vector.
        vector<bool> prevRow(tSum + 1, false);

        // Base Case.
        prevRow[0] = true;

        if (arr[0] <= tSum)
        {
            prevRow[arr[0]] = true;
        }

        for (int idx = 1; idx < n; idx++)
        {
            // 'currRow' vector.
            vector<bool> currRow(tSum + 1, false);
            currRow[0] = true;

            for (int target = 1; target <= tSum; target++)
            {
                // Picking the 'ith' element.
                int pick = false; /* Initialize this with false. */

                // We only pick the current element, if the value of current element is <= target.
                if (arr[idx] <= target)
                {
                    pick = prevRow[target - arr[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[target];

                // Store the answer of this subproblem and the return.
                currRow[target] = (pick || notPick);
            }

            // After the above loop end, our currRow will become prevRow.
            prevRow = currRow;
        }

        // prevRow will store the valid subset sum value from s1.
        // Traverse the prevRow, find s2 and find the minimum difference.
        int mini = INT_MAX;
        for (int i = 0; i < prevRow.size(); i++)
        {
            if (prevRow[i] == true)
            {
                int s1 = i;
                int s2 = tSum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }

public:
    /* Question: We are given an array ‘ARR’ with N positive integers. We need to partition the array into two subsets such that the absolute difference of the sum of elements of the subsets is minimum. We need to return only the minimum absolute difference of the sum of elements of the two partitions. */
    int minSubsetSumDifference(vector<int> &arr)
    {
        return solveSpaceOptimized(arr);
    }
};

int main(void)
{
    vector<int> arr{1, 2, 3, 4};
    int n = arr.size();

    // Solution.
    Solution S;
    cout << "Minimum Absolute Difference : " << S.minSubsetSumDifference(arr) << ".\n";
    return 0;
}