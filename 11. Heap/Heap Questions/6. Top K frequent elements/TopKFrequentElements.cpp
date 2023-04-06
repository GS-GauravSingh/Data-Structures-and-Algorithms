#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* so we have to find such K elements whose frequency is maximum. */

    /* Approach: Using Map and Priority Queue (Min Heap), lets dry run this approach on one example to understand how this approach works.

    Example: arr[] = {1,1,1,3,2,2,4}, K = 2. In this example, we have to find k (k = 2) elements whose frequency is maximum.

    // Step 1: Declare an unordered_map and store frequency of each element in map.
    After storing the frequency of each element, our unordered_map would look like this,

    Map (Key = arr[i], value = frequency of arr[i])
    1 -> 3
    3 -> 1
    2 -> 2
    4 -> 1

    Now, from this map, we have to find the elements whose frequency is maximum, in this map we can clearly see that 1 and 2 are the element having maximum frequence.

    So, lets see how to extract 1 and 2 from the map, so to extract these value form map we have to use Min Heap.

    And we have to push a pair inside the Min Heap.
    First block of pair = frequency of arr[i].
    Second block of pair = arr[i].

    We are pushing the pair because min heap will sort the pairs according to the first block of pair.
    So the element having minimum frequency is present at the top of the min heap.

    Lets start pushing pairs from the map into the min heap.
    Map (Key = arr[i], value = frequency of arr[i])
    1 -> 3
    3 -> 1
    2 -> 2
    4 -> 1

    Pair,
    First block of pair = frequency of arr[i].
    Second block of pair = arr[i].

    1st pair = <3, 1>

    pushing first pair.
    Min Heap
    <3,1>

    after pushing, the size of max heap is not > K, so we do nothing in this case.


    2nd pair = <1, 3>
    pushing second pair.
    Min Heap
    <1,3>
    <3,1>

    after pushing, the size of max heap is not > K, so we do nothing in this case.

    3rd pair = <2, 2>
    pushing third pair.
    Min Heap
    <1,3>
    <2,2>
    <3,1>

    Now, after pushing, the size of max heap is > K (K = 2), so pop the top element of max heap, because the top element has the minimum frequence and we want only K element having maximum frequency.

    After popping
    Min Heap
    <2,2>
    <3,1>

    4th pair = <1, 4>
    pushing third pair.
    Min Heap
    <1, 4>
    <2,2>
    <3,1>

    Now, after pushing, the size of max heap is > K (K = 2), so pop the top element of max heap, because the top element has the minimum frequence and we want only K element having maximum frequency.

    After popping
    Min Heap
    <2,2>
    <3,1>

    loop ends here.

    After the above loop ends our max heap will contain the k elements whose frequency is maximum.

    Time Complexity of this approach is O(n*log(k)), and Space Complexity is O(k), because at any time our min heap does not contain more than k element.
    */

    /* Method to find Top K frequent elements. */
    void topKFrequent(vector<int> &nums, int k)
    {
        // Step 1: Declare an unordered_map and store frequency of each element in map.
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i];
            freq[element]++;
        }

        /*
        Step 2: Extract key, value pairs from map and push the pair into the min heap and the order of pairs is,
        First block of pair = frequency of arr[i].
        Second block of pair = arr[i].

        And after pushing the apir, check the size of max heap, if the size of max heap > k, in this case simply pop the top element of max heap.
        */

        // Min Heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // traversing the map.
        for (auto i = freq.begin(); i != freq.end(); i++)
        {
            // First block of pair = frequency of arr[i].
            // Second block of pair = arr[i].
            int frequency = i->second;
            int value = i->first;

            pq.push({frequency, value});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: After the above loop ends our max heap will contain the k elements whose frequency is maximum.
        while (!pq.empty())
        {
            cout << pq.top().second << " ";
            pq.pop();
        }
    }
};

int main(void)
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int K = 2;

    // Solution.
    Solution S;
    int k = 2;
    S.topKFrequent(nums, k);
}