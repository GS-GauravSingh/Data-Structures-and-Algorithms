/*
Height of Binary Tree:-

1. Height of the tree is the maximum levels we have in a tree or,
2. Height of the tree is the longest path from root node to the deepest leaf node. So, the number of nodes in this longest path from root to the deepest leaf node is the height of the tree.

Note :- Depth of the tree = height of the tree.

Example Tree:-
                                            1           ---- Level 1, Height 1, Depth 1
                                         /     \
                                        3        5      ---- Level 2, Height 2, Depth 2
                                      /  \      /
                                     7    11   17       ---- Level 3, Height 3, Depth 3

Approach 1:- traverse the tree using level order traversal and count the number of level we have in the tree.

Height of binary tree = number of levels in a tree.

Approach 2:- calculate the height of left subtree and right subtree,
take the maximum of left and right and add 1 (root node).
int ans = max(left, right) + 1; // +1 is for adding root node.

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
    Approach 1:- traverse the tree using level order traversal and count the number of level we have in the tree.

    Height of binary tree = Number of levels in a tree.

    Time Complexity :- O(n), n is the number of nodes is a Binary Tree.
    Space Complexity :- O(n), for queue data structure.
    */
    int heightOfTheTree_Approach_1(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Height of Empty Tree is 0.
            return 0;
        }

        // declaring the queue.
        queue<Node *> q;

        // pushing the root node into the queue.
        q.push(root);

        // pushing delimiter that represent the end of a particular level.
        q.push(NULL);

        // variable to store height or depth of the tree.
        int height = 0;

        // Level Order Traversal.
        while (!q.empty())
        {
            // take out the front node of the queue.
            Node *frontNode = q.front();

            /* If frontNode == NULL, it means current level has ended and our queue will contain the child nodes of the nodes present at this current level.

            So, increment the height and push the delimiter again for the next level only if the queue is not empty if the queue is empty it means we are at the last level because the nodes present at this level(a level which has ended) have no child nodes.
            */
            if (frontNode == NULL)
            {
                // incrementing the height.
                height++;

                // popping the delimiter that represent the current level which has ended.
                q.pop();

                // pushing the new delimiter for upcomming level.
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                // pop the front element of the queue.
                q.pop();

                // push the left and right child nodes if exists.
                if (frontNode->leftChild != NULL)
                {
                    q.push(frontNode->leftChild);
                }

                if (frontNode->rightChild != NULL)
                {
                    q.push(frontNode->rightChild);
                }
            }
        }

        // return the height of the tree.
        return height;
    }

    /*
    Approach 2:- calculate the height of left subtree and right subtree,
    take the maximum of left and right and add 1 (root node).

    int ans = max(left, right) + 1; // +1 is for adding root node.

    Time Complexity :- O(n), n is the number of nodes is a Binary Tree.
    Space Complexity :- O(n), recursive stack space.
    */
    int heightOfTheTree_Approach_2(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Height of Empty Tree is 0.
            return 0;
        }

        // Recursive Case.
        // Calculate the height of left subtree.
        int leftHeight = heightOfTheTree_Approach_2(root->leftChild);

        // Calculate the height of right subtree.
        int rightHeight = heightOfTheTree_Approach_2(root->rightChild);

        // take the maximum height from the left or right subtree and add 1 for the heigh of the root node.
        int maxHeight = max(leftHeight, rightHeight) + 1;

        // return maxHeight.
        return maxHeight;
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
    */

    /*
    Exmaple TestCases:-

    Ex 1:-  1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , Height = 3.
    view:-                      1                           level 0 (0-based indexing of levels).
                        3               5                   level 1
                    7      11       17      -1              level 2
                -1  -1  -1  -1   -1   -1                    level 3


    Ex 2:-  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, Height = 4.
    view:-                          1                        level 0 (0-based indexing of levels).
                        2                   3                level 1
                    4       5           -1      6            level 2
                -1  -1   7   -1             -1   -1          level 3
                    -1  -1                                   level 4

    */

    // Solution.
    Solution S;
    cout << "(Approach 1) Height or Depth of the Tree is " << S.heightOfTheTree_Approach_1(root) << "." << endl;
    cout << "(Approach 2) Height or Depth of the Tree is " << S.heightOfTheTree_Approach_2(root) << "." << endl;
}