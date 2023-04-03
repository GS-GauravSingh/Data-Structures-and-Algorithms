/*
Given an array of N elements, where each element is at most K away from its target position, devise an algorithm that sorts in O(N log K) time.

Examples:

Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, K = 3
Output: arr[] = {2, 3, 5, 6, 8, 9, 10}
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /*
    Approach 1: Using Sorting, sort the given array.
    Time Complexity of Approach 1 is O(n log(n)) and space complexity, in case of Quick sort and Heap sort is O(log(n)), in case of Merge sort space complexity is O(n).

    Approach 2: Using Priority Queue (Min Heap), lets dry run this approach with one example to understand how does this approach works.


    Our Algorithm is:
    Step 1: Traverse the array using any loop.
    Step 2: While traversing,
            First, push the element (arr[i]) into the heap and check,

            if(the size of Min Heap is greater than k)
            {
                If size of Min heap > k, in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.
            }
    Step 3: After the above loop ends, one by one extract all the elements from Min Heap and push all the element into the answer vector.

    ----------------------------------- Dry Run -----------------------------------------
    Example: arr[] = {6, 5, 3, 2, 8, 10, 9}, K = 3.

    // pointer to traverse the array.
    Initially, i = 0,

    For i = 0,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        6
    
    ans vector = {}, and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 1,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        5
        6
    ans vector = {}, and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 2,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        3
        5
        6
    ans vector = {}, and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 3,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        2
        3
        5
        6
    Now, the size of min heap is greater than K (value of K = 3), so in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.

    ans vector = {2};

    After popping, our Min Heap would look like this,
    Min Heap
        3
        5
        6
    
    Question: Why we are storing and popping the top element of Min Heap, when size of min heap is > K ?
    Answer: because any element is present at most K away from its correct position and when the size of min heap is > K, our minimum element of sorted array is present at the top of the min heap.

    For i = 4,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        3
        5
        6
        8

    Now, the size of min heap is greater than K (value of K = 3), so in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.

    ans vector = {2, 3};

    After popping, our Min Heap would look like this,
    Min Heap
        5
        6
        8

    For i = 5,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        5
        6
        8
        10

    Now, the size of min heap is greater than K (value of K = 3), so in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.

    ans vector = {2, 3, 5};

    After popping, our Min Heap would look like this,
    Min Heap
        6
        8
        10

    For i = 6,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        6
        8
        9
        10

    Now, the size of min heap is greater than K (value of K = 3), so in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.

    ans vector = {2, 3, 5, 6};

    After popping, our Min Heap would look like this,
    Min Heap
        8
        9
        10

    loop ends here.

    After the above loop ends, one by one extract all the elements from Min Heap and push all the element into the answer vector.

    Min Heap
        8
        9
        10

    After extracting all elemnts form min heap and pushing them into the answer vector, or min heap is empty and our answer vector contains all elements in sorted order.
    ans vector = {2, 3, 5, 6, 8, 9, 10};

    Time Complexity of this approach is O(n*log(k)), and space complexity is O(k).
    */

    /* Method to return the sorted array. */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our min heap does not contain more than k element.
    vector<int> nearlySorted(vector<int> &arr, int K)
    {
        // Min Heap.
        priority_queue<int, vector<int>, greater<int>> pq;

        // vector to store answer (sorted array).
        vector<int> ans;

        // traversing the vector.
        for (int i = 0; i < arr.size(); i++)
        {
            // Step 1: push arr[i] into Min Heap.
            pq.push(arr[i]);

            // Step 2: Check the size of Min Heap.
            // If size of Min Heap is > K, in this case, store the top element of Min Heap in answer vector and then pop the top element from Min Heap.
            if (pq.size() > K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }

        // Step 3: After the above loop ends, one by one extract all the elements from Min Heap and push all the element into the answer vector.
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        // Step 4: return answer vector.
        return ans;
    }

    /* Method to print vector. */
    // Time Complexity: O(n), n is the size of vector.
    // Space Complexity: O(1).
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int K = 3;

    // Solution.
    Solution S;
    vector<int> ans = S.nearlySorted(arr, K);
    S.printVec(ans);
}