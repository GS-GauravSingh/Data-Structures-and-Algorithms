#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /*
    Approach 1: Using Sorting, Sort the give array and return kth smallest element.
    Time complexity of this approach is O(n*log(n)), and space complexity is O(1).

    Approach 2: Using Priority Queue (Max Heap), lets dry run this approach with one example to understand how does this approach works.

    Our Algorithm is:
    Step 1: Traverse the array using any loop.
    Step 2: While traversing,
            First, push the element (arr[i]) into the heap and check,

            if(the size of Max Heap is greater than k)
            {
                If size of Max heap > k, in this case simply pop the top element of Max Heap.
            }
    Step 3: After the above loop ends, our kth smallest element is present at the top of the Max Heap.

    Note: Kth smallest element means, we have to find the maximum element among the first k smallest elements. So, at any point of time, our Max Heap will only have k number of elements and elements in Max Heap are pushed according to Heap order preperty , which says that in Max Heap the value of root node >= the value of its child node, it means the maximum element is present at the top of the Max Heap.

    And When the size of Max Heap is > k, we pop the top element form the Max Heap, in this way, what happens is, when the loop ends, our Max Heap will contains the k smallest element and at the top of the Max Heap, the maximum element among the first k smallest elements is present at the top of the Max Heap.

    Example: Dry-Run:
    array = {7, 10, 4, 3, 20, 15};
    K = 3;

    // pointer to traverse the array.
    Initially, i = 0,

    For i = 0,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        7
    and the size of max heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 1,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        10
        7
    and the size of max heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 2,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        10
        7
        4
    and the size of max heap is not greater than K (value of K = 3), so we do nothing in this case.

    For i = 3,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        10
        7
        4
        3
    and the size of max heap is greater than K (value of K = 3), so in this case, we pop the top element of the Max Heap.

    Question: Why we are popping the top element of Max Heap, when size of max heap is > K ?
    Answer: Because we only want k smallest elements in our Min Heap, so that the maximum among the first k smallest element is present at the top of the max heap.

    So, after popping, our Max Heap would look like this,
        Max Heap
        7
        4
        3

    For i = 4,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        20
        7
        4
        3
    and the size of max heap is greater than K (value of K = 3), so in this case, we pop the top element of the Max Heap.

    So, after popping, our Max Heap would look like this,
        Max Heap
        7
        4
        3

    For i = 5,  First, We insert arr[i] into the max heap. And in Max Heap, maximum element is present at the top.
    Max Heap
        15
        7
        4
        3
    and the size of max heap is greater than K (value of K = 3), so in this case, we pop the top element of the Max Heap.

    So, after popping, our Max Heap would look like this,
        Max Heap
        7
        4
        3

    loop ends here.

    Our answer is present at the top of the Max Heap.

    So, at any time our max heap does not contain more than k element, so the time complexity of the approach is O(n*log(k)) and space complexity of this approach is O(k), because we are using Max Heap data structure (Priority Queue).

    */
    /* Method to find kth smallest element in unsorted array. */
    // Time Complexity: O(n*log(k))
    // Space Complexity: O(k), at any time our max heap does not contain more than k element.
    int kthSmallest(vector<int> arr, int k)
    {
        // Max Heap.
        priority_queue<int> pq;

        // Traversing the array.
        for (int i = 0; i < arr.size(); i++)
        {
            // Step 1: push arr[i] into Max Heap.
            pq.push(arr[i]);

            // Step 2: Check the size of Max Heap.
            // If size of Max Heap is > K, in this case pop the top element of Max Heap.
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // Step 3: After the above loop ends, our kth smallest element is present at the top of the Max Heap.
        return pq.top();
    }
};

int main(void)
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // Solution.
    Solution S;
    cout << "Kth Smallest element is " << S.kthSmallest(arr, k) << ".\n";
}