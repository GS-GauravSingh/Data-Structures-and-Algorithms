#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
    You are now provided with an attractive offer.
    For every candy you buy from the store and get at most K other candies ( all are different types ) for free.
    Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
    In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free. */
    vector<int> candyStore(int candies[], int N, int K)
    {
        // sort the candies array.
        sort(candies, candies + N);

        // Finding Minimum Amount.
        int minAmt = 0;
        int buy = 0;
        int free = N - 1;

        while (buy <= free)
        {
            minAmt += candies[buy++];
            free -= K;
        }

        // Finding Maximum Amount.
        int maxAmt = 0;
        buy = N - 1;
        free = 0;

        while (free <= buy)
        {
            maxAmt += candies[buy--];
            free += K;
        }

        return {minAmt, maxAmt};
    }
};

int main(void)
{
    int candies[] = {3, 2, 1, 4};
    int n = sizeof(candies) / sizeof(candies[0]);
    int k = 2;

    // Solution.
    Solution S;
    vector<int> ans = S.candyStore(candies, n, k);
    cout << "Minimum Amount : " << ans[0] << ".\n";
    cout << "Maximum Amount : " << ans[1] << ".\n";
    return 0;
}