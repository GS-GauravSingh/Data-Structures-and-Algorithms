/*
Heap sort is a sorting algorithm that sorts an array of elements by using a heap data structure. The algorithm works as follows:

1. First Step is to convert the given array into heap data structure either Min Heap or Max Heap.
2. Find the maximum (in a max heap) or minimum (in a min heap) element in the heap and place it at the end of the array.
3. Reduce the size of the heap by one.
4. Re-heapify the heap to maintain the heap property.
5. Repeat steps 2-4 until all elements have been extracted from the heap and placed in the sorted order in the array.

Note:-
1. Heap sort is an in-place algorithm.
2. Its typical implementation is not stable, but can be made stable.
3. Typically 2-3 times slower than well-implemented QuickSort.
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Heap Sort Class ------------------------------- */
class HEAPSORT
{
private:
    /*

    /* Heapify Algorithm for Max Heap. */
    /* It Takes input in 0-based indexing. */

    // idx: "idx" is the index of that node, which we have to place in its correct position in Max Heap.
    // n: "n" is the size of array.
    // arr: "arr" is a Complete Binary Tree, which is represented using array.
    // Time Complexity of Heapify Algorithm is O(n*log(n)).
    // Space Complexity of Heapify Algorithm is O(log(n)), O(log(n)) because of recursive stack space.
    void maxHeapify(int idx, int n, vector<int> &arr)
    {
        // we have to place this node in its correct position.
        int nodeIdx = idx;

        // In 0-Based Indexing,
        // Left Child: (2*i+1)th index.
        int leftChildIdx = 2 * idx + 1;

        // Right Child: (2*i+2)th index.
        int rightChildIdx = 2 * idx + 2;

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

public:
    /* Method to sort the array using Heap Sort. */
    // Time Complexity of Heap Sort is O(n*log(n)).
    // Space Complexity of Heap Sort is O(1).
    void heapSort(vector<int> &arr)
    {
        // Now, we have to repeat the below steps until the size of the array is not 1.
        int n = arr.size() - 1;
        while (n > 0)
        {
            // Step 2: After converting array into Max heap.
            // In Max Heap the maximum element is present at index 0 in vector, so swap the maximum element with the last element of the array.
            int &maximumElement = arr[0]; // getting the maximum element of Max Heap.
            int &lastElement = arr[n];    // getting the last element of Max Heap.

            // swapping the maximum element with the last element of the array.
            swap(maximumElement, lastElement);

            // Step 3: Node maximum element is placed at its correct postion i.e., last.
            // Skip the last element and place the rest of the elements in its correct position.
            // to skip the last element just decrement the size of array.
            n--;

            // Step 4: Now, After swapping, it is possible that the array does not statisfy the heap order property, so re-heapify the array.
            // We have to place the node at index 0 in its correct position.
            maxHeapify(0, n, arr);
        }
    }

    /* Method to convert array into Max Heap. */
    // Time Complexity of Heapify Algorithm is O(n*log(n)).
    // Space Complexity of Heapify Algorithm is O(log(n)), O(log(n)) because of recursive stack space.
    void convertIntoMaxHeap(vector<int> &arr)
    {
        // Step 1: First Step is to convert the given array into heap data structure either Min Heap or Max Heap.

        // I am converting the given array into Max Heap.
        // For converting the array into Max heap, we have to use heapify algorithm.

        int n = arr.size(); // size of array.

        // In 0-based indexing, leaf nodes start from n/2 to n-1, where n is the size of the array.
        for (int i = (n / 2); i >= 0; i--)
        {
            maxHeapify(i, n, arr);
        }
    }

    /* Method to print vector. */
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
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    HEAPSORT hp;
    hp.convertIntoMaxHeap(arr);
    hp.heapSort(arr);
    hp.printVec(arr);
}