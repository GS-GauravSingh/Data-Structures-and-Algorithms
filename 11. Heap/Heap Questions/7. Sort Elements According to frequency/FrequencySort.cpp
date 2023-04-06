#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    // This question is almost same as previous question.

    // Time Complexity: O(n*log(n))
    // Space Complexity: O(n).
    void frequencySort(vector<int> &arr)
    {
        // Step 1: Declare an unordered_map and store frequency of each element in map.
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            int element = arr[i];
            freq[element]++;
        }

        /*
        Step 2: Extract key, value pairs from map and push all the pair into the max heap and the order of pairs is,
        First block of pair = frequency of arr[i].
        Second block of pair = arr[i].
        */

        // Max Heap.
        priority_queue<pair<int, int>> pq;

        // traversing the map.
        for (auto i = freq.begin(); i != freq.end(); i++)
        {
            // First block of pair = frequency of arr[i].
            // Second block of pair = arr[i].
            int frequency = i->second;
            int value = i->first;

            pq.push({frequency, value});
        }

        // Step 3: traverse through the Max Heap and print elements according to its frequency.
        // Max heap will sort the apir according to the first block of pair and first block of pair is storing the frequency, so the element having maximum frequency is present at the top of the max heap. 
        while (!pq.empty())
        {
            // getting the actual value.
            int element = pq.top().second;

            // getting the frequency of top element.
            int frequency = pq.top().first;

            // printing element according to its frequency.
            while (frequency > 0)
            {
                cout << element << " ";
                frequency--;
            }

            // popping the top element.
            pq.pop();
        }
    }
};

int main(void)
{
    vector<int> arr = {1, 1, 1, 3, 2, 2, 4};

    // Soltion.
    Solution S;
    S.frequencySort(arr);
}