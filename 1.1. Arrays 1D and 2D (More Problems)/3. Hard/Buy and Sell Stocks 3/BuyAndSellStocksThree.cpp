#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Recursive Solution. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int idx, int canIBuyOrNot, int transactions, vector<int> &prices)
    {
        // Base Case

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.

        // If transactions == 0, it means that we cannot make any more transactions. Therefore we return 0.
        if (idx >= prices.size() || transactions == 0)
        {
            return 0;
        }

        // Recursive Case.

        // When canIBuyOrNot == 1, we can buy the stock.
        if (canIBuyOrNot)
        {
            // For buying a stock on a particular day, we have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1, transactions). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day,

            // And the ‘transactions’ variable will remain the same as if no transaction took place.
            int optionOne = 0 + solveRecursive(idx + 1, 1, transactions, prices);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.

            // As we have only bought the stock and not sold it the transaction remains incomplete and the ‘transactions’ variable value remains unchanged.
            int optionTwo = -prices[idx] + solveRecursive(idx + 1, 0, transactions, prices);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.

            // And the ‘transactions’ variable will remain the same as if no transaction took place.
            int optionOne = 0 + solveRecursive(idx + 1, 0, transactions, prices);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.

            // As we have sold the earlier bought stock, we make one complete transaction, therefore now we update the 'transactions' variable’s value to transactions - 1.
            int optionTwo = +prices[idx] + solveRecursive(idx + 1, 1, transactions - 1, prices);

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

    // Time Complexity: O(n * 2 * 3), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n * 2 * 3), recursive stack space and size of dp vector.
    int solveMemoized(int idx, int canIBuyOrNot, int transactions, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        // Base Case

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.

        // If transactions == 0, it means that we cannot make any more transactions. Therefore we return 0.
        if (idx >= prices.size() || transactions == 0)
        {
            return 0;
        }

        // Recursive Case.

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[idx][canIBuyOrNot][transactions] != -1)
        {
            return dp[idx][canIBuyOrNot][transactions];
        }

        // When canIBuyOrNot == 1, we can buy the stock.
        if (canIBuyOrNot)
        {
            // For buying a stock on a particular day, we have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1, transactions). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day,

            // And the ‘transactions’ variable will remain the same as if no transaction took place.
            int optionOne = 0 + solveMemoized(idx + 1, 1, transactions, prices, dp);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.

            // As we have only bought the stock and not sold it the transaction remains incomplete and the ‘transactions’ variable value remains unchanged.
            int optionTwo = -prices[idx] + solveMemoized(idx + 1, 0, transactions, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot][transactions] = max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.

            // And the ‘transactions’ variable will remain the same as if no transaction took place.
            int optionOne = 0 + solveMemoized(idx + 1, 0, transactions, prices, dp);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.

            // As we have sold the earlier bought stock, we make one complete transaction, therefore now we update the 'transactions' variable’s value to transactions - 1.
            int optionTwo = +prices[idx] + solveMemoized(idx + 1, 1, transactions - 1, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot][transactions] = max(optionOne, optionTwo);
        }
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * 2 * 3), where 'n' is the size of the vector.
    // Space Complexity: O(n * 2 * 3), size of dp vector.
    int solveTabulized(vector<int> &prices)
    {
        // 'dp' vector.
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base Case
        // As dp array is intialized to 0, we have already covered the base case.

        // Outer loop is used to traverse the dp vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                for (int transactions = 1; transactions <= 2; transactions++)
                {

                    // When canIBuyOrNot == 1, we can buy the stock.
                    if (canIBuyOrNot)
                    {
                        // For buying a stock on a particular day, we have two options:

                        // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
                        int optionOne = 0 + dp[idx + 1][1][transactions];

                        // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
                        int optionTwo = -prices[idx] + dp[idx + 1][0][transactions];

                        // As we are looking to maximize the profit earned, we will return the maximum value.
                        dp[idx][canIBuyOrNot][transactions] = max(optionOne, optionTwo);
                    }

                    // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
                    else
                    {

                        // For selling a stock on a particular day, we again have two options:

                        // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
                        int optionOne = 0 + dp[idx + 1][0][transactions];

                        // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
                        int optionTwo = +prices[idx] + dp[idx + 1][1][transactions - 1];

                        // As we are looking to maximize the profit earned, we will return the maximum value.
                        dp[idx][canIBuyOrNot][transactions] = max(optionOne, optionTwo);
                    }
                }
            }
        }

        return dp[0][1][2];
    }

    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n * 2 * 3), where 'n' is the size of the vector.
    // Space Complexity: O(n * 2 * 3), size of dp vector.
    int solveSpaceOptimized(vector<int> &prices)
    {
        // 'ahead' vector.
        vector<vector<int>> ahead(2, vector<int>(3, 0));

        // 'currRow' vector.
        vector<vector<int>> currRow(2, vector<int>(3, 0));

        // Base Case
        // As dp array is intialized to 0, we have already covered the base case.

        // Outer loop is used to traverse the dp vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                for (int transactions = 1; transactions <= 2; transactions++)
                {

                    // When canIBuyOrNot == 1, we can buy the stock.
                    if (canIBuyOrNot)
                    {
                        // For buying a stock on a particular day, we have two options:

                        // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
                        int optionOne = 0 + ahead[1][transactions];

                        // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
                        int optionTwo = -prices[idx] + ahead[0][transactions];

                        // As we are looking to maximize the profit earned, we will return the maximum value.
                        currRow[canIBuyOrNot][transactions] = max(optionOne, optionTwo);
                    }

                    // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
                    else
                    {

                        // For selling a stock on a particular day, we again have two options:

                        // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
                        int optionOne = 0 + ahead[0][transactions];

                        // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
                        int optionTwo = +prices[idx] + ahead[1][transactions - 1];

                        // As we are looking to maximize the profit earned, we will return the maximum value.
                        currRow[canIBuyOrNot][transactions] = max(optionOne, optionTwo);
                    }
                }
            }
            ahead = currRow;
        }

        return ahead[1][2];
    }

public:
    /* Question: We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

    1. We can buy and sell the stock any number of times.
    2. In order to sell the stock, we need to first buy it on the same or any previous day.
    3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
    4. We can do at most 2 transactions. */
    int maxProfit(vector<int> &prices, int n)
    {

        // Solve Space Optimized.
        return solveSpaceOptimized(prices);
    }
};

int main(void)
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    // Solution.
    Solution S;
    cout << "The maximum profit that can be generated is " << S.maxProfit(prices, n);
    return 0;
}