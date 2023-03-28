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

    /* Approach 2: Helper Method to find the kth largest value in a BST. */
    int helper(BSTNode *root, int k, int &count)
    {
        // Base case
        if (root == NULL)
        {
            return -1;
        }

        // Recurisve case
        // Move right, because all the largest element is present at the right.
        int rightAns = helper(root->right, k, count);
        if(rightAns != -1)
        {
            return rightAns;
        }

        // Process root node.
        count++;
        if (count == k)
        {
            return root->data;
        }

        // Move Left.
        int leftAns = helper(root->left, k, count);
        return leftAns;
    }

public:
    /* Approach 1: Store the inorder traversal of BST and return the kth largest element. */
    int kthLargest_Approach_1(BSTNode *root, int &k)
    {
        // Step 1: store the inorder traversal of BST.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: return kth largest element.
        return inorder[inorder.size() - k];
    }

    /* Approach 2: traverse the tree using inorder traversal and use a counter variable to find the kth smallest element. */
    int kthLargest_Approach_2(BSTNode *root, int &k)
    {
        int count = 0;
        return helper(root, k, count);
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
    int k = 2;
    cout << "kth largest element is " << S.kthLargest_Approach_1(root, k) << ".\n";
    cout << "kth largest element is " << S.kthLargest_Approach_2(root, k) << ".\n";
}