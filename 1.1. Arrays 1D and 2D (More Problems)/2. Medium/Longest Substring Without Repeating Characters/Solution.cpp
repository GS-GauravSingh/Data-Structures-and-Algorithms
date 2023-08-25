#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Brute Force Approach: generate all subarrays and then find the length of the longest subarray/substring without repeating characters. */
    // Time Complexity: O(n^3), where 'n' is the length of the string "str".
    // Space Complexity: O(256), space used by unordered_set.
    int lengthOfLongestSubstring_BruteForce(string str)
    {
        // length of the string.
        int len = str.length();

        // variable to store the length of the longest substring without repeating characters.
        int maxLen = 0;

        // Generate all subarrays.
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                // vector to check for repeating characters.
                // So, str consists of English letters, digits, symbols and spaces. So, we need to use unordered_set, because In total, there are 256 ASCII characters.
                unordered_set<char> set;

                // boolean variable to check if repeating character is present in current substring or not.
                bool isRepeatingCharPresent = false;

                for (int k = i; k <= j; k++)
                {
                    // Condition to check if there is any repeating character in the current substring.
                    if (set.find(str[k]) != set.end())
                    {
                        // It means repeating characters is present in current substring.
                        // SO, we cannot consider this substring. So, move to next substring.
                        isRepeatingCharPresent = true;
                        break;
                    }

                    // Insert characters in this substring into the set and mark it as true.
                    set.insert(str[k]);
                }

                // If "isRepeatingCharPresent == true", it means repeating characters are present in this current subarray.
                // If "isRepeatingCharPresent == false", it means there are no repeating characters current subarray. So compute the length and store the maximum length.
                if (isRepeatingCharPresent == false)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        // return maximum length.
        return maxLen;
    }

    /* Better Approach: generate all subarrays using nested loops and then find the length of the longest subarray/substring without repeating characters. */
    // Time Complexity: O(n^2), where 'n' is the length of the string "str".
    // Space Complexity: O(256), space used by unordered_set.
    int lengthOfLongestSubstring_Better(string str)
    {
        // length of the string.
        int len = str.length();

        // variable to store the length of the longest substring without repeating characters.
        int maxLen = 0;

        // Generate all subarrays.
        for (int i = 0; i < len; i++)
        {
            // vector to check for repeating characters.
            // So, str consists of English letters, digits, symbols and spaces. So, we need to use unordered_set, because In total, there are 256 ASCII characters.
            unordered_set<char> set;

            // boolean variable to check if repeating character is present in current substring or not.
            bool isRepeatingCharPresent = false;

            for (int j = i; j < len; j++)
            {

                // Condition to check if there is any repeating character in the current substring.
                if (set.find(str[j]) != set.end())
                {
                    // It means repeating characters is present in current substring.
                    // SO, we cannot consider this substring. So, move to next substring.
                    isRepeatingCharPresent = true;
                    break;
                }

                // Insert characters in this substring into the set and mark it as true.
                set.insert(str[j]);

                // If "isRepeatingCharPresent == true", it means repeating characters are present in this current subarray.
                // If "isRepeatingCharPresent == false", it means there are no repeating characters current subarray. So compute the length and store the maximum length.
                if (isRepeatingCharPresent == false)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        // return maximum length.
        return maxLen;
    }

    /* Optimized Approach: I will get back to this later after learning sliding windows. */

public:
    int lengthOfLongestSubstring(string str)
    {
        // // Brute Force Approach.
        // return lengthOfLongestSubstring_BruteForce(str);

        // Better Approach.
        return lengthOfLongestSubstring_Better(str);
    }
};

int main(void)
{
    string str = "abcabcbb";

    // Solution.
    Solution obj;
    cout << "Length of longest substring without repeating characters: " << obj.lengthOfLongestSubstring(str) << ".";
    return 0;
}