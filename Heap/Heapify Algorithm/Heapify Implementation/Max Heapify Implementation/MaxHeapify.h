#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------- What is Heapify -------------------------------
What is Heapify Algorithm ?
Heapify is a process of converting an array into a heap data structure. A heap is a complete binary tree where the value of each node is greater than or equal to (in a max heap) or less than or equal to (in a min heap) the values of its children nodes.

Basically, in input, you have been given a Complete Binary Tree which is represented using arrays. So, heapify is the process of converting that Complete Binary Tree (CBT is represented using an array) into the heap data structure.


--------------------------------------- Leaf Nodes -----------------------------------
Leaf Nodes:
In 0-Based indexing:
    1. Leaf Nodes starts from index n/2 to n-1, where n is the size of the array or n is the number of nodes in Heap.

In 1-Based indexing:
1. If n = size of array, then,
    1.1. Leaf Nodes starts from index ( (n/2) + 1 ) to n-1, where n is the size of the array.

2. If n = number of nodes in Heap, then,
    2.1. Leaf Nodes starts from index ( (n/2) + 1 ) to n, where n is the number of nodes in Heap.


--------------------------------------- Important Point ---------------------------------
So, in Heapify what we are doing is, a Complete Binary Tree is given which is represented using an array and our task is to convert this CBT(which is represented using an array) into a heap either Max Heap or Min Heap.

I am using a Bottom-Up approach to convert the given array into the heap either Max Heap or Min Heap.

So, In the Bottom-Up approach, we start traversing the array from the back and skip all the leaf nodes and start the construction of heaf from the first non-leaf nodes.

Question: Why we are skipping the leaf nodes ?
Answer: We are skipping the leaf nodes because the leaf nodes do not have any children, they cannot violate the heap property. Hence, we can safely skip them during the heap construction process.

In Short, all leaf nodes are already statisfies the heap order preperty.
All leaf nodes in a heap data structure already satisfy the heap order property by definition and hence there is no need to perform any heapify operation on them.
*/

class MAX_Heapify
{
private:
public:
    /*
    --------------------------------- Note -----------------------------------------

    Time Compelxity of placing one node in it correct position is O(log(n)) and Time Compelxity of placing "n" node in it correct position is O(n*log(n)).

    Time Complexity of Building Heap is O(n), and Time Compelxity of placing one node in it correct position (heapify) is O(log(n)).

    So, Overall Time Complexity of Heapify Algorithm is O(n*log(n)).
    Space Complexity of Heapify Algorithm is O(log(n)), O(log(n)) because of recursive stack space.

    */

    /* Heapify Algorithm for Max Heap. */
    /* It Takes input in 1-based indexing. */

    // idx: "idx" is the index of that node, which we have to place in its correct position in Max Heap.
    // n: "n" is the size of array.
    // arr: "arr" is a Complete Binary Tree, which is represented using array.

    // Time Complexity of Heapify Algorithm is O(n*log(n)).
    // Space Complexity of Heapify Algorithm is O(log(n)), O(log(n)) because of recursive stack space.
    void maxHeapify(int idx, int n, vector<int> &arr)
    {
        // we have to place this node in its correct position.
        int nodeIdx = idx;

        // In 1-Based Indexing,
        // Left Child: (2*i)th index.
        int leftChildIdx = 2 * idx;

        // Right Child: (2*i+1)th index.
        int rightChildIdx = 2 * idx + 1;

        // In case of Max Heap, value of root node >= value of its child node.
        // Comparing with left child.
        if ((leftChildIdx < n) && (arr[nodeIdx] < arr[leftChildIdx]))
        {
            // If root node (arr[nodeIdx]) < child node (arr[leftChildIdx]), it means root node is not at its correct possition.

            // Update its index.
            nodeIdx = leftChildIdx;
        }

        // Comparing with right child.
        if ((rightChildIdx < n) && (arr[nodeIdx] < arr[rightChildIdx]))
        {
            // If root node (arr[nodeIdx]) < child node (arr[rightChildIdx]), it means root node is not at its correct possition.

            // Update its index.
            nodeIdx = rightChildIdx;
        }

        /* Now, simply check, if the index of the root node (nodeIdx) is updated or not.

        If the node is already in its correct position, in this case, the above 2 if conditions will not execute and the index of node is equal to idx i.e., nodeIdx = idx, and if the node has already in its correct position, then you have to nothing to do.

        But if the node is not in its correct position in this case, the above 2 if conditions will execute and the nodeIdx will points to the correct index of node (arr[idx]) and nodeIdx != idx, in this case, place the node (arr[idx]) to its correct postion and call recursion for rest of the case.
        */
        if (nodeIdx != idx)
        {
            swap(arr[idx], arr[nodeIdx]);
            maxHeapify(nodeIdx, n, arr);
        }
    }
};
