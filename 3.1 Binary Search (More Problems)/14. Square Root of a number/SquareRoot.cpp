#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
public:
    /* Question: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’. */

    // Time COmplexity: O(log(n)).
    // Space Complexity: O(1)
    int floorSqrt(long long int n)
    {
        // Base Case
        // If 'n == 0', return 0, because square root of 0 is 0.
        if (n == 0)
        {
            return 0;
        }

        // See, The square root of any given number 'n' always lies in the range of [1, n] and if you observe our search spaces is also [1, n] which is sorted in ascending order, so we can easily apply binary search.
        long long int low = 1;
        long long int high = n;

        // variable to store answer.
        long long int ans = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid.
            long long int mid = low + (high - low) / 2;

            // mid = sqrt(n) => mid*mid = n.
            if ((mid * mid) == n)
            {
                return (int)mid;
            }
            else if ((mid * mid) > n)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main(void)
{
    long long int n = 100;

    // SOlution.
    Solution obj;
    cout << "The floor value of Square root of " << n << " is: " << obj.floorSqrt(n) << ".";
    return 0;
}