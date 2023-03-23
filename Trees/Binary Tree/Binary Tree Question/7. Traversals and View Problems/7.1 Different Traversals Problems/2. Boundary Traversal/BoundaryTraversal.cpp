/*
Question:
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Example:-
Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

Boundary Traversal: 1 2 4 8 9 6 7 3 1

Approach:-
step 1:- print left nodes, excluding leaf nodes.
step 2:- print leaf nodes, from left to right.
step 3:- print right nodes in reverse order.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.
*/
#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Printing/Storing the left Boundary. */
    /*
    Approach:- Print/Store all the left node except for the leaf node.
    Example:
    Input:
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
                / \
                8   9

    All left nodes are: 1 2 (4 is a leaf node that's why we left that node).
    We handle the leaf node in a separate function.
    */
    void leftboundaryTraversal(Node *root, vector<int> &leftBoundary)
    {
        // Base case
        if (root == NULL)
        {
            // this is a normal base case that we use in almost every tree question.
            return;
        }
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            // this is a main base case.
            // Skipping the leaf node.
            return;
        }

        // Recursive case.
        // store the leftmost node and move towards the base case.
        leftBoundary.push_back(root->data);

        // move left if exist otherwise move right.
        if (root->leftChild != NULL)
        {
            leftboundaryTraversal(root->leftChild, leftBoundary);
        }
        else
        {
            leftboundaryTraversal(root->rightChild, leftBoundary);
        }
    }

    /* Printing/Storing the leaf nodes. */
    /*
    Approach:- Print/Store all the leaf node.
    Example:
    Input:
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
                / \
                8   9

    All leaf nodes are: 4 5 8 9 6 7.
    */
    void leafTraversal(Node *root, vector<int> &leafNode)
    {
        // Base case
        if (root == NULL)
        {
            // this is a normal base case that we use in almost every tree question.
            return;
        }
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            // if it is a leaf node, then store it.
            leafNode.push_back(root->data);
            return;
        }

        // Recursive case.
        leafTraversal(root->leftChild, leafNode);
        leafTraversal(root->rightChild, leafNode);
    }

    /* Printing/Storing the leaf nodes. */
    /*
    Approach:- Print/Store all the leaf node.
    Example:
    Input:
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
                / \
                8   9

    All Right nodes in reverse order: 3 1.
    */
    void rightBoundaryTraversal(Node *root, vector<int> &rightBoundary)
    {
        // Base case
        if (root == NULL)
        {
            // this is a normal base case that we use in almost every tree question.
            return;
        }
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            // skip the leaf node.
            return;
        }

        // Recursive case.
        if (root->rightChild != NULL)
        {
            rightBoundaryTraversal(root->rightChild, rightBoundary);
        }
        else
        {
            rightBoundaryTraversal(root->leftChild, rightBoundary);
        }

        // Store answer.
        rightBoundary.push_back(root->data);
    }

public:
    /* Methods or Behavior of Solution Class. */

    /* Boundary Traversal. */
    // Time Complexity: O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity: O(h), h si the height of the tree. 
    vector<int> boundaryTraversal(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            return {root->data};
        }

        // Step 1:- first push the root->data into our answer.
        vector<int> ans;
        ans.push_back(root->data);

        // Step 2:- store the left boundary except the leaf node.
        leftboundaryTraversal(root->leftChild, ans);

        // Step 3:- store all leaf nodes.
        leafTraversal(root, ans);

        // Step 4:- store the right boundary in reverse order except the leaf node.
        rightBoundaryTraversal(root->rightChild, ans);

        // Step 5:- return answer.
        return ans;
    }

    /* Method to print vector. */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
    vector<int> ans = S.boundaryTraversal(root);
    cout << "Boundary Traversal:\n";
    S.printVec(ans);
}