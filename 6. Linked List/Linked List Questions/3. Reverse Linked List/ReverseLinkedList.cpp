#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(1)
    void reverseList(ListNode<int> *&head)
    {
        ListNode<int> *currentNode = head;
        ListNode<int> *previousNode = NULL;
        ListNode<int> *nextNode = NULL;

        while (currentNode != NULL)
        {
            // store the reference of next node.
            nextNode = currentNode->next;

            // make a connection, that the current Node points to the previous Node.
            currentNode->next = previousNode;

            // move pointers.
            previousNode = currentNode;
            currentNode = nextNode;
        }

        // at this point your [previousNode] is the head of reversed linked list.
        head = previousNode;
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
    // ListNode<int> *node7;

    // Initializing Nodes.
    node5 = new ListNode<int>(5);
    node4 = new ListNode<int>(4, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // reverse linked list.
    Solution S;
    cout << "Before Reverse : ";
    S.printList(head);
    cout << "After Reverse : ";
    S.reverseList(head);
    S.printList(head);
}