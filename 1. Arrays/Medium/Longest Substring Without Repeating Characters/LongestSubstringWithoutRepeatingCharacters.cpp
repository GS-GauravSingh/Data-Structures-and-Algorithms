/*
Question :-
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Approach  :- Using set */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    int lengthOfLongestSubstring(string s)
    {
        // length of string.
        int len = s.length();

        unordered_set<char> hashSet;

        int left = 0, right = 0, maxLen = 0;

        while (right < len)
        {
            // if s[right] is unique, then insert it into set.
            if (hashSet.find(s[right]) == hashSet.end())
            {
                hashSet.insert(s[right]);
            }
            else
            {
                // if s[right] is not unique, the start removing elements from set until you remove the duplicate of s[right].
                while (hashSet.find(s[right]) != hashSet.end())
                {
                    hashSet.erase(s[left]);
                    left++;
                }

                // after removing the duplicate of s[right], s[right]  become unique.
                // So, insert it into set.
                hashSet.insert(s[right]);
            }

            // update max length.
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

int main()
{
    string str = "abcabcbb";

    Solution S;
    cout << S.lengthOfLongestSubstring(str);
}