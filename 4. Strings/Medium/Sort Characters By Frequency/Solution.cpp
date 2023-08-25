#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n log(n)), where 'n' is the length of the string "str".
    // Space Compleixty: O(n) + O(n), space used by unordered_map and Priority Queue (Max Heap).
    string frequencySort(string str)
    {

        // This 'freqMap' map is used to store the frequency of each character in the input string.
        unordered_map<char, int> freqMap;

        // Store the frequency of each character in map.
        for (auto ch : str)
        {
            freqMap[ch]++;
        }

        // Declare a max heap and push all the characters with its frequency into the max heap.
        // I am using pair<int, char>, because max heap will sort the character according to the first block of pair and we need the character with maximum frequence at the top of the max heap.
        priority_queue<pair<int, char>> maxHeap;
        for (auto it : freqMap)
        {
            int frequency = it.second;
            char ch = it.first;

            maxHeap.push({frequency, ch});
        }

        // Declare a string to store answer.
        string ans;

        // Now, Traverse the max heap and store the answer.
        while (!maxHeap.empty())
        {
            // The character with maximum frequenct will present at the top of the Max Heap.

            // Frequency of Character.
            int freq = maxHeap.top().first;

            // Original Character.
            char ch = maxHeap.top().second;

            // Pop the top element of the max heap.
            maxHeap.pop();

            // Insert the character into the answer string 'freq' times.
            while (freq > 0)
            {
                ans.push_back(ch);
                freq--;
            }
        }

        // finally return answer.
        return ans;
    }
};

int main(void)
{
    string str = "tree";

    // Solution.
    Solution obj;
    cout << obj.frequencySort(str);
    return 0;
}