#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Method to chech whether a string is palindrome or not. */
    // Time Complexity: O(n), where 'n' is the length of the string "str".
    // Space Complexity: O(1).
    bool isPalindrome(string str)
    {
        int start = 0, end = str.length() - 1;
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

    /* Brute Force Approach: Generate all substrings and then find the longest palindromic sybstring. */
    // Time Complexity: O(n^2*n), where 'n' is the length of the string "str".
    // Space Complexity: O(1).
    string longestPalindrome_BruteForce(string str)
    {

        int n = str.length();

        int maxLen = 0;
        string ans;

        for (int i = 0; i < n; i++)
        {
            // string variable to store substring.
            string substring;

            for (int j = i; j < n; j++)
            {
                substring.push_back(str[j]);

                // If current substring is a plaindrome.
                if (isPalindrome(substring))
                {
                    int substringLength = substring.length();

                    // Store the longest palindromic substring.
                    if (substringLength > maxLen)
                    {
                        maxLen = substringLength;
                        ans = substring;
                    }
                }
            }
        }

        return ans;
    }

    /* Optimized Approach:

    Intution: One by one Consider all characters of the string and treat this individual character as the center character of the palindrome (the individual character is a palindrome in itself)  and from this center character try to expand outwards on both the sizes i.e., left and right and check if the characters from a palindrome or not, expand until the left and right pointer points to the length of the string or the substring from left to right is no longer a plaindrome.  In this way, we can easily find the longest palindrome.

    This approach is called  "expand around center" approach for finding the longest palindromic substring.

    Note: When I am considering a character as the center of the palindrome, It means this is an Odd length palindrome because there's only one center character, and when I am expanding outwards, the left and right characters should match in order to expand further.
    We have to handle the case of even length palindrome also.

    Dry-Run:
    Example: "A B R B A D A A D A B", space in between character are just used for formatting, do not consider space as a part of the string.

    Picking 0 index Character as the center of the palindrome:
    str:        -1 "A B R B A D A A D A B" -1
    Pointers:    l  c r                             , l => left pointer, c=> center, r=> right pointer
    There is no character at left of 'A'. So, window does not expand.
    Length of palindrome is 1: "A".

    Picking 1 index Character as the center of the palindrome:
    str:        -1 "A B R B A D A A D A B" -1
    Pointers:       l c r                             , l => left pointer, c=> center, r=> right pointer
    Character at left of 'B' is 'A' and Character at right of 'B' is 'R', both the character does not match, it means it is not forming a palindrome. Don't need to expand the windoes further.
    Length of palindrome is 1: "B".

    Picking 2 index Character as the center of the palindrome:
    str:        -1 "A B R B A D A A D A B" -1
    Pointers:         l c r                           , l => left pointer, c=> center, r=> right pointer
    Character at left of 'R' is 'B' and Character at right of 'B' is 'B', both the character matches, it means it is forming a palindrome.
    Length of palindrome is 3: "BRB".

    Try to expand further.
    str:        -1 "A B R B A D A A D A B" -1
    Pointers:       l   c   r                           , l => left pointer, c=> center, r=> right pointer
    We got a palindrome, Length of palindrome is 5: "ABRBA".

    Try to expand further.
    str:        -1 "A B R B A D A A D A B" -1
    Pointers:    l      c     r                          , l => left pointer, c=> center, r=> right pointer
    left and right pointer doesn't match.

    and so on...

    */
    // Time Complexity: O(n^2), where 'n' is the length of the string "str".
    // Space Complexity: O(1).
    string longestPalindrome_Optimized(string str)
    {

        int n = str.length();

        string LPS = "";

        // Loop to Iterate over each character.
        for (int i = 0; i < n; i++)
        {
            // ODD Length Palindrome.
            // One by One Consider Each character as the center of the Palindrome and try of exapnd outwards on both side (left and right).
            int left = i;
            int right = i;

            // Expanding outwards on left and right side.
            while (left >= 0 && right < n && str[left] == str[right])
            {
                // Store the Longest Palindromic Substring.
                int substringLength = right - left + 1;

                if (substringLength > LPS.length())
                {
                    LPS = str.substr(left, substringLength);
                }

                // Update Pointers.
                left--;
                right++;
            }

            // Even Length.
            left = i;
            right = i + 1;

            // Expanding outwards on left and right side.
            while (left >= 0 && right < n && str[left] == str[right])
            {
                // Store the Longest Palindromic Substring.
                int substringLength = right - left + 1;

                if (substringLength > LPS.length())
                {
                    LPS = str.substr(left, substringLength);
                }

                // Update Pointers.
                left--;
                right++;
            }
        }

        return LPS;
    }

public:
    string longestPalindrome(string str)
    {

        // // Brute Force Solution.
        // return longestPalindrome_BruteForce(str);

        // Optimized Solution.
        return longestPalindrome_Optimized(str);
    }
};

int main(void)
{
    string str = "babad";

    // Solution.
    Solution obj;
    cout << obj.longestPalindrome(str);
    return 0;
}