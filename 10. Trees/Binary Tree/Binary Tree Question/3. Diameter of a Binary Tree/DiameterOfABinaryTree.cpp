/*
1. Diameter of Tree = The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root node.

2. The length of a path between two nodes is represented by the number of edges between them. Length = number of edges in the path.

3. Or, The length of a path between two nodes is represented by the number of nodes between them. Length = number of nodes in the path.

4. Whether to take length = number of edges in the path or length = number of nodes in the path. It is given in the question.

Example :
Input :
       1
     /  \
    2    3

Output: 3
Explanation:
Longest Path : 3 -> 1 -> 2 or 2 -> 1 -> 3.
Diameter = no. of nodes in longest path = 3.
Diameter = no. of edges in longest path = 2.

Example Tree:-
                                            1           ---- Level 1, Height 1, Depth 1
                                         /     \
                                        3        5      ---- Level 2, Height 2, Depth 2
                                      /  \      /
                                     7    11   17       ---- Level 3, Height 3, Depth 3


Longest Path: 7 -> 3 -> 1 -> 5 -> 17 or 11 -> 3 -> 1 -> 5 -> 17
Diameter = no. of nodes in longest path = 5.
Diameter = no. of edges in longest path = 4.

*/
#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------- Solution Class ---------------------------------- */
class Solution
{
private:
    /*
    Method to calculate the height of the Binary Tree.

    Time Complexity :- O(n), n is the number of nodes is a Binary Tree.
    Space Complexity :- O(n), recursive stack space.
    */
    int heightOfTheTree(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            // Height of Empty Tree is 0.
            return 0;
        }

        // Recursive Case.
        // Calculate the height of left subtree.
        int leftHeight = heightOfTheTree(root->leftChild);

        // Calculate the height of right subtree.
        int rightHeight = heightOfTheTree(root->rightChild);

        // take the maximum height from the left or right subtree and add 1 for the heigh of the root node.
        int maxHeight = max(leftHeight, rightHeight) + 1;

        // return maxHeight.
        return maxHeight;
    }

public:
    /*
    Approach :- Our Longest path may exist in 3 directions,

                1. It may possible that Our Longest path exists in Left Subtree.
                2. It may possible that Our Longest path exists in Right Subtree.
                3. It may possible that Our Longest paths are the combination of some path of the Left subtree and some path of the Right Subtree.

    Time Complexity :- O(n^2), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */
    int diameterOfBinaryTree(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            // Diameter of Empty Tree is 0.
            return 0;
        }

        // Recursive Case.

        // 1. It may possible that Our Longest path exists in Left Subtree.
        int left = diameterOfBinaryTree(root->leftChild);

        // 2. It may possible that Our Longest path exists in Right Subtree.
        int right = diameterOfBinaryTree(root->rightChild);

        // 3. It may possible that Our Longest paths are the combination of some path of the Left subtree and some path of the Right Subtree.
        // In this case calculate the height of left and right subtree, and our answer is the summation of height of left subtree and height of right subtree + 1 (+1 is the height of the root node).
        int leftHeight = heightOfTheTree(root->leftChild);
        int rightHeight = heightOfTheTree(root->rightChild);
        int LeftAndRightDiameter = leftHeight + rightHeight + 1;

        // 4. Our ans is the maximum among the above 3 options.
        return max(left, max(right, LeftAndRightDiameter));
    }

    /* Optimizing Above Approach :- In above approach we are calculating the height separately, but there is no need for calculating the height separately. We can use the same diameter function to calculate the height.

    Time Complexity :- O(n), n is the number of nodes in a Binary Tree.
    Space Complexity :- O(n), recurive stack space.
    */
    // First block of pair represents diameter.
    // Second block of pair represent height.
    pair<int, int> diameterOfBinaryTree_Optimized(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            // Diameter of Empty Tree is 0.
            // Height of Empty Tree is 0.
            pair<int, int> DiameterAndHeight = make_pair(0, 0);
            return DiameterAndHeight;

            // or you can make pair like this {0,0}.
            // return {0,0};
        }

        // Recursive Case.

        // 1. It may possible that Our Longest path exists in Left Subtree.
        pair<int, int> left = diameterOfBinaryTree_Optimized(root->leftChild);

        // 2. It may possible that Our Longest path exists in Right Subtree.
        pair<int, int> right = diameterOfBinaryTree_Optimized(root->rightChild);

        // 3. It may possible that Our Longest paths are the combination of some path of the Left subtree and some path of the Right Subtree.
        // In this case calculate the height of left and right subtree, and our answer is the summation of height of left subtree and height of right subtree + 1 (+1 is the height of the root node).

        // First block of pair represents diameter.
        int leftDiameter = left.first;
        int rightDiameter = right.first;

        // Second block of pair represent height.
        int leftHeight = left.second;
        int rightHeight = right.second;
        int LeftAndRightDiameter = leftHeight + rightHeight + 1;

        // 4. Our ans is the maximum among the above 3 options.
        pair<int, int> ans;

        // storing the maximum diameter among the above 3 options.
        ans.first = max(leftDiameter, max(rightDiameter, LeftAndRightDiameter));

        // storing the height.
        ans.second = max(leftHeight, rightHeight) + 1;

        // return answer;
        return ans;
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

    Longest Path: 7 -> 3 -> 1 -> 5 -> 17 or 11 -> 3 -> 1 -> 5 -> 17
    Diameter = no. of nodes in longest path = 5.
    Diameter = no. of edges in longest path = 4.
    */

    // Solution.
    Solution S;
    cout << "Diameter of Binary Tree : " << S.diameterOfBinaryTree(root) << ".\n";
    cout << "Diameter of Binary Tree : " << S.diameterOfBinaryTree_Optimized(root).first << ".\n";
}