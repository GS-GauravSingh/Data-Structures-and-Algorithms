#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* The task of this method is to check whether the string "goal" is a substring of string "s+s" or not. */
    // Time Complexity: O((N - K + 1) * K), where 'N' is the size of the concatenated string ("s+s") and 'K' is the l;ength of the string "goal".
    // Space Complexity: O(k), space used to store the substrings.
    bool isSubstring_BruteForce(string concatenatedString, string goal)
    {
        // Length fo the string "s+s"(Concatenated String).
        int N = concatenatedString.length();

        // Length of substring is same as the length of the string goal.
        int K = goal.length();

        // Now, there can be only N - K + 1, substring of length K.
        for (int i = 0; i < (N - K + 1); i++)
        {
            // String to store the current substring.
            string currSubstring;

            // Traverse through the current substring and store all the character present in the current substring in the string "currSubstring".
            for (int j = 0; j < K; j++)
            {
                currSubstring.push_back(concatenatedString[i + j]);
            }

            // If the string "goal" is a substring, then return true.
            if (currSubstring == goal)
            {
                return true;
            }
        }

        // If the string "goal" is not a substring, then return false.
        return false;
    }

    /* Optimized Approach: Using Sliding Window. */
    /* The task of this method is to check whether the string "goal" is a substring of string "s+s" or not. */
    // Time Complexity: O(N), where 'N' is the size of the concatenated string ("s+s") and 'K' is the length of the string "goal".
    // Space Complexity: O(k), space used be dequeue DS.
    bool isSubstring_Optimized(string concatenatedString, string goal)
    {
        // Length fo the string "s+s"(Concatenated String).
        int N = concatenatedString.length();

        // Length of substring is same as the length of the string goal.
        int K = goal.length();

        // Push all the echaracters of the string "goal" into a deque, this is used for comparing the string goal with the substrings.
        deque<char> goal_dq;
        for (auto ch : goal)
        {
            goal_dq.push_back(ch);
        }

        // Pointers.
        // Start pointer will represent the starting position/index of the K sized window.
        int start = 0;

        // End pointer will represent the ending position/index of the K sized window.
        int end = 0;

        // Using dequeue DS for maintaining the window.
        deque<char> dq;

        // Sliding Window.
        while (end < N)
        {
            // Current Character.
            char currChar = concatenatedString[end];

            // Push back the current character into the dequeue.
            dq.push_back(currChar);

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // When "windowSize < K", it means we haven't reached the window size.
            if (windowSize < K)
            {
                end++;
            }

            // When "windowSize == K", it means we hit the window size i.e., K.
            else if (windowSize == K)
            {
                // dq will have all the characters of the current window.

                // If the string "goal" is a substring, then return true.
                if (dq == goal_dq)
                {
                    return true;
                }

                // Otherwise, remove the first character of the current window and shift this window ahead.
                dq.pop_front();

                // shift this window ahead.
                start++;
                end++;
            }
        }

        // If the string "goal" is not a substring, then return false.
        return false;
    }

public:
    /* How to solve?

    Observation: If both the strings are of different length, then it is impossible for string "s" to become the same as string "goal" after any number of shifts.

    Now, this problem involves rotation and one rotation means moving the leftmost character to the rightmost position
    Let's take an example string: s = "abcde" and goal = "cdeab".

    Now, if I manually perform rotation, then all the possible rotations are:
    Original String: s:          "abcde"
    Rotate by One Character:     "bcdea"
    Rotate by Two Characters:    "cdeab"
    Rotate by Three Characters:  "deabc"
    Rotate by Four Characters:   "eabcd"
    Rotate by Five Characters:   "abcde", When you rotate a string by its length (i.e., s.length() times), you end up with the original string.

    Now, To find all the possible rotations of a given string, you can concatenate the original string with itself, creating a longer string.
    Now, if we concatenate the string "s" with itself, we got this string: s + s = "abcdeabcde", which is twice the length of the original string and this concatenated string will give us all the possible rotations of string "s".

    And if the string "goal" is a valid rotation of the string "s", then it is indeed a substring of the concatenated string "s + s".

    Now, we just have to check, whether the string "goal" is a substring of this concatenated string or not. If string "goal" is a substring of string "s+s"(concatenated string), then we can say that, the string "s" can be converted into the string "goal" after some number of shifts, otherwise if string "goal" is not a substring of "s+s", then string "s" cannot be converted into the string "goal" after any number of rotations.

    Algorithm:
    1. Concatenate the string "s" with itself to create "s + s," which contains all possible rotations of "s."
    2. Check if the string "goal" is a substring of "s + s."
    3. If "goal" is a substring, then "s" can be converted into "goal" after some number of shifts (rotations). If not, it's not possible.
    */
    bool rotateString(string s, string goal)
    {

        // If both the strings are of different length, then it is impossible for string "s" to become the same as string "goal" after any number of shifts.
        if (s.length() != goal.length())
        {
            return false;
        }

        // Step 1: Concatenate the string "s" with itself to create "s + s," which contains all possible rotations of "s."
        string concatenatedString = s + s;

        // Step 2: Check if the string "goal" is a substring of "s + s."
        // bool isSubstring = isSubstring_BruteForce(concatenatedString, goal);
        bool isSubstring = isSubstring_Optimized(concatenatedString, goal);

        // Step 3: If "goal" is a substring, then "s" can be converted into "goal" after some number of shifts (rotations). If not, it's not possible.
        return isSubstring;
    }
};

int main(void)
{
    string s = "abcde";
    string goal = "cdeab";

    // Solution.
    Solution obj;
    if (obj.rotateString(s, goal))
    {
        cout << "String \"" << s << "\" can be converted in the string \"" << goal << "\" after some number of shifts.";
    }
    else
    {
        cout << "String \"" << s << "\" cannot be converted in the string \"" << goal << "\" after any number of shifts.";
    }
    return 0;
}