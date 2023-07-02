#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Solution. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int canIBuyOrNot, vector<int> &prices)
    {
        // Base Case

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.
        if (idx >= prices.size())
        {
            return 0;
        }

        // Recursive Case.

        // When canIBuyOrNot == 1, we can buy the stock.
        if (canIBuyOrNot)
        {
            // For buying a stock on a particular day, we have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
            int optionOne = 0 + solveRecursive(idx + 1, 1, prices);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
            int optionTwo = -prices[idx] + solveRecursive(idx + 1, 0, prices);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
            int optionOne = 0 + solveRecursive(idx + 1, 0, prices);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
            int optionTwo = +prices[idx] + solveRecursive(idx + 1, 1, prices);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return max(optionOne, optionTwo);
        }
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n * 2), recursive stack space and size of dp vector.
    int solveMemoized(int idx, int canIBuyOrNot, vector<int> &prices, vector<vector<int>> &dp)
    {
        // Base Case

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.
        if (idx >= prices.size())
        {
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][canIBuyOrNot] != -1)
        {
            return dp[idx][canIBuyOrNot];
        }

        // When canIBuyOrNot == 1, we can buy the stock.
        if (canIBuyOrNot)
        {
            // For buying a stock on a particular day, we have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
            int optionOne = 0 + solveMemoized(idx + 1, 1, prices, dp);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
            int optionTwo = -prices[idx] + solveMemoized(idx + 1, 0, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
            int optionOne = 0 + solveMemoized(idx + 1, 0, prices, dp);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
            int optionTwo = +prices[idx] + solveMemoized(idx + 1, 1, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
        }
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(n * 2), size of dp vector.
    int solveTabulized(vector<int> &prices)
    {
        // 'dp' vector.
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        // Base Case
        dp[prices.size()][0] = dp[prices.size()][1] = 0;

        // Outer loop is used to traverse the dp vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                // When canIBuyOrNot == 1, we can buy the stock.
                if (canIBuyOrNot)
                {
                    // For buying a stock on a particular day, we have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
                    int optionOne = 0 + dp[idx + 1][1];

                    // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionTwo = -prices[idx] + dp[idx + 1][0];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
                }

                // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
                else
                {

                    // For selling a stock on a particular day, we again have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionOne = 0 + dp[idx + 1][0];

                    // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
                    int optionTwo = +prices[idx] + dp[idx + 1][1];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
                }
            }
        }

        return dp[0][1];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(2), size of vectors.
    int solveSpaceOptimized(vector<int> &prices)
    {
        // 'ahead' vector.
        vector<int> aheadRow(2, 0);

        // 'currRow' vector.
        vector<int> currRow(2, 0);

        // Base Case
        aheadRow[0] = aheadRow[1] = 0;

        // Outer loop is used to traverse the dp vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                // When canIBuyOrNot == 1, we can buy the stock.
                if (canIBuyOrNot)
                {
                    // For buying a stock on a particular day, we have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
                    int optionOne = 0 + aheadRow[1];

                    // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionTwo = -prices[idx] + aheadRow[0];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    currRow[canIBuyOrNot] = max(optionOne, optionTwo);
                }

                // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
                else
                {

                    // For selling a stock on a particular day, we again have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionOne = 0 + aheadRow[0];

                    // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
                    int optionTwo = +prices[idx] + aheadRow[1];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    currRow[canIBuyOrNot] = max(optionOne, optionTwo);
                }
            }

            aheadRow = currRow;
        }

        return aheadRow[1];
    }

public:
    /*
    Question :
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.


    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.


    Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.


    Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

    Constraints:
    1 <= prices.length <= 3 * 10^4
    0 <= prices[i] <= 10^4
    */

    int maximumProfit(vector<int> &prices)
    {
        // // Recursive Solution.
        // return solveRecursive(0, 1, prices);

        // // DP Memoization Solution.
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solveMemoized(0, 1, prices, dp);

        // // DP Tabulation Solution.
        // return solveTabulized(prices);

        // Solve Space Optimized.
        return solveSpaceOptimized(prices);
    }
};

int main(void)
{
    vector<int> prices{7, 1, 5, 3, 6, 4};

    // Solution.
    Solution S;
    cout << "The maximum profit by selling the stock is " << S.maximumProfit(prices) << ".\n";
    return 0;
}