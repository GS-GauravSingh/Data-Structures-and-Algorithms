#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(n/k) => O(n), n is the numbers of nodes in a Linked List.
    ListNode<int> *reverseKGroup(ListNode<int> *head, int k)
    {
        // Base Case.
        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }

        // Recursive Case.

        // Step 1 :- Reverse First k Nodes.
        int temp = k;

        // Just Checking, if the nodes is a multiple of k or not.
        // if temp != 0 and ptr == NULL,
        // it means, number of nodes is not a multiple of k.
        // So, don't reverse these nodes.
        ListNode<int> *ptr = head;
        while (temp != 0)
        {
            if (ptr == NULL)
            {
                return head;
            }

            ptr = ptr->next;
            temp--;
        }

        // if the above loop does not return anything,
        // it means, the number of nodes is a multiple of k.
        temp = k;

        ListNode<int> *currentNode = head;
        ListNode<int> *previousNode = NULL;
        ListNode<int> *nextNode = NULL;

        while (currentNode != NULL && temp != 0)
        {
            // store the reference of next node.
            nextNode = currentNode->next;

            // make a connection, that the current Node points to the previous Node.
            currentNode->next = previousNode;

            // move pointers.
            previousNode = currentNode;
            currentNode = nextNode;

            // decremet temp.
            temp--;
        }

        // As we know that, after reversing the linked list,
        // our previous node will be the head of the reverse linked list.

        // and head will become tail of Linked List.
        // and nextNode will point to the start node of next k-group.

        // Step 2:- rest recursion will handle.
        if (nextNode != NULL)
        {
            ListNode<int> *reverseHead = reverseKGroup(nextNode, k);
            head->next = reverseHead;
        }

        return previousNode;
    }

    /* Method to Print Linked List. */
    void printList(ListNode<int> *&head)
    {
        ListNode<int> *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    // creating nodes of linked list.
    ListNode<int> *head;
    ListNode<int> *node2;
    ListNode<int> *node3;
    ListNode<int> *node4;
    ListNode<int> *node5;
    ListNode<int> *node6;

    // Initializing Nodes.

    // Odd Number of Nodes.
    node5 = new ListNode<int>(5);
    node4 = new ListNode<int>(4, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // even Number of Nodes.
    // node6 = new ListNode<int>(6);
    // node5 = new ListNode<int>(5, node6);
    // node4 = new ListNode<int>(4, node5);
    // node3 = new ListNode<int>(3, node4);
    // node2 = new ListNode<int>(2, node3);
    // head = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    S.printList(head);
    ListNode<int> *newHead = S.reverseKGroup(head, 3);
    S.printList(newHead);
}