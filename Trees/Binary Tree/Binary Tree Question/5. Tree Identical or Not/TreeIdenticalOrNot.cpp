/*
Question:- Given two binary trees, the task is to find if both of them are identical or not.

Example 1:

Input:
     1          1
   /   \      /   \
  2     3    2     3

Output: Yes


Example 2:
Input:
    1       1
  /  \     /  \
 2    3   3    2

Output: No

Explanation: Different node value are found. First tree => 1->left = 2, Second Tree => 1-> left = 3.
*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------- Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /*
    Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */
    bool isSameTree(Node *p, Node *q)
    {
        // Base Case
        if (p == NULL && q == NULL)
        {
            // If both points to NULL, it means at this point trees are identical return true.
            return true;
        }

        if (p == NULL || q != NULL)
        {
            // If one of them points to NULL, it means trees are not identical return false.
            return false;
        }


        // Recursive Case

        // Checking if the left subtree is identical or not.
        bool isLeftIdentical = isSameTree(p->leftChild, q->leftChild);

        // Checking if the right subtree is identical or not.
        bool isRightIdentical = isSameTree(p->rightChild, q->rightChild);

        // Comparing the value.
        bool compare = p->data == q->data;

        // If the above 3 conditions are true, it means the both the trees are identical.
        if (isLeftIdentical && isRightIdentical && compare)
        {
            return true;
        }
        else
        {
            return false;
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
    if (S.isSameTree(root, root))
    {
        cout << "Identical.";
    }
    else
    {

        cout << "Not Identical.";
    }
}