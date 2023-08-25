#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // Time Complexity: O(n), where 'n' is the size of th nums vector.
    // Space Complexity: O(log(n)), recursive stack space.
    TreeNode *inorderToBST(vector<int> &inorder, int start, int end)
    {
        // Base Case
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
        TreeNode *root = new TreeNode(dataForNode);

        // Step 3: divide the inorder traversal into 2 parts, first is from start to mid and second is from mid+1 to end.

        // and create the left subtree from the first part of inorder traversal i.e., from start to mid-1 and,
        root->left = inorderToBST(inorder, start, mid - 1);

        // create the right subtree from the second part of inorder traversal i.e., from mid+1 to end.
        // Doing this the left and right subtree will contains the equal number of nodes and the difference between the heights of left and right subtree is always <= 1, which means the BST is balanced.
        root->right = inorderToBST(inorder, mid + 1, end);

        // return root.
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        // Given array is sorted in ascending order and as we know that the inorder traversal of BST is also sorted in ascending order.
        // So, we can easily create Balanced BST using sorted array. You just need to know How to create Balance BST from inorder traversal.
        return inorderToBST(nums, 0, nums.size() - 1);
    }

    /* Helper Method to Print BST - Inorder Traversal. */
    // Time Complexity: O(n), where 'n' is the number of nodes in BST.
    // Space Complexity: O(h), where 'h' is the height of the BST.
    void inorderTraversal(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case.

        // Inorder Traversal -> Order of Traversal -> Left Root Right.

        // Left.
        inorderTraversal(root->left);

        // Root.
        cout << root->val << " ";

        // Right.
        inorderTraversal(root->right);
    }
};

int main(void)
{
    vector<int> nums{-10, -3, 0, 5, 9};

    // Solution.
    Solution obj;
    TreeNode *root = obj.sortedArrayToBST(nums);

    // Printing BST.
    obj.inorderTraversal(root);
    return 0;
}