/*
Question:
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.


Our task is to construct the Binary Tree using Inorder and Preorder traversal, and return the root node of a Binary Tree.
*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper Method to build binary tree from inorder and preorder traversal. */
    // Time Complexity :- O(n), n is the size of the vector.
    // Space Complexity :- O(h), h is the height of the binary tree.
    Node *helper(vector<int> &postorder, vector<int> &inorder, int &idx /* idx, used to traverse the postorder vector. */, int inOrderStartingIdx, int inOrderEndingIdx, unordered_map<int, int> &position)
    {
        // Base Case
        if (idx < 0 || inOrderStartingIdx > inOrderEndingIdx)
        {
            return NULL;
        }

        // Recursive case.

        // Step 1:- create root node from postorder traversal.
        int dataForRoot = postorder[idx--];
        Node *root = new Node(dataForRoot);

        // Step 2:- find root node position in inorder vector.
        int positionOfRootInInorder = position[dataForRoot];

        // Step 3:- all the element at the left of root node position in inorder vector, creates the left subtree, and all the element at the right of root node position in inorder vector, creates the right subtree.

        // first create right subtree, because Postorder: Left Right Root, we are traversing the popstorder vector from the back side.

        root->rightChild = helper(postorder, inorder, idx, positionOfRootInInorder + 1, inOrderEndingIdx, position);

        root->leftChild = helper(postorder, inorder, idx, inOrderStartingIdx, positionOfRootInInorder - 1, position);

        return root;
    }

public:
    /* Method to build binary tree from inorder and preorder traversal. */
    Node *buildTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
    {
        // Base Case
        if (postorder.size() == 1 && inorder.size() == 1)
        {
            // if the size of both the vector == 1, in this case, create root node and return it.
            Node *root = new Node(postorder[0]);
            return root;
        }

        // necessary variables.
        int inOrderStartingIdx = 0;
        int inOrderEndingIdx = inorder.size() - 1; // both vectors have same size.
        int idx = postorder.size() - 1;

        // to find the root node position in inorder vector.
        // I am using a map.
        unordered_map<int, int> position;
        for (int i = 0; i < inorder.size(); i++)
        {
            position[inorder[i]] = i;
        }

        Node *root = helper(postorder, inorder, idx, inOrderStartingIdx, inOrderEndingIdx, position);
        return root;
    }
};

int main(void)
{
    vector<int> inOrderTraversal = {9, 3, 15, 20, 7};
    vector<int> postOrderTraversal = {9, 15, 7, 20, 3};

    // Solution.
    Solution S;
    Node *root = S.buildTreeFromPostorderAndInorder(postOrderTraversal, inOrderTraversal);

    // Printing Binary Tree.
    BinaryTree BT;
    BT.PreOrderTraversalRecursive(root);
}