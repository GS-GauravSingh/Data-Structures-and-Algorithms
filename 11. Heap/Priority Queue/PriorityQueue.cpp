#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    /*

    Question: What is Priority Queue ?
    Answer: Priority Queue in C++ STL is the implementation of Heap Data Structure. You need to include the queue library to use the priority queue.

    Syntax: priority_queue<data type> variableName;
    Example: priority_queue<int> pq; // it creates Max Heap by default.

    Note: a priority queue is implemented as max heap by default in C++ but, it also provides us an option to change it to min heap by passing another parameter while creating a priority queue.

    Syntax: priority_queue <int, vector<int>, greater<int>> pq; // min heap.
    */

    // Creating Max Heap.
    // A priority queue is implemented as max heap by default in C++.
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    // To check if it is a max heap or not, just print the element present at the top of the maxheap.
    // because the maximum element is present at the top of the max heap.

    cout << "Maximum Element is " << maxHeap.top() << ".\n"; // Output: 5

    // Creating Min Heap.
    // A priority queue is implemented as max heap by default in C++  but, it also provides us an option to change it to min heap by passing another parameter while creating a priority queue.
    // Syntax: priority_queue <int, vector<int>, greater<int>> pq; // min heap.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    // To check if it is a min heap or not, just print the element present at the top of the minheap.
    // because the minimum element is present at the top of the min heap.

    cout << "Minimum Element is " << minHeap.top() << ".\n"; // Output: 5
}