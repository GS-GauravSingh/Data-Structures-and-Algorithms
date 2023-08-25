#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Recursive Solution. */
    // Time Complexity: O(2^n), where 'n' is the size of the vector.
    // Space Complexity: O(n), recursive stack space.
    int maxProfit_Recursive(int idx, int canIBuyOrNot, vector<int> &prices)
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
            int optionOne = 0 + maxProfit_Recursive(idx + 1, 1, prices);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
            int optionTwo = -prices[idx] + maxProfit_Recursive(idx + 1, 0, prices);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
            int optionOne = 0 + maxProfit_Recursive(idx + 1, 0, prices);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
            int optionTwo = +prices[idx] + maxProfit_Recursive(idx + 1, 1, prices);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return max(optionOne, optionTwo);
        }
    }

    /* Optimizing above Recursive Solution using Dynamic Programming - Memoization. */
    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(n) + O(n * 2), recursive stack space and size of dp vector.
    int maxProfit_Memoized(int idx, int canIBuyOrNot, vector<int> &prices, vector<vector<int>> &dp)
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
            int optionOne = 0 + maxProfit_Memoized(idx + 1, 1, prices, dp);

            // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
            int optionTwo = -prices[idx] + maxProfit_Memoized(idx + 1, 0, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
        }

        // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
        else
        {

            // For selling a stock on a particular day, we again have two options:

            // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
            int optionOne = 0 + maxProfit_Memoized(idx + 1, 0, prices, dp);

            // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
            int optionTwo = +prices[idx] + maxProfit_Memoized(idx + 1, 1, prices, dp);

            // As we are looking to maximize the profit earned, we will return the maximum value.
            return dp[idx][canIBuyOrNot] = max(optionOne, optionTwo);
        }
    }

    /* Optimizing above Dynamic Programming - Memoization solution using Dynamic Programming - Tabulation. */
    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(n * 2), size of dp vector.
    int maxProfit_Tabulized(vector<int> &prices)
    {
        // 'dp' vector.
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.
        dp[prices.size()][0] = dp[prices.size()][1] = 0;

        // Traversing the 'dp' vector.
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
    // IF we closely look at teh relationship, we only need next row to calculate the answer of current row.

    // Time Complexity: O(n * 2), where 'n' is the size of the vector.
    // Space Complexity: O(2) + O(2), space used by 'nestRow' and 'currRow' vector.
    int maxProfit_SpaceOptimized(vector<int> &prices)
    {
        // 'nextRow' vector.
        vector<int> nextRow(2, 0);

        // 'currRow' vector.
        vector<int> currRow(2, 0);

        // If idx == arr.size(), it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.
        nextRow[0] = nextRow[1] = 0;

        // Traversing the 'dp' vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                // When canIBuyOrNot == 1, we can buy the stock.
                if (canIBuyOrNot)
                {
                    // For buying a stock on a particular day, we have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the 'canIBuyOrNot' variable value will still remain 1, indicating that we can buy the stock the next day.
                    int optionOne = 0 + nextRow[1];

                    // Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -prices[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have bought the stock, the ‘canIBuyOrNot’ variable value will change to 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionTwo = -prices[idx] + nextRow[0];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    currRow[canIBuyOrNot] = max(optionOne, optionTwo);
                }

                // When canIBuyOrNot == 0, it means we are already holding a stock and to buy another stock we have to sell this stock first. So, we cannot buy stock, we are only allowed to sell.
                else
                {

                    // For selling a stock on a particular day, we again have two options:

                    // Option 1: To do 'no' transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘canIBuyOrNot’ variable value will still remain at 0, indicating that we can’t buy and only sell the stock the next day.
                    int optionOne = 0 + nextRow[0];

                    // Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +prices[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have sold the stock, the ‘canIBuyOrNot’ variable value will change to 1, indicating that we can buy the stock the next day.
                    int optionTwo = +prices[idx] + nextRow[1];

                    // As we are looking to maximize the profit earned, we will return the maximum value.
                    currRow[canIBuyOrNot] = max(optionOne, optionTwo);
                }
            }

            // update pointers.
            nextRow = currRow;
        }

        return nextRow[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {

        // // Recursive Solution.
        // return maxProfit_Recursive(0, 1, prices);

        // // DP - Memoization Solution.
        // vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        // return maxProfit_Memoized(0, 1, prices, dp);

        // // DP - Tabulation Solution.
        // return maxProfit_Tabulized(prices);

        // Space Optimized Solution.
        return maxProfit_SpaceOptimized(prices);
    }
};

int main(void)
{
    vector<int> prices{7, 1, 5, 3, 6, 4};

    // Solution.
    Solution obj;
    cout << "Maximum Profit: " << obj.maxProfit(prices) << ".";
    return 0;
}