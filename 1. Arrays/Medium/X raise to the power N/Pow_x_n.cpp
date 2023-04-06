#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Brute Force Approach :- using for loop, run a loop from 1 to n and multiply x, n times. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    double myPow(double x, int n)
    {
        // i am taking abs(n) because, it will handle the -ve value of n.
        double ans = 1;
        for (int i = 0; i < abs(n); i++)
        {
            ans *= x;
        }

        // If power is negative, ex :- 2^-4
        // answer is (1/(2^4)).
        if (n < 0)
        {
            ans = 1 / ans;
        }

        return ans;
    }

    /* Optimized Approach :- Binary Exponentiation. */
    // Time Complexity :- O(log(n)), where n is the power.
    // Space Complexity :- O(log(n)), recursive stack space.
    double binaryExponentiation_Recursive(double x, int n)
    {
        // Base Case
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }

        // Recursive Case
        double ans = binaryExponentiation_Recursive(x, n / 2);

        // if n is odd.
        if (n & 1)
        {
            return ans * ans * x;
        }

        // if n is even.
        return ans * ans;
    }

    // Time Complexity :- O(log(n)), where n is the power.
    // Space Complexity :- O(1).
    double binaryExponentiation_Iterative(double x, int n)
    {
        // Base Case
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }

        // Iterative Case
        int power = n;
        double ans = 1.0;

        while (power)
        {
            if (power & 1)
            {
                ans = ans * x;
            }

            ans = ans * ans;

            power = power >> 1;
        }

        return ans;
    }

    double myPow_Optimized(double x, int n)
    {
        // double ans = binaryExponentiation_Recursive(x, abs(n));
        double ans = binaryExponentiation_Iterative(x, abs(n));
        if (n < 0)
        {
            ans = 1 / ans;
        }
        return ans;
    }
};

int main()
{
    int x = 2;
    int n = 10;

    Solution s;
    cout << s.myPow_Optimized(x, n);
}