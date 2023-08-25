#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), where 'n' is the size of the 'prices' vector.
    // Space Complexity: O(1).
    int maxProfit(vector<int> &prices)
    {

        // size of vector.
        int n = prices.size();

        // variable to store maximum profit.
        int maximumProfit = 0;

        // We always want our 'buy' point to be minimum.
        int buy = INT_MAX;

        // Iterate through the prices vector.
        for (int i = 0; i < n; i++)
        {
            // Update the buy variable by taking the minimum value between the current 'buy' and the current price 'prices[i]'. This ensures that 'buy' always represents the minimum buying price encountered so far.
            buy = min(buy, prices[i]);

            // Update the 'maximumProfit' by taking the maximum value between the current 'maximumProfit' and the difference between the current price and the 'buy' price. This calculates the potential profit if selling at the current price.
            maximumProfit = max(maximumProfit, prices[i] - buy);
        }

        // return maximum profit.
        return maximumProfit;
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