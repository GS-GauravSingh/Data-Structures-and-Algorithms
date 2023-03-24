#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to return the maximum sum of adjacent nodes. */
    // Time Complexity :- O(n), n is the number of node in a Binary Tree.
    // Space Complexity :- O(n), recursive stack space.

    // First block of pair is used to store the sum including the current level node.
    // Second block of pair is used to store the sum excluding the current level node.
    pair<int, int> helper(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {0, 0};
        }

        // Recursive case
        pair<int, int> leftAns = helper(root->leftChild);
        pair<int, int> rightAns = helper(root->rightChild);

        // Backtracking step (while comming back from the base case).

        // if your are including the current node,
        // then you have to exclude the child nodes of current node.
        pair<int, int> ans;
        ans.first = root->data + leftAns.second + rightAns.second;

        // if your are excluding the current node,
        // then you have to include the child nodes of current node.
        ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return ans;
    }

public:
    /* Method to return the maximum sum of adjacent nodes. */
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
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
    cout << S.getMaxSum(root);
}