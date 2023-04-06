#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Method to return a list containing elements of right view of the binary tree. */
    // Time Complexity :- O(n), n is the number of nodes in a binary tree.
    // Space Complexity :- O(n), space used by queue.
    vector<int> rightView(Node *root)
    {
        /*
        Approach:- Traverse the tree using level order traversal and store the last node of each level ( from right) in our answer.
        */

        // Base Case
        if (root == NULL)
        {
            return {};
        }

        // declaring of queue of type Node*.
        queue<Node *> q;

        // pushing the root node into the queue.
        q.push(root);

        // vector to store answer.
        vector<int> ans;

        // traverse the queue.
        while (!q.empty())
        {
            // gettig the size of the queue.
            int sizeOfQueue = q.size();

            // process the nodes at current level.
            for (int i = 1; i <= sizeOfQueue; i++)
            {
                // take out the front node fromt the queue.
                Node *frontNode = q.front();

                // pop the front element from the queue.
                q.pop();

                // when i == sizeOfQueue, it means this frontNode is the last element/node of current level
                // Store it.
                if (i == sizeOfQueue)
                {
                    ans.push_back(frontNode->data);
                }

                // push the left and right child of front node.
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

        // return ans.
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
    vector<int> ans = S.rightView(root);
    S.printVec(ans);
}