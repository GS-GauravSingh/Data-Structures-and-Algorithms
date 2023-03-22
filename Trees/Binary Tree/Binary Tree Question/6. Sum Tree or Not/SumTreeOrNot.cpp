/*
Question:-
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.



Example 1:

Input:
    3
  /   \
 1     2

Output: 1

Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.

*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------- Solution Class ---------------------------------- */
class Solution
{
private:
    /* Metho for calculating the sum of nodes of a tree.*/
    // Time complexity:- O(n), n is the number of nodes in a binary tree.
    // Space complexity:- O(n), recursive stack space.
    int sumOfTreeNodes(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Case.
        int leftSum = sumOfTreeNodes(root->leftChild);
        int rightSum = sumOfTreeNodes(root->rightChild);

        return (leftSum + rightSum + root->data);
    }

public:
    /*
    Time Complexity :- O(n^2), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */
    bool isSumTree(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // An empty tree is also a Sum Tree. So, return true.
            return true;
        }

        // Skip the leaf nodes.
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            // A leaf node is also considered a Sum Tree. So, return true.
            return true;
        }

        // Recursive case
        bool left = isSumTree(root->leftChild);
        bool right = isSumTree(root->rightChild);

        // calculating the sum of node at left and right.
        int leftSum = sumOfTreeNodes(root->leftChild);
        int RightSum = sumOfTreeNodes(root->rightChild);

        // if the above condition are true it means a tree is a sum tree.
        if ((leftSum + right == root->data) && left && right)
        {
            return true;
        }
        return false;
    }

    /* Optimizing Above Approach :- In above approach we are calculating the sum of nodes separately, but there is no need for calculating the sum of nodes separately. We can use the same isSumTree function to calculate the sum.

    Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */

    // First block of pair represents boolean value that denotes that the tree is sum tree or not.
    // Second block of pair represent the sum of nodes.
    pair<bool, int> isSumTree_Optimized(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // An empty tree is also a Sum Tree.
            // And sum of empty tree is 0.
            return {true, 0};
        }

        // Skip the leaf nodes.
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            // A leaf node is also considered a Sum Tree.
            // And sum = root->data.
            return {true, root->data};
        }

        // Recursive case
        pair<bool, int> left = isSumTree_Optimized(root->leftChild);
        pair<bool, int> right = isSumTree_Optimized(root->rightChild);

        // getting the boolean value, that represent that the left and right subtree is sum tree or not.
        bool isLeftSumTree = left.first;
        bool isRightSumTree = right.first;

        // getting the sum of nodes at left and right.
        int leftSum = left.second;
        int rightSum = right.second;

        // if the above condition are true it means a tree is a sum tree.
        if ((leftSum + rightSum == root->data) && isLeftSumTree && isRightSumTree)
        {
            pair<bool, int> ans;
            ans.first = true;
            ans.second = leftSum + rightSum + root->data;
            return ans;
        }
        else
        {
            pair<bool, int> ans;
            ans.first = false;
            ans.second = leftSum + rightSum + root->data;
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
    cout << S.isSumTree_Optimized(root).first;
}