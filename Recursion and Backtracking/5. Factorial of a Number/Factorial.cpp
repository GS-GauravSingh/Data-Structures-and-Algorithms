#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Iterative Function to find a factorial. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int factorialIterative(int n)
    {

        int factorial = 1;
        for (int i = 1; i <= n; i++)
        {
            factorial *= i;
        }

        return factorial;
    }

    /* Recursive Function to find a factorial. */
    // Time Complexity :- O()
    // Space Complexity :- O()
    int factorialRecursive(int n)
    {

        // Base Condition.
        if (n == 0 || n == 1)
        {
            return 1;
        }

        // Recursive Case.
        return n * factorialRecursive(n - 1);
    }
};

int main()
{
    Solution S;

    // taking the value of n.
    int n;
    cin >> n;

    cout << "(Iterative Method) Factorial of " << n << " is : " << S.factorialIterative(n) << endl;
    cout << "(Recursive Method) Factorial of " << n << " is : " << S.factorialRecursive(n) << endl;
}