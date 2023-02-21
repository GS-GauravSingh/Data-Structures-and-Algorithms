#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Iterative Function to print natural numbers from 1 to n. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    void print1toN_Iterative(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    /* Recursive Function to print natural numbers from 1 to n. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    void print1toN_Recursive(int n)
    {
        // Base Condition.
        if (n == 0)
        {
            return;
        }

        // Recursive Case.
        // first we ge to the base case and while returning back from the base case,
        // we print the value of n.
        print1toN_Recursive(n - 1);

        // Backtracking Step (While returning back from the base case).
        cout << n << " ";
    }
};

int main()
{
    Solution S;

    // taking the value of n.
    int n;
    cin >> n;

    cout << "Iteartive Method Output :- ";
    S.print1toN_Iterative(n);

    cout << "Recursive Method Output :- ";
    S.print1toN_Recursive(n);
}