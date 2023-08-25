#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    How to solve ?
    See, An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    For example:
    "listen" is an anagram of "silent"
    "debit card" is an anagram of "bad credit"

    Here are some important points related to Anagrams:
    1. All the Anagrams of a particular word indeed have the same length as the original word. If two words have different lengths, they cannot be anagrams of each other. Length is an important characteristic when determining whether two words are anagrams or not.
    2.  In anagrams, not only do the characters need to be the same, but their frequencies should also match. This means that for two words to be anagrams of each other, they should have the same characters occurring the same number of times.

    For example, let's consider the words "listen" and "silent."
    They are anagrams of each other because they share the same characters ("l," "i," "s," "t," "e," "n") and the frequency of each character is the same in both words.

    Here's another example:
    "triangle" and "integral" are anagrams of each other because they share the same characters and the frequency of each character matches.

    Algorithm:
    1. Initialize two arrays or maps to store the frequency of characters in each word.
    2. Store the frequence of character in map.
    3. Compare both the maps:
        - If both are identical, the words are anagrams.
        - If they are not identical, the words are not anagrams.
    */

    // Time Complexity: O(n), where 'n' is the length of the string 's'.
    // SPace Complexity: O(26) + O(26), space used by auxiliary arrays/vectors.
    bool isAnagram(string s, string t)
    {

        // If two words have different lengths, they cannot be anagrams of each other.
        if (s.length() != t.length())
        {
            return false;
        }

        // s and t consist of lowercase English letters.
        vector<int> freq_S(26, 0);
        vector<int> freq_T(26, 0);

        // Storing the frequency of each charaacter.
        for (int i = 0; i < s.length(); i++)
        {
            freq_S[s[i] - 'a']++;
            freq_T[t[i] - 'a']++;
        }

        // If both arrays are identical, the words are anagrams.
        if (freq_S == freq_T)
        {
            return true;
        }

        // If both the arrays are not identical, the words are not anagrams.
        return false;
    }
};

int main(void)
{
    string s = "anagram";
    string t = "nagaram";

    // Solution.
    Solution obj;

    if (obj.isAnagram(s, t))
    {
        cout << "The words are anagrams.";
    }
    else
    {
        cout << "The words are not anagrams.";
    }
    return 0;
}