#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* The 'canMakeOrNot' function checks whether it's possible to make the required number of bouquets with a given 'waiting period'. */

    // Time Complexity: O(n), where 'n' is the size of the 'bloomDay' vector.
    // Space Complexity: O(1).
    bool canMakeOrNot(vector<int> &bloomDay, int m /* number of bouquets */, int k /* flowers per bouquet */, int waitingPeriod)
    {
        int bucketNumber = 0;
        int flowersCount = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // The current flower will bloom in 'bloomDay[i]'. And when 'bloomDay[i] <= waitingPeriod', which means that the current flower will bloom within the given waiting period. After that, we can use this flower in our bouquet.
            if (bloomDay[i] <= waitingPeriod)
            {
                // Increase the flower count for current bucket, We need total 'k' flowers per bouquets.
                flowersCount++;

                // when 'flowersCount == k', it means, we filled the current bucket.
                // So, increment bucket number and set flowers count to 0 for next bucket.
                if (flowersCount == k)
                {
                    bucketNumber++;
                    flowersCount = 0;
                }
            }

            // Now, this step in important.
            // To make a bouquet, we need to use 'k' adjacent flowers from the garden.
            // It is possible that, while collecting flowers from the garden, some flowers will not bloom within the specified 'waitingPeriod'. So, In this case, reset the flower count to 0, because we need a continuous group of flowers to form a bouquet.
            else
            {
                flowersCount = 0;
            }
        }

        // If we are able to create 'm' bouquets or more than 'm' bouquets within the specified 'waitingPeriod', then return true. Otherwise, return false.
        if (bucketNumber >= m)
            return true;

        return false;
    }

public:
    // Time Complexity: O(n) for finding minimum and maximum element of array + O(n * log(n)) for finding answer.
    // Space Complexity: O(1).
    int minDays(vector<int> &bloomDay, int m, int k)
    {

        // Size of vector.
        int n = bloomDay.size();

        // Suppose we have to make 'm' bouquets and each bouquet has 'k' flowers, it means we need a total of 'm*k' flowers to make 'm' bouquets. But, if the size of arrays is less than 'm*k', then it is impossible to make 'm' bouquets, where each bouquet has 'k' flowers in it.
        if ((long long)m * k > n)
        {
            return -1;
        }

        // Consider this array: {7,7,7,7,12,7,7}, in this example, the minimum days we have to wait is 7 and in 7 days 6 flowers will bloom and the maximum days we have to wait is 12 and in 12 days all the flowers will bloom.
        // So, our search spaces is from[min_element(bloomDay), max_element(bloomDay)].
        int low = INT_MAX;
        int high = INT_MIN;

        // Initializing our pointers.
        for (int i = 0; i < n; i++)
        {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        // variable to store answer.
        // Initialize it with -1, because if it is impossible to make 'm' bouquets, then we have to return -1.
        int ans = -1;

        // Binary Search.
        while (low <= high)
        {
            // Mid (Waiting Period).
            int mid = low + (high - low) / 2;

            // Now, if I wait for 'mid' number of days and if I am able to make 'm' bouquets or more than 'm' bouquets, where each bouquet has 'k' flowers within the waiting period ('mid'). Then it is obvious that, if I wait more then 'mid' number of daysn the also I am able to make 'm' bouquets or more than 'm' bouquets, where each bouquet has 'k' flowers.

            // So, this waiting period 'mid' can be a possible answer so store this and move to left half for finding a best possible answer.
            if (canMakeOrNot(bloomDay, m, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }

            // Now, if I am not able to make 'm' bouquets within the waiting period ('mid'). Then is is obvious that if I want for less then 'mid' number of days, then I also not able to make 'm' bouquets. So, move to right half.
            else
            {
                low = mid + 1;
            }
        }

        // return answer.
        return ans;
    }
};

int main(void)
{
    vector<int> bloomDay{1, 10, 3, 10, 2};
    int m = 3, k = 1;

    // Solution.
    Solution obj;
    int ans = obj.minDays(bloomDay, m, k);

    if (ans == -1)
        cout << "We cannot make 'm' bouquets.\n";
    else
        cout << "We can make 'm' bouquets. But we have to wait for minimum " << ans << " number of days.\n";

    return 0;
}