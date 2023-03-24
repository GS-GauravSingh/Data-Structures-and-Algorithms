/*
Question:-
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Example 1:

Input:
n1 = 2 , n2 = 3
       1
      / \
     2   3
Output: 1

Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
           5
          /
         2
        / \
       3   4
Output: 2

Explanation:
LCA of 3 and 4 is 2.

Expected Time Complexity:- O(N).
Expected Auxiliary Space:- O(Height of Tree).
*/

#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Method to return the LCM of 2 nodes. */
    // Time Complexity :- O(n), n is the number of node in a Binary Tree.
    // Space Complexity :- O(n), recursive stack space.
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
    {
        // Base Case
        if(root == NULL)
        {
            // if root points to null, simply return from there.
            // In means, in this path is no such node(p or q) exists , that's why we reached to null.
            // Simply return NULL from here.
            return NULL;
        }

        // Find the given nodes (p or q).
        if((root->data == p->data) || (root->data == q->data))
        {
            // if we are able to find one of the node. the simply return that node.
            return root;
        }

        // Recursive Case
        Node* leftAns = lowestCommonAncestor(root->leftChild, p, q);
        Node* rightAns = lowestCommonAncestor(root->rightChild, p, q);

        if(leftAns != NULL && rightAns != NULL)
        {
            // For any particul node, if laftAns and rightAns both are not NULL, it means we are able to find both the node and their LCA is the current root node.
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
        {
            // if leftAns is successfull in finding p or q, in that case simply return leftAns;
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL)
        {
            // if rightAns is successfull in finding p or q, in that case simply return rightAns;
            return rightAns;
        }
        else{
            // if leftAns and rightAns both are not successfull in finding p or 1, in that case simply return NULL;
            return NULL;
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

    LCA(7, 11) = 3.
    LCA(7, 17) = 1.
    LCA(11, 17) = 1.
    LCA(3, 5) = 1.

    */

    // Solution.
    Solution S;
    Node *p = new Node(7);
    Node *q = new Node(17);

    Node *LCA = S.lowestCommonAncestor(root, p, q);
    cout << "LCA(" << p->data << ", " << q->data << ") = " << LCA->data << ".\n";
}