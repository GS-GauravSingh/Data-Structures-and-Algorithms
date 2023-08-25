#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Intution: See, In question, it is clearly mentioned that, "No two characters may map to the same character, but a character may map to itself". This means that there is a one-to-one mapping between the character of string 's' and string 't', meaning each character in string 's' can map to only one character in string 't', and no two characters in string 's' can map to the same character in string 't'.

    Example 1: s = "egg", t = "add"

    e  g  g
    |  |  |
    a  d  d
    A one-to-one mapping, also known as a bijection, means that each element in the first set (characters from string 's' in this case) is associated with exactly one element in the second set (characters from string 't'). No two elements from the first set can be associated with the same element in the second set.

    In the example:
    "e" from string 's' is mapped to "a" in string 't'.
    "g" from string 's' is mapped to "d" in string 't'.
    This forms a valid one-to-one mapping.

    Example 2: s = "foo", t = "bar"

    f  o  o
    |  |  |
    b  a  r
    In this example,
    The first character in string 's' is "f", which maps to "b" in string 't'.
    The second character in string 's' is "o", which maps to "a" in string 't'.
    The third character in string 's' is again "o", which maps to "r" in string 't'.

    Here, the character "o" from string 's' is being mapped to two different characters ("a" and "r") in string 't'. This violates the one-to-one mapping rule, where each character from string 's' should mapped to exactly one character in string 't', and no two characters from string 's' should map to the same character in string 't'.

    So, If you can establish a valid one-to-one mapping between the characters of string 's' and the characters of string 't', then you can conclude that the strings are isomorphic. This means that each character in string 's' corresponds to exactly one character in string 't', and no two characters in string 's' are associated with the same character in string 't'. If you encounter any violation of these conditions, you can safely determine that the strings are not isomorphic.

    */

    // Time Complexity: O(n), where 'n' is the length of the string 's' (length of both the strings are same).
    // Space Complexity: O(256) + O(256), space used by auxiliary arrays.
    bool isIsomorphic(string s, string t)
    {

        // String "s" and string "t" consist of any valid ascii character and in total there are 256 ASCII Characters.
        int mapOne[256] = {0};
        int mapTwo[256] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            // Character are converted to their ASCII value.
            int charOne = s[i];
            int charTwo = t[i];

            // If both mapOne[charOne] and mapTwo[charTwo] are 0, this means the characters have not been encountered before, so it's a new mapping.
            if (mapOne[charOne] == 0 && mapTwo[charTwo] == 0)
            {
                // Store the mapping in both arrays.
                mapOne[charOne] = charTwo;
                mapTwo[charTwo] = charOne;
            }

            //  If both mapOne[charOne] and mapTwo[charTwo] are not 0, it means that these characters have been encountered before, and their mappings have already been stored in the arrays.
            else
            {
                // mapOne[charOne] != charTwo and mapTwo[charTwo] != charOne,
                // This condition checks if the current mapping conflicts with the existing mapping. It's saying that if the existing mapping stored in mapOne for charOne is not equal to charTwo, and the existing mapping stored in mapTwo for charTwo is not equal to charOne, then there is a mismatch between the mappings, and the strings are not isomorphic.
                if (mapOne[charOne] != charTwo && mapTwo[charTwo] != charOne)
                {
                    return false;
                }
            }
        }

        // If the above loop does not return flase, then return true at the end, indicating that the strings are isomorphic.
        return true;
    }
};

int main(void)
{
    string s = "paper";
    string t = "title";

    // Solution.
    Solution obj;
    if (obj.isIsomorphic(s, t))
    {
        cout << "Strings are Isomorphic.";
    }
    else
    {

        cout << "Strings are not Isomorphic.";
    }
    return 0;
}