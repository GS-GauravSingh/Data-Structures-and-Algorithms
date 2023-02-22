#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- Using loop. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int pow_Iterative(int x, int n)
    {
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = ans * x;
        }
        return ans;
    }

    /* Approach 2 :- Using Recursion (Binary Exponentiation). */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(log(n)), recursive stack space.
    int binaryExponentiation_Recursive(int x, int n)
    {
        // Base Condition.
        if (n == 0)
        {
            // 2^0 = 1.
            return 1;
        }
        if (n == 1)
        {
            // 2^1 = 2.
            return x;
        }

        // Recursive Case.
        int ans = binaryExponentiation_Recursive(x, n / 2);

        if (n & 1)
        {
            // odd power.
            return ans * ans * x;
        }

        // even power.
        return ans * ans;
    }

    /* Approach 3 :- Iterative code for Binary Exponentiation. */
    // Time Complexity :- O(log(1))
    // Space Complexity :- O(1)
    int binaryExponentiation_Iterative(int x, int n)
    {
        int ans = 1;
        while (n !=  0)
        {
            int lastBit = n & 1;
            if (lastBit == 1)
            {
                // multiply answer with current power of x.
                ans = ans * x;
            }

            // if last bit is 0, increase the power of x.
            x = x * x;

            n = n >> 1;
        }

        return ans;
    }
};

int main()
{
    int number = 2;
    int power = 13;

    Solution S;

    cout << number << "^" << power << " = " << S.pow_Iterative(number, power) << endl;
    cout << number << "^" << power << " = " << S.binaryExponentiation_Iterative(number, power) << endl;
}