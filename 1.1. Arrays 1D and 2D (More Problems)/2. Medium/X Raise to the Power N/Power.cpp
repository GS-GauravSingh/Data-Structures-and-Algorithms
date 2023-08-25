#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: We have to calculate x^n, So use for loop and multiple x, n times.

    Example: 2^4 = 2 * 2 * 2 * 2, we multiple 2, 4 times to get 2^4.
    */

    // Time Complexity: O(n), where 'n' is the power.
    // Space Complexity: O(1).
    double xRaiseToThePowerN(double x, int n)
    {
        // Base Case

        // When any number (except zero) is raised to the power of zero, the result is always 1. Ex: 2^0 = 1.
        if (n == 0)
        {
            return 1;
        }

        // When any number "a" is raised to the power of 1, the result is always equal to the number itself. Ex: 2^1 = 2.
        if (n == 1)
        {
            return x;
        }

        // variable to store answer (x^n).
        double ans = 1;

        // Use for loop and multiple x, n times.
        for (long long i = 1; i <= n; i++)
        {
            ans = ans * x;
        }

        // return answer.
        return ans;
    }

    /* Optimized Approach: Using Binary Exponentiation.

    Binary Exponentiation is way of finding 'x raise to the power n' in log(n) (log withbase 2) multiplications. In brute force approach, to calculate 'x raise to the power n', we have to multiply 'x', 'n' time to get the answer and the TC of this is O(n), where 'n' is the power.

    Let's see how can we calculate 'x raise to the power n' in log(n) (log withbase 2) multiplications using Binary Exponentiation.

    Example: Let's say we have to '2 raise to the power 16' i.e., 2^16.

    2^16 = I can write 2^16 like this: 2^8 * 2*8, Yes I can.
    2^16 = 2^8 * 2*8, Now, lets find 2^8.

    2^8 =  I can write 2^8 like this: 2^4 * 2*4, Yes I can.
    2^8 = 2^4 * 2*4, Now, lets find 2^4.

    2^4 =  I can write 2^4 like this: 2^2 * 2*2, Yes I can.
    2^4 = 2^2 * 2*2, Now, lets find 2^2.

    2^2 =  I can write 2^2 like this: 2^1 * 2*1, Yes I can.
    2^2 = 2^1 * 2*1, Now, lets find 2^1.

    Now, we know that, When any number "a" is raised to the power of 1, the result is always equal to the number itself. Ex: 2^1 = 2.
    and When any number (except zero) is raised to the power of zero, the result is always 1. Ex: 2^0 = 1.

    So, 2 ^ 1 = 2 and 2 ^ 0 = 1.

    Now, put the value of 2^1 in above equations.
    2^2 = 2^1 * 2*1,
    2^2 = 2 * 2       {2^1 = 2}.
    2^2 = 4.

    Now, put the value of 2^2.
    2^4 = 2^2 * 2*2
    2^4 = 4 * 4      {2^2 = 4}.
    2^4 = 16.

    Now, put the value of 2^4.
    2^8 = 2^4 * 2*4
    2^8 = 16 * 16      {2^4 = 16}.
    2^8 = 256.

    Now, put the value of 2^8.
    2^16 = 2^8 * 2*8
    2^16 = 256 * 256      {2^8 = 256}.
    2^16 = 65,536.

    2^16 = 65,536 and we got our answer and if you observe, we got this answer in log(n) (log with base 2) multiplications, where 'n' is the power.

    How to calculate log(a) with base 2?
    Another way to calculate log(16) (log with base 2), is to repeatedly divide 16 by 2 until the result becomes 1. The number of times you perform this division will give you the value of the logarithm.

    Let's see the steps:
    16 ÷ 2 = 8           ------- step 1
    8 ÷ 2 = 4            ------- step 2
    4 ÷ 2 = 2            ------- step 3
    2 ÷ 2 = 1            ------- step 4

    So, After four divisions/steps, we reach 1. Therefore, log(16) (log with base 2) = 4.

    Note: When the terms with the same base are multiplied, the powers are added, i.e., a^m × a^n = a^(m+n). Example: 2^4 × 2^2 = 2^(4+2) = 2^6 = 64.
    */

    // Time Complexity: O(log(n)), where 'n' is the power.
    // Space Complexity: O(log(n)), recursive stack space.
    double binaryExponentiation_Recursive(double x, int n)
    {
        // Base Case

        // When any number (except zero) is raised to the power of zero, the result is always 1. Ex: 2^0 = 1.
        if (n == 0)
        {
            return 1;
        }

        // When any number "a" is raised to the power of 1, the result is always equal to the number itself. Ex: 2^1 = 2.
        if (n == 1)
        {
            return x;
        }

        // Recursive case

        double ans = binaryExponentiation_Recursive(x, n / 2); // In every step, we divide the power into its half.

        // When power is Odd.
        // 2^16 = I can write 2^16 like this: 2^8 * 2*8, Yes I can.
        // Similarly, when power is odd, 2^17 = I can write 2^16 like this: 2^8 * 2*8 * 2*1, Yes I can. So, when power is odd, we multiple the answer by given number 'x'.
        if (n & 1)
        {
            // Odd Power.
            return ans * ans * x;
        }

        // Even Power.
        return ans * ans;
    }

public:
    double myPow(double x, int n)
    {

        // // Brute Force Solution.
        // double ans = xRaiseToThePowerN(x, abs(n) /* passing positive power, because power can be negative. */);

        // Optimized Solution - Binary Exponentiation - Recursive.
        double ans = binaryExponentiation_Recursive(x, abs(n) /* passing positive power, because power can be negative. */);

        // Case of Negative Power, we have to handle this case seperately.
        if (n < 0)
        {
            /* Negative powers are calculated using the concept of reciprocals. When a number "a" is raised to a negative power "n", it is equivalent to taking the reciprocal of "a" raised to the positive power "|n|".

            Mathematically, we can express this as follows:    a^-n = 1/a^n

            where:
            "a" is the base number,
            "-n" is the negative power, and
            "|n|" is the absolute value of "n."
            */

            return (1 / ans);
        }

        return ans;
    }
};

int main(void)
{
    double x = 2;
    int n = -6;

    // Solution.
    Solution obj;
    cout << x << "^" << n << " = " << obj.myPow(x, n) << ".";
    return 0;
}