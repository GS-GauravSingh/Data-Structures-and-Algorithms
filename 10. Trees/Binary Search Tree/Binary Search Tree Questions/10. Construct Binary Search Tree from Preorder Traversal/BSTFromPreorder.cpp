#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper Method to create BST from Preorder traversal. */
    // Time Complexity: O(n), n is the size of the preorder vector.
    // Space Complexity: O(h), h is the height of the BST.
    BSTNode *createBSTFromPreorder(vector<int> &preorder, int &idx /* idx is used to traverse preorder vector. */, int minimumRange, int maximumRange)
    {
        // Base case
        if (idx >= preorder.size())
        {
            return NULL;
        }

        if (preorder[idx] < minimumRange || preorder[idx] > maximumRange)
        {
            return NULL;
        }

        // Recursive case.

        // create root node.
        BSTNode *root = new BSTNode(preorder[idx++]);

        // move left.
        root->left = createBSTFromPreorder(preorder, idx, minimumRange, root->data);

        // move right.
        root->right = createBSTFromPreorder(preorder, idx, root->data, maximumRange);

        // return root.
        return root;
    }

public:
    /* Method to create BST from Preorder traversal. */
    BSTNode *bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        return createBSTFromPreorder(preorder, idx, INT_MIN, INT_MAX);
    }
};

int main(void)
{

    // preorder traversal of BST.
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Solution.
    Solution S;
    BSTNode *root = S.bstFromPreorder(preorder);

    BinarySearchTree bst;
    bst.LevelOrderTraversal(root);
}