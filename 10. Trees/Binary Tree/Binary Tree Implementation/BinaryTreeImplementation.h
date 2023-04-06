/*

Binary Tree:- A tree is called Binary Tress, if each node has 0 child, 1 child or 2 child. Empty tree is also a valid binary tree.

In Short:-
Binary Tree => each node has <= 2 child.


There are 5 common ways of traversing the nodes of a Binary Tree, namely:
1. In order Traversal (Order of Printing/Traversing the Binary Tree => Left, Root, Right)
2. Pre Order Traversal (Order of Printing/Traversing the Binary Tree => Root, Left, Right).
3. Post Order Traversal (Order of Printing/Traversing the Binary Tree => Left, Right, Root)
4. Level Order Traversal (Level Wise Traversing).
5. Morris Traversal.

Time and Space Complexities of Binary Tree Traversals :-
1. InOrder Traversal :-
Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
Space Complexity:- O(h), h is the height of the tree.

2. PreOrder Traversal :-
Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
Space Complexity:- O(h), h is the height of the tree.

3. PostOrder Traversal :-
Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
Space Complexity:- O(h), h is the height of the tree.

4. LevelOrder Traversal :-
Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
Space Complexity:- O(n), n is the size of queue.

5. Morris Traversal
Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
Space Complexity:- O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/* Node Structure for Binary Tree. */
class Node
{
private:
public:
    /* Data Members or Properties of the Node Class. */

    /* Each Node in the Binary Tree has 3 attributes,
    1. Data/Value.
    2. Left Child (Pointer to left child).
    3. Right Child (Pointer to right child).
    */
    int data;
    Node *leftChild;
    Node *rightChild;

    /* Methods or Behavior of the Node Class. */
    // Default Constructor.
    Node()
    {
        this->data = 0;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    // Parameterized Constructor.
    Node(int data)
    {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

/* Binary Tree Class. */
class BinaryTree
{
private:
    /* Data Members or Properties of the Node Class. */
public:
    /* Methods or Behavior of the Node Class. */

    /*
    1st Recursive Method To Build Binary Tree:-

    PreOrder Build :- In PreOrder Build, First we build the root node, then we build the left child, and then we build the right child, this way of building tree is know as Pre-order Build.

    PreOrder Build :- Order (Root Node, Left Node, Right Node).
    */

    Node *buildTreePreOrder(Node *&root)
    {
        // Step 1 :- getting the data for node.

        cout << "Enter Data for Node : \n";
        int value;
        cin >> value;

        // Step 2 :- Creat a node with given data.
        root = new Node(value);

        // Step 3 :- setting up the delimiter. Delimiter means breaking point.
        // -1 represent NULL.
        if (value == -1)
        {
            return NULL;
        }

        // Step 4 :- get the value for left child and make connections.
        cout << "Enter the value for the left child of " << root->data << ", ";
        root->leftChild = buildTreePreOrder(root->leftChild);

        // Step 5 :- get the value for right child and make connections.
        cout << "Enter the value for the right child of " << root->data << ", ";
        root->rightChild = buildTreePreOrder(root->rightChild);

        // Step 6 :- for a particular root node, when both left and child pointer are set, then return the root node.
        return root;
    }

    /*
    2nd Recursive Method To Build Binary Tree :-  Level Order Build
    */
    void buildTreeLevelOrder(Node *&root)
    {
        // 1. Declaring the queue of type Node*.
        queue<Node *> q;

        // 2. Initially our root node will be NULL. So, first get the data for root node, create a root node with given value.
        // getting the data for the root node.
        cout << "Enter Data for Root Node : ";
        int dataForRoot;
        cin >> dataForRoot;

        // creating root node with the give data.
        root = new Node(dataForRoot);

        // 3. Now, push root node into the queue.
        q.push(root);

        // 4. run a loop while q is not empty.
        while (!q.empty())
        {
            // 4.1. store the front node present at the queue (Node* frontNode = q.front()).
            Node *frontNode = q.front();

            // 4.2. pop the front element of the queue. (q.pop()).
            q.pop();

            // 4.3. get the data for th left child of front node, create a node for left child, make connections and then push left child into the queue.
            cout << "Enter data for the left child of " << frontNode->data << " : ";

            // getting data for left child of frontNode.
            int dataForLeftChild;
            cin >> dataForLeftChild;

            if (dataForLeftChild != -1)
            {
                frontNode->leftChild = new Node(dataForLeftChild);
                q.push(frontNode->leftChild);
            }

            // 4.3. get the data for th right child of front node, create a node for right child, make connections and then push right child into the queue.

            cout << "Enter data for the right child of " << frontNode->data << " : ";
            int dataForRightChild;
            cin >> dataForRightChild;

            if (dataForRightChild != -1)
            {
                frontNode->rightChild = new Node(dataForRightChild);
                q.push(frontNode->rightChild);
            }
        }
    }

    /* ----------------------------------- All Binary Tree Traversal. ------------------------------ */

    /* Level-Order Traversal (Order of Traversing: Level Wise). */
    /*
    LevelOrder Traversal also Known as Breadth First Search (BFS),Level order traversal means printing in levels, It means first we need to print the root node present at level 0, then we need to print all elements present at level 1, then level 2, level 3 and so on.

    Approach:- using Queue.
    Step 1. declare queue of type node*.  queue<node*> q;
    Step 2. push root node into queue, because at first root node is printed.
    q.push(root);
    Step 3. run a loop while queue is not empty and do the following things,
        3.1. store the front node present at queue (Node* temp = q.front()).
        3.2. pop the front element of queue. (q.pop()).
        3.3. print the data present at front (cout<<temp -> data).
        3.4. push the children nodes of front node (store at temp) present at queue in the queue if it is not NULL.

    when queue is empty all elements will be printed in single line.

    To get the output in levels, you need a delimiter that denotes the ending of particular level.

    Time Complexity:- O(n), n is the number of nodes in the Binary Tree.
    Space Complexity:- O(n), n is the size of queue.
    */

    void LevelOrderTraversal(Node *root)
    {
        // Step 1. declare queue of type node*.  (queue<node*> q)
        queue<Node *> q;

        // Step 2. push root node into the queue, because at first we need to print the root node.
        q.push(root);

        // delimiter representing the end of level 0. this is just for formatting the output.
        q.push(NULL);

        // Step 3. run a loop while queue is not empty and do the following things,
        while (!q.empty())
        {
            // Step 3.1. store the front node present at the queue (Node* frontNode = q.front()).
            Node *frontNode = q.front();

            // Formatting the output.
            if (frontNode == NULL)
            {
                // If FrontNode == NULL, it means the current level has ended and our queue will contain the child nodes of the nodes present at the current level.

                // Now, when the current level has ended, we have to print a new line.
                cout << "\n";

                // Now, pop this NULL from the Queue.
                q.pop();

                // Now, push the delimiter againg for next level only when the queue is not empty.
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                // Step 3.2. pop the front element of the queue. (q.pop()).
                q.pop();

                // Step 3.3. print the data of forntNode (cout<<frontNode->data);
                cout << frontNode->data << " ";

                // Step 3.4. push the child nodes of frontNode present in the queue, if child nodes is present(not NULL).
                if (frontNode->leftChild != NULL)
                {
                    q.push(frontNode->leftChild);
                }

                if (frontNode->rightChild != NULL)
                {
                    q.push(frontNode->rightChild);
                }
            }
        }
    }

    /* In-Order Traversal (Order of Traversing: Left Node, Root Node, Right Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void InOrderTraversalRecursive(Node *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        InOrderTraversalRecursive(root->leftChild);
        cout << root->data << " ";
        InOrderTraversalRecursive(root->rightChild);
    }

    /* Pre-Order Traversal (Order of Traversing: Root Node, Left Node, Right Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void PreOrderTraversalRecursive(Node *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        cout << root->data << " ";
        PreOrderTraversalRecursive(root->leftChild);
        PreOrderTraversalRecursive(root->rightChild);
    }

    /* Post-Order Traversal (Order of Traversing: Left Node, Right Node, Root Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void PostOrderTraversalRecursive(Node *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        PostOrderTraversalRecursive(root->leftChild);
        PostOrderTraversalRecursive(root->rightChild);
        cout << root->data << " ";
    }
};