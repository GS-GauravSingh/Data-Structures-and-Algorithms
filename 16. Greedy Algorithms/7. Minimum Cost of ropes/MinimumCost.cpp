#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.  */

    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long cost = 0;
        while (pq.size() > 1)
        {
            long long first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            long long merge = first + second;

            cost += merge;

            pq.push(merge);
        }

        return cost;
    }
};

int main(void)
{
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);

    // Solution.
    Solution S;
    cout << S.minCost(arr, n);
    return 0;
}