/*
## What is Inorder Predecessor ? ##

Lets take an example to understand this,
Example Tree:-
                            1
                         /     \
                        3        5
                      /  \      /
                     7    11   17

Inorder Traversal of above tree is: 7, 3, 11, 1, 17, 5

Inorder Predecessor of 7 is nothing (because there is no value before 7).
Inorder Predecessor of 3 is 7.
Inorder Predecessor of 11 is 3.
Inorder Predecessor of 1 is 11.
Inorder Predecessor of 17 is 1.
Inorder Predecessor of 5 is 17.

## What is Inorder Successor ? ##
Inorder Traversal of above tree is: 7, 3, 11, 1, 17, 5

Inorder Successor of 7 is 3.
Inorder Successor of 3 is 11.
Inorder Successor of 11 is 1.
Inorder Successor of 1 is 17.
Inorder Successor of 17 is 5.
Inorder Successor of 5 is nothing (because there is no value after 7).

## How to find inorder predecessor ?

A simple approach is to store the inorder traversal of Binary Tree and find the inorder predecessor of any given element.Now, If you want to find the inorder predecessor without storing the inorder traversal, see the example below,

Lets say you have to find the predessor of 1.
Lets take currentNode = 1;
Now, to find predessor of 1 move one node towards left i.e., currentNode -> lefcurrentNode -> left = 3, now currentNode = 3.

Now, from here the rightmost child node is our inorder predecessor.
The right most childnode is 3 is 11.So, the predecessor of 1 is 11.



## How to find inorder Successor ?

A simple approach is to store the inorder traversal of Binary Tree and find the inorder seccessor of any given element. Now, If you want to find the inorder successor without storing the inorder traversal, see the example below,

Lets say you have to find the predessor of 1.

Lets take currentNode = 1;
Now, to find successor of 1 move one node towards right i.e., currentNode -> right, currentNode -> right = 5, now currentNode = 5.

Now, from here the leftmost child node is our inorder successor.
The left most childnode is 5 is 17.

So, the successor of 1 is 17.


In case of BST we can say that,

Inorder predecessor of node with value n: is the maximum value in left subtree.
Inorder successor of node with value n: is the minimum value in right subtree.
*/

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

    /* Binary Search. */
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
    int binarySearch(vector<int> arr, int key)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                // key found.
                return mid;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // key not found.
        return -1;
    }

public:
    /* Approach 1: Store the inorder traversal of BST into a vector and return the inorder predecessor and successor of given element. */
    // first block of pair represents the inorder predecessor.
    // second block of pair represents the inorder successor.

    // Time Complexity: O(n), n is the number of nodes in a BST.
    // Space Complexity: O(n), vector is used for storing inorder traversal.
    pair<int, int> predecessorSuccessor(BSTNode *root, int key)
    {
        // Step 1: store the inorder traversal of BST into a vector.
        vector<int> inorder;
        MorrisTraversal(root, inorder);

        // Step 2: find the key into the inorder vector.
        // for finding the index of key i am using Binary Search.
        int idxOfKey = binarySearch(inorder, key);

        // Step 3: return inorder predecessor and inorder successor.
        pair<int, int> ans;
        if (idxOfKey == 0)
        {
            // if index of key is 0, in this case inorder predecessor of key does not exists.
            ans.first = -1;
            ans.second = inorder[idxOfKey + 1];
            return ans;
        }
        if (idxOfKey == (inorder.size() - 1))
        {
            // if index of key is inorder.size() - 1, in this case inorder successor of key does not exists.
            ans.second = -1;
            ans.first = inorder[idxOfKey - 1];
            return ans;
        }

        // normal case
        ans.first = inorder[idxOfKey - 1];
        ans.second = inorder[idxOfKey + 1];
        return ans;
    }

    /* Approach 2: In case of BST, Inorder predecessor of node with value n is the maximum value in left subtree and Inorder successor of node with value n is the minimum value in right subtree. */
    // first block of pair represents the inorder predecessor.
    // second block of pair represents the inorder successor.

    // Time Complexity: O(n), n is the number of nodes in a BST.
    // Space Complexity: O(1)
    pair<int, int> predecessorSuccessor_Optimized(BSTNode *root, int key)
    {
        // Step 1:- find node.
        BSTNode *curr = root;
        int predecessor = -1;
        int successor = -1;
        while (curr->data != key)
        {
            if (curr->data < key)
            {
                // curr->data is less than key, it means this node may be a possible predecessor so store it.
                predecessor = curr->data;
                curr = curr->right;
            }
            else
            {
                // curr->data is greater than key, it means this node may be a possible successor so store it.
                successor = curr->data;
                curr = curr->left;
            }
        }

        /*

        To find predecessor of x:-
        Step 1:- find x.
        Step 2:- move to left one step and from here the rightmost node is the predecessor of x.

        To find successor of x:-
        Step 1:- find x.
        Step 2:- move to right one step and from here the leftmost node is the successor of x.

        */
        BSTNode *leftTree = curr->left;
        while (leftTree != NULL)
        {
            predecessor = leftTree->data;
            leftTree = leftTree->right;
        }

        BSTNode *rightTree = curr->right;
        while (rightTree != NULL)
        {
            successor = rightTree->data;
            rightTree = rightTree->left;
        }

        // Step 3: return ans.
        pair<int, int> ans = {predecessor, successor};
        return ans;
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
    int key = 3;
    pair<int, int> ans = S.predecessorSuccessor_Optimized(root, key);
    cout << "Inorder Predecessor of " << key << " is " << ans.first << ".\n";
    cout << "Inorder Successor of " << key << " is " << ans.second << ".\n";
}