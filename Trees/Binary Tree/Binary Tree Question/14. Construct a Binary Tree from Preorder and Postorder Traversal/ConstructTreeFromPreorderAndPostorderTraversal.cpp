/*
Question:
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

Example:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Tree Preview:
                            1
                         /    \
                        2      3
                      /  \    / \
                     4    5   6  7

Our task is to construct the Binary Tree using Preorder and Postorder traversal, and return the root node of a Binary Tree.



---------------------------- Approach ---------------------------------------------
Important Points:- 
1. If only preorder and postorder is given, than it is impossible to construct unique binary tree.
2. If only preorder and postorder is given, than it is possible to construct unique full binary tree.

Full Binary Tree => each node has 0 or 2 child.

Example : preorder[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and,
          postorder[] = {8, 9, 4, 5, 2, 6, 7, 3, 1}.

Order of Traversal in Preorder: Root Left Right.
Order of Traversal in Postorder: Left Right Root.

So, in preorder vector, the leftmost element is the root of the tree and in postorder vector, the rightmost element is the root of the tree.

The leftmost element in preorder vector is 1, and according to Order of Traversal in Preorder i.e., Root Left Right, we can say that, the next element after 1 must be the left child of root and the next element after successor of 1 must be the right child of root.

next element after 1 is 2 (2 is the left child of root), and next element after 2 is 4 (4 is the right child of root).

How to find the all nodes in left subtree?
Order of Traversal in Postorder: Left Right Root. So, if you find the position of left child of root i.e., position of 2 in postorder vector.

Then all the node from start to the position of 2 (in postorder), must be in the left subtree i.e., {8, 9, 4, 5, 2} and all the node from position of 2 (in postorder) to end, must be in the left subtree i.e., {6, 7, 3}.

*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper Method to build binary tree from preorder and postorder traversal. */
    // Time Complexity :- O(n), n is the size of the vector.
    // Space Complexity :- O(h), h is the height of the binary tree.
    Node *helper(vector<int> &preorder, vector<int> &postorder, int &preIdx, int postSI, int postEI, unordered_map<int, int> &position)
    {
        // Base case
        if (preIdx >= preorder.size() || postSI > postEI)
        {
            return NULL;
        }

        // Recursive Case
        // The first element in preorder traversal (vector) is the root node.
        // Create the root node, and increment preIdx (after incrementing preIdx will point to next element of root).
        Node *root = new Node(preorder[preIdx++]);

        // If the current subarray has only one element, simply return that element.
        if (postSI == postEI)
        {
            return root;
        }

        // Search the successor of root in postorder traversal vector.
        // our preIdx pointer will point to successor of root.
        // get the index of successor from map.
        int successorIdx = position[preorder[preIdx]];

        // Use the index of successor element found in postorder traversal,
        // to divide the postorder array in two parts.
        // Left subtree is from postSI to successorIdx and,
        // Right subtree is from  successorIdx + 1 to postEI - 1 (skipping the root in postorder).

        root->leftChild = helper(preorder, postorder, preIdx, postSI, successorIdx, position);
        root->rightChild = helper(preorder, postorder, preIdx, successorIdx + 1, postEI - 1, position);

        return root;
    }

public:
    /* Method to build binary tree from preorder and postorder traversal. */
    Node *buildTreeFromPreorderAndPostorder(vector<int> &preorder, vector<int> &postorder)
    {
        // Base Case
        if (preorder.size() == 1)
        {
            return new Node(preorder[0]);
        }

        unordered_map<int, int> position;
        for (int i = 0; i < postorder.size(); i++)
        {
            position[postorder[i]] = i;
        }

        int preIdx = 0;
        return helper(preorder, postorder, preIdx, 0, postorder.size() - 1, position);
    }
};

int main(void)
{
    vector<int> postOrderTraversal = {4, 5, 2, 6, 7, 3, 1};
    vector<int> preOrderTraversal = {1, 2, 4, 5, 3, 6, 7};

    // Solution.
    Solution S;
    Node *root = S.buildTreeFromPreorderAndPostorder(preOrderTraversal, postOrderTraversal);

    // Printing Binary Tree.
    BinaryTree BT;
    BT.LevelOrderTraversal(root);
}