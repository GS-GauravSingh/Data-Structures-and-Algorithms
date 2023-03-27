#include <bits/stdc++.h>
using namespace std;

/* Node Structure for BST. */
class Node
{
private:
public:
    /* Data Members or Properties of Solution Class. */
    int data;    // data for node.
    Node *left;  // pointer to left child node.
    Node *right; // pointer to right child node.

    /* Methods or Behavior of Solution Class. */

    // Paramaterized Constructor.
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/*

Binary Search Tree.

The properties that separate a binary search tree from a regular binary tree is:
1. For Every Node,
    1. All nodes of left subtree are less than the root node.
    2. All nodes of right subtree are more than the root node.

BST = node values at Root -> left < Root value and node values at Root -> right > Root value.
So , for every node if this property is statisfied then this tree is considered as Binary Search Tree (BST).

Property:- InOrder Traversal of Binary Search Tree (BST) comes out to be in sorted order.
*/
class BinarySearchTree
{
private:
    /* Method to insert data into the BST. */
    // Time Complexity:- O(log(n)), log n time taken to insert one element into the BST.
    // Space Complexity: O(h), h is the height of the BST. 
    Node *insertIntoBST(Node *root, int data)
    {
        // Base case
        // When root points to NULL, in this case, simply create a new node and return that new Node.
        if (root == NULL)
        {
            root = new Node(data);
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

public:
    /* Method that take node value as input to insert into the BST. */
    // Time Complexity:- O(n log(n)), log n time taken to insert one element into the BST and we have to insert n elements into the BST that's why the time complexity is O(n log(n))
    // Space Complexity: O(h), h is the height of the BST. 
    void takeInput(Node *&root)
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
};
