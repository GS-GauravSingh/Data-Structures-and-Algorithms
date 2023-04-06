#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach 1 :- Using 2 pointer approach. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    bool checkPalindrome_Iteartive(string str)
    {
        int start = 0;
        int end = str.length() - 1;

        while (start <= end)
        {
            if (str[start] != str[end])
            {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }

    /* Approach 1 recursive code. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    bool checkPalindrome_Recursive(string str, int start, int end)
    {
        // Base Condition.
        if (start >= end)
        {
            return true;
        }
        if (str[start] != str[end])
        {
            return false;
        }

        // Recursive Case.
        return checkPalindrome_Recursive(str, start + 1, end - 1);
    }
};

int main()
{
    string str = "RADAR";

    Solution S;
    cout << S.checkPalindrome_Iteartive(str) << endl;
    cout << S.checkPalindrome_Recursive(str, 0, str.length() - 1);
}