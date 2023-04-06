/*
Given a integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Approach:  Using Priority Queue (Max Heap).

    Example: arr = {5,6,7,8,9}, K = 3, X = 7.

    Now, insted of push a value (arr[i]) into max heap, we have to push a pair and
    the first pair will contain the absolute value of arr[i]-x, 
    the second block of paire will conatin the actual value (arr[i]).

    The first pair will contain the absolute value of arr[i]-x, because max heap will sort the array accoring to the first block of pair and the top of the max heap will contain the pair having maximum difference.

    // Pointer to traverse array.
    initially i = 0.

    For i = 0, arr[0] = 5, K = 3, X = 7.
    Our pair is {abs(5-7), 5} => {2,5}.

    Max Heap
    <2,5>
    And the size of Max Heap is not > K, so we do nothing in this case.


    For i = 1, arr[1] = 6, K = 3, X = 7.
    Our pair is {abs(6-7), 6} => {1,6}.
    Max Heap
    <2,5>
    <1,6>

    And the size of Max Heap is not > K, so we do nothing in this case.

    For i = 2, arr[2] = 7, K = 3, X = 7.
    Our pair is {abs(7-7), 7} => {0,7}.

    Max Heap
    <2,5>
    <1,6>
    <0,7>
    And the size of Max Heap is not > K, so we do nothing in this case.

    For i = 3, arr[3] = 8, K = 3, X = 7.
    Our pair is {abs(8-7), 8} => {1,8}.

    Max Heap
    <2,5>
    <1,8>
    <1,6>
    <0,7>

    Now, the size of Max Heap is > K, so pop the top element of max heap, because the top pair will heav the maximum frequency.

    After popping,
    Max Heap
    <1,8>
    <1,6>
    <0,7>

    For i = 4, arr[4] = 9, K = 3, X = 7.
    Our pair is {abs(9-7), 9} => {2,9}.

    Max Heap
    <2,9>
    <1,8>
    <1,6>
    <0,7>

    Now, the size of Max Heap is > K, so pop the top element of max heap, because the top pair will heav the maximum frequency.

    After popping,
    Max Heap
    <1,8>
    <1,6>
    <0,7>

    loop ends here.

    After the above loop ends, our Max heap will contains the K closest element to X.

    Max Heap
    <1,8>
    <1,6>
    <0,7>

    So, 8,6, and 7 are the K (K = 3) closest element to X (X = 7).

    Time Complexity of this approach is O(n*log(k)), and Space Complexity is O(k), because at any time our min heap does not contain more than k element.
    */
   
    /* Approach:  Using Priority Queue (Max Heap). */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our min heap does not contain more than k element.
    void KClosests(vector<int> arr, int K, int X)
    {
        // Max Heap
        // The first block of the pair contains the absolute value of arr[i]-x, arr[i]-x, because any number which is closest to X has the minimum difference with X, it means jo bhi number X ke closest hoga, us number of difference X ke saath minimum aayega.

        // The second block of pair contains the actual value arr[i].
        priority_queue<pair<int, int>> pq;

        // traverseing the array.
        for (int i = 0; i < arr.size(); i++)
        {
            // Step 1: push pair into the Max Heap.
            pq.push({abs(arr[i] - X), arr[i]});

            // Step 2: check the sie of max heap.
            // If the size of Max Heap > K, simply pop the top element from max heap.
            // Because this is max heap and the top element of max heap will have the maximum difference with X.
            if (pq.size() > K)
            {
                pq.pop();
            }
        }

        // Step 3: After the above loop end, our max heap will contain the K closest element to X.
        while (!pq.empty())
        {
            cout << pq.top().second << " ";
            pq.pop();
        }
    }
};

int main(void)
{
    vector<int> arr = {5, 6, 7, 8, 9};
    int K = 3;
    int X = 7;

    // Solution.
    Solution S;
    S.KClosests(arr, K, X);
}