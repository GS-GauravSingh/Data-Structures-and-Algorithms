#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Find sum of n natural numbers. */
    // Time Complexity :- O(1)
    // Space Complexity :- O(1)
    int sumofNaturalNumbers_Using_Formula(int n)
    {

        // Sum of N natural Numbers = (n*(n+1))/2;
        return (n * (n + 1)) / 2;
    }

    /* Iterative Function to find sum of n natural numbers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    int sumofNaturalNumbers_Iterative(int n)
    {

        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += i;
        }

        return sum;
    }

    /* Recursive Function to find sum of n natural numbers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    int sumofNaturalNumbers_Recursive(int n)
    {

        // Base Condition.
        if (n == 0)
        {
            return 0;
        }

        // Recursive Case.
        return n + sumofNaturalNumbers_Recursive(n - 1);
    }
};

int main()
{
    Solution S;

    // taking the value of n.
    int n;
    cin >> n;

    cout << "(Using Formula (n * (n+1)/2), Sum of N Natural Number is " << S.sumofNaturalNumbers_Using_Formula(n) << endl;
    cout << "(Iterative Method), Sum of N Natural Number is " << S.sumofNaturalNumbers_Iterative(n) << endl;
    cout << "(Recursive Method), Sum of N Natural Number is " << S.sumofNaturalNumbers_Recursive(n) << endl;
}