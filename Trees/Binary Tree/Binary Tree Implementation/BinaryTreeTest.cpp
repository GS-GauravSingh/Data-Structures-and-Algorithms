#include <bits/stdc++.h>
#include "BinaryTreeImplementation.h"
using namespace std;

int main(void)
{
    // Creating a root node of the Binary tree.
    Node *root = NULL;

    // Building Tree (PreOrder Build).
    // BinaryTree BT;
    // BT.buildTreePreOrder(root);

    // Building Tree (LevelOrder Build).
    BinaryTree BT;
    BT.buildTreeLevelOrder(root);

    /*
    Example Build :-
    Input for Pre-Order Build :- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Input for Level Order Build :- 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    Tree preview :-
                                            1
                                         /     \
                                        3        5
                                      /  \      / \
                                     7    11   17 -1(NULL)
                                    / \  / \   / \
                                  -1 -1 -1 -1 -1 -1
    */

    // Printing Tree.
    cout << "\nLevel Order Traversal of Binary Tree,\n";
    BT.LevelOrderTraversal(root);

    cout << "In-Order Traversal of Binary Tree,\n";
    BT.InOrderTraversalRecursive(root);

    cout << "\nPre-Order Traversal of Binary Tree,\n";
    BT.PreOrderTraversalRecursive(root);

    cout << "\nPost-Order Traversal of Binary Tree,\n";
    BT.PostOrderTraversalRecursive(root);
}