#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
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

        // Printing SCS.
        int idx1 = s1.length() - 1;
        int idx2 = s2.length() - 1;

        // string to store SCS (Shortest Common Supersequence).
        string SCS = "";

        while (idx1 > 0 && idx2 > 0)
        {
            int leftCell = (idx2 - 1 >= 0) ? dp[idx1][idx2 - 1] : 0;
            int upCell = (idx1 - 1 >= 0) ? dp[idx1 - 1][idx2] : 0;
            
            // Matches.
            if (s1[idx1] == s2[idx2])
            {
                SCS.push_back(s1[idx1]);

                idx1--;
                idx2--;
            }

            // Not Matches.

            else if (upCell > leftCell)
            {
                SCS.push_back(s1[idx1]);

                idx1--;
            }
            else
            {
                SCS.push_back(s2[idx2]);

                idx2--;
            }

        }

        // Adding Remaing Characters - Only one of the below two while loops will run.
        while (idx1 >= 0)
        {
            SCS.push_back(s1[idx1--]);
        }
        while (idx2 >= 0)
        {
            SCS.push_back(s2[idx2--]);
        }

        reverse(SCS.begin(), SCS.end());
        return SCS;
    }

public:
    /* Question: We are given two strings ‘S1’ and ‘S2’. We need to return their shortest common supersequence. A supersequence is defined as the string which contains both the strings S1 and S2 as subsequences.

    Example: S1 = "brute" and S2 = "groot".
    Shortest Common Supersequence: bgruoote => S1 (b ru  te) and S2( gr oot ).

    We need to return the length of the longest common subsequence and the string as well.
    */
    string shortestSupersequence(string a, string b)
    {
        return solveTabulized(a, b);
    }
};

int main(void)
{
    string A = "brute";
    string B = "groot";

    // Solution.
    Solution S;
    cout << "The Shortest Common Supersequence is : " << S.shortestSupersequence(A, B) << ".\n";

    return 0;
}