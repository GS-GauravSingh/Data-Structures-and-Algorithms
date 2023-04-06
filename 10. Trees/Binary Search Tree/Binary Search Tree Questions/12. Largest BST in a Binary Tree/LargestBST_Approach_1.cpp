/*
Question: Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
*/

#include <bits/stdc++.h>
#include "../../../Binary Tree/Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Morris (Inorder) Traversal. */
    // Time Complexity of Morris Traversal: O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity of Morris Traversal: O(1), because Morris traversal is an iterative algorithm.
    int MorrisTraversal(Node *root)
    {
        // Initialize the root as the current node.
        Node *currentNode = root;

        // to store total number of nodes in this BST.
        int count = 0;

        // Run a While loop till currentNode is not null.
        while (currentNode != NULL)
        {
            // check if curr has a left child.
            if (currentNode->leftChild == NULL)
            {
                // If curr does not have a left child, print curr and move right (curr->right).
                count++;
                currentNode = currentNode->rightChild;
            }
            else
            {
                // Else If curr has a left child, then find the inorder predecessor.
                Node *predecessor = currentNode->leftChild;
                while (predecessor->rightChild != NULL && predecessor->rightChild != currentNode)
                {
                    predecessor = predecessor->rightChild;
                }

                // make temporary connection with currentNode.
                if (predecessor->rightChild == NULL)
                {
                    // if predecessor -> right == NULL,
                    // then make temporary link with currentNode.
                    // predecessor -> right = currentNode and then move left (currentNode->left).
                    predecessor->rightChild = currentNode;
                    currentNode = currentNode->leftChild;
                }

                // remove temporary connection.
                else
                {
                    // if predecessor -> right != NULL, then remove temporary link with current.
                    // predecessor -> right = NULL, print current -> data and move right.
                    predecessor->rightChild = NULL;
                    count++;
                    currentNode = currentNode->rightChild;
                }
            }
        }

        return count;
    }

    // Recursive function to determine if a given binary tree is a BST or not
    // by keeping a valid range (starting from [-INFINITY, INFINITY]) and
    // keep shrinking it down for each node as we go down recursively

    // Time Complexity: O(n), n is the number of nodes in a BST.
    // Space Complexity: O(h), h is the height of a BST.
    bool isBST(Node *root, int minimumRange, int maximumRange)
    {
        // Base Case
        if (root == NULL)
        {
            // empty tree is  valid BST.
            return true;
        }

        if (root->data < minimumRange || root->data > maximumRange)
        {
            return false;
        }

        // Recursive Case

        // left part.
        bool isLeftBST = isBST(root->leftChild, minimumRange, root->data);

        // right part.
        bool isRightBST = isBST(root->rightChild, root->data, maximumRange);

        // process root node.
        if (isLeftBST == true && isRightBST == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Method to find the size of the largest BST in a given binary tree.
    // Time Complexity: O(n^2), n is the number of nodes in a BST.
    // Space Complexity: O(h), h is the height of a BST. 
    int findLargestBST(Node *root)
    {
        // Base Case
        if(root == NULL)
        {
            return -1;
        }       

        // Recursive Case

        // process root node.
        if(isBST(root, INT_MIN, INT_MAX) == true)
        {
            // using morris traversal to count total number of nodes in a BST.
            return MorrisTraversal(root); 
        }

        // left part.
        int left = findLargestBST(root->leftChild);

        // right part.
        int right = findLargestBST(root->rightChild);

        return max(left, right);

    }

public:
    /*
    Approach (Brute Force):- visit each and every node and check if it creates a valid BST or not, if yes the store the size of BST, else not.
    Time Complexity:- O(n^2)
    Space Complexity:- O(h)
    */

    /* Return the size of the largest sub-tree which is also a BST. */
    int largestBst(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            return 1;
        }

        return findLargestBST(root);
    }
};

int main(void)
{
    /*
    Sample Build: Input for Preorder Build: 1 4 6 -1 -1 8 -1 -1 4 -1 -1
    Tree Preview:
                                1
                             /     \
                            4       4
                          /   \
                         6     8
    Output: 1
    Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the
    leaf Nodes are the BSTs with size equal to 1.
    */

    // Creating root node for Binary Tree.
    Node *root = NULL;

    // Building Binary Tree.
    BinaryTree bt;
    bt.buildTreePreOrder(root);
    bt.LevelOrderTraversal(root);

    // Solution.
    Solution S;
    cout << S.largestBst(root);
}