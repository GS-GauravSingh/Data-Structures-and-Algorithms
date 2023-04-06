#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Morris (Inorder) Traversal. */
    // Time Complexity of Morris Traversal: O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity of Morris Traversal: O(1), because Morris traversal is an iterative algorithm.
    void MorrisTraversal(BSTNode *root, vector<int> &inorderTraversal)
    {
        // Initialize the root as the current node.
        BSTNode *currentNode = root;

        // Run a While loop till currentNode is not null.
        while (currentNode != NULL)
        {
            // check if curr has a left child.
            if (currentNode->left == NULL)
            {
                // If curr does not have a left child, print curr and move right (curr->right).
                inorderTraversal.push_back(currentNode->data);
                currentNode = currentNode->right;
            }
            else
            {
                // Else If curr has a left child, then find the inorder predecessor.
                BSTNode *predecessor = currentNode->left;
                while (predecessor->right != NULL && predecessor->right != currentNode)
                {
                    predecessor = predecessor->right;
                }

                // make temporary connection with currentNode.
                if (predecessor->right == NULL)
                {
                    // if predecessor -> right == NULL,
                    // then make temporary link with currentNode.
                    // predecessor -> right = currentNode and then move left (currentNode->left).
                    predecessor->right = currentNode;
                    currentNode = currentNode->left;
                }

                // remove temporary connection.
                else
                {
                    // if predecessor -> right != NULL, then remove temporary link with current.
                    // predecessor -> right = NULL, print current -> data and move right.
                    predecessor->right = NULL;
                    inorderTraversal.push_back(currentNode->data);
                    currentNode = currentNode->right;
                }
            }
        }
    }

public:
    /* Approach: Store the Inorder traversal of BST, as we know that the inorder traversal of BST comes out in sorted order, and after that create a linked list. */

    /* Method that flatten BST into a Sorted Linked List. */

    // Time Complexity: O(n), n is the number of nodes in the BST.
    // Space Complexity: O(n), space used by vector.
    BSTNode *flatten(BSTNode *root)
    {
        // Step 1: store the inorder traversal of BST.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: create a linked list using inorder vector.
        BSTNode *head = NULL;
        BSTNode *tail = NULL;
        for (auto data : inorder)
        {
            // creating a node.
            BSTNode *newNode = new BSTNode(data);

            // inserting node in a linked list.
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->right = newNode;
                tail = newNode;
            }
        }

        // Step 3: return the head of linked list.
        return head;
    }
};

int main(void)
{
    /*
    Sample Inputs:
    I/O 1 : 1 2 3 4 7 -1
    I/O 2 : 10 2 3 8 9 4 7 -1
    */

    // Creating root node of BST.
    BSTNode *root = NULL;

    // Building Binary Search Tree.
    BinarySearchTree bst;
    bst.takeInput(root);

    // Solution.
    Solution S;
    BSTNode *head = S.flatten(root);

    // Printing linked list.
    BSTNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->right;
    }
    cout << "NULL";
}