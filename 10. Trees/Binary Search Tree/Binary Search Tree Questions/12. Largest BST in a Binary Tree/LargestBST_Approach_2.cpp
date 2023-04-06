/*
Question: Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
*/

#include <bits/stdc++.h>
#include "../../../Binary Tree/Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

class Info
{
    /*
    So, for each node, we have to know the maximum value of left subtree and minimum value of right subtree. But why?
    because for valid BST  this condition needs to be true,
    { left subtree maximum value < root -> data < right subtree minimum value }.

    also we need to know, if the left and right subtree is valid BST or not.

    and last we need size variable to store the size of valid BST.
    */
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper method to return the size of the largest sub-tree which is also a BST. */
    // Time Complexity:- O(n).
    // Space Complexity:- O(height of the tree) in worst case O(n).
    Info solve(Node *root, int &ans)
    {
        // Base Case
        if (root == NULL)
        {
            return {INT_MIN, INT_MAX, true, 0};
        }

        // Recursive Case

        // left part.
        Info left = solve(root->leftChild, ans);

        // right part.
        Info right = solve(root->rightChild, ans);

        // root node.
        Info currNode;

        // update size.
        currNode.size = left.size + right.size + 1; // +1 for adding size of root node.

        // update maxi, maximum value came from right.
        currNode.maxi = max(right.maxi, root->data);

        // update mini, minimum value came from left.
        currNode.mini = min(left.mini, root->data);

        // check if left, right and root is valid BST or not.
        if (left.isBST == true && right.isBST == true && (left.maxi < root->data && right.mini > root->data))
        {
            currNode.isBST = true;
        }
        else
        {
            currNode.isBST = false;
        }

        // update answer (store maximum size if it is a vlid BST).
        if (currNode.isBST == true)
        {
            ans = max(ans, currNode.size);
        }

        return currNode;
    }

public:
    /*
    Approach 2 (Optimized):- in approach 1, what we are doing wrong is, for each node we are calling isBST() method, which will increases our time complexity. So, we can calculate all of this in a single method.

    Time Complexity:- O(n)
    Space Complexity:- O(height of the tree) in worst case O(n).
    */

    /* Return the size of the largest sub-tree which is also a BST. */
    int largestBst(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        int maxSize = 0;
        Info ans = solve(root, maxSize);
        return maxSize;
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