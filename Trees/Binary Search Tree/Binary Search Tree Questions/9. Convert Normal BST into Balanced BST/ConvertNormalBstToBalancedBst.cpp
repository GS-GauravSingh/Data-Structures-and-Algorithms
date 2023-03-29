/*
Balanced BST:- for every node if( abs( height of (left subtree) - height of(right subtree) ) <= 1).
if the above condition is true for every node then the BST is balanced.

Our Task:- We have to convert the given BST to Balnced BST.
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

    /* Method to create BST from Inorder vector. */
    BSTNode *inorderToBST(vector<int> &inorder, int start, int end)
    {
        // Base case
        if (start > end)
        {
            return NULL;
        }

        // Recursive case.
        // Now, we have to create a BST from inorder vector whose height is balanced.
        // To create such BST from inorder traversal whose height is balanced follow the below steps,

        // Step 1: find middle element of inorder traversal.
        int mid = start + (end - start) / 2;

        // Step 2: create node for middle element.
        int dataForNode = inorder[mid];
        BSTNode *root = new BSTNode(dataForNode);

        // Step 3: divide the inorder traversal into 2 parts, first is from start to mid and second is from mid+1 to end.

        // and create the left subtree from the first part of inorder traversal i.e., from start to mid-1 and,
        root->left = inorderToBST(inorder, start, mid-1);

        // create the right subtree from the second part of inorder traversal i.e., from mid+1 to end.
        // Doing this the left and right subtree will contains the equal number of nodes and the difference between the hwights of left and right subtree is always <= 1, which means the BST is balanced.
        root->right = inorderToBST(inorder, mid + 1, end);

        // return root.
        return root;
    }

public:
    /* Approach: Store the Inorder traversal of BST, as we know that the inorder traversal of BST comes out in sorted order, after that create a BST from inorder vector. */

    /* Method that convert normal BST into Balanced BST. */

    // Time Complexity: O(n), n is the number of nodes in the BST.
    // Space Complexity: O(n), space used by vector.
    BSTNode *balancedBst(BSTNode *root)
    {
        // Step 1: store the inorder traversal of BST.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: create BST from inorder vector.
        BSTNode *balancedBSTRoot = inorderToBST(inorder, 0, inorder.size() - 1);
        return balancedBSTRoot;
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
    BSTNode* balancedBSTRoot = S.balancedBst(root);
    bst.LevelOrderTraversal(balancedBSTRoot);
}