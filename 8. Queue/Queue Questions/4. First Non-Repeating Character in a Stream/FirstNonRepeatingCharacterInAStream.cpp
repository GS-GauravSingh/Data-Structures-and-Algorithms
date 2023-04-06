#include <bits/stdc++.h>
using namespace std;

/* --------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach : Using Queue and hashing. */
    // Time Complexity :- O(26*n), n i the lenght of the stream of characters.
    // Space Complexity :- O(26), map is used to store frequency of characters.
    string FirstNonRepeatingCharacter(string str)
    {
        // unordered_map to store frequency of characters.
        unordered_map<char, int> freq;

        // queue to find first non-repeting character in a stream.
        queue<char> q;

        // string to store answer.
        string ans = "";

        // traversing through the string.
        for (char ch : str)
        {
            // storing the frequency of character "ch".
            freq[ch]++;

            // push character "ch" into the queue.
            q.push(ch);

            // Now, traverse through the queue and find the first NON-Repeating character.
            while (!q.empty())
            {
                if (freq[q.front()] == 1)
                {
                    // First NON-Repeating Character.
                    ans.push_back(q.front());
                    break; // after storing the First NON-Repeating Character, simple break the loop, because it may possible that other non-repeating characters are present inside the queue and we don't need to store that non-repeating characters in our answer.
                }
                else
                {
                    // Repeating Character.

                    // if the frequency of the character present at the front of the queue is greater than 1, it means it is a repeating character and we don't care about repeating characters. So, simply pop that repeating character from the queue.
                    q.pop();
                }
            }

            // After the above while loop ends there can be 2 cases,

            // Case 1 : Our queue is not empty, it means that the first non-repeating character is found and stored in our answer. Example stream = "ab".

            // Case 2 : Our queue becomes empty, if our queue becomes empty, it means there is no non-repeating character found for the stream of characters till now. Example stream = "aa".
            // and in this case our answer is "#".
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        // return answer
        return ans;
    }
};

int main(void)
{
    string str = "aabc";

    // Solution.
    Solution S;
    string ans = S.FirstNonRepeatingCharacter(str);
    cout << "Answer => " << ans;
}