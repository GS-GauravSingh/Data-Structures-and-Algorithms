#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

    N – The maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.
    Currently, it’s Monday, and she needs to survive for the next S days.
    Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive. */
    int minimumDays(int S, int N, int M)
    {

        int sundays = S / 7;
        int buyingDays = S - sundays;
        int totalFood = S * M;

        int ans = 0;
        if (totalFood % N == 0)
        {
            ans = totalFood / N;
        }
        else
        {
            ans = totalFood / N + 1;
        }

        if (ans <= buyingDays)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main(void)
{
    int S = 10;
    int N = 16;
    int M = 2;

    // Solution.
    Solution obj;
    cout << obj.minimumDays(S, N, M);
    return 0;
}