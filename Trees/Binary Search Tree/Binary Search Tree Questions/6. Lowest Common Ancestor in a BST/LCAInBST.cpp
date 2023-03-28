/*
## What is Inorder Predecessor ? ##

Lets take an example to understand this,
Example Tree:-
                            1
                         /     \
                        3        5
                      /  \      /
                     7    11   17

Inorder Traversal of above tree is: 7, 3, 11, 1, 17, 5

Inorder Predecessor of 7 is nothing (because there is no value before 7).
Inorder Predecessor of 3 is 7.
Inorder Predecessor of 11 is 3.
Inorder Predecessor of 1 is 11.
Inorder Predecessor of 17 is 1.
Inorder Predecessor of 5 is 17.

## What is Inorder Successor ? ##
Inorder Traversal of above tree is: 7, 3, 11, 1, 17, 5

Inorder Successor of 7 is 3.
Inorder Successor of 3 is 11.
Inorder Successor of 11 is 1.
Inorder Successor of 1 is 17.
Inorder Successor of 17 is 5.
Inorder Successor of 5 is nothing (because there is no value after 7).

## How to find inorder predecessor ?

A simple approach is to store the inorder traversal of Binary Tree and find the inorder predecessor of any given element.Now, If you want to find the inorder predecessor without storing the inorder traversal, see the example below,

Lets say you have to find the predessor of 1.
Lets take currentNode = 1;
Now, to find predessor of 1 move one node towards left i.e., currentNode -> lefcurrentNode -> left = 3, now currentNode = 3.

Now, from here the rightmost child node is our inorder predecessor.
The right most childnode is 3 is 11.So, the predecessor of 1 is 11.



## How to find inorder Successor ?

A simple approach is to store the inorder traversal of Binary Tree and find the inorder seccessor of any given element. Now, If you want to find the inorder successor without storing the inorder traversal, see the example below,

Lets say you have to find the predessor of 1.

Lets take currentNode = 1;
Now, to find successor of 1 move one node towards right i.e., currentNode -> right, currentNode -> right = 5, now currentNode = 5.

Now, from here the leftmost child node is our inorder successor.
The left most childnode is 5 is 17.

So, the successor of 1 is 17.


In case of BST we can say that,

Inorder predecessor of node with value n: is the maximum value in left subtree.
Inorder successor of node with value n: is the minimum value in right subtree.
*/

#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /*
    Time Complexity:- O(height of the Tree)
    Space Complexity:- O(1)
    */
    BSTNode *lca(BSTNode *root, BSTNode *p, BSTNode *q)
    {
        // Base CAse
        if (root == NULL)
        {
            return root;
        }

        while (root != NULL)
        {
            if (root->data < p->data && root->data < q->data)
            {
                // if root -> data is < p -> data and q -> data, it means p and q are present at right subtree.
                root = root->right;
            }

            else if (root->data > p->data && root->data > q->data)
            {
                // if root -> data is > p -> data and q -> data, it means p and q are present at left subtree.
                root = root->left;
            }

            else
            {
                // if ( (root -> data is > p -> data) && (root -> data < q -> data) ) ||
                //    ( (root -> data is < p -> data) && (root -> data > q -> data) );
                // in this case your root is the lca, return root.
                return root;
            }
        }
    }
};

int main(void)
{
    /*
    Sample Inputs:
    I/O 1 : 1 2 3 4 7 -1
    I/O 2 : 10 2 3 8 9 4 7 -1
    */

    // Creating root node of BST.
    BSTNode *root = NULL;

    // Building Binary Search Tree.
    BinarySearchTree bst;
    bst.takeInput(root);

    // Solution.
    Solution S;

    BSTNode* p = new BSTNode(4);
    BSTNode* q = new BSTNode(9);


    cout<<"LCA : "<<S.lca(root, p, q)->data<<".";

}