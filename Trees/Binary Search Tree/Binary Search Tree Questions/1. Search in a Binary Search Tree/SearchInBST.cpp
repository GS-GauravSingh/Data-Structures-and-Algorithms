/*
Question:

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

*/
#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Methods or Behavior of Solution Class. */

    /* Recursive Method to Find the node in the BST that the node's value equals val  and return the subtree rooted with that node. */
    // Time Complexity: O(log(n)) in average case, in Worst Case wheen skewed tree is given then TC is O(n).
    // Space Complexity: O(h), h is the height of the BST.
    BSTNode *searchInBST_Recursive(BSTNode *root, int val)
    {
        // Base Case
        // If the root points to NULL, it means the value which we have to find in the BST, that value does not exist in the BST so return NULL.
        if (root == NULL)
        {
            return NULL;
        }

        // Recursive Case
        // Apply Binary Search.
        if (root->data == val)
        {
            // value found, reutrn the root node.
            return root;
        }
        else if (root->data < val)
        {
            // if root->data < val, move right.
            // because in BST, left subtree value < root value and right subtree value > root value.
            return searchInBST_Recursive(root->right, val);
        }
        else
        {
            // if root->data > val, move left.
            // because in BST, left subtree value < root value and right subtree value > root value.
            return searchInBST_Recursive(root->left, val);
        }
    }

    /* Iterative Method to Find the node in the BST that the node's value equals val  and return the subtree rooted with that node. */
    // Time Complexity: O(log(n)) in average case, in Worst Case wheen skewed tree is given then TC is O(n).
    // Space Complexity: O(1).
    BSTNode *searchInBST_Iterative(BSTNode *root, int val)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == val)
        {
            return root;
        }

        // pointer to traverse BST.
        BSTNode *currentNode = root;
        while (currentNode != NULL)
        {
            if (currentNode->data == val)
            {
                // value found, reutrn the root node.
                return currentNode;
            }
            else if (currentNode->data < val)
            {
                // if currentNode->data < val, move right.
                // because in BST, left subtree value < root value and right subtree value > root value.
                currentNode = currentNode->right;
            }
            else
            {
                // if currentNode->data > val, move left.
                // because in BST, left subtree value < root value and right subtree value > root value.
                currentNode = currentNode->left;
            }
        }

        // if the above loop does not return anything and currentNode p[oints to NULL, it means the value which we have to find in the BST, that value does not exist in the BST so return NULL.
        return NULL;
    
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
    int val = 7;
    BSTNode *ans = S.searchInBST_Iterative(root, val);
    // BSTNode *ans = S.searchInBST_Recursive(root, val);

    if (ans == NULL)
    {
        cout << val << " not found.\n";
    }
    else
    {
        bst.PreOrderTraversalRecursive(ans);
    }
}