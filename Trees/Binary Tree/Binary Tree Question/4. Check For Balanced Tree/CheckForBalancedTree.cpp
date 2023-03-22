/*
Question:-

Given a binary tree, find if tree is balanced or not.
A Binary Tree is Balanced if the difference between the height of its left subtree and right subtree is not more than 1 for all nodes of the tree.

A balanced tree
        1
     /     \
   10      39
  /
5

Explanation:-

For Node with data 1,
        Height of Left Subtree = 2, Height of Left Subtree = 1.
        Difference between the height of left subtree and right subtree is 1, and difference is <= 1, means it is valid.

For Node with data 10,
        Height of Left Subtree = 1, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 0, and difference is <= 1, means it is valid.

For Node with data 39,
        Height of Left Subtree = 0, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 0, and difference is <= 1, means it is valid.

For Node with data 5,
        Height of Left Subtree = 0, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 0, and difference is <= 1, means it is valid.

Conclusion: For all nodes the difference b/w the height of left and right subtree is <= 1, means it is a balanced binary tree.




An unbalanced tree
        1
     /
   10
  /
5

Explanation:-
For Node with data 1,
        Height of Left Subtree = 2, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 2, and difference is not <= 1, means it is not valid.

For Node with data 10,
        Height of Left Subtree = 1, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 0, and difference is <= 1, means it is valid.

For Node with data 5,
        Height of Left Subtree = 0, Height of Left Subtree = 0.
        Difference between the height of left subtree and right subtree is 0, and difference is <= 1, means it is valid.

Conclusion: For all nodes the difference b/w the height of left and right subtree is not <= 1, means it is a not a balanced binary tree.
*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------- Solution Class ---------------------------------- */
class Solution
{
private:
    /*
    Method to calculate the height of the Binary Tree.

    Time Complexity :- O(n), n is the number of nodes is a Binary Tree.
    Space Complexity :- O(n), recursive stack space.
    */
    int heightOfTheTree(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Height of Empty Tree is 0.
            return 0;
        }

        // Recursive Case.
        // Calculate the height of left subtree.
        int leftHeight = heightOfTheTree(root->leftChild);

        // Calculate the height of right subtree.
        int rightHeight = heightOfTheTree(root->rightChild);

        // take the maximum height from the left or right subtree and add 1 for the heigh of the root node.
        int maxHeight = max(leftHeight, rightHeight) + 1;

        // return maxHeight.
        return maxHeight;
    }

public:
    /*
    Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */
    bool isBalanced(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Empty tree is a Balanced Binary tree.
            return true;
        }

        // Recursive case

        // Check if the left subtree is balanced or not.
        bool isLeftBalanced = isBalanced(root->leftChild);

        // Check if the right subtree is balanced or not.
        bool isRightBalanced = isBalanced(root->rightChild);

        // Check if the difference b/w the height of the left and right subtree is <= 1 or not.
        int leftHeight = heightOfTheTree(root->leftChild);
        int rightHeight = heightOfTheTree(root->rightChild);
        int difference = abs(leftHeight - rightHeight);

        // if difference is <= 1 and Left and right subtree is balanced, it means the tree is balanced.
        if (difference <= 1 && isLeftBalanced && isRightBalanced)
        {
            // means tree is balanced.
            return true;
        }
        else
        {
            return false;
        }
    }

    /* Optimizing Above Approach :- In above approach we are calculating the height separately, but there is no need for calculating the height separately. We can use the same isBalanced function to calculate the height.

    Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */

    // First block of pair represents boolean value that denotes that the tree is balnced or not.
    // Second block of pair represent height.
    pair<bool, int> isBalanced_Optimized(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Empty tree is a Balanced Binary tree.
            // Height of the Empty Tree is 0.
            return {true, 0};
        }

        // Recursive case

        // Check if the left subtree is balanced or not.
        pair<bool, int> left = isBalanced_Optimized(root->leftChild);

        // Check if the right subtree is balanced or not.
        pair<bool, int> right = isBalanced_Optimized(root->rightChild);

        // getting the boolean value that denotes that the tree is balanced or not.
        bool isLeftBalanced = left.first;
        bool isRightBalanced = right.first;

        // Check if the difference b/w the height of the left and right subtree is <= 1 or not.
        int leftHeight = left.second;
        int rightHeight = right.second;
        int difference = abs(leftHeight - rightHeight);

        // if difference is <= 1 and Left and right subtree is balanced, it means the tree is balanced.
        if (difference <= 1 && isLeftBalanced && isRightBalanced)
        {
            // means tree is balanced.
            pair<bool, int> ans;
            ans.first = true;
            ans.second = max(leftHeight, rightHeight) + 1;
            return ans;
        }
        else
        {
            pair<bool, int> ans;
            ans.first = false;
            ans.second = max(leftHeight, rightHeight) + 1;
            return ans;
        }
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
    BT.LevelOrderTraversal(root);

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

    It is a Balanced Binary Tree.


    */

    // Solution.
    Solution S;

    if (S.isBalanced_Optimized(root).first)
    {
        cout << "Balanced.";
    }
    else
    {
        cout << "Not Balanced.";
    }
}