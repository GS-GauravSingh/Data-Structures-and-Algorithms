/*
Question:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

*/
#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Morris (Inorder) Traversal. */
    // Time Complexity of Morris Traversal: O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity of Morris Traversal: O(1), because Morris traversal is an iterative algorithm.
    void MorrisTraversal(BSTNode *root, vector<int> &inorderTraversal)
    {
        // Initialize the root as the current node.
        BSTNode *currentNode = root;

        // Run a While loop till currentNode is not null.
        while (currentNode != NULL)
        {
            // check if curr has a left child.
            if (currentNode->left == NULL)
            {
                // If curr does not have a left child, print curr and move right (curr->right).
                inorderTraversal.push_back(currentNode->data);
                currentNode = currentNode->right;
            }
            else
            {
                // Else If curr has a left child, then find the inorder predecessor.
                BSTNode *predecessor = currentNode->left;
                while (predecessor->right != NULL && predecessor->right != currentNode)
                {
                    predecessor = predecessor->right;
                }

                // make temporary connection with currentNode.
                if (predecessor->right == NULL)
                {
                    // if predecessor -> right == NULL,
                    // then make temporary link with currentNode.
                    // predecessor -> right = currentNode and then move left (currentNode->left).
                    predecessor->right = currentNode;
                    currentNode = currentNode->left;
                }

                // remove temporary connection.
                else
                {
                    // if predecessor -> right != NULL, then remove temporary link with current.
                    // predecessor -> right = NULL, print current -> data and move right.
                    predecessor->right = NULL;
                    inorderTraversal.push_back(currentNode->data);
                    currentNode = currentNode->right;
                }
            }
        }
    }

public:
    /* Method to determine if the give BST is a valid binary search tree (BST) or not. */

    /* Approach: Store the Inorder traversal of BST, as we know that the inorder traversal of BST comes out in sorted order and if the given BST is valid, then its inorder traversal must be sorted in increasing order otherwise the given BST is not valid.  */
    // Time Complexity: O(n), n is the number of nodes in the Binary Search Tree.
    // Space Complexity: O(1), if we exclude the size of vector, otherwise, if we include the size of vector then space complexity is O(n).
    bool isValidBST(BSTNode *root)
    {
        // Step 1: store the inorder traversal of BST.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: If the given BST is valid, then its inorder traversal must be sorted in increasing order otherwise the given BST is not valid.
        for (int i = 1; i < inorder.size(); i++)
        {
            if (inorder[i - 1] > inorder[i])
            {
                // not sorted.
                return false;
            }
        }

        return true;
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
    if (S.isValidBST(root))
    {
        cout << "BST is valid.\n";
    }
    else
    {
        cout << "BST is not valid.\n";
    }
}