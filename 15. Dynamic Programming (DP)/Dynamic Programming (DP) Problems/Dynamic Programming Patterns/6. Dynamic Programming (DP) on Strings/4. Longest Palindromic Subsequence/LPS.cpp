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
    /* Question: A palindromic string is a string that is equal to its reverse. For example: “nitin” is a palindromic string. Now the question states to find the length of the longest palindromic subsequence of a string. */
    int lps(string &str)
    {
        /* Approach 1: Using Brute Force

        We are given a string S, the simplest approach will be to generate all the subsequences and store them, then manually find out the longest palindromic subsequence.

        This naive approach will give us the correct answer but to generate all the subsequences, we will require exponential ( 2n ) time. Therefore we will try some other approaches. */

        /* Approach 2: Using Dynamic Programming, Pre-req: Longest Common Subsequence

        We can use the approach discussed in Longest Common Subsequence, to find the Longest Palindromic Subsequence.
        Intuition:

        Let us say that we are given the following string.

        str =          bbabcbcab
        reverse(str) = bacbcbabb

        The longest palindromic subsequence will be: “babcbab”.

        What is special about this string is that it is palindromic (equal to its reverse) and of the longest length.

        Now let us write the reverse of str next to it and please think about the highlighted characters.
        str =          (b)b(abcb)c(ab)
        reverse(str) = (ba)c(bcbab)b

        If we look closely at the highlighted characters, they are nothing but the longest common subsequence of the two strings.

        Now, we have taken the reverse of the string for the following two reasons:
            1. The longest palindromic subsequence being a palindrome will remain the same when the entire string is reversed.
            2. The length of the palindromic subsequence will also remain the same when the entire string is reversed.

        From the above discussion we can conclude:
        The longest palindromic subsequence of a string is the longest common subsequence of the given string and its reverse.
        */
        string str1 = str;
        string str2 = str;
        reverse(str2.begin(), str2.end());

        return solveSpaceOptimized(str1, str2);
    }
};

int main(void)
{
    string str = "bbbab";

    // Solution.
    Solution S;
    cout << "The Length of the Longest Palindromic Subsequence is " << S.lps(str) << ".\n";
    return 0;
}