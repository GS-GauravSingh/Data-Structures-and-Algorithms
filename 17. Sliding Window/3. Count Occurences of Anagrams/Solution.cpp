#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Generate all subarrays/substrings of size 'k'. */
    // Time Complexity: O((N - K + 1) * K), where 'N' is the size of the string and 'K' is the window size.
    // Space Complexity: O(26), space used by auxiliary vector's.
    int search_BruteForce(string word, string text)
    {
        // size of string "text".
        int N = text.size();

        // Now, here is size of window is same as the length of the string "word", because all the anagrams of word also have same length.
        // All the anagrams of a word have the same length. Anagrams are words or phrases that are formed by rearranging the letters of another word or phrase, using all the original letters exactly once. Since the total count of letters remains the same in anagrams, the length of the words remains the same as well.
        int K = word.size();

        // variable to store the count the occurence of anagrams of given word "word" in "text".
        int cnt = 0;

        // Store the frequence of each character present in the string "word". This will help us to compare the string "word" with the substrings that we are going to generate.
        vector<int> wordFreq(26, 0);
        for (int i = 0; i < K; i++)
        {
            // extract the current character.
            char currChar = word[i];

            // store the frequency of 'currChar' in frequence vector 'wordFreq'.
            wordFreq[currChar - 'a']++;
        }

        // There can only be (N - K + 1) subarrays of size 'K'.
        for (int i = 0; i < (N - K + 1); i++)
        {

            // Now, create a auxiliary vector to store the frequence of character present in the current substring of size 'K'.
            vector<int> aux(26, 0);

            // Traverse through the current window of size 'K'.
            for (int j = 0; j < K; j++)
            {
                // Extract the current character from the string "text".
                char currChar = text[i + j];

                // Store it's frequence.
                aux[currChar - 'a']++;
            }

            // Now, just compare both of the vector "wordFreq" ("wordFreq", Stores the frequence of each character present in the string "word") and "aux" ("aux" Stores the frequence of each character present in the current subarray/substring).
            // And if both the vectors are equal, it means current substring is a anagram of string "word", because current substring has same characters as we have in the string "word".
            if (wordFreq == aux)
            {
                // Increment the count.
                cnt++;
            }
        }

        // return the answer.
        return cnt;
    }

    /* Optimized Approach: Using Sliding Window. */
    // Time Complexity: O(N) + O(K), where 'N' is the size of the string and 'K' is the window size.
    // Space Complexity: O(26), space used by auxiliary vector's.
    int search_Optimized(string word, string text)
    {
        // size of string "text".
        int N = text.size();

        // Now, here is size of window is same as the length of the string "word", because all the anagrams of word also have same length.
        // All the anagrams of a word have the same length. Anagrams are words or phrases that are formed by rearranging the letters of another word or phrase, using all the original letters exactly once. Since the total count of letters remains the same in anagrams, the length of the words remains the same as well.
        int K = word.size();

        // variable to store the count the occurence of anagrams of given word "word" in "text".
        int cnt = 0;

        // Store the frequence of each character present in the string "word". This will help us to compare the string "word" with the substrings that we are going to generate.
        vector<int> wordFreq(26, 0);
        for (int i = 0; i < K; i++)
        {
            // extract the current character.
            char currChar = word[i];

            // store the frequency of 'currChar' in frequence vector 'wordFreq'.
            wordFreq[currChar - 'a']++;
        }

        // Pointers.
        // 'Start' pointer will represent the starting point/index of 'k' size window.
        int start = 0;

        // 'End' pointer will represent the ending point/index of 'k' size window.
        int end = 0;

        // Auxiliary vector to store the frequence of character present in the current substring of size 'K'.
        vector<int> aux(26, 0);

        // Loop, end<N.
        while (end < N)
        {
            // Extract the current character.
            char currChar = text[end];

            // Store the frequency of 'currChar' in frequence vector 'aux'.
            aux[currChar - 'a']++;

            // 'windowSize' represent the total number of element in current window.
            // 'k' sized window has 'k' number of elements and 'windowSize' sized window has 'windowSize' number of elements.
            int windowSize = end - start + 1;

            // If 'windowSize' is less then 'k'.
            if (windowSize < K)
            {
                end++;
            }

            // when "windowSize == K", it means we hit the window size i.e., k.
            else if (windowSize == K)
            {
                // Now, at this point, our window size is equal to k, it means all the character present in this current substring of size k, the frequence of all these characters are stored inside our 'aux' frequncy vector.

                // Now, we just have to find whether this current substring is anagram of string "word" or not.

                // Now to check, just compare both of the vector "wordFreq" ("wordFreq", Stores the frequence of each character present in the string "word") and "aux" ("aux" Stores the frequence of each character present in the current subarray/substring).

                // And if both the vectors are equal, it means current substring is a anagram of string "word", because current substring has same characters as we have in the string "word".
                if (wordFreq == aux)
                {
                    // Increment the count.
                    cnt++;
                }

                // Now, we have to shift this window ahead, but before shifting this window ahead, we have to remove the starting charcater of current window form our frequency vector.
                aux[text[start] - 'a']--;

                // Now, move to the next window.
                start++;
                end++;
            }
        }

        // return the answer.
        return cnt;
    }

public:
    /* Question: Given a string "word" and a string "text". Return the count of the occurrences of anagrams of the word in the text. */
    int search(string word, string text)
    {
        // // Brute Force Approach.
        // return search_BruteForce(word, text);

        // Optimized Approach.
        return search_Optimized(word, text);
    }
};

int main(void)
{
    string text = "forxxorfxdofr";
    string word = "for";

    // Solution.
    Solution obj;
    cout << "Total Occurences: " << obj.search(word, text) << ".";
    return 0;
}