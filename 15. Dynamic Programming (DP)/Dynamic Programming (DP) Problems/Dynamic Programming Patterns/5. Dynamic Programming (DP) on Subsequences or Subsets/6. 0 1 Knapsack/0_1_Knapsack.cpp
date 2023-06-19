#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Solution to find and return the maximum value that a theif can generate by steling items. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int maxWeight, vector<int> &weight, vector<int> &value)
    {
        // Base Cases.

        // When maxWeight = 0, it means, the thief's bag capacity is full now and they cannot rob more items.
        if (maxWeight == 0)
        {
            // So simply return 0 from here.
            return 0;
        }

        // For element at index 0, the thief has again 2 choices, first is to rob this or the second is to ignore this.
        // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag. Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element.
        if (idx == 0)
        {
            // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag.
            if (weight[0] <= maxWeight)
            {
                // return the cost of this element.
                return value[0];
            }

            // Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element. So return 0.
            return 0;
        }

        // Recursive Case.

        // The thief has 2 choises, first is to rob this or the second is to ignore this.

        // Picking the 'ith' element.
        int pick = 0;

        // Note: we only pick this element, if the weight of this element is (<=) the capacity of thief's bag. Otherwise we cannot pick this.
        if (weight[idx] <= maxWeight)
        {
            // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
            pick = value[idx] + solveRecursive(idx - 1, maxWeight - weight[idx], weight, value);
        }

        // Not Picking the 'ith' element.
        int notPick = solveRecursive(idx - 1, maxWeight, weight, value);

        // return the maximum value that the thief can generate by picking or not Picking the 'ith' element.
        return max(pick, notPick);
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n*maxWeight), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n*maxWeight), recursive stack space and size of 'dp' array/vector.
    int solveMemoized(int idx, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
    {
        // Base Cases.

        // When maxWeight = 0, it means, the thief's bag capacity is full now and they cannot rob more items.
        if (maxWeight == 0)
        {
            // So simply return 0 from here.
            return 0;
        }

        // For element at index 0, the thief has again 2 choices, first is to rob this or the second is to ignore this.
        // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag. Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element.
        if (idx == 0)
        {
            // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag.
            if (weight[0] <= maxWeight)
            {
                // return the cost of this element.
                return value[0];
            }

            // Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element. So return 0.
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][maxWeight] != -1)
        {
            return dp[idx][maxWeight];
        }

        // The thief has 2 choises, first is to rob this or the second is to ignore this.

        // Picking the 'ith' element.
        int pick = 0;

        // Note: we only pick this element, if the weight of this element is (<=) the capacity of thief's bag. Otherwise we cannot pick this.
        if (weight[idx] <= maxWeight)
        {
            // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
            pick = value[idx] + solveMemoized(idx - 1, maxWeight - weight[idx], weight, value, dp);
        }

        // Not Picking the 'ith' element.
        int notPick = solveMemoized(idx - 1, maxWeight, weight, value, dp);

        // return the maximum value that the thief can generate by picking or not Picking the 'ith' element.
        // Store the answer of this subproblem and then return answer.
        return dp[idx][maxWeight] = max(pick, notPick);
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n*maxWeight), where 'n' is the size of the vector.
    // Space Complexity: O(n*maxWeight), size of 'dp' array/vector.
    int solveTabulized(int maxWeight, int n, vector<int> &weight, vector<int> &value)
    {
        // 'dp' vector/array to store and compute the answer of subproblems.
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

        // Base Cases.
        // When maxWeight = 0, it means, the thief's bag capacity is full now and they cannot rob more items.
        // When maxWeight = 0, then the possible value of idx is from 0 to n-1 and when maxWeight is 0, then we cannot rob any item.
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        // For element at index 0, the thief has again 2 choices, first is to rob this or the second is to ignore this.
        // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag. Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element.
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            dp[0][i] = value[0];
        }

        // The thief has 2 choices, first is to rob this or the second is to ignore this.
        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < n; idx++)
        {
            for (int maxWt = 1; maxWt <= maxWeight; maxWt++)
            {
                // Picking the 'ith' element.
                int pick = 0;

                // Note: we only pick this element, if the weight of this element is (<=) the capacity of thief's bag. Otherwise we cannot pick this.
                if (weight[idx] <= maxWt)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = value[idx] + dp[idx - 1][maxWt - weight[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = dp[idx - 1][maxWt];

                // return the maximum value that the thief can generate by picking or not Picking the 'ith' element.
                // Store the answer of this subproblem and then return answer.
                dp[idx][maxWt] = max(pick, notPick);
            }
        }

        return dp[n - 1][maxWeight];
    }

    /* Space Optimizing the above DP Tabulation Code. */
    /* If we closely look the relation,

    dp[ind][maxWt] =  dp[ind-1][maxWt] || dp[ind-1][maxWt-weight[ind]]

    We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it. */

    // Time Complexity: O(n*maxWeight), where 'n' is the size of the vector.
    // Space Complexity: O(maxWeight) + O(maxWeight), size of both the array/vector.
    int solveSpaceOptimized(int maxWeight, int n, vector<int> &weight, vector<int> &value)
    {
        // prevRow vector/array.
        vector<int> prevRow(maxWeight + 1, 0);

        // Base Cases.
        // When maxWeight = 0, it means, the thief's bag capacity is full now and they cannot rob more items.
        // When maxWeight = 0, then the possible value of idx is from 0 to n-1 and when maxWeight is 0, then we cannot rob any item.
        prevRow[0] = 0;

        // For element at index 0, the thief has again 2 choices, first is to rob this or the second is to ignore this.
        // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag. Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element.
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            prevRow[i] = value[0];
        }

        // The thief has 2 choices, first is to rob this or the second is to ignore this.
        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < n; idx++)
        {
            // currRow vector/array.
            vector<int> currRow(maxWeight + 1, 0);
            currRow[0] = 0;

            for (int maxWt = 1; maxWt <= maxWeight; maxWt++)
            {
                // Picking the 'ith' element.
                int pick = 0;

                // Note: we only pick this element, if the weight of this element is (<=) the capacity of thief's bag. Otherwise we cannot pick this.
                if (weight[idx] <= maxWt)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = value[idx] + prevRow[maxWt - weight[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[maxWt];

                // return the maximum value that the thief can generate by picking or not Picking the 'ith' element.
                // Store the answer of this subproblem and then return answer.
                currRow[maxWt] = max(pick, notPick);
            }

            prevRow = currRow;
        }

        return prevRow[maxWeight];
    }

    /* Space Optimizing the above Space Optimized Code. */

    // We can use single array instead of using 2 arrays.

    // Time Complexity: O(n*maxWeight), where 'n' is the size of the vector.
    // Space Complexity: O(maxWeight), size of 'prevRow' the array/vector.
    int solveSpaceOptimized2(int maxWeight, int n, vector<int> &weight, vector<int> &value)
    {
        // prevRow vector/array.
        vector<int> prevRow(maxWeight + 1, 0);

        // Base Cases.
        // When maxWeight = 0, it means, the thief's bag capacity is full now and they cannot rob more items.
        // When maxWeight = 0, then the possible value of idx is from 0 to n-1 and when maxWeight is 0, then we cannot rob any item.
        prevRow[0] = 0;

        // For element at index 0, the thief has again 2 choices, first is to rob this or the second is to ignore this.
        // Now, a thief can only rob this, if the weight of this element is less than or equal to (<=) the capacity of the thief's bag. Otherwise, if weight of this element is greater than (>) the capacity of thief bag, then the theif cannot rob this element.
        for (int i = weight[0]; i <= maxWeight; i++)
        {
            prevRow[i] = value[0];
        }

        // The thief has 2 choices, first is to rob this or the second is to ignore this.
        // Outer loop is to traverse the 'dp' vector.
        for (int idx = 1; idx < n; idx++)
        {
            prevRow[0] = 0;

            for (int maxWt = maxWeight; maxWt > 0; maxWt--)
            {
                // Picking the 'ith' element.
                int pick = 0;

                // Note: we only pick this element, if the weight of this element is (<=) the capacity of thief's bag. Otherwise we cannot pick this.
                if (weight[idx] <= maxWt)
                {
                    // If we are picking the 'ith' element, then we have to add the cost of 'ith' element.
                    pick = value[idx] + prevRow[maxWt - weight[idx]];
                }

                // Not Picking the 'ith' element.
                int notPick = prevRow[maxWt];

                // return the maximum value that the thief can generate by picking or not Picking the 'ith' element.
                // Store the answer of this subproblem and then return answer.
                prevRow[maxWt] = max(pick, notPick);
            }

        }

        return prevRow[maxWeight];
    }

public:
    /* Question: A theif is robbing a store and a theif can caary a maximal weight of 'maxWeight' into his Knapsack. There are 'N' items in the store, weight[i] represent the weight of 'ith' item and value[i] represent the value of 'ith' item.
    YOur task is to find and return the maximum value that a theif can generate by steling items, considering the constraint that, the theif's knapsacks(bag) maximum capacity is 'maxWeight'. */
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        // Recursive Solution.
        // return solveRecursive(n - 1, maxWeight, weight, value);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        // return solveMemoized(n - 1, maxWeight, weight, value, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(maxWeight, n, weight, value);

        // Space Optimized Solution.
        return solveSpaceOptimized(maxWeight, n, weight, value);
    }
};

int main(void)
{
    vector<int> weight{1, 2, 4, 5};
    vector<int> value{5, 4, 8, 6};
    int maxWeight = 5;
    int n = weight.size();

    // Solution.
    Solution S;
    cout << "Thief's Profit : " << S.knapsack(weight, value, n, maxWeight) << "$.\n";
    return 0;
}