/*
Question: Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
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
    /* Approach: Store the Inorder traversal of BST, as we know that the inorder traversal of BST comes out in sorted order, an after that we can use 2 pointer approach to easily find if there exist two elements in the BST such that their sum is equal to k, or not. */

    /* Method that return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise. */

    // Time Complexity: O(n), n is the number of nodes in the BST.
    // Space Complexity: O(n), space used by vector.
    bool findTarget(BSTNode *root, int k)
    {
        // Step 1 : store the inorder traversal of BST.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: using 2 pointer, check if any 2 elements is present in the vector whose summation is equal to the given value k.
        int low = 0, high = inorder.size() - 1;
        while (low < high)
        {
            int sum = inorder[low] + inorder[high];
            if (sum == k)
            {
                return true;
            }

            // move pointers.
            if (sum < k)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        // if the above loop doesn't return anything, it means the pair whose sum equals to k does not exist so return false.
        return false;
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
    int k = 9;
    if (S.findTarget(root, k))
    {
        cout << "Pair Exists.\n";
    }
    else
    {
        cout << "Pair does not exist.\n";
    }
}