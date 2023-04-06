/*
Question:-
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.

If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9

Approach:-
Suppose there is a number line.

          -2  -1   0    1   2   3
                   1                                level 0
                 /   \
               2       3                            level 1
             /   \   /   \
           4      5 6      7                        level 2
                      \      \
                       8      9                     level 3

Now, when youn traverse the tree using level order traversal.

for level 0 and for number 0 on number line the answer is = 1

for level 1 and for number -1 on number line the answer is = 2
for level 1 and for number 1 on number line the answer is = 3

for level 2 and for number -2 on number line the answer is = 4
for level 2 and for number 0 on number line the answer is = 5, 6
for level 2 and for number 2 on number line the answer is = 7

for level 3 and for number 1 on number line the answer is = 8
for level 3 and for number 3 on number line the answer is = 9

Summarize:- (level, point on number line) = list of data.

(level 0, number 0) = 1,5,6
(level 1, number -1) = 2
(level 1, number 1) = 3
(level 2, number -2) = 4
(level 2, number 2) = 7
(level 3, number 1) = 8
(level 3, number 3) = 9

Now, print all vector in single line in sorted order(sort according to number line, means first -2, -1, 0 ,1, 2, 3, and so on.)

-2 = 4
-1 = 2
0 = 1,5,6
1 = 3,8
2 = 7
3 = 9

Answer = {4,2,1,5,6,3,8,7,9}
our answer is same as Output:- 4 2 1 5 6 3 8 7 9

*/
#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Vertical Order Traversal */
    // Time Complexity:- O(N log N), N is the number of nodes in a binary tree.
    // Space Complexity:- O(N)
    vector<int> verticalTraversal(Node *root)
    {

        // Base Case
        if (root == NULL)
        {
            return {};
        }

        // map to store horizontal distance, level and nodes at particular horizontal distance and level.
        // first int in below map is used to store horizontal distance.
        // first int in nested map is used to level.
        // vector<int> in nested map is used to nodes at particular horizontal distance and level.
        map<int, map<int, vector<int>>> mpp;

        // queue.
        // First pair is used to store the Node.
        // First int, in nested pair is used to store horizontal distance.
        // Second int, in nested pair is used to store level.
        queue<pair<Node *, pair<int, int>>> q;

        // push the root node into the queue.
        // Initially level and horizontal distance both will be 0.
        q.push({root, {0, 0}});

        // traverse the queue.
        while (!q.empty())
        {
            // take out the front element form the queue.
            pair<Node *, pair<int, int>> frontElement = q.front();

            // pop the front element of the queue.
            q.pop();

            // Now, from the frontElement, take out the node, horizontal distance and level.
            Node *frontNode = frontElement.first;
            int hz = frontElement.second.first;   // horizontal distance.
            int lvl = frontElement.second.second; // level.

            // store horizontal distance, level and nodes at particular horizontal distance and level.
            mpp[hz][lvl].push_back(frontNode->data);

            // Push left and right child of front node.
            // When pushing the left child, decrement the horizontal distance by 1 and increment the level by 1.
            if (frontNode->leftChild != NULL)
            {
                q.push({frontNode->leftChild, {hz - 1, lvl + 1}});
            }
            // When pushing the right child, increment the horizontal distance by 1 and increment the level by 1.
            if (frontNode->rightChild != NULL)
            {
                q.push({frontNode->rightChild, {hz + 1, lvl + 1}});
            }
        }

        // store the answer.
        vector<int> result;

        for (auto i : mpp)
        {
            // i will point to => map<int, map<int, vector<int>>>
            // i.second will point to => map<int, vector<int>> (nested map).

            for (auto j : i.second)
            {
                // j will point to => map<int, vector<int>> (nested map).
                // j.second will point to => vector<int>
                for (auto k : j.second)
                {
                    result.push_back(k);
                }
            }
        }

        // return answer.
        return result;
    }

    /* Method to print Vector. */
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
    vector<int> ans = S.verticalTraversal(root);
    S.printVec(ans);
}