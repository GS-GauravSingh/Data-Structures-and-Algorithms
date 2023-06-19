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
    /* Question: We are given two strings, str1 and str2. We are allowed the following operations:
        1. Delete any number of characters from string str1.
        2. Insert any number of characters in string str1.
    We need to tell the minimum operations required to convert str1 to str2. */
    int canYouMake(string &A, string &B)
    {
        int aLen = A.length();
        int bLen = B.length();

        int lcs = solveSpaceOptimized(A, B);

        int deletion = aLen - lcs;
        int insertions = bLen - lcs;

        return (deletion+insertions);

    }
};

int main(void)
{
    string str1 = "abcd";
    string str2 = "anc";

    // Solution.
    Solution S;
    cout<<"Minimum Insertions/Deletions requires is : "<<S.canYouMake(str1, str2)<<".\n";
    return 0;
}