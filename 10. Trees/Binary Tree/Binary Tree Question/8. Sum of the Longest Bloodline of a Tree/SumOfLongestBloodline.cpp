/*
Question:
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.

If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
Output: 13

Explanation:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6

Longest Path from root to leaf: 4 -> 3 -> 1 -> 6,
sum = (4 + 2 + 1 + 6) = 13


Example 2:
Input:
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

In this case more than one longest path exists:
1. 1 -> 2 -> 4, Sum of (1,2,4) = 7
2. 1 -> 2 -> 5, Sum of (1,2,5) = 8
3. 1 -> 3 -> 6, Sum of (1,3,6) = 10
4. 1 -> 3 -> 7, Sum of (1,3,7) = 11 (this path having the Maximum sum so our answer is 11).

If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Output: 11
*/

#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper Method to return the sum of longest path from root node to leaf node. */
    // Time Complexity :- O(n), n is the number of node in a Binary Tree.
    // Space Complexity :- O(n), recursive stack space.
    void helper(Node *root, int sum, int &maxSum, int len, int &maxLen)
    {
        // Base case
        if (root == NULL)
        {
            /*
            When root == NULL, it means we had reached the end of a particular path.
            Now, check the length,
            if(length is greater than maximum length)
            {
                // in this case, update maximum length and store the sum.
            }
            else if(length is == maximum length)
            {
                // it means, more than one path of same length exists in the Binary Tree.
                // in this case, take the maximum sum.
            }

            // if both the avove condition are false, it means the length is smaller than maximum length.
            // simply return fron here.
            */

            if (len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen)
            {
                maxSum = max(maxSum, sum);
            }

            return;
            // if both the above condition are false, it means the length is smaller than maximum length.
            // simply return fron here.
        }

        // Recurisve case.

        // Calculate the sum.
        sum += root->data;

        // Recursive Class.
        helper(root->leftChild, sum, maxSum, len + 1, maxLen);
        helper(root->rightChild, sum, maxSum, len + 1, maxLen);
    }

public:
    /* Method to return the sum of longest path from root node to leaf node. */
    int sumOfLongRootToLeafPath(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            return 0;
        }

        int len = 0;
        int maxLen = 0;

        int sum = 0;
        int maxSum = INT_MIN;

        helper(root, sum, maxSum, len, maxLen);
        return maxSum;
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


    In this case more than one longest path exists:
    1. 1 -> 3 -> 7, Sum of (1,3,7) = 11
    2. 1 -> 3 -> 11, Sum of (1,3,11) = 15
    3. 1 -> 5 -> 17, Sum of (1,5,17) = 23 (this path having the Maximum sum so our answer is 23).

    If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

    Output: 23

    */

    // Solution.
    Solution S;
    cout << "Maximum Sum : " << S.sumOfLongRootToLeafPath(root);
}