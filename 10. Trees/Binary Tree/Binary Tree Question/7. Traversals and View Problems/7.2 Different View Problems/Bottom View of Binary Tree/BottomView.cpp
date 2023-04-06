/*
Question:-
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.

For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

For the above tree the output should be 5 10 4 14 25.

Approach:-

<0> = 20
<-1> = 8
<1> = 22
<-2> = 5


<0> = 3 // remove old value of 0 (which is 20).
<0> = 4 // remove old value of 0 (which is 3).

<2> = 25

<-1> = 10 // remove old value of -1 (which is 8).

<1> = 14 // remove old value of  1 (which is 22).

Now print all hd's in sorted order,

hd :- -2, -1, 0 ,1, 2
ans:-  5, 10, 4, 14, 25



*/

#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Method to return a list of nodes visible from the bottom view from left to right in Binary Tree. */
    // Time Complexity :- O(n log n), n is the number of nodes in a binary tree.
    // Space Complexity :- O(n)
    vector<int> bottomView(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            return {};
        }

        // vector to store answer (top view).
        vector<int> ans;

        // map to store one to one mapping of horizontal distance and node's data.
        // first block of int in map is used to store horizontal distance.
        // second block of int in map is used to store node's data.
        map<int, int> mpp;

        // queue.
        // first block of pair is used to store binary tree node.
        // second block of pair is used to calculate horizontal distance.
        queue<pair<Node *, int>> q;

        // push root node into the queue.
        // initially horiaontal distance is 0.
        q.push({root, 0});

        // traverse the queue.
        while (!q.empty())
        {
            // take out the front element opf the queue.
            pair<Node *, int> frontElement = q.front();

            // pop the front element of the queue.
            q.pop();

            // Now, take out the Node and horizontal distance from the frontElement.
            Node *frontNode = frontElement.first;
            int hz = frontElement.second; // hz means horizontal distance.

            // For any particula horizontal distance, we need to store the value which appears at the end.
            // at any particular hd, if value is exist, we will rewrite it.
            // if value doesn't exist, then we will store it.
            mpp[hz] = frontNode->data;

            // push the left and right child nodes.
            if (frontNode->leftChild != NULL)
            {
                q.push({frontNode->leftChild, hz - 1});
            }
            if (frontNode->rightChild != NULL)
            {
                q.push({frontNode->rightChild, hz + 1});
            }
        }

        // store the answer.
        for (auto i : mpp)
        {
            ans.push_back(i.second);
        }

        // return answer.
        return ans;
    }

    /* Method to print vector */
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
    vector<int> ans = S.bottomView(root);
    S.printVec(ans);

}