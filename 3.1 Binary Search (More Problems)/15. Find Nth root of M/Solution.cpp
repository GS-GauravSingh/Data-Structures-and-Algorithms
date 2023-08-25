#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Helper Function. */
    // Note: Binary Exponentiation = Overflow.
    int isValid(int mid, int n, int m)
    {
        long long ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;

            if (ans > m)
                return 2;
        }

        if (ans == m)
        {
            return 1;
        }

        return 0;
    }

public:
    /* Question: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the ‘nth root is not an integer, return -1. */

    // Time Complexity: O(log(n))
    // Space Complexity: O(1).
    int NthRoot(int n, int m)
    {
        if (n == 1)
        {
            return m; // The first root of any number is the number itself
        }
        if (m == 0)
        {
            return 0; // Special case for m = 0
        }

        int low = 1;
        int high = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int val = isValid(mid, n, m);

            if (val == 1)
            {
                return mid;
            }
            else if (val == 0)
            {
                low = mid + 1;
            }
            else
            {
                // val == 3.
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main(void)
{
    int n = 9, m = 1953125;

    // SOlution.
    Solution obj;
    int ans = obj.NthRoot(n, m);
    cout << "The answer is: " << ans << ".";
    return 0;
}