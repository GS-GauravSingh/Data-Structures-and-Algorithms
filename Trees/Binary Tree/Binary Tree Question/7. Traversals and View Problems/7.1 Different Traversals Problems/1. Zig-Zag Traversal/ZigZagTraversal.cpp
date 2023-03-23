#include <bits/stdc++.h>
#include "../../../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Methods or Behavior of Solution Class. */

    /* Zig-Zag Traversal. */
    // Time COmplexity: O(n), n is the number of nodes in a Binary Tree.
    // Space COmplexity: O(n), space used by queue.
    vector<vector<int>> zigzagLevelOrder(Node *root)
    {
        // Some modification in level order traversal will give the correct answer.

        // vector to store answer.
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        // declaring a queue of type Node*.
        queue<Node *> q;

        // push root node into the queue.
        q.push(root);

        // flag to find the direction.
        bool leftToRight = true;

        // traverse the queue.
        while (!q.empty())
        {
            // getting the size of the queue.
            int sizeOfQueue = q.size();

            // vector to store nodes of current level.
            // total number of nodes in the current level = sizeOfQueue.
            vector<int> nodesAtCurrentLevel(sizeOfQueue);

            // processing current level, storing data in normal or reverse order.
            for (int i = 0; i < sizeOfQueue; i++)
            {
                // tak out the front element of the queue and then pop the front element.
                Node *frontNode = q.front();
                q.pop();

                // important Step.
                // Normal or reverse insertion.
                // If the flag leftToRight = true, then insert element in normal order i.e., from index 0 to sizeOfQueue -1.
                // but If the flag leftToRight = false, then insert element in reverse order i.e., from index sizeOfQueue -1 to 0.
                int indexToInsert = (leftToRight == true) ? i : sizeOfQueue - i - 1;
                nodesAtCurrentLevel[indexToInsert] = frontNode->data;

                // push left and right child of front node if exists.
                if (frontNode->leftChild != NULL)
                {
                    q.push(frontNode->leftChild);
                }
                if (frontNode->rightChild != NULL)
                {
                    q.push(frontNode->rightChild);
                }
            }

            // change the direction.
            leftToRight = !leftToRight;

            // store the answer.
            result.push_back(nodesAtCurrentLevel);
        }

        // return answer.
        return result;
    }

    /* Method to print 2D vector. */
    void print2DVec(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
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

    cout<<"Level Order Traversal:\n";
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

    Zig-Zag Traversal: 1 5 3 7 11 17

    Level 1 (Left to Right): 1
    Level 2 (Right to Left): 5 3
    Level 3 (Left to Right): 7 11 17
    */

    // Solution.
    Solution S;
    vector<vector<int>> ZigZagTraversal = S.zigzagLevelOrder(root);
    cout<<"Zig-Zag Traversal:\n";
    S.print2DVec(ZigZagTraversal);
}