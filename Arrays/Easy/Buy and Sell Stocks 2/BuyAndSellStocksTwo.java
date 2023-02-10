
public class BuyAndSellStocksTwo {
    /*
     * Time Complexity :- O(n)
     * Space Complexity :- O(1)
     */
    static int maxProfit(int prices[]) {

        // size of array.
        int n = prices.length;

        // variable to store maximum profit.
        int maximumProfit = 0;

        for (int i = 0; i < n - 1; i++) {
            int buy = prices[i];
            int sell = prices[i + 1];

            if (sell > buy) {
                maximumProfit += sell - buy;
            }
        }

        return maximumProfit;
    }

    public static void main(String[] args) {
        int prices[] = { 7, 1, 5, 3, 6, 4 };

        System.out.println(maxProfit(prices));
    }
}
