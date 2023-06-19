#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n * m), where 'n' is the length of string 's1' and 'm' is the length of string 's2'.
    // Space Complexity: O(n*m), size of 'dp' vector.
    string solveTabulized(string &s1, string &s2)
    {
        // 'dp' vector to store and computer the answer of subproblems.
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));

        // Outer loops is used to traverse the 'dp' vector.
        for (int idx1 = 0; idx1 < s1.length(); idx1++)
        {
            for (int idx2 = 0; idx2 < s2.length(); idx2++)
            {

                // Matches.
                if (s1[idx1] == s2[idx2])
                {
                    dp[idx1][idx2] = 1 + ((idx1 - 1 < 0 || idx2 - 1 < 0) ? 0 : dp[idx1 - 1][idx2 - 1]);
                }

                // Not Matches.
                else
                {
                    dp[idx1][idx2] = 0 + max(
                                             ((idx2 - 1 < 0) ? 0 : dp[idx1][idx2 - 1]),
                                             ((idx1 - 1 < 0) ? 0 : dp[idx1 - 1][idx2]));
                }
            }
        }

        // Printing Longest Common Sunsequence.

        // Pointers.
        int idx1 = s1.length() - 1;
        int idx2 = s2.length() - 1;

        // String to store LCS.
        string lcs = "";
        while (idx1 >= 0 || idx2 >= 0)
        {
            // Matches.
            if (s1[idx1] == s2[idx2])
            {
                // Store the Common Element.
                lcs.push_back(s1[idx1]);

                // When character matches, in this case we move to the diagonal element.
                idx1 = idx1 - 1;
                idx2 = idx2 - 1;
            }

            // Not Matches.
            else if (s1[idx1] > s2[idx2])
            {
                idx1--;
            }
            else
            {
                idx2--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }

public:
    /* Question: Given 2 strings 's' and 't', your task is to find the length of the 'Longest Common Subsequence' and print the LCS. */
    string lcs(string s, string t)
    {
        // DP Tabulation Solution.
        return solveTabulized(s, t);
    }
};

int main(void)
{
    string s1 = "acd";
    string s2 = "ced";

    // Solution.
    Solution S;
    cout << "The Longest Common Subsequence is '" << S.lcs(s1, s2) << "'.\n";
    return 0;
}