#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* --------------------------- Solution Class ----------------------------------- */
class Solution
{
private:
public:
    /* Method to count leaf nodes.
    Approach :- Traverse the Binary Tress using any traversal of your choice and find the leaf node.
    */
    // Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the Binary Tree.
    void countLeafNodes(Node *root, int &leafCount)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case
        countLeafNodes(root->leftChild, leafCount);
        countLeafNodes(root->rightChild, leafCount);

        // A leaf is a node that does not have a child node in the tree.
        // condition for leaf node.
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            leafCount++;
        }
    }
};
int main(void)
{
    // Creating a root node of the Binary tree.
    Node *root = NULL;

    // Building Tree (PreOrder Build).
    BinaryTree BT;
    BT.buildTreePreOrder(root);

    // Building Tree (LevelOrder Build).
    // BinaryTree BT;
    // BT.buildTreeLevelOrder(root);

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

    In the above Binary Tree, there is a total of 3 leaf nodes which are 7, 11, and 17.
    */

    Solution S;
    int leafCount = 0;
    S.countLeafNodes(root, leafCount);
    cout
        << "Total Leaf Node : " << leafCount << ".";
}