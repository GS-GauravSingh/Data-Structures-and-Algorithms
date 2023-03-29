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

    /* Method to merge 2 sorted vectors. */
    // Time Complexity: O(m+n), m and n is the size of vec1 and vec2.
    // Time Complexity: O(m+n).
    vector<int> merge(vector<int> &vec1, vector<int> &vec2)
    {
        // vector to store answer.
        vector<int> merged;

        // pointers to traverse vectors.
        int i = 0, j = 0;
        while (i < vec1.size() && j < vec2.size())
        {
            if (vec1[i] < vec2[j])
            {
                merged.push_back(vec1[i++]);
            }
            else
            {
                merged.push_back(vec2[j++]);
            }
        }

        // remaining element in vector 1.
        while (i < vec1.size())
        {
            merged.push_back(vec1[i++]);
        }

        // remaining element in vector 2.
        while (j < vec2.size())
        {
            merged.push_back(vec2[j++]);
        }

        return merged;
    }

    /* Method that creates BST from Inorder Traversal. */
    // Time Complexity: O(n), n is the size of inorder traversal vector..
    // Time Complexity: O(h), h is the height of the BST.
    BSTNode *createBSTFromInorder(vector<int> &inorder, int start, int end)
    {
        // Base case
        if (start > end)
        {
            return NULL;
        }

        // Recursive case
        int mid = start + (end - start) / 2;
        BSTNode *root = new BSTNode(inorder[mid]);
        root->left = createBSTFromInorder(inorder, start, mid - 1);
        root->right = createBSTFromInorder(inorder, mid + 1, end);
        return root;
    }

public:
    /* Approach:

    Step 1: store the inorder traversal of both the BST into a separate vectors (inorder traversal of BST comes out in sorted order.)

    Step 2: now, at this point we have 2 sorted vector, vector 1 will contain the inorder traversal of first BST and vector 2 will contain the inorder traversal of second BST. Now, in this step, merge both the vectors into a single vector.

    Step 3: at this point we only have a single vector, which is sorted in increasing order. Now you can easily create BST from inorder traversal.
    */

    /* Method to merge 2 BST into single BST. */
    // Time Complexity: O(m+n)
    // Space Complexity: O(m+n)
    BSTNode *mergeBST(BSTNode *root1, BSTNode *root2)
    {
        // Step 1: store the inorder traversal of both the BST into a separate vectors (inorder traversal of BST comes out in sorted order.)
        vector<int> inorderTraversalOfFirstBST;
        MorrisTraversal(root1, inorderTraversalOfFirstBST);

        vector<int> inorderTraversalOfSecondBST;
        MorrisTraversal(root2, inorderTraversalOfSecondBST);

        // Step 2: merge both vectors into a single vector.
        vector<int> inorderTraversal = merge(inorderTraversalOfFirstBST, inorderTraversalOfSecondBST);

        // Step 3: create BST from inorder traversal.
        BSTNode *root = createBSTFromInorder(inorderTraversal, 0, inorderTraversal.size() - 1);

        // Step 4: return root.
        return root;
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
    BSTNode *root1 = NULL;
    BSTNode *root2 = NULL;

    // Building Binary Search Tree.
    BinarySearchTree bst;
    bst.takeInput(root1);
    bst.takeInput(root2);

    // Solution.
    Solution S;
    BSTNode *root = S.mergeBST(root1, root2);
    bst.LevelOrderTraversal(root);
}