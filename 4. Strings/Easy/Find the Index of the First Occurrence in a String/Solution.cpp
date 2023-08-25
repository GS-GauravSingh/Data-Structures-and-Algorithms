#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Generates all possible substrings of size 'needle.size()' within the haystack and compares each substring with the needle string. If a match is found, then returns the starting index of the match/substring otherwise, returns -1, means needle string is not present in haystack. */
    // Time Complexity: O((N-K+1)*K), where 'N' is the length of the haystack and 'K' is the length of the needle.
    // Space Complexity: O(K), space used to store the substring.
    int strStr_BruteForce(string haystack, string needle)
    {
        // Length of the string "heystack".
        int N = haystack.length();

        // Length of the string "needle".
        int K = needle.size();

        // There can only be (N - K + 1) substrings of size K.
        for (int i = 0; i < (N - K + 1); i++)
        {
            // Initialize an empty string "temp" to store the current substring.
            string temp;

            // Traverse through the current substring and store all the character of current substring into our "temp" string.
            for (int j = 0; j < K; j++)
            {
                char currChar = haystack[i + j];
                temp.push_back(currChar);
            }

            // If the "temp" string matches the "needle" string, return the index 'i', indicating the starting position of the first occurrence of the needle within the haystack.
            if (needle == temp)
            {
                return i;
            }
        }

        // If no match is found after iterating through all possible substrings, return -1 to indicate that the needle does not exist within the haystack.
        return -1;
    }

    /* Better Approach: Using Sliding Window. */
    // Time Complexity: O(N*K), where 'N' is the length of the haystack and 'K' is the length of the needle.
    // Space Complexity: O(K), space used to store the substring.
    int strStr_Better(string haystack, string needle)
    {
        // Length of the string "heystack".
        int N = haystack.length();

        // Length of the string "needle".
        int K = needle.size();

        // Pointers for Sliding Window.
        // 'Start' pointer will represent the starting point/index of the 'k' sized window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of the 'k' sized window.
        int end = 0;

        // An empty string "temp" is used to store the current substring.
        string temp;

        while (end < N)
        {
            // Push the current character into the "temp" string.
            temp.push_back(haystack[end]);

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // If 'windowSize' is less then 'k'.
            if (windowSize < K)
            {
                end++;
            }

            // When "windowSize == K", it means we hit the window size i.e., k.
            else if (windowSize == K)
            {
                // Now, When "windowSize == K", it means we hit the window size i.e., k and all the character present in this k sized window or substring are stored in the "temp" string.

                // If the "temp" string matches the "needle" string, return the index 'start', indicating the starting position of the first occurrence of the needle within the haystack.
                if (needle == temp)
                {
                    return start;
                }

                // But, if the "temp" string does not matches the "needle" string, in this case we have to shift the window ahead.

                // But, before shifting this window ahead, we have to remove the starting character of current window/substring.
                temp.erase(temp.begin()); // O(n) operation, where 'n' is the length of the string.

                // Shift this window ahead.
                start++;
                end++;
            }
        }

        // If no match is found after iterating through all possible substrings, return -1 to indicate that the needle does not exist within the haystack.
        return -1;
    }

    /* Optimized Approach: Using Sliding Window with Dequeue. */
    // Time Complexity: O(N), where 'N' is the length of the haystack and 'K' is the length of the needle.
    // Space Complexity: O(K), space used by dequeue.
    int strStr_Optimized(string haystack, string needle)
    {
        // Length of the string "heystack".
        int N = haystack.length();

        // Length of the string "needle".
        int K = needle.size();

        // I am using dequeue DS, because in dequeue provide us the functionality to preform insertion and deletion from both ends i.e., Front and rear and the time complexity of these operations in constant.
        // Declare a dequeue and insert all character of needle into the deque.
        deque<char> needleDQ;
        for (auto ch : needle)
        {
            needleDQ.push_back(ch);
        }

        // Declare another dequeue and this deque will used in sliding window.
        deque<char> temp;

        // Pointers for Sliding Window.
        // 'Start' pointer will represent the starting point/index of the 'k' sized window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of the 'k' sized window.
        int end = 0;

        while (end < N)
        {
            // Push the current character into the "temp" dequeue.
            temp.push_back(haystack[end]);

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // If 'windowSize' is less then 'k'.
            if (windowSize < K)
            {
                end++;
            }

            // When "windowSize == K", it means we hit the window size i.e., k.
            else if (windowSize == K)
            {
                // Now, When "windowSize == K", it means we hit the window size i.e., k and all the character present in this k sized window or substring are stored in the "temp" string.

                // If the "temp" string matches the "needle" string, return the index 'start', indicating the starting position of the first occurrence of the needle within the haystack.
                if (needleDQ == temp)
                {
                    return start;
                }

                // But, if the "temp" string does not matches the "needle" string, in this case we have to shift the window ahead.

                // But, before shifting this window ahead, we have to remove the starting character of current window/substring.
                temp.pop_front(); // O(1) operation.

                // Shift this window ahead.
                start++;
                end++;
            }
        }

        // If no match is found after iterating through all possible substrings, return -1 to indicate that the needle does not exist within the haystack.
        return -1;
    }

public:
    int strStr(string haystack, string needle)
    {

        // // Brute Force Solution.
        // return strStr_BruteForce(haystack, needle);

        // // Better Solution.
        // return strStr_Better(haystack, needle);

        // Optimized Solution.
        return strStr_Optimized(haystack, needle);
    }
};

int main(void)
{
    string haystack = "sadbutsad";
    string needle = "sad";

    // Solution.
    Solution obj;
    if (obj.strStr(haystack, needle) != -1)
    {
        cout << "First Occurence: " << obj.strStr(haystack, needle) << ".";
    }
    else
    {
        cout << "\"" << needle << "\" does not occur in \"" << haystack << "\".";
    }
    return 0;
}