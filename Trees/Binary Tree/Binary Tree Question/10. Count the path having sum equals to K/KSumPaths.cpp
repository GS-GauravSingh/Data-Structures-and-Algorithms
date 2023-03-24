/*
Question:-
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.


Example 1:

Input:
Tree =
          1
        /   \
       2     3
K = 3
Output: 2

Explanation:
Path 1 : 1 + 2 = 3
Path 2 : only leaf node 3
Example 2:

Input:
Tree =
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6
K = 5
Output: 8

Explanation:
The following paths sum to K.
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5

Since the answer may be very large, compute it modulo 10^9 + 7.
Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(Height of Tree)
*/

#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Helper Method to return the total number of paths having sum equals to k. */
    // Time Complexity :- O(n^2), n is the number of node in a Binary Tree.
    // Space Complexity :- O(h), h is the height of the tree.
    void helper(Node *root, int k, int &count, vector<int> path)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recursive Case.
        // push current node into the path.
        path.push_back(root->data);

        // recursive call.
        helper(root->leftChild, k, count, path);
        helper(root->rightChild, k, count, path);

        // Backtracking Step (while returning back from the base case).
        // When you reached the base case, the path vector will contain all the nodes' data that comes in this path.
        // Now, Simply iterate the path vector, from back and check if there is any nodes present in the path vector whose sum is equal to the given value k. If present then increment the count, otherwise don't do anything.
        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];

            if (sum == k)
            {
                count++;
            }
        }

        // while returning back from this node, delete this node from the path vector.
        path.pop_back();
    }

public:
    /* Method to return the total number of paths having sum equals to k. */
    int sumK(Node *root, int k)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        // path vector.
        vector<int> path;

        // to store total number of path whose summation equals to k.
        int count = 0;

        helper(root, k, count, path);
        return count;
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

    for k = 11, only 2 path exists, 
    1. 1 -> 3 -> 7.
    2. 11 (the leaf node).

    */

    // Solution.
    Solution S;
    int k = 11;
    cout << "Total Path having Sum equals to K : " << S.sumK(root, k) << ".";
}