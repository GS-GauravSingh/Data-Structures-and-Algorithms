#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to convert BST into Sorted Linked List (In-Place). */
    // Time Complexity: O(n), n is the number of nodes in BST.
    // Space Complexity: O(h), h is the height of the BST.
    void convertBstToDoublyLinkedList(BSTNode *root, BSTNode *&head /* head of the linked list. */, BSTNode *&previous /* to make connection in linked list, we need the previous pointer. */)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        // Recrusive Case.

        // Traverse the BST using inorder traversal, because we have to convert BST into Sorted Linked List.

        // Move Left.
        convertBstToDoublyLinkedList(root->left, head, previous);

        // process root node.
        if (previous == NULL)
        {
            head = root;
            previous = root;
        }
        else
        {
            previous->right = root;
            root->left = previous; // this connection will create doubly linked list.

            // move previous pointer.
            previous = root;
        }

        // Move right.
        convertBstToDoublyLinkedList(root->right, head, previous);
    }

    /* Method to merge 2 sorted linked lists into single linked list. */
    // Time Complexity: O(m+n), m and n is the size of list1 and list2.
    // Space Complexity: O(1).
    BSTNode *merge2SortedDoublyLinkedLists(BSTNode *&list1, BSTNode *&list2)
    {
        // head and tail pointer of answer list.
        BSTNode *ansHead = NULL;
        BSTNode *ansTail = NULL;

        // traversing the lists.
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data < list2->data)
            {
                // make connections.
                if (ansHead == NULL)
                {
                    // connections.
                    ansHead = ansTail = list1;
                }
                else
                {
                    // connections.
                    ansTail->right = list1;
                    list1->left = ansTail;

                    ansTail = ansTail->right;
                }

                // move pointer.
                list1 = list1->right;
            }
            else
            {
                // make connections.
                if (ansHead == NULL)
                {
                    // connections.
                    ansHead = ansTail = list2;
                }
                else
                {
                    // connections.
                    ansTail->right = list2;
                    list2->left = ansTail;

                    ansTail = ansTail->right;
                }

                // move pointer.
                list2 = list2->right;
            }
        }

        // remaining element in list 1.
        while (list1 != NULL)
        {
            // connections.
            ansTail->right = list1;
            list1->left = ansTail;

            ansTail = ansTail->right;

            // move pointer.
            list1 = list1->right;
        }
        // remaining element in list 2.
        while (list2 != NULL)
        {
            // connections.
            ansTail->right = list2;
            list2->left = ansTail;

            ansTail = ansTail->right;

            // move pointer.
            list2 = list2->right;
        }

        // return merged list.
        return ansHead;
    }

    /* Method that creates BST from Inorder Traversal. */
    // Time Complexity: O(n), n is the size of inorder traversal list.
    // Time Complexity: O(h), h is the height of the BST.
    BSTNode *createBSTFromInorderList(BSTNode *&head, int n /* n is the number of nodes in the list. */)
    {
        // Base case
        if (n <= 0 || head == NULL)
        {
            return NULL;
        }

        // Recursive case
        // First create left subtree from first n/2 nodes.
        BSTNode *leftSubtree = createBSTFromInorderList(head, n / 2);

        // Process root node.

        // After creating left subtree from first n/2 nodes. Now, you are at n/2+1th node,
        // means it is the middle node.
        // So, create root node of this middle node.
        BSTNode *root = head;

        // make connections.
        // join root with left subtree.
        root->left = leftSubtree;

        // move head one node head (because you already created a root node).
        head = head->right;

        // Move to right subtree.
        // Create right subtree from rest n-n/2-1 node.
        BSTNode *rightSubtree = createBSTFromInorderList(head, n - n / 2 - 1);

        // make connection, join root with right subtree.
        root->right = rightSubtree;

        // return root node.
        return root;
    }

    /* Method to count number of nodes in a linked list. */
    // Time Complexity: O(n), n is the size of list.
    // Time Complexity: O(1).
    int countNodes(BSTNode *head)
    {
        BSTNode *ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->right;
        }

        return count;
    }

public:
    /* Approach:

    Step 1: convert both the BSTs into 2 sorted linked list (In-Place).

    Step 2: now, at this point we have 2 sorted linked list, list 1 will contain the elements of first BST in sorted order and list 2 will contain the elements of second BST in sorted order. Now, in this step, merge both the linked list into a single linked list.

    Step 3: at this point we only have a single linked list, which is sorted in increasing order. Now you can easily create BST from inorder traversal.
    */

    /* Method to merge 2 BST into single BST. */
    // Time Complexity: O(m+n), m and n is the size of both the linked list.
    // Space Complexity: O(h1+h2), h1 and h2 are the height of BST 1 and BST 2.
    BSTNode *mergeBST(BSTNode *root1, BSTNode *root2)
    {
        // Step 1: convert both the BSTs into 2 sorted linked list (In-Place).
        // Note: inorder traversal of BST comes out in sorted order.
        BSTNode *head_1 = NULL;
        BSTNode *previous_1 = NULL;
        convertBstToDoublyLinkedList(root1, head_1, previous_1);

        BSTNode *head_2 = NULL;
        BSTNode *previous_2 = NULL;
        convertBstToDoublyLinkedList(root2, head_2, previous_2);

        // Step 2: merge both the linked lists into a single liked lists.
        BSTNode *inorderTraversalList = merge2SortedDoublyLinkedLists(head_1, head_2);

        // Step 3: create BST from inorder traversal.
        int n = countNodes(inorderTraversalList);
        BSTNode *root = createBSTFromInorderList(inorderTraversalList, n);

        // Step 4: return root.
        return root;
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
    BSTNode *root1 = NULL;
    BSTNode *root2 = NULL;

    // Building Binary Search Tree.
    BinarySearchTree bst;
    bst.takeInput(root1);
    bst.takeInput(root2);

    // Solution.
    Solution S;
    BSTNode *root = S.mergeBST(root1, root2);
    bst.LevelOrderTraversal(root);
}