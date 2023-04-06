#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Iterative Function to find nth term of fibonacci series. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    void fibIterative(int n)
    {
        // The first term of the Fibonacci series is 0,
        // the second term of the Fibonacci series is 1
        // and the next term of the fibonacci series is the summation of previous 2 terms.
        int firstTerm = 0;
        int secondTerm = 1;
        int nextTerm;

        // printing first 2 terms of fibonacci series.
        cout << firstTerm << " " << secondTerm << " ";

        for (int i = 2; i <= n; i++)
        {
            // the next term of the fibonacci series is the summation of previous 2 terms.
            nextTerm = firstTerm + secondTerm;

            // printing next term.
            cout << nextTerm << " ";

            // update first and second terms.
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }

        cout << endl
             << n << "th term of fibonacci series is " << nextTerm << "." << endl;
    }

    /* Recursive Function to find nth term of fibonacci series. */
    // Time Complexity :- O(2^n)
    // Space Complexity :- O(n), recursive stack space.
    int fibRecursive(int n)
    {
        // The first term of the Fibonacci series is 0,
        // the second term of the Fibonacci series is 1
        // and the next term of the fibonacci series is the summation of previous 2 terms.

        // Base Condition.
        if (n == 0)
        {
            // The first term of the Fibonacci series is 0.
            return 0;
        }
        if (n == 1)
        {
            // the second term of the Fibonacci series is 1.
            return 1;
        }

        // Recursive Case.
        // The next term of the fibonacci series is the summation of previous 2 terms.
        int nextTerm = fibRecursive(n - 1) + fibRecursive(n - 2);
        return nextTerm;
    }
};

int main()
{
    // taking the value of n.
    int n;
    cin >> n;

    Solution S;
    cout << "---- Iterative Method Output ---- \nFibonacci Series => ";
    S.fibIterative(n);
    cout << "\n----Recursive Method Output ----\n"<<n<<"th term of fibonacci series is " << S.fibRecursive(n);
}