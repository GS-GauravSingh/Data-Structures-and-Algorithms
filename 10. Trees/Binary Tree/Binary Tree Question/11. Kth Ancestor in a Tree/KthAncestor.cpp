/*
Question:-
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.

Example 1:-
Input:

k = 1
node = 3

      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to return the kth ancestor of a node. */
    // Time Complexity :- O(n), n is the number of node in a Binary Tree.
    // Space Complexity :- O(n), recursive stack space.
    Node* helper(Node *root, int &k, int node)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        // Find the vale of node in the binary tree.
        if (root->data == node)
        {
            return root;
        }

        // Recursive case
        Node* leftAns = helper(root->leftChild, k, node);
        Node* rightAns = helper(root->rightChild, k, node);

        // Backtracking step (while comming back from the base case).
        if (leftAns != NULL && rightAns == NULL)
        {
            k--;
            if (k <= 0)
            {
                // lock the answer.
                k = INT_MAX;
                return root;
            }

            return leftAns;
        }

        if (leftAns == NULL && rightAns != NULL)
        {
            k--;
            if (k <= 0)
            {
                // lock the answer.
                k = INT_MAX;
                return root;
            }

            return rightAns;
        }

    }

public:
    /* Method to return the kth ancestor of a node. */
    int kthAncestor(Node *root, int k, int node)
    {
        Node* ans = helper(root, k, node);
        // if ans == NULL, it means the node is not present in the Binary Tree, so if the node itself is not present than how can we find the kth ancestor.
        // if ans->data == node, it means the kth ancestor does not exists.
        if (ans == NULL || ans->data == node)
        {
            return -1;
        }

        return ans->data;
    }
};

int main(void)
{
    // Building the tree.
    // Creating a root node of the Binary tree.
    Node *root = NULL;

    // Building Tree (PreOrder Build).
    BinaryTree BT;
    BT.buildTreePreOrder(root);

    /*
    Example Build :-
    Input for Pre-Order Build :- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Input for Level Order Build :- 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    Tree preview :-
                                            1           ---- Level 1, Height 1, Depth 1
                                         /     \
                                        3        5      ---- Level 2, Height 2, Depth 2
                                      /  \      /
                                     7    11   17       ---- Level 3, Height 3, Depth 3


    */

    // Solution.
    Solution S;
    int k = 2;
    int node = 11;
    cout << k << "th Ancestor of " << node << " is " << S.kthAncestor(root, k, node) << ".";
}