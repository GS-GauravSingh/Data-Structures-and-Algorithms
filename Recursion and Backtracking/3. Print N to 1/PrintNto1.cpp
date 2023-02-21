#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Iterative Function to print natural numbers from n to 1. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    void printNto1_Iterative(int n)
    {
        for (int i = n; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    /* Recursive Function to print natural numbers from n to 1. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    void printNto1_Recursive(int n)
    {
        // Base Condition.
        if (n == 0)
        {
            return;
        }

        // Recursive Case.
        // print the value of n and move forward towards the base case.
        cout << n << " ";

        // recursive call.
        printNto1_Recursive(n - 1);
    }
};

int main()
{
    Solution S;

    // taking the value of n.
    int n;
    cin >> n;

    cout << "Iteartive Method Output :- ";
    S.printNto1_Iterative(n);

    cout << "Recursive Method Output :- ";
    S.printNto1_Recursive(n);
}