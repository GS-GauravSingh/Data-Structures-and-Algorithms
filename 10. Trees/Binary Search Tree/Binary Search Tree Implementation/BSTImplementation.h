#include <bits/stdc++.h>
using namespace std;

/* BSTNode Structure for BST. */
class BSTNode
{
private:
public:
    /* Data Members or Properties of Solution Class. */
    int data;       // data for node.
    BSTNode *left;  // pointer to left child node.
    BSTNode *right; // pointer to right child node.

    /* Methods or Behavior of Solution Class. */

    // Paramaterized Constructor.
    BSTNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/*

Binary Search Tree.

The properties that separate a binary search tree from a regular binary tree is:
1. For Every BSTNode,
    1. All nodes of left subtree are less than the root node.
    2. All nodes of right subtree are more than the root node.

BST = node values at Root -> left < Root value and node values at Root -> right > Root value.
So , for every node if this property is statisfied then this tree is considered as Binary Search Tree (BST).

Property:- InOrder Traversal of Binary Search Tree (BST) comes out in sorted order.
*/
class BinarySearchTree
{
private:
    /* Method to insert data into the BST. */
    // Time Complexity:- O(log(n)), log n time taken to insert one element into the BST.
    // Space Complexity: O(h), h is the height of the BST.
    BSTNode *insertIntoBST(BSTNode *root, int data)
    {
        // Base case
        // When root points to NULL, in this case, simply create a new node and return that new BSTNode.
        if (root == NULL)
        {
            root = new BSTNode(data);
            return root;
        }

        // Recursive Case.

        // Compare Data with Roots data (root->data).
        // If data is < root->data, it means we have to insert this data at the left of the BST.
        if (data < root->data)
        {
            // Insert at left.
            root->left = insertIntoBST(root->left, data);
        }
        // else, If data is > root->data, it means we have to insert this data at the right of the BST.
        else
        {
            // Insert at right.
            root->right = insertIntoBST(root->right, data);
        }
    }

    /* Method that returns the minimum value in the BST. */
    /*
    Now, Binary Search Tree has One Property and that property is,

        Property: InOrder Traversal of Binary Search Tree (BST) comes in sorted order and in Inorder, the order of Traversal Left, Root, Right.

        It means the leftmost is the minimum node of the BST and, the rightmost node is the maximum node of the BST. Now, you can easily find the minimum and maximum node of the BST.
    */

    // Time Complexity: O(n) in case of left skewed BST.
    // Space Complexity: O(1)
    BSTNode *findMinimum(BSTNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            // empty tree.
            return NULL;
        }

        // if root node does not have left child, in the case, the root node is the minimum node of the BST.
        if (root->left == NULL)
        {
            return root;
        }

        // pointer to traverse the BST.
        BSTNode *currentNode = root;

        // leftmost node is the minimum node of the BST.
        while (currentNode->left != NULL)
        {
            currentNode = currentNode->left;
        }

        // return the minimum node.
        return currentNode;
    }

    /* Method that returns the maximum value in the BST. */
    /*
    Now, Binary Search Tree has One Property and that property is,

        Property: InOrder Traversal of Binary Search Tree (BST) comes in sorted order and in Inorder, the order of Traversal Left, Root, Right.

        It means the leftmost is the minimum node of the BST and, the rightmost node is the maximum node of the BST. Now, you can easily find the minimum and maximum node of the BST.
    */

    // Time Complexity: O(n) in case of left skewed BST.
    // Space Complexity: O(1)
    BSTNode *findMaximum(BSTNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            // empty tree.
            return NULL;
        }

        // if root node does not have right child, in the case, the root node is the maximum node of the BST.
        if (root->left == NULL)
        {
            return root;
        }

        // pointer to traverse the BST.
        BSTNode *currentNode = root;

        // rightmost node is the minimum node of the BST.
        while (currentNode->right != NULL)
        {
            currentNode = currentNode->right;
        }

        // return the maximum node.
        return currentNode;
    }

public:
    /* Method that take node value as input to insert into the BST. */
    // Time Complexity:- O(n log(n)), log n time taken to insert one element into the BST and we have to insert n elements into the BST that's why the time complexity is O(n log(n))
    // Space Complexity: O(h), h is the height of the BST.
    void takeInput(BSTNode *&root)
    {
        cout << "Enter data to insert into BST:-\n";
        cout << "-1 Represents NULL.\n";

        // continuously taking user input.
        int data;
        while (true)
        {
            // taking data as input.
            cin >> data;

            // -1 means, stop inserting data.
            if (data == -1)
            {
                break;
            }

            // inserting data into the BST.
            root = insertIntoBST(root, data);
        }
    }

    /* ------------- Method to delete a node with given value from BST. ---------------- */
    /*
    Algorithm:-
    Step 1:- First find the node that we have to delete.
    Step 2:- After finding the node which we have to delete, Now there are some cases,

        case 1: the node which we have to delete have 0 child nodes (leaf node). In this case just delete that node and return NULL.

        case 2: the node which we have to delete have 1 child node. In this case just delete the node and return the child node.

        case 3: the node which we have to delete have 2 child nodes. In this case we have to options:

                Option 1st:- find the maximum value from left subtree and replace that value of this node value, and delete that value from left subtree.

                Option 2nd:- find the minimum value from right subtree and replace that value of this node value, and delete that value from right subtree.

                => You can use any one option of your choice.
    */

    // Time Complexity: O(log(n)) in average case, O(n) in worst case.
    // Space Complexity: O(h), h is the height of the BST.
    BSTNode *deleteFromBST(BSTNode *&root, int val)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        // Recursive case.

        // Step 1: find the value which we have to delete.
        if (root->data == val)
        {
            // value found.

            // Step 2: After finding the node which we have to delete, Now there are some cases,

            // Case 1: the node which we have to delete have 0 child nodes (leaf node). In this case just delete that node and return NULL.
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // Case 2: the node which we have to delete have 1 child node. In this case just delete the node and return the child node.

            // Only Left Child.
            else if (root->left != NULL && root->right == NULL)
            {
                BSTNode *leftChild = root->left; // storing the reference of left child.
                delete root;
                return leftChild;
            }

            // Only Right Child.
            else if (root->left == NULL && root->right != NULL)
            {
                BSTNode *rightChild = root->right; // storing the reference of right child.
                delete root;
                return rightChild;
            }

            // Case 3: the node which we have to delete have 2 child nodes. In this case we have to options:

            // Option 1st: find the maximum value from left subtree and replace the value of node which we have to delete with the maximum value, and delete that maximum value from the left subtree.

            // Option 2nd: find the minimum value from right subtree and replace the value of node which we have to delete with the minimum value, and delete that minimum value from the right subtree.

            // => You can use any one option of your choice.
            else if (root->left != NULL && root->right != NULL)
            {
                // I am using option second.
                // Option 2nd: find the minimum value from right subtree and replace the value of node which we have to delete with the minimum value, and delete that minimum value from the right subtree.

                // getting the minimum value from the right subtree.
                BSTNode *minimumValue = findMinimum(root->right);

                // replace the value of node which we have to delete with the maximum value.
                root->data = minimumValue->data;

                // deleting that minimum value from the right subtree.
                root->right = deleteFromBST(root->right, minimumValue->data);
            }
        }
        else if (root->data < val)
        {
            // if root->data < val, move right.
            // because in BST, left subtree value < root value and right subtree value > root value.
            root->right = deleteFromBST(root->right, val);
        }
        else
        {
            // if root->data > val, move left.
            // because in BST, left subtree value < root value and right subtree value > root value.
            root->left = deleteFromBST(root->left, val);
        }

        // return root node.
        return root;
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

    void LevelOrderTraversal(BSTNode *root)
    {
        // Step 1. declare queue of type node*.  (queue<node*> q)
        queue<BSTNode *> q;

        // Step 2. push root node into the queue, because at first we need to print the root node.
        q.push(root);

        // delimiter representing the end of level 0. this is just for formatting the output.
        q.push(NULL);

        // Step 3. run a loop while queue is not empty and do the following things,
        while (!q.empty())
        {
            // Step 3.1. store the front node present at the queue (Node* frontNode = q.front()).
            BSTNode *frontNode = q.front();

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
                if (frontNode->left != NULL)
                {
                    q.push(frontNode->left);
                }

                if (frontNode->right != NULL)
                {
                    q.push(frontNode->right);
                }
            }
        }
    }

    /* In-Order Traversal (Order of Traversing: Left Node, Root Node, Right Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void InOrderTraversalRecursive(BSTNode *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        InOrderTraversalRecursive(root->left);
        cout << root->data << " ";
        InOrderTraversalRecursive(root->right);
    }

    /* Pre-Order Traversal (Order of Traversing: Root Node, Left Node, Right Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void PreOrderTraversalRecursive(BSTNode *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        cout << root->data << " ";
        PreOrderTraversalRecursive(root->left);
        PreOrderTraversalRecursive(root->right);
    }

    /* Post-Order Traversal (Order of Traversing: Left Node, Right Node, Root Node). */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void PostOrderTraversalRecursive(BSTNode *root)
    {
        // Base case
        // If root == NULL, simply return from there.
        if (root == NULL)
        {
            return;
        }

        // Recursive case.
        PostOrderTraversalRecursive(root->left);
        PostOrderTraversalRecursive(root->right);
        cout << root->data << " ";
    }
};
