#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(m) + O(m), size of 'prevRow' and 'currRow' vector.
    int solveSpaceOptimized(string &s1, string &s2)
    {
        // 'prevRow' vector.
        vector<int> prevRow(s2.length(), 0);

        // 'currRow' vector.
        vector<int> currRow(s2.length(), 0);

        // Outer loops is used to traverse the 'dp' vector.
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                // Matches.
                if (s1[idx1] == s2[idx2])
                {
                    currRow[idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : prevRow[idx2 - 1]);
                }

                // Not Matches.
                else
                {
                    currRow[idx2] = 0 + max(
                                            ((idx2 - 1 < 0) ? 0 : currRow[idx2 - 1]),
                                            ((idx1 - 1 < 0) ? 0 : prevRow[idx2]));
                }
            }

            prevRow = currRow;
        }

        return prevRow[s2.length() - 1];
    }

public:
    /* Question: A palindromic string is a string that is the same as its reverse. For example: “nitin” is a palindromic string. Now the question states that we are given a string, we need to find the minimum insertions that we can make in that string to make it a palindrome. */
    int minInsertion(string &str)
    {
        int n = str.length();

        string str2 = str;
        reverse(str2.begin(), str2.end());

        int longestPalindromicSubsequence = solveSpaceOptimized(str, str2);
        return (n - longestPalindromicSubsequence);
    }
};

int main(void)
{
    string str = "abcaa";

    // Solution.
    Solution S;
    cout << "Minimum Insertions required is " << S.minInsertion(str) << ".\n";
    return 0;
}