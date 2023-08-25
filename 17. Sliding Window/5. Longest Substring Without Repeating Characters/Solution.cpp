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

    /* Optimized Approach: Using Sliding Window. */
    // Time Complexity: O(n), where 'n' is the length of the string "str".
    // Space Complexity: O(256), space used by unordered_set.
    int lengthOfLongestSubstring_Optimized(string str)
    {
        // length of the string.
        int len = str.length();

        // variable to store the length of the longest substring without repeating characters.
        int maxLen = 0;

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        int end = 0;

        // unordered_set to check for repeating characters.
        unordered_set<char> set;

        // Run a loop, while end < N.
        while (end < len)
        {
            // Current Character.
            char currChar = str[end];

            // Now,if current character "currChar" is not present in the set.
            // It means that all the characters in this current window size are non-repeating characters.
            if (set.find(currChar) == set.end())
            {
                // Insert this character into the set.
                set.insert(currChar);
                
                // Calculating the window size.
                // 'windowSize' represent the total number of element in current window.
                int windowSize = end - start + 1;

                // Update the maximum length.
                maxLen = max(maxLen, windowSize);

                // Now, current window has no repeating elements. Now expand this window to find best possible answer.
                end++;
            }

            // But, if the current window has repeating elements then, in this case we have to shring the window size.
            else
            {
                
                // Shrink the window.
                while (set.find(currChar) != set.end())
                {
                    set.erase(str[start]);
                    start++;
                }

                set.insert(currChar);
                end++;
            }
        }

        return maxLen;
    }

public:
    int lengthOfLongestSubstring(string str)
    {
        // // Brute Force Approach.
        // return lengthOfLongestSubstring_BruteForce(str);

        // // Better Approach.
        // return lengthOfLongestSubstring_Better(str);

        // Optimized Approach.
        return lengthOfLongestSubstring_Optimized(str);
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