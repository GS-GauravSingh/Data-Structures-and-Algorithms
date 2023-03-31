#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Implementing Min Heap using Array. --------------------------------- */
/*

# in 1-based indexing,
Parent Node is present at: i / 2;
Left Child is present at:  2 * i;
Right Child is present at: 2 * i + 1;

# in 0-based indexing,
Parent Node is present at: (i-1) / 2;
Left Child is present at:  2 * i + 1;
Right Child is present at: 2 * i + 2;


Time Complexity of Insertion and Deletion is O(log(n)).
*/

class Min_Heap
{
private:
    /* Data Members or Properties of Min_Heap Class. */

    // Instead of Using static array, i am using dynamic array to implement heap, because dynamic array can grow in runtime.
    vector<int> arr;

public:
    /* Methods or Behavior of Min_Heap Class. */

    // Constructor.
    Min_Heap(int default_size = 10)
    {
        // setting the size of array.
        // Adding 1 in size because i am using 1-based indexing to implement heap.
        arr.reserve(default_size + 1);

        // blocking the 0th index, because i am using 1-based indexing to implement heap.
        arr.push_back(-1);
    }

    /*
    So, basically we visualize Heap as tree but we store its elements in the memory using arrays.

    In 0-based indexing,
    Parent Node: ((i-1)/2)th index.
    Left Child: (2*i+1)th index.
    Right Child: (2*i+2)th index.

    In 1-based indexing,
    Parent Node: (i/2)th index.
    Left Child: (2*i)th index.
    Right Child: (2*i+1)th index.



    Example Min HEAP:
                                            20
                                          /    \
                                        30     40
                                      /   \
                                    50    60

    index:-          0  1  2  3  4  5
    array/vector = {-1,20,30,40,50,60}; // blocking the 0th index.

    For node present at 1 index i.e., 20.
    node = 20, (i = 1).

    Left child of 20 = (2 * i)th index,
    => 2 * 1 = 2, at index 2, in vector, 30 is present and the left child of 20 is 30.

    Right child of 20 = (2 * i + 1)th index,
    => 2 * 1 + 1 = 3, at index 3, in vector, 40 is present and the right child of 20 is 40.

    Parent Node of 20 = (i/2)th index,
    => 1/2 = 0.5, when index is less than 0, then it means you are finding the parent of root node and root node has no parent.
    => 0.5 is not a valid index, so there is no parent of 20.



    For node present at 2 index i.e., 30.
    node = 30, (i = 2).

    Left child of 30 = (2 * i)th index,
    => 2 * 2 = 4, at index 4, in vector, 50 is present and the left child of 30 is 50.

    Right child of 30 = (2 * i + 1)th index,
    => 2 * 2 + 1 = 5, at index 5, in vector, 60 is present and the right child of 30 is 60.

    Parent node of 30 = (i/2)th index,
    => 2/2 = 1, at index 1, in vector, 20 is present and the parent node of 30 is 20.

    Note: In 0-based indexing, from index (n/2) to index (n-1), all the nodes are leaf nodes, where n is the size of array in integers.

    Note: In 1-based indexing, from index ((n/2) + 1) to index (n-1), all the nodes are leaf nodes, where n is the size of array in integers.

    => So, in this example, size of vector is 6, so, n = 6.
    => Now, from from index ((n/2) + 1) to index (n-1), all the nodes are leaf nodes.
    => ((n/2) + 1) => ((6/2)+1) = 3+1 = 4.
    => (n-1) = 6-1 = 5.
    => From index 4 to index 5, all nodes are leaf nodes.
    => In vector, value present at index 4 to 5 are 50 and 60, so 50 and 60 are leaf nodes and you can verify it through the above tree preview.


    ----------------------------- Insertion in Heap -----------------------------------------------

    Let's perform Insertion:
    Example MAX HEAP:-
                                            20
                                          /    \
                                        30     40
                                      /   \
                                    50    60

    index:-          0  1  2  3  4  5
    array/vector = {-1,20,30,40,50,60};

    Suppose, We have to insert, let's say 10 in our MIN Heap. Follow the below steps to insert,
    Step 1: insert that value at the end of our vector i.e., push_back(value).
    Step 2: place the inserted value to its correct position.

    ----------------- DRY RUN ------------------------
    Step 1: insert that value at the end of our vector i.e., push_back(value).


    after push_back(10) operation in vector,
    index:-          0  1  2  3  4  5  6
    array/vector = {-1,20,30,40,50,60, 10};

    visualize tree:-
                                            20
                                          /    \
                                        30     40
                                      /   \   /
                                    50    60 10


    Step 2:- place the inserted value to its correct position.

    Now, to place 10 to its correct position, compare the inserted value with its parent node. In case of Min Heap value of parent Node <= value of its child nodes and In case of Max Heap value of parent Node >= value of its child nodes.

    ------------------ Placing Inserted Value to its Correct Position ---------------
    index:-          0  1  2  3  4  5  6
    array/vector = {-1,20,30,40,50,60, 10};
    visualize tree:
                                            20
                                          /    \
                                        30     40
                                      /   \   /
                                    50    60 10

    Parent node of 10 is present at (i/2)th index
    Index of 10 is 6, so i = 6.
    ==> i/2 = 6/2 = 3, Parent node of 10 is present at 3rd index and 40 is present at index 3.
    ==> Parent of 10 is 40.

    Now, This is a Inplementation of Min Heap and In case of Min Heap value of parent Node <= value of its child nodes.

    Comparing Inserted Value (10) with its parent 40.
    ==> Parent Node is 40 and Child Node is 10.
    ==> Child node is < Parent Node, it means 10 is not at it correct position, so, swap it with its parent node.

    Parent of 10 is 40. So, acc. to Min Heap root node is always <= it child nodes.
    swap(10,40);

    index:-          0  1  2  3  4  5  6
    array/vector = {-1,20,30,10,50,60, 40};
    visualize tree:
                                            20
                                          /    \
                                        30     10
                                      /   \   /
                                    50    60 40
    Now, at this point 10 is not placed at correct position, so compare 10 again with its parent node.

    Parent node of 10 is present at (i/2)th index
    Index of 10 is 3, so i = 3.
    ==> i/2 = 3/2 = 1, Parent node of 10 is present at 1 index and 20 is present at index 1.
    ==> Parent of 10 is 20.

    Comparing Inserted Value (10) with its parent 20.
    ==> Parent Node is 20 and Child Node is 10.
    ==> Child node is < Parent Node, it means 10 is not at it correct position, so, swap it with its parent node.

    Parent of 10 is 20. So, acc. to Min Heap root node is always <= it child nodes.
    swap(10,20);

    index:           0  1  2  3  4  5  6
    array/vector = {-1,10,30,20,50,60, 40};
    visualize tree:
                                            10
                                          /    \
                                        30     20
                                      /   \   /
                                    50    60 40

    see, 10 is place at it's correct position.

    Note: you have to repeat this step 2 until the inserted value is placed at its correct position.
    */

    /* Method to Push and Element into the Min Heap. */
    // Time Complexity of Insertion is O(log(n)).
    // Space Complexity of Insertion is O(1).
    void push(int value)
    {
        // Step 1: insert that value at the end of our vector i.e., push_back(value).
        arr.push_back(value);

        // Step 2: place the inserted value to its correct position.
        // getting the index of inserted value.
        int indexOfInsertedValue = arr.size() - 1;

        // placing the value to its correct position.
        // indexOfInsertedValue > 1, greater than 1, because i am using 1-based indexing to impelement heap.
        // And if indexOfInsertedValue is 1, it means it is a root node and root node has no parent, root node is already placed at its correct position.
        while (indexOfInsertedValue > 1)
        {
            // getting the index of parent node of inserted value.
            // In 1-based indexing, Parent Node = (i/2)th index.
            int indexOfParentNode = indexOfInsertedValue / 2;

            // Comparing the inserted value with its parent.
            // In case of Max Heap value of parent Node >= value of its child nodes.
            int &childNode = arr[indexOfInsertedValue];
            int &parentNode = arr[indexOfParentNode];

            // If value of childNode < parentNode, it means inserted value is not at its correct position.
            // So swap the inserted value with its parent node.
            if (childNode < parentNode)
            {
                swap(childNode, parentNode);

                // after swapping, the index of inserted value gets changed.
                // Inserted value will move to the index of its parent node and,
                // Parent Node will move to the index of its Child Node i.e., inserted value.

                // Now update the index of inserted value.
                indexOfInsertedValue = indexOfParentNode;
            }

            // If value of childNode < parentNode, it means inserted value is at its correct position.
            // simply return from here.
            else
            {
                return;
            }
        }
    }

    /*
    -------------------------------- Deletion in Min Heap -----------------------------------

    Let's perform Deletion: Remember always perfrom deletion from root node.

    Example:
    index:           0  1  2  3  4  5  6
    array/vector = {-1,10,30,20,50,60, 40};
    visualize tree:
                                            10
                                          /    \
                                        30     20
                                      /   \   /
                                    50    60 40


    Let's start deletion, as we know that in Heap we always perform deletion from root node. So, lets delete root node i.e., 10.

    Steps For Deletion:
    Step 1: Replace or Swap the value of last node with root node.
    Step 2: Remove the last node from vector i.e., pop_back().
    Step 3: Place Root Node to its correct position.

    --------------------------- DRY RUN --------------------------------------
    Step 1:- Replace or Swap the value of last node with root node.

    Our vector looks like this,
    index:           0  1  2  3  4  5  6
    array/vector = {-1,10,30,20,50,60, 40};
    visualize tree:
                                            10
                                          /    \
                                        30     20
                                      /   \   /
                                    50    60 40

    Now, in our vector we clearly see that, the last nodes is 40 and the root node is 10.
    So, Replace or Swap the value of last node with root node.

    Operation (Replacing value of last node with root node):
    // arr[1] = arr[n-1], or you can swap the values also like this, swap(arr[1], arr[n-1]);
    // so i chose swapping, and i swap the values.
    swap(arr[1], arr[n-1]);

    After the above operation, our vector would look like this,
    index:           0  1  2  3  4  5  6
    array/vector = {-1,40,30,20,50,60, 10};
    visualize tree:
                                            40
                                          /    \
                                        30     20
                                      /   \   /
                                    50    60 10


    Step 2: Remove the last node from vector i.e., pop_back().
    index:           0  1  2  3  4  5  6
    array/vector = {-1,40,30,20,50,60, 10};
    visualize tree:
                                            40
                                          /    \
                                        30     20
                                      /   \   /
                                    50    60 10
    Operation:
    pop_back();

    After removing,
    index:           0  1  2  3  4  5 
    array/vector = {-1,40,30,20,50,60};
    visualize tree:
                                            40
                                          /    \
                                        30     20
                                      /   \  
                                    50    60



    Step 3:- Place Root Node to its correct position.
    index:           0  1  2  3  4  5 
    array/vector = {-1,40,30,20,50,60};
    visualize tree:
                                            40
                                          /    \
                                        30     20
                                      /   \  
                                    50    60


    For placing Root node to its correct position, we have to compare root node with its child nodes and In case of Min Heap value of parent Node <= value of its child nodes.

    Root Node = 40, (i = 1).
    Left Child of 40 is at (2*i)th index i.e., 2*1 = 2, left child of 40 is present at index 2 and at index 2, 30 is present so the left child of 40 is 30.

    Right Child of 40 is at (2*i+1)th index i.e., 2*1+1 = 3, right child of 40 is present at index 3 and at index 3, 20 is present so the right child of 40 is 20.

    Now, we have to compare root node with both of its child nodes.

    Comparing root node with its left child node.
    Root Node = 40.
    Left Child = 30.

    In case of Min Heap value of parent Node <= value of its child nodes.

    Root Node > Child Node, it means root node is not at its correct position, so we swap the value of root node with its left child.

    after swapping,
    index:           0  1  2  3  4  5 
    array/vector = {-1,30,40,20,50,60};
    visualize tree:
                                            30
                                          /    \
                                        40     20
                                      /   \  
                                    50    60

    See, 40 is placed at its correct position.

    Note: you have to repeat this step 3 until the root node is placed at its correct position.
    */

    /* Method to Pop Element from Min Heap. We always perform Deletion from Root Node. */
    // Time Complexity of Deletion is O(log(n)).
    // Space Complexity of Deletion is O(1).
    void pop()
    {
        // Base Case
        if (arr.size() == 1)
        {
            cout << "Nothing to Delete, Heap is already empty.\n";
            return;
        }

        // Step 1: Replace or Swap the value of last node with root node.
        int &rootNode = arr[1];              // getting the value of root node.
        int &lastNode = arr[arr.size() - 1]; // getting the value of last node.
        swap(rootNode, lastNode);            // swapping the value of last node with root node.

        // Step 2: Remove the last node from vector i.e., pop_back().
        arr.pop_back(); // last node removed.

        // Step 3: Place Root Node to its correct position.
        int indexOfRootNode = 1;
        while (indexOfRootNode < arr.size())
        {
            // getting the index of left child of root.
            // In 1-based indexing, Left Child = (2*i)th index.
            int leftChildIndex = 2 * indexOfRootNode;
            int &leftChidOfRoot = arr[leftChildIndex];

            // getting the index of right child of root.
            // In 1-based indexing, Right Child = (2*i+1)th index.
            int rightChildIndex = 2 * indexOfRootNode + 1;
            int &rightChildOfRoot = arr[rightChildIndex];

            // In case of Min Heap value of parent Node <= value of its child nodes.
            int &rootNode = arr[indexOfRootNode]; // getting the value of root node.

            // Comparing root with left child.
            if ((leftChildIndex < arr.size()) && (leftChidOfRoot < rootNode))
            {
                swap(leftChidOfRoot, rootNode);

                // after swapping our root node will be at index of left child.
                // after swapping our left child will be at index of root node.
                // so update the index of root node.
                indexOfRootNode = leftChildIndex;
            }

            // Comparing root with right child.
            else if ((rightChildIndex < arr.size()) && (rightChildOfRoot < rootNode))
            {
                swap(rightChildOfRoot, rootNode);

                // after swapping our root node will be at index of right child.
                // after swapping our right child will be at index of root node.
                // so update the index of root node.
                indexOfRootNode = rightChildIndex;
            }
            else
            {
                // if root node has greater value (>=) than its child nodes,
                // it means root node is placed at it correct position, so simply return from here.
                return;
            }
        }
    }

    /* Method to Print Heap/Vector elements. */
    void print()
    {
        cout << "Size of Heap: " << arr.size() << "." << endl;
        cout << "Parent Node: (i/2)the index, Left Child: (2*i)th index, Right Child: (2*i+1)th index.\n";
        cout << "All the above indexes are according to 1-based index.\n";
        cout << "Min Heap Elements => ";
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
