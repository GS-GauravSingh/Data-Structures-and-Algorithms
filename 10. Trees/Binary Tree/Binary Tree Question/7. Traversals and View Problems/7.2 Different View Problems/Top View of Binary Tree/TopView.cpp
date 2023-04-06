/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6      7

Top view will be: 4 2 1 3 7

Note: Return nodes from leftmost node to rightmost node.

Exmaple 1:-
Input:

       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Approach:- Approach same as vertical order traversal,

<level 0, number 0 on no. line> = 10

<level 1, number -1 on no. line> = 20
<level 1, number  1 on no. line> = 30

<level 2, number  -2 on no. line> = 40
<level 2, number   0 on no. line> = 60, 90, but at <level 0 and no. 0> pe phele hi ek value aa chuki hai (10) toh agar hum top se dekhenge toh 60 and 90 jo hai ye 10 ke niche aayenge like this,
10
60
90

toh hume upar se sirf 10 hi dikhayi dega toh hum 60 and 90 ko ignore karenge.

<level 2, number  2 on no. line> = 100

Note:- so, we need only one value at any particular horizontal distance.
So we need a map to store 1 to 1 mappinp of hd -> Node.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N).
*/
#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Method to return a list of nodes visible from the top view from left to right in Binary Tree. */
    // Time Complexity :- O(n log n), n is the number of nodes in a binary tree.
    // Space Complexity :- O(n)
    vector<int> topView(Node *root)
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

            // Now, store the one to one mapping of horizontal distance and node's data.
            // At any particular hd, if value doesn't exists in map only then we have to insert the value.
            // if value already exist's in the map, in that case do nothing.
            if (mpp.find(hz) == mpp.end())
            {
                mpp[hz] = frontNode->data;
            }

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
    void printVec(vector<int> &arr)
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
    vector<int> ans = S.topView(root);
    S.printVec(ans);
}