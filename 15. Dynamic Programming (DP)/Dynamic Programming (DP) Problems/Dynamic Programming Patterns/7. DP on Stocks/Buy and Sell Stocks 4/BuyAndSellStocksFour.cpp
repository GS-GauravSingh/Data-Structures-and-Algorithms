#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Space Optimizing the above DP Tabulation Code. */

    // Time Complexity: O(n * 2 * k), where 'n' is the size of the vector.
    // Space Complexity: O(n * 2 * k), size of dp vector.
    int solveSpaceOptimized(vector<int> &prices, int k)
    {
        // 'ahead' vector.
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));

        // 'currRow' vector.
        vector<vector<int>> currRow(2, vector<int>(k + 1, 0));

        // Base Case
        // As dp array is intialized to 0, we have already covered the base case.

        // Outer loop is used to traverse the dp vector.
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canIBuyOrNot = 0; canIBuyOrNot <= 1; canIBuyOrNot++)
            {
                for (int transactions = 1; transactions <= k; transactions++)
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

        return ahead[1][k];
    }

public:
    /* Question: We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

    1. We can buy and sell the stock any number of times.
    2. In order to sell the stock, we need to first buy it on the same or any previous day.
    3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
    4. We can do at most 'k' transactions. */
    int maxProfit(vector<int> &prices, int n, int k)
    {

        // Solve Space Optimized.
        return solveSpaceOptimized(prices, k);
    }
};

int main(void)
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    // Solution.
    Solution S;
    cout << "The maximum profit that can be generated is " << S.maxProfit(prices, n, k);
    return 0;
}