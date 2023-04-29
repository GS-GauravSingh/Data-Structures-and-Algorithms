#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Question: Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.

    Keep the following conditions in mind:
    1. A word can only consist of lowercase characters.
    2. Only one letter can be changed in each transformation.
    3. Each transformed word must exist in the wordList including the targetWord.
    4. startWord may or may not be part of the wordList.
    5. Return an empty list if there is no such transformation sequence.
    */

    /*
    Time Complexity and Space Complexity: It cannot be predicted for this particular algorithm because there can be multiple sequences of transformation from startWord to targetWord depending upon the example, so we cannot define a fixed range of time or space in which this program would run for all the test cases.
    */
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {

        // vector to store answer.
        vector<vector<string>> ans;

        // Push all words of wordList into a set.
        // So that we can easily find whether a word is present in the wordList or not.
        // This will make searching and deletion of word in less time.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Creating a queue data structure of type {vector<string>}.
        // vector<string> will store the sequence of words from startWord to endWord.
        queue<vector<string>> q;

        // Push the startWord into the queue.
        q.push({beginWord});

        // Variable to store level.
        int lvl = 0; // Initially we are at level 0.

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        // Traverse the queue.
        while (!q.empty())
        {
            // Take out the front element of the queue.
            vector<string> currSequence = q.front();

            // Pop the front element of the queue.
            q.pop();

            // Now, erase all the words used on the previous level to create new transformtions.
            if (currSequence.size() > lvl)
            {
                lvl++;

                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }

            // Take out the word from the currSequence.
            string word = currSequence.back();

            // If word matches the tragetWord, then store this sequence into our answer vector.
            if (word == endWord)
            {
                ans.push_back(currSequence);
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
                        // Then, push this word into our current sequence.
                        currSequence.push_back(word);

                        // push this sequence into the queue.
                        q.push(currSequence);

                        // mark this word as visited, because this word is created on this current level.
                        usedOnLevel.push_back(word);

                        // pop this word from our currentSequence.
                        currSequence.pop_back();
                    }
                }

                // Replace the transformed character with its original character.
                word[i] = original;
            }
        }

        return ans;
    }

    /* Method to print 2d Vector. */
    void print2dVec(vector<vector<string>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    // Solution.
    Solution S;
    vector<vector<string>> ans = S.findSequences(startWord, targetWord, wordList);
    S.print2dVec(ans);
}