/*
Question :-
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------ Solution Class ------------------------ */
class Solution
{
public:
    /* Brute Force Approach :- Using nested loops.
    Time Complexity :- O(n^2)
    Space Complexity :- O(1)
    */
    int maxProfit_BruteForce(vector<int> &prices)
    {

        // size of vector.
        int n = prices.size();

        // variable to store maximum profit.
        int maximumProfit = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] > prices[i])
                {
                    int profit = prices[j] - prices[i];
                    maximumProfit = max(maximumProfit, profit);
                }
            }
        }

        return maximumProfit;
    }

    /* Optimized Approach :- One Pass.
    Time Complexity :- O(n)
    Space Complexity :- O(1)
    */
    int maxProfit_Optimized(vector<int> &prices)
    {

        // size of vector.
        int n = prices.size();

        // variable to store maximum profit.
        int maximumProfit = 0;

        int buy = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            buy = min(buy, prices[i]);
            maximumProfit = max(maximumProfit, prices[i] - buy);
        }

        return maximumProfit;
    }
};

int main()
{
    Solution S;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // cout << S.maxProfit_BruteForce(prices);
    cout << S.maxProfit_Optimized(prices);
}