#include <bits/stdc++.h>
#include "MinHeapify.h"
using namespace std;

void printVec(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main(void)
{
    MIN_Heapify heapify;

    // Complete Binary Tree, represented in the form of array.
    // We have to convert this into Max Heap.
    vector<int> arr = {-1, 54, 53, 55, 52, 50};

    // size of array.
    int n = arr.size();

    // Max Heap Construction.
    // Traverse the array from back and start the construction of Max Heap from first Non-Leaf Node.
    for (int i = ((n / 2) + 1); i > 0; i--)
    {
        // place all non-leaf nodes in its correct position.
        heapify.minHeapify(i, n, arr);
    }

    /*
    Note:

    Time Compelxity of placing one node in it correct position is O(log(n)) and Time Compelxity of placing "n" node in it correct position is O(n*log(n)).

    Time Complexity of Building Heap (above for loop) is O(n), and Time Compelxity of placing one node in it correct position (heapify) is O(log(n)).

    So, Overall Time Complexity of Heapify Algorithm is O(n*log(n)).
    */

    printVec(arr);
}