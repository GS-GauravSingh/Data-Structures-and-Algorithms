#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /*
    Approach 1: Using Sorting, Sort the give array and return kth Largest element.
    Time complexity of this approach is O(n*log(n)), and space complexity is O(1).

    Approach 2: Using Priority Queue (Min Heap), lets dry run this approach with one example to understand how does this approach works.

    Our Algorithm is:
    Step 1: Traverse the array using any loop.
    Step 2: While traversing,
            First, push the element (arr[i]) into the heap and check,

            if(the size of Min Heap is greater than k)
            {
                If size of Min heap > k, in this case simply pop the top element of Max Heap.
            }
    Step 3: After the above loop ends, our kth Largest element is present at the top of the Min Heap.

    Note: Kth Largest element means, we have to find the minimum element among the first k largest elements. So, at any point of time, our Min Heap will only have k number of elements and elements in Min Heap are pushed according to Heap order preperty , which says that in Min Heap the value of root node <= the value of its child node, it means the minimum element is present at the top of the Min Heap.

    And When the size of Min Heap is > k, we pop the top element form the Min Heap, in this way, what happens is, when the loop ends, our Min Heap will contains the k largest elements and at the top of the Min Heap, the minimum element among the first k largest elements is present at the top of the Min Heap.

    Example: Dry-Run:
    array = {7, 10, 4, 3, 20, 15};
    K = 3;

    // pointer to traverse the array.
    Initially, i = 0,

    For i = 0,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        7
    and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 1,  First, We insert arr[i] into the max heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        7
        10
    and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 2,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        4
        7
        10
    and the size of min heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 3,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        3
        4
        7
        10
    and the size of min heap is greater than K (value of K = 3), so in this case, we pop the top element of the Min Heap.

    Question: Why we are popping the top element of Min Heap, when size of min heap is > K ?
    Answer: Because we only want k largest elements in our Min Heap, so that the minimum among the first k largest element is present at the top of the min heap.

    So, after popping, our Min Heap would look like this,
    Min Heap
        4
        7
        10

    For i = 4,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        4
        7
        10
        20
    and the size of min heap is greater than K (value of K = 3), so in this case, we pop the top element of the Max Heap.

    So, after popping, our Min Heap would look like this,
    Min Heap
        7
        10
        20


    For i = 5,  First, We insert arr[i] into the min heap. And in Min Heap, minimum element is present at the top.
    Min Heap
        7
        10
        15
        20
    and the size of min heap is greater than K (value of K = 3), so in this case, we pop the top element of the Max Heap.

    So, after popping, our Min Heap would look like this,
    Min Heap
        10
        15
        20

    loop ends here.

    Our answer is present at the top of the Min Heap.

    So, at any time our max heap does not contain more than k element, so the time complexity of the approach is O(n*log(k)) and space complexity of this approach is O(k), because we are using Min Heap data structure (Priority Queue).

    */
    /* Method to find kth Largest element in unsorted array. */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our min heap does not contain more than k element.
    int kthLargest(vector<int> arr, int k)
    {
        // Min Heap.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Traversing the array.
        for (int i = 0; i < arr.size(); i++)
        {
            // Step 1: push arr[i] into Min Heap.
            pq.push(arr[i]);

            // Step 2: Check the size of Min Heap.
            // If size of Min Heap is > K, in this case pop the top element of Min Heap.
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: After the above loop ends, our kth largest element is present at the top of the Min Heap.
        return pq.top();
    }
};

int main(void)
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // Solution.
    Solution S;
    cout << "Kth Largest element is " << S.kthLargest(arr, k) << ".\n";
}