#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Question: Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.

    Keep the following conditions in mind:
    1. A word can only consist of lowercase characters.
    2. Only one letter can be changed in each transformation.
    3. Each transformed word must exist in the wordList including the targetWord.
    4. startWord may or may not be part of the wordList

    Note: If no possible way to transform sequence from startWord to targetWord return 0.
    */

    /*
    Time Complexity: O(N * M * 26), Where N = size of wordList Array and M = word length of words present in the wordList.
    Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

    Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }, Where N = size of wordList Array.
    */
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Creating a queue data structure of type {word, transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal.
        // Push the startWord into the queue with the sequence length of 1.
        q.push({startWord, 1});

        // Push all values of wordList into a set.
        // So that we can easily find whether a word is present in the wordList or not.
        // This will make searching and deletion of word in less time.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Erase the startWord from the wordList, because we don't want to count this transformation again.
        st.erase(startWord);

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front element of the queue.
            pair<string, int> frontNode = q.front();

            // Pop the front element of the queue.
            q.pop();

            // Take out the word and the step to reach that word from the frontNode.
            string word = frontNode.first;
            int steps = frontNode.second;

            // we return the steps as soon as the first occurence of targetWord is found.
            if (word == targetWord)
            {
                return steps;
            }

            // Traverse the word.
            for (int i = 0; i < word.size(); i++)
            {

                // Storing the original character, if we don't able to create any valid transformation then we have to change the transformed character to its original character.
                char original = word[i];

                // Now, for every character present in the string "word".
                // Now, replace each character of ‘word’ with characters from 'a' to 'z', then check if ‘word’ exists in wordList.
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // If the transformed word is present in the set.
                    if (st.find(word) != st.end())
                    {
                        // Then, mark this word as visited, means erase this word from set.
                        st.erase(word);

                        // and push the transformed word into the queue and increment the steps by 1.
                        q.push({word, steps + 1});
                    }
                }

                // Replace the transformed character with its original character.
                word[i] = original;
            }
        }

        // If there is no transformation sequence possible, in this case return 0.
        return 0;
    }
};

int main(void)
{
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    // Solution.
    Solution S;
    int ans = S.wordLadderLength(startWord, targetWord, wordList);
    cout << ans << endl;
}